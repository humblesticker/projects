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
            r += rd; c += cd; if(r < 0 || r >= R || c < 0 || c >= C) break;
            if(a[r][c] == '#') { time = 2; continue; }

            int newt = cell.t + time; 
            if(t[r][c] < 0 || newt < t[r][c]) { q.push({r, c, newt}); t[r][c] = newt; }
            break;
        }
	}

public:
	int pathLength(vector<string> a, int r1, int c1, int r2, int c2) {
        int R = a.size(), C = a[0].length();
        vector<vector<int>> t(R, vector<int>(C, -1));
		priority_queue<Cell> q; q.push({ r1, c1, 0}); t[r1][c1] = 0;

		while(!q.empty()) {
			auto cur = q.top(); if(cur.r == r2 && cur.c == c2) return cur.t;

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
        { "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................", "........................................"}, 
        17, 6, 25, 36) << endl;
    return 0;
}