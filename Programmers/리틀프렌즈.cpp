#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node {
    int y, x;
};
vector<Node> alpha[30];
vector<string>map;
string answer;

bool findChar(char cur, int m, int n) {
    int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
    Node s = alpha[cur - 'A'][0], e = alpha[cur - 'A'][1];

    for (int i = 0; i < 4; i++) {
        int ny = s.y + dy[i];
        int nx = s.x + dx[i];

        while ((ny >= 0 && ny < m && nx >= 0 && nx < n) && (map[ny][nx] == '.' || map[ny][nx] == cur)) {
            if (map[ny][nx] == cur) {
                return true;
            }

            //꺾이는 부분 위치 지정
            int ldir = 0, rdir = 0;
            if (i <= 1) {
                ldir = 2; rdir = 3;
            }
            else {
                ldir = 0; rdir = 1;
            }

            //왼쪽 검사
            int ly = ny + dy[ldir], lx = nx + dx[ldir];
            while ((ly >= 0 && ly < m && lx >= 0 && lx < n) && (map[ly][lx] == '.' || map[ly][lx] == cur)) {
                if (map[ly][lx] == cur) {
                    return true;
                }
                ly += dy[ldir]; lx += dx[ldir];
            }

            //오른쪽 검사
            int ry = ny + dy[rdir], rx = nx + dx[rdir];
            while ((ry >= 0 && ry < m && rx >= 0 && rx < n) && (map[ry][rx] == '.' || map[ry][rx] == cur)) {
                if (map[ry][rx] == cur) {
                    return true;
                }
                ry += dy[rdir]; rx += dx[rdir];
            }

            //전진
            ny += dy[i];
            nx += dx[i];
        }
    }
    return false;
}
string solution(int m, int n, vector<string> board) {
    answer = "";
    map = board;
    for (int i = 0; i < 30; i++) {
        alpha[i].clear();
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = board[i][j];
            if ('A' <= board[i][j] && board[i][j] <= 'Z') {
                Node n;
                n.y = i;    n.x = j;
                alpha[board[i][j] - 'A'].push_back(n);
            }
        }
    }

    for (int i = 0; i <= 26; i++) {
        // 이미 검사 했으면
        //cout << (char)i + 'A' << "  " << alpha[i].size() << endl;
        if (alpha[i].empty()) continue;

        if (findChar(i+'A', m, n)) {
            // 지울 수 있으면 처음부터 다시 검사(앞글자부터)
            map[alpha[i][0].y][alpha[i][0].x] = '.';
            map[alpha[i][1].y][alpha[i][1].x] = '.';
            answer += i+'A';
            alpha[i].clear();
            // i=0이면 A부터 검사 안하고 B부터 검사함(++때문에)
            i = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //cout << map[i][j];
            if ('A' <= map[i][j] && map[i][j] <= 'Z') {
                answer = "IMPOSSIBLE";
                //break;
            }
        }
        cout << endl;
    }

    return answer;
}
/*
생각
1 - A~Z까지 처음부터 순회하는 생각은 했지만 상,하,좌,우(dir)과 꺾인 갯수(cnt)를 중첩으로 생각해야 했다
    - 단순한 bfs로는 어려울 것 같았다(4가지 방향에 대해 bfs를 돌리는 방법도 있었지만)

풀이
1- 어차피 한번씩 꺾여야 하기 때문에 상하->좌우, 좌우->상하로 꺾일 때만 확인해주면 된다.
    쭉 직진을 한다는 생각으로 한번씩 꺾어주어 확인했다.
*/