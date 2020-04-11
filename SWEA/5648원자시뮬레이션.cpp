#include<iostream>
#include<list>
#include<set>
#include<string>
#include<vector>
using namespace std;
int T, N;
int dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,-1,1 };
int map[4001][4001]; 

struct Node {
    int x, y, dir, energy, flag;
};
vector<Node> v;

bool allDie() {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].flag)return false;
    }
    return true;
}

int simulate() {
    int ans = 0;
    while (!allDie()) {

        // 이동
        for (int i = 0; i < v.size(); i++) {
            if (v[i].flag) {   //살아있는 애들에 대해서
                int ny = v[i].y + dy[v[i].dir];
                int nx = v[i].x + dx[v[i].dir];
                map[v[i].x][v[i].y] = 0;

                //범위 내에 있다면
                if (ny >= 0 && ny <= 4000 && nx >= 0 && nx <= 4000) {
                    map[nx][ny] += 1;
                    v[i].y = ny;
                    v[i].x = nx;
                }
                else {
                    // 범위를 벗어남 -> 영원히 못만남
                    v[i].flag = false;
                }
            }
        }

        // 겹치는 원자 체크
        for (int i = 0; i < v.size(); i++) {
            if (v[i].flag) {   //살아있는 애들에 대해서
                //cout << map[v[i].x][v[i].y] << endl;
                if (map[v[i].x][v[i].y] > 1) {
                    // 겹치는 애들 처리
                    for (int j = 0; j < v.size(); j++) {
                        if (i == j || !v[j].flag) continue;
                        if (v[i].y == v[j].y && v[i].x == v[j].x) {
                            v[j].flag = false;
                            ans += v[j].energy;
                        }
                    }
                    ans += v[i].energy;
                    v[i].flag = false;
                    //cout << "겹침 " << v[i].y << ", " << v[i].x << endl;
                }
                map[v[i].x][v[i].y] = 0;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            Node tmp;
            cin >> tmp.x >> tmp.y >> tmp.dir >> tmp.energy;
            tmp.y = (tmp.y + 1000) * 2;   //음수처리, 0.5초 처리
            tmp.x = (tmp.x + 1000) * 2;
            tmp.flag = true;
            v.push_back(tmp);
            map[tmp.x][tmp.y] = true;
        }
        int ans = simulate();
        cout << "#" << t << " " << ans << "\n";

        //초기화
        v.clear();
    }
    return 0;
}
/*
생각1
- 리스트로 구현하려 했지만 0.5초에서 겹치는 부분을 효율적으로 처리할 방법을 모르겠음
   -> map, set, vector를 써서 좌표를 매핑하고 처리하려 했지만 비효율적

문제1
- 함수 좌표가 아닌 방문 좌표로 생각해서 y, x처리를 제대로 못함(주의)

풀이
- 음수는 +1000으로 해서 0,2000으로 처리
- 0.5초는 2000*2 -> 4000 * 4000으로 처리해보자

*/