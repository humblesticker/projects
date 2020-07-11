#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int find(vector<int>& a) {
    int max = -1, index = -1, count = 0;

    for(int i=0; i<a.size(); i++) {
        if(a[i] >= max) {
            if(a[i] > max) count = 0;
            
            count++; if(count <= 3) index = i;
            max = a[i];
        }
    }

    return index;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int pos = find(a);
    vector<int> result;
    for(int i=0; i<a.size(); i++) 
        if(i != pos) result.push_back(a[i]);
 
    for (int i = 0; i < result.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << result[i];
    }
    cout << endl;

    return 0;
}
/*

*/