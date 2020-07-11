#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int find(int x, int y, int z) {
    if(z == 0) return 0;

    for(int i=1, pa=0; pa < z; i++) {
        int a1 = pa + x; if(a1 == z) return 2*i - 1;
        int a2 = pa + x - y; if(a2 == z) return 2*i;

        if(a2 <= pa) break;
        pa = a2;
    }

    return -1;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << find(x, y, z) << endl;
    return 0;
}