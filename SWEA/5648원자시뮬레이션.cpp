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

        // �̵�
        for (int i = 0; i < v.size(); i++) {
            if (v[i].flag) {   //����ִ� �ֵ鿡 ���ؼ�
                int ny = v[i].y + dy[v[i].dir];
                int nx = v[i].x + dx[v[i].dir];
                map[v[i].x][v[i].y] = 0;

                //���� ���� �ִٸ�
                if (ny >= 0 && ny <= 4000 && nx >= 0 && nx <= 4000) {
                    map[nx][ny] += 1;
                    v[i].y = ny;
                    v[i].x = nx;
                }
                else {
                    // ������ ��� -> ������ ������
                    v[i].flag = false;
                }
            }
        }

        // ��ġ�� ���� üũ
        for (int i = 0; i < v.size(); i++) {
            if (v[i].flag) {   //����ִ� �ֵ鿡 ���ؼ�
                //cout << map[v[i].x][v[i].y] << endl;
                if (map[v[i].x][v[i].y] > 1) {
                    // ��ġ�� �ֵ� ó��
                    for (int j = 0; j < v.size(); j++) {
                        if (i == j || !v[j].flag) continue;
                        if (v[i].y == v[j].y && v[i].x == v[j].x) {
                            v[j].flag = false;
                            ans += v[j].energy;
                        }
                    }
                    ans += v[i].energy;
                    v[i].flag = false;
                    //cout << "��ħ " << v[i].y << ", " << v[i].x << endl;
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
            tmp.y = (tmp.y + 1000) * 2;   //����ó��, 0.5�� ó��
            tmp.x = (tmp.x + 1000) * 2;
            tmp.flag = true;
            v.push_back(tmp);
            map[tmp.x][tmp.y] = true;
        }
        int ans = simulate();
        cout << "#" << t << " " << ans << "\n";

        //�ʱ�ȭ
        v.clear();
    }
    return 0;
}
/*
����1
- ����Ʈ�� �����Ϸ� ������ 0.5�ʿ��� ��ġ�� �κ��� ȿ�������� ó���� ����� �𸣰���
   -> map, set, vector�� �Ἥ ��ǥ�� �����ϰ� ó���Ϸ� ������ ��ȿ����

����1
- �Լ� ��ǥ�� �ƴ� �湮 ��ǥ�� �����ؼ� y, xó���� ����� ����(����)

Ǯ��
- ������ +1000���� �ؼ� 0,2000���� ó��
- 0.5�ʴ� 2000*2 -> 4000 * 4000���� ó���غ���

*/