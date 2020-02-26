#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[125000];    //
int solution(vector<vector<int>> triangle) {
    int answer = 0,MAX=0,idx=0;
    arr[0] = triangle[0][0];
    for (int i = 0; i < triangle.size(); i++) {
        int size = triangle[i].size();
        if (i == triangle.size() - 1) {
            for (int j = 0; j < size; j++) {
                MAX = MAX < arr[idx] ? arr[idx] : MAX;
                idx++;
            }
        }
        else {
            for (int j = 0; j < size; j++) {
                int n1 = arr[idx] + triangle[i + 1][j];
                int n2 = arr[idx] + triangle[i + 1][j + 1];

                arr[idx + size] = max(arr[idx + size], n1);
                arr[idx + size + 1] = max(arr[idx + size + 1], n2);
                idx++;
            }
        }
    }
    return MAX;
}

/*
풀이
- 현재 위치에서 다음위치, 다음위치+1의 값 중, 가장 큰 값을 우선으로 하고
    다음 위치의 arr의 최대값과 비교하며 갱신
- 마지막 위치에선 이미 구해진 최대값으로 MAX값 갱신
*/