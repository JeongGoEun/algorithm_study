#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int request, end;
};

// compare의 기준을 잘 보자
struct compare {
    bool operator()(Node n1, Node n2) {
        if (n1.end == n2.end) {
            n1.request > n2.request;
        }
        return n1.end > n2.end;
    }
};
int solution(vector<vector<int>> jobs) {
    int sum = 0, idx=0, time=0;

    sort(jobs.begin(), jobs.end());
    priority_queue<Node, vector<Node>, compare> pq;

    while (idx < jobs.size() || !pq.empty()) {
        if (idx < jobs.size() && jobs[idx][0] <= time) {
            // 시작 시간보다 전에 들어온 우선순위들
            pq.push({ jobs[idx][0], jobs[idx][1] });
            idx++;
            continue;
        }

        if (!pq.empty()) {
            // 소요시간 + 대기시간
            Node n = pq.top();
            pq.pop();

            time += n.end;
            sum += time - n.request;
        }
        else {
            time = jobs[idx][0];
        }
    }
    return sum / jobs.size();
}