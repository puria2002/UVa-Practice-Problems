//solution to UVa 10819: Trouble of 13-Dots
#include<iostream> 
#include<algorithm>
#include<cstring>
using namespace std;
int dp[110][10001]; //direct access table


int bestValue(int budget, int index, pair<int,int>* catalog, int spending, int n)
{
    if (spending > budget + 200) return -(1 << 30); //overspent no matter what

    if (budget <= 1800 && spending > budget) return -(1 << 30); //again overspent

    //if spending exceeds by less than 201 and budget > 1800, we must check to make sure final spending 
    //is above 2000
    if (index == n)
    {
        if (spending > budget && spending <= 2000) return -(1 << 30); //overspent--no refund issued
        return 0; //can purchase no more items
    }


    if (dp[index][spending] != -1) return dp[index][spending];

    //we either buy item at index or not buy it:
    return dp[index][spending] = max(bestValue(budget, index + 1, catalog, spending, n), (catalog[index]).second + 
    bestValue(budget, index + 1, catalog, spending + (catalog[index]).first, n));

 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    pair<int, int>* catalog;
    int m ,n;
    while (cin >> m >> n)
    { 
        memset(dp, -1, sizeof dp);

        catalog = new pair<int,int>[n];

        for (int i = 0; i < n; i++)
        {
            cin >> (catalog[i]).first;
            cin >> (catalog[i]).second;
        }

        cout << bestValue(m, 0, catalog, 0, n) << "\n";
        delete[] catalog;

    }
    return 0;

}