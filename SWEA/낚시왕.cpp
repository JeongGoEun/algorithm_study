#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct shark {
    int h;
    int w;
    int s; // 속력
    int dir;
    int z; // 크기
};
bool cmp(int A, int B)
{
    return A > B;
}
bool cmp2(shark s1, shark s2) {
    if (s1.w == s2.w) {
        return s1.h < s2.h;
    }
    return s1.w < s2.w;
}

vector<int> vmap[101][101];
int dh[5] = { 0,-1,1,0,0 }; // 상하 12
int dw[5] = { 0,0,0,1,-1 }; // 우좌 34
int H, W, M;
int map[101][101];
vector<shark> vs; // 상어 벡터

int vs_len;
int ret = 0;
void Input();
void get_fishing(int w);
void eat_shark();
int change_dir(int dir); // 맨 끝으로 가면 방향 변경
void move_shark(int v); // 한 상어의 움직임
void Solution();
void print_shark();
void print_s();

int main() {
    Input();
    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }
    Solution();
    cout << ret << endl;
    return 0;
}

void Solution() {
    //change_s();
    for (int w = 1; w <= W; w++) { // 1초당 낚시왕의 w 위치
       //print_shark();
        get_fishing(w); // 상어를 먼저 잡고

        for (int v = 0; v < vs.size(); v++) { // 샤크 이동
            // 먹히지 않았다면
            if (vs[v].z != 0) {
                move_shark(v);
            }
        }

        //print_s();
        eat_shark(); // 샤크끼리 먹음
    }
}
void get_fishing(int w) {
    for (int i = 0; i < vs.size(); i++) {
        // 이미 본 상어
        if (vs[i].w < w) continue;

        for (int j = 1; j <= H; j++) {
            // 위에서 부터 가장 가까운 상어
            if (vs[i].h == i) {
                ret += vs[i].z;
                //먹었다는 처리
                vs[i].z = 0;
                return;
            }
        }
    }
    //for (int h = 1; h <= H; h++) {
    //    for (int v = 0; v < ; v++) {
    //        if (vs[v].h == h && vs[v].w == w) { // 맨 위에서 잡히는 상어가 있다면
    //            if (vs[v].z != 0) {
    //                //cout << v + 1 << "번 샤크 잡음 " << endl;
    //                ret += vs[v].z;
    //                vs[v].z = 0;
    //                //cout << "ret : " << ret << endl;
    //                return;
    //            }
    //        }
    //    }
    //}
}

void move_shark(int v) { // 한 상어의 움직임
   //v 번째 shark 움직임
    int s = vs[v].s; // 속도
    int dir = vs[v].dir;

    //cout << v + 1 << "번 움직임 횟수 : " << s << endl;
    for (int t = 0; t < s; t++) {
        int h = vs[v].h;
        int w = vs[v].w;
        dir = vs[v].dir;

        if (h == 1) {
            if (dir == 1) { // 상
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }
        if (h == H) {
            if (dir == 2) { // 하
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }
        if (w == 1) {
            if (dir == 4) { // 좌
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }
        if (w == W) {
            if (dir == 3) { // 우
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }


        dir = vs[v].dir;
        int nh = vs[v].h + dh[dir];
        int nw = vs[v].w + dw[dir];

        vs[v].h = nh;
        vs[v].w = nw;


        //if (dir == 1 || dir == 2) { // 상 하 일 때, h
        //   if (1 == h || h == H) { // 맨 끝으로 갔으면 방향을 변경한다.
        //      //cout << "방향 바꾸기" << endl;
        //      int ndir = change_dir(dir);
        //      vs[v].dir = ndir;
        //   }
        //}
        //else { // 좌 우 변경이 필요할 때
        //   if (1 == w || w == W) { // 맨 끝으로 갔으면 방향을 변경한다.
        //      //cout << "방향 바꾸기" << endl;
        //      int ndir = change_dir(dir);
        //      vs[v].dir = ndir;
        //   }
        //}

    }

    map[vs[v].h][vs[v].w]++;

    vmap[vs[v].h][vs[v].w].push_back(vs[v].z);
}

int change_dir(int dir) {
    if (dir == 1)   return 2;
    else if (dir == 2)   return 1;
    else if (dir == 3)   return 4;
    else if (dir == 4)   return 3;
}

void eat_shark() {
    print_s();
    // 이동한 상어 다시 sort
    sort(vs.begin(), vs.end(), cmp2);
    bool visited[101][101];
    shark smap[101][101];
    for (int i = 0; i < vs.size(); i++) {
        // 이동하지 않은 상어들에 대해
        if (vs[i].z > 0) {
            if (!visited[vs[i].h][vs[i].w]) {
                //처음엔 자신이 최대
                smap[vs[i].h][vs[i].w] = vs[i];
                visited[vs[i].h][vs[i].w] = true;
            }
            else {
                if (smap[vs[i].h][vs[i].w].z < vs[i].z) {
                    //최대 상어 갱신
                    smap[vs[i].h][vs[i].w] = vs[i];
                }
            }
        }
    }

    // 살아남은 상어들 다시 넣어주기
    vs.clear();
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (visited[i][j]) {
                vs.push_back(smap[i][j]);
            }
        }
    }

    /*
    // 두번째
    for (int h = 1; h <= H; h++) {
       for (int w = 1; w <= W; w++) {
          int vmap_size = vmap[h][w].size();

          if (vmap_size > 1) {
             sort(vmap[h][w].begin(), vmap[h][w].end(), cmp); // 오름차순 z의 값이지
             int max = vmap[h][w][0];
             for (int i = 0; i < vmap_size; i++) {
                cout << vmap[h][w][i] << " ";
             }
             cout << endl;
             cout << "max 값 : " << max << endl;
             for (int v = 1; v < vs_len; v++) {
                if (vs[v].h == h && vs[v].w == w && vs[v].z != 0) {
                      vs[v].z = 0;
                }
             }
          }

       }
    }
    */



}

void Input() {
    cin >> H >> W >> M;
    shark tmp;
    for (int m = 0; m < M; m++) {
        cin >> tmp.h >> tmp.w >> tmp.s >> tmp.dir >> tmp.z;
        if (tmp.dir == 1 || tmp.dir == 2) { // 상 , 하 면 h로 해야지.
            tmp.s = (tmp.s % ((2 * H) - 2));
        }
        else {
            tmp.s = (tmp.s % ((2 * W) - 2));
        }
        vs.push_back(tmp);
    }
    sort(vs.begin(), vs.end(), cmp2);
}

void print_s() {
    cout << "shark 위치 : " << endl;
    for (int v = 0; v < vs.size(); v++) {
        cout << vs[v].h << ", " << vs[v].w << endl;
    }
}