#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct shark {
    int h;
    int w;
    int s; // �ӷ�
    int dir;
    int z; // ũ��
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
int dh[5] = { 0,-1,1,0,0 }; // ���� 12
int dw[5] = { 0,0,0,1,-1 }; // ���� 34
int H, W, M;
int map[101][101];
vector<shark> vs; // ��� ����

int vs_len;
int ret = 0;
void Input();
void get_fishing(int w);
void eat_shark();
int change_dir(int dir); // �� ������ ���� ���� ����
void move_shark(int v); // �� ����� ������
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
    for (int w = 1; w <= W; w++) { // 1�ʴ� ���ÿ��� w ��ġ
       //print_shark();
        get_fishing(w); // �� ���� ���

        for (int v = 0; v < vs.size(); v++) { // ��ũ �̵�
            // ������ �ʾҴٸ�
            if (vs[v].z != 0) {
                move_shark(v);
            }
        }

        //print_s();
        eat_shark(); // ��ũ���� ����
    }
}
void get_fishing(int w) {
    for (int i = 0; i < vs.size(); i++) {
        // �̹� �� ���
        if (vs[i].w < w) continue;

        for (int j = 1; j <= H; j++) {
            // ������ ���� ���� ����� ���
            if (vs[i].h == i) {
                ret += vs[i].z;
                //�Ծ��ٴ� ó��
                vs[i].z = 0;
                return;
            }
        }
    }
    //for (int h = 1; h <= H; h++) {
    //    for (int v = 0; v < ; v++) {
    //        if (vs[v].h == h && vs[v].w == w) { // �� ������ ������ �� �ִٸ�
    //            if (vs[v].z != 0) {
    //                //cout << v + 1 << "�� ��ũ ���� " << endl;
    //                ret += vs[v].z;
    //                vs[v].z = 0;
    //                //cout << "ret : " << ret << endl;
    //                return;
    //            }
    //        }
    //    }
    //}
}

void move_shark(int v) { // �� ����� ������
   //v ��° shark ������
    int s = vs[v].s; // �ӵ�
    int dir = vs[v].dir;

    //cout << v + 1 << "�� ������ Ƚ�� : " << s << endl;
    for (int t = 0; t < s; t++) {
        int h = vs[v].h;
        int w = vs[v].w;
        dir = vs[v].dir;

        if (h == 1) {
            if (dir == 1) { // ��
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }
        if (h == H) {
            if (dir == 2) { // ��
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }
        if (w == 1) {
            if (dir == 4) { // ��
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }
        if (w == W) {
            if (dir == 3) { // ��
                int ndir = change_dir(dir);
                vs[v].dir = ndir;
            }
        }


        dir = vs[v].dir;
        int nh = vs[v].h + dh[dir];
        int nw = vs[v].w + dw[dir];

        vs[v].h = nh;
        vs[v].w = nw;


        //if (dir == 1 || dir == 2) { // �� �� �� ��, h
        //   if (1 == h || h == H) { // �� ������ ������ ������ �����Ѵ�.
        //      //cout << "���� �ٲٱ�" << endl;
        //      int ndir = change_dir(dir);
        //      vs[v].dir = ndir;
        //   }
        //}
        //else { // �� �� ������ �ʿ��� ��
        //   if (1 == w || w == W) { // �� ������ ������ ������ �����Ѵ�.
        //      //cout << "���� �ٲٱ�" << endl;
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
    // �̵��� ��� �ٽ� sort
    sort(vs.begin(), vs.end(), cmp2);
    bool visited[101][101];
    shark smap[101][101];
    for (int i = 0; i < vs.size(); i++) {
        // �̵����� ���� ���鿡 ����
        if (vs[i].z > 0) {
            if (!visited[vs[i].h][vs[i].w]) {
                //ó���� �ڽ��� �ִ�
                smap[vs[i].h][vs[i].w] = vs[i];
                visited[vs[i].h][vs[i].w] = true;
            }
            else {
                if (smap[vs[i].h][vs[i].w].z < vs[i].z) {
                    //�ִ� ��� ����
                    smap[vs[i].h][vs[i].w] = vs[i];
                }
            }
        }
    }

    // ��Ƴ��� ���� �ٽ� �־��ֱ�
    vs.clear();
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (visited[i][j]) {
                vs.push_back(smap[i][j]);
            }
        }
    }

    /*
    // �ι�°
    for (int h = 1; h <= H; h++) {
       for (int w = 1; w <= W; w++) {
          int vmap_size = vmap[h][w].size();

          if (vmap_size > 1) {
             sort(vmap[h][w].begin(), vmap[h][w].end(), cmp); // �������� z�� ������
             int max = vmap[h][w][0];
             for (int i = 0; i < vmap_size; i++) {
                cout << vmap[h][w][i] << " ";
             }
             cout << endl;
             cout << "max �� : " << max << endl;
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
        if (tmp.dir == 1 || tmp.dir == 2) { // �� , �� �� h�� �ؾ���.
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
    cout << "shark ��ġ : " << endl;
    for (int v = 0; v < vs.size(); v++) {
        cout << vs[v].h << ", " << vs[v].w << endl;
    }
}