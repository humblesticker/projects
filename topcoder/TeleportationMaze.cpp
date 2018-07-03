#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Cell { int r; int c; int t; };
bool operator<(const Cell& a, const Cell& b) { return a.t > b.t; }

class TeleportationMaze { 
	void check(Cell& cell, int rd, int cd, vector<string> &a, priority_queue<Cell> &q, vector<vector<int>> &t) {
        int time = 1, R = a.size(), C = a[0].length(), r = cell.r, c = cell.c;
        
        while(true) {
            r += rd; c += cd; cout << r << "," << c << endl;
            if(r < 0 || r >= R || c < 0 || c >= C) return;
            if(a[r][c] == '#') time = 2;
            else if(t[r][c] < 0 || cell.t + time < t[r][c]) {
                t[r][c] = cell.t + time;
                q.push({r, c, cell.t + time});

                cout << "update" << endl;
                for(auto r : t) {
                    for(auto n : r) cout << n << ",";
                    cout << endl;
                }
                cout << endl;

                return;
            }
        }
	}

public:
	int pathLength(vector<string> a, int r1, int c1, int r2, int c2) {
        int R = a.size(), C = a[0].length();
        vector<vector<int>> t(R, vector<int>(C, -1));
		priority_queue<Cell> q; q.push({ r1, c1, 0}); t[r1][c1] = 0;

		while(!q.empty()) {
			auto cur = q.top(); 
            cout << "top:" << cur.r << "," << cur.c << "," << cur.t << endl;
            if(cur.r == r2 && cur.c == c2) return cur.t;

			check(cur, 0, -1, a, q, t);
			check(cur, 0, 1, a, q, t);
			check(cur, -1, 0, a, q, t);
			check(cur, 1, 0, a, q, t);
			q.pop();
		}

		return -1;	
	} 
};

int main() {
    TeleportationMaze tm;
    cout << tm.pathLength(
        {
            "......", 
            "######", 
            ".####."
        }, 
        0, 0, 0, 5) << endl;
    return 0;
}