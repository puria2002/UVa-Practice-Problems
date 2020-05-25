//solution to UVa 10576: Y2K Accounting
#include<iostream>
using namespace std;

//input space (2^12) small enough to permit recursive backtracking
//let deficit correspond to 0 and surplus to 1 in the bitmask

long long backtrack(int s, int d, int m, long long sum, long long totsum, char bitmask)
{
    
    if (m > 4 && sum > 0) return -12 * d; //prune
    if (m == 12) return totsum; //reached a leaf
    //if deficit
    long long def;
    if (m >= 5)
    {
        if (bitmask & (1 << (m - 5))) //i.e. if the sliding window had a surplus
        {
            def = backtrack(s, d, m + 1, sum - d - s, totsum - d, bitmask);
        }
        else
        {
            def = backtrack(s, d, m + 1, sum, totsum - d, bitmask);
        }
        
    }
    else def = backtrack(s, d, m + 1, sum - d, totsum - d, bitmask);
    //if surplus
    long long sur;
    if (m < 7) bitmask |= (1 << m);
    if (m >= 5)
    {
        if (bitmask & (1 << (m - 5))) //i.e. if the sliding window had a surplus
        {
            sur = backtrack(s, d, m + 1, sum, totsum + s, bitmask);
        }
        else
        {
            sur = backtrack(s, d, m + 1, sum + d + s, totsum + s, bitmask);
        }
        
    }
    else sur = backtrack(s, d, m + 1, sum + s, totsum + s, bitmask);
    return max(def , sur);
}
int main()
{
    ios::sync_with_stdio(0);
    int s, d;
    long long res;
    while (cin >> s >> d)
    {
        res = backtrack(s, d, 0, 0, 0, 0);
        if (res >=  0) cout << res << endl;
        else cout << "Deficit" << endl;
    }
}