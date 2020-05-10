#include <iostream>
#include <algorithm>
using namespace std;

int getCycle(int n) {
    int cycle = 1;

    while(n != 1) {
        if(n%2 == 0) n /= 2;
        else n = 3*n + 1;
        cycle++;
    }

    return cycle;
}

int main()
{
    int first, second; 
    while (cin >> first >> second)
    {  
        int start = min(first, second), end = max(first, second), maxCycle = 0;

        for(int i=start; i<=end; i++) 
            maxCycle = max(maxCycle, getCycle(i));

        cout << first << " " << second << " " << maxCycle << endl;
    }
    return 0;
}

/*
read i, j
max = 0
iterate from i to j
    track max

foo
    n, cycle = 1
    while n != 1
        if(n%2 == 0) n =/ 2
        else n = 3*n + 1
        cycle++
    return cycle
*/