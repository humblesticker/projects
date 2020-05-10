#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class LongBeautifulInteger {
    

public:
    
};

int main() {
    int n, k, x; LongBeautifulInteger B;
    cin >> n >> k >> x;
    
    return 0;
}
/*
i from 0 to n-k-1
    make i+k th digit same as ith digit

print length of y
print y

sync(int from, int to, int n, int mult)
    if to >= from just n += diff * mult
    else 
        current = (n / mult)
        incr = to + 10 - from
        n = (current + incr) * mult
*/