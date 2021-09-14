#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

int meetCnt[1000];  // 만난 횟수

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    list<int> waitList;   // 나가는 것 대기하는 리스트
    list<int>::iterator it;
    int j=0;    // leave index

    for(int i=0;i<enter.size();i++) {
        if(waitList.empty()) {
            waitList.push_back(enter[i]);
        } else {
            // 일단 넣고
            waitList.push_back(enter[i]);

            // 같다면 지우기
            if(enter[i] == leave[j]) {
                
            } else {
                // 이전까지 ++
                for(int k=0;k<j;k++) {
                    meetCnt[li[k]]++;
                }
                meetCnt[j] += li.size();
                li.push_back(enter[i]);
            }
        }
    }

    return answer;
}