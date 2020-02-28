#include <string>
#include<iostream>
#include<set>
using namespace std;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
struct Node {
	int y, x;
};
set<string> s;	//y+x좌표의 set
int solution(string dirs) {
	int answer = 0;
	Node cur = { 0,0 };
	for (int i = 0; i < dirs.size(); i++) {
		int ny = 0, nx = 0,dir=0;
		if (dirs[i] == 'U') {
			dir = 0;
		}
		else if (dirs[i] == 'D') {
			dir = 1;
		}
		else if (dirs[i] == 'R') {
			dir = 2;
		}
		else {
			dir = 3;
		}
		ny = cur.y + dy[dir];
		nx = cur.x + dx[dir];
		if ((-5 <= ny && ny <= 5) && (-5 <= nx && nx <= 5)) {
			cur.y = ny;
			cur.x = nx;
			string tmp = to_string(cur.y) + to_string(cur.x);
			cout << tmp << endl;
			if (!s.count(tmp)) {
				answer++;
				s.insert(tmp);
			}
		}
	}
	return answer;
}