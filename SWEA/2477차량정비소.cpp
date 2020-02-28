#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
struct Node {
	int cn, rc, rp, time;
	// 고객 넘버, 접수창구 번호, 정비창구 번호, 시간
};

struct rccomp {
	bool operator()(const Node n1, const Node n2) {
		return n1.time > n2.time;
	}
};
struct rpcomp {
	bool operator()(const Node n1, const Node n2) {
		if (n1.time == n2.time) {
			return n1.cn > n2.cn;
		}
		else {
			return n1.time > n2.time;
		}
	}
};

int N, M, K, A, B, ans, runTime;
int recept[21], repair[21];
Node rcCheck[21], rpCheck[21];

priority_queue<Node, vector<Node>, rccomp> rcq;	//정비창구
priority_queue<Node, vector<Node>, rpcomp> rpq;	//정비창구
void printf() {
	for (int i = 1; i <= N; i++) {
		if(rcCheck[i].cn!=0)
			cout << rcCheck[i].cn << ", " << rcCheck[i].time << endl;
	}
	cout << endl;
	for (int i = 1; i <= M; i++) {
		if (rpCheck[i].cn != 0)
			cout << rpCheck[i].cn << ", " << rpCheck[i].time  << endl;
	}
	cout << endl << endl;
}
void input() {
	for (int i = 1; i <= N; i++) {
		cin >> recept[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> repair[i];
	}
	for (int i = 1; i <= K; i++) {
		int time = 0;
		cin >> time;
		rcq.push({ i,0,0,time });
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K >> A >> B;
		runTime = 0;
		input();
		int popCnt = 0;

		while (popCnt < K) {
			//접수 끝난사람 정비실에 넣기
			if (runTime != 0) {
				for (int i = 1; i <= N; i++) {
					if (rcCheck[i].time == runTime) {
						rpq.push(rcCheck[i]);
						rcCheck[i] = { 0,0,0,0 };
					}
				}

				// 정비 끝난사람
				for (int i = 1; i <= M; i++) {
					if (rpCheck[i].time == runTime) {
						if (rpCheck[i].rc == A && rpCheck[i].rp == B) {
							ans += rpCheck[i].cn;
						}
						rpCheck[i] = { 0,0,0,0 };
						popCnt++;
					}
				}
			}
			
			bool flag = false;
			int idx = 1;
			//접수대기->접수하기
			while (true) {
				if (rcq.empty()) break;
				Node cur = rcq.top();
				flag = false;
				//cout << cur.time << ", " << runTime << endl;
				if (cur.time <= runTime) {
					for (int i = idx; i <= N; i++) {
						if (rcCheck[i].time == 0) {
							rcq.pop();

							cur.rc = i;
							cur.time = runTime + recept[i];
							rcCheck[i] = cur;

							idx += 1;
							flag = true;
							break;
						}
					}
				}
				if (!flag)break;
			}

			idx = 1;
			flag = false;
			//정비대기->정비하기
			while (true) {
				if (rpq.empty()) break;
				Node cur = rpq.top();
				flag = false;
				if (cur.time <= runTime) {
					for (int i = idx; i <= M; i++) {
						if (rpCheck[i].time == 0) {
							rpq.pop();

							cur.rp = i;
							cur.time = runTime + repair[i];
							rpCheck[i] = cur;

							idx += 1;
							flag = true;
							break;
						}
					}
				}
				if (!flag)break;
			}
			runTime++;
			//printf();
		}

		cout << "#" << t << " " << ans << "\n";

		// 초기화
		memset(recept, 0, sizeof(recept));
		memset(repair, 0, sizeof(repair));
		ans = 0;

		for (int i = 1; i <= N; i++) {
			rcCheck[i] = { 0,0,0,0 };
		}
		for (int i = 1; i <= M; i++) {
			rpCheck[i] = { 0,0,0,0 };
		}
	}
	return 0;
}
/*
문제
- priority queue에서 empty가 아닐땐 pop을 못하게 했는데 예외처리가 안됨
	=>rcq, rpq 변수명 실수,,,

- 처음에 접수창구 확인->접수 처리->정비 창구 확인->정비로 진행했는데
	접수창구에서 새로 들어가자마자 접수 처리가 됨 -> 1초에 2번의 일을 하는것
	0초일 땐 따로 구분해주고 진짜 순서대로
	시간을 관리할 땐 그 안에 변수를 쓰는게 아니라 총 시간(runTime)으로 비교하는 습관

   ② 두 명 이상의 고객들이 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이용했던 접수 창구번호가 작은 고객이 우선한다.
   이 조건에서 그냥 pq안쓰고 앞부터 검사하면 되는 문제
*/