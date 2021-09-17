#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int y,x;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<Node> v;

    for(int i=0;i<places.size();i++) {
        for(int j=0;j<places[i].size();j++) {
            for(int k=0;k<5;k++) {
                if(places[j][k] == 'P') {
                    v.push_back({j,k});  // P가 들어있는 위치
                }
            }
        }
    }

    for(int i=0;i<v.size();i++) {
        Node curNode=v[i];
        for(int j=i+1;j<v.size();j++) {
            Node nextNode=v[j];

            if(curNode.y == nextNode.y) {

            } else if(curNode.x == nextNode.x) {

            } else if (대각선 처리) {

            } else {
                break;
            }
        }
    }
    return answer;
}

