#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct Node {
    int plays, idx;
};

set<string> s;  //�뷡 ���� Ȯ��
vector<Node> v[100];    // ������ ���� �ε��� �߰�
map<string, int> gm;    // �뷡 ����, �÷��̼�
map<string, int> gi;    // �뷡 ����, ���� �ε���

bool comp(Node n1, Node n2) {
    if (n1.plays == n2.plays) {
        return n1.idx < n2.idx;
    }
    return n1.plays > n2.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int idx = 0;
    for (int i = 0; i < genres.size(); i++) {
        Node n;
        n.idx = i;
        n.plays = plays[i];
        if (s.count(genres[i])) {
            int tIdx = gi[genres[i]];
            v[tIdx].push_back(n);
            gm[genres[i]] += plays[i];
        }
        else {
            s.insert(genres[i]);
            v[idx].push_back(n);
            gm[genres[i]] = plays[i];
            gi[genres[i]] = idx++;
        }
    }
    vector<pair<int, string>> tmpV;
    // gm->vector��ȯ ��  sorting
    for (auto it=gm.begin();it!=gm.end();it++) {
        tmpV.push_back({ it->second, it->first });
    }
    sort(tmpV.begin(), tmpV.end(), greater<pair<int,string>>());

    for (int i = 0; i < tmpV.size(); i++) {
        int tIdx = gi[tmpV[i].second];  //�帣 �ε��� ��������
        //cout << tIdx << ", " << tmpV[i].second << endl;
        //�帣 ���� ��Ʈ
        sort(v[tIdx].begin(), v[tIdx].end(), comp);
        int cnt = 0;
        for (int j = 0; j < v[tIdx].size(); j++) {
            if (cnt == 2) break;
            answer.push_back(v[tIdx][j].idx);
            cnt++;
        }
    }

    return answer;
}