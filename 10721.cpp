//solution to UVa 10721: Bar Codes
#include<iostream>
#include<cstring>
using namespace std;

long long dp[51][51];

//very simple recursive relationship between counts
long long BC(int n, int k, int m)
{
    if (n <= 0) return 0;

    if (k == 1)
    {
        if (n <= m) return 1;
        else return 0;
    } //simple base case

    if (dp[n][k] != -1) return dp[n][k];

    dp[n][k] = 0;
    for (int i = 1; i <= m; i++)
    {
        dp[n][k] += BC(n - i, k - 1, m);
    }
    return dp[n][k];
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k, m;

    unsigned long long res;
    while (cin >> n >> k >>m)
    {
        memset(dp, -1, sizeof dp);
        cout << BC(n, k, m) << "\n";
    }

    return 0;
}