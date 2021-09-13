#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int SIZE=0;
struct Node{
    int games=0, winCnt=0, weight=0, playerNum=0;
    double winRate=0;
};

struct comp{
    bool operator() (Node n1, Node n2) {
        // 정렬 함수
    }
};
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    SIZE = weights.size();
    vector<Node> boxers(SIZE);

    // 복서들 초기화
    for(int i=0; i<SIZE; i++) {
        boxers[i] = { SIZE, 0, weights[i], 0, i+1 };
    }

    // 승패 설정
    for(int i=0; i<SIZE; i++) {
        string hStr = head2head[i];
        for(int j=i;j<hStr.size();j++) {
            // 자기 자신이 아닐 때
            if(i != j) {
                if(hStr[j] == 'N') {
                    // 아직 붙어본 적 없을 때 - 둘다 게임수 차감
                    boxers[i].games--;
                    boxers[j].games--;
                } else if(hStr[j] == 'W') {
                    // 이겼을 때 - 자신의 winCnt 증가
                    boxers[i].winCnt++;
                } else {
                    // 졌을 때 - 상대의 winCnt 증가       
                    boxers[j].winCnt++;
                }
            }
        }
    }

    for(int i=0;i<SIZE;i++) {
        if(boxers[i].games != 0) {
            boxers[i].winRate = boxers[i].games / boxers[i].winCnt;
        }
    }

    // 정렬
    sort(boxers.begin(), boxers.end(), comp);

    for(int i=0;i<SIZE;i++) {
        answer[i] = boxers[i].playerNum;
    }

    return answer;
}