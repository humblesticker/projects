#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Coins {
    int msb(int b) {
        int i = -1;
        while(b > 0) { b >>= 1; i++; }
        return i; 
    }

    // find 
    int find(int pos, vector<int>& coins) {
        for(int i=pos; i>=0; i--) if(coins[i] > 0) return i;
        return -1;
    }

public:
    int get(int b, vector<int> coins) {
        int count = 0, pos = 0;
        while((pos = msb(b)) >= 0) {
            int found = find(pos, coins); if(found < 0) return -1;
            int m = (1 << found), n = min(b/m, coins[found]);
            //cout << pos << "," << found << "," << m << "," << n << "\n";
            b -= n * m; coins[found] -= n; count += n;
        }
        return count;
    }
};

int main() {
    int n, q, a, b, value = 1; vector<int> coins(31); 
    unordered_map<int, int> map; for(int i=0; i<31; i++, value *= 2) map[value] = i;
    cin >> n >> q; while(n-- > 0) { cin >> a; coins[map[a]]++; }

    Coins c;
    while(q-- > 0) { cin >> b; cout << c.get(b, coins) << "\n"; }
    return 0;
}
/*
b: 10000
coins: 01220
*/