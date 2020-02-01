#include<iostream>
#include <string>
#include <vector>
using namespace std;
bool visited[9];
int MIN = 987654321;

// 현재 위치, 고친 갯수, 새로운 약한 부분
void dfs(int idx, int cnt, vector<int> nweak) {

}

int solution(int n, vector<int> weak, vector<int> dist) {
    for (int i = 0; i < dist.size(); i++) {
        vector<int> nweak;

        for (int j = i; j < dist.size(); j++) {
            nweak.push_back(weak[j]);
        }
        for (int j = 0; j < i; j++) {
            nweak.push_back(weak[j]+n);
        }

        visited[i] = true;
        dfs(0, 0, nweak);
        visited[i] = false;
    }

    return MIN;
}