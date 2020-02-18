#include <string>
#include <vector>
#include <iostream>
#include<cstring>

using namespace std;
int arr[35],arr2[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < reserve.size(); i++) {
        //arr2[reserve[i]] = 1;
        arr[reserve[i]] += 1;
    }
    for (int i = 0; i < lost.size(); i++) {
        //arr2[lost[i]] = -1;   -   reserve인애가 잃어버릴 수도 있으니까 고정 값X
        arr[lost[i]] += -1;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == -1) {
            if (arr[i - 1] == 1) {
                arr[i - 1] = arr[i] =  0;
            }
            else if (arr[i + 1] == 1) {
                arr[i + 1] = arr[i] =  0;
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] != -1) {
            answer++;
        }
    }
    return answer;
}

/*
생각
1- 1과 5일때만 왼쪽,오른쪽 처리하고 나머지는 양쪽 보고 판단하여 비교(정확성:33%)
->문제점 1로 초기화했는데 line34에서 1보다 큰 애들을 세어줘서 틀림(초기화를 다르게 하기)

배운점 =>범위 상관 없게 만드는 것도 방법 // 최대가 30이니까 가능한 것
(1일 때는 0을 보면되니까 왼쪽은 상관 없다 - 어차피 0 -> 오른쪽만 보게 됨, 오른쪽을 볼때도 30보다 조금 큰값을 넣어서 0으로 만든다


!문제점
예외: 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
이러한 예외를 보지 않고, 고정 된 값을 넣어줬다가 엄청 헤맸다.,,
*/