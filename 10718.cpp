//Solution to UVa 10718: Bit Mask
#include<iostream>
using namespace std;

//simple recursion + greedy
unsigned int max(unsigned int target, unsigned int L, unsigned int U, unsigned int n)
{
    int i, j;
    for (i = n-1; i >=0; i--)
    {
        if (U & (1 << i)) break;
    }

    if (i == -1) return 0;

    for (j = n -1; j >=0; j--)
    {
        if (L & (1 << j)) break;
    }


    if (i == j)
    {
        return (1 << i) + max(target, L, U, i);
    }
    else
    {
        if (target & (1 << i)) return max(target, L, -1, i);
        else return (1 << i) + max(target, 0, U, i);
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    unsigned int N, L, U;
    while (cin >> N >> L >> U)
    {
        cout << max(N, L , U , 32) << "\n";
    }
}