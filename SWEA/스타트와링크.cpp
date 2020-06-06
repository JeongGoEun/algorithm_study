#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int N, S[20][20],MIN=987654321;
bool visited[20];

void dfs(int idx, int depth);

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	dfs(0, 0);
	cout<< MIN;
	return 0;
}
void dfs(int idx, int depth) {
	if (depth == N / 2) {
		int sum1 = 0, sum2 = 0;
		vector<int> v1, v2;
		/*cout << endl;
		for (int i = 0; i < N; i++) {
			cout << visited[i] << " ";
		}
		cout << endl;*/
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				v1.push_back(i);
			}
			else {
				v2.push_back(i);
			}
		}

		//1ÆÀ 
		for (int i = 0; i < v1.size(); i++) {
			for (int j = i + 1; j < v1.size(); j++) {
				sum1 += S[v1[i]][v1[j]] + S[v1[j]][v1[i]];
			}
		}

		//2ÆÀ
		for (int i = 0; i < v2.size(); i++) {
			for (int j = i + 1; j < v2.size(); j++) {
				sum2 += S[v2[i]][v2[j]] + S[v2[j]][v2[i]];
			}
		}
		//cout << sum1 << ", " << sum2 << endl;
		int diff = abs(sum1 - sum2);
		MIN = MIN > diff ? diff : MIN;
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, depth + 1);
			visited[i] = false;
		}
	}
}