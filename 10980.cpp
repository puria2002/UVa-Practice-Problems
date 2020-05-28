//Solution to UVa 10980: Lowest Price in Town
#include<stdio.h>
#include<iostream>
#include<algorithm> 
#include<cstring>
#include<sstream>
using namespace std;
int dp[200];

int bestPrice(pair<int, int>* items, int M, int amount)
{
    if (amount == 0) return 0;

    if (amount < 0) return 1 << 30;

    if (dp[amount - 1] != -1) return dp[amount - 1];

    dp[amount - 1] = 1 << 30;

    for (int i = 0; i < M; i++)
    {
        dp[amount - 1] = min(dp[amount - 1], items[i].second + bestPrice(items, M, amount - items[i].first));
    } 

    return dp[amount - 1]; 

}
int main()
{ 
    int K, M, amount, a, b;
    int entry = 0;
    pair<int,int> items[21]; //hold AMOUNT and PRICE of items
    items[0].first = 1;
    while (scanf("%d.%d %d", &a, &b, &M) != EOF)
    {   
        memset(dp, -1, sizeof dp);
        entry++;
        items[0].second =  100 * a + b;
        for (int i = 1; i <= M; i++)
        {
            scanf("%d %d.%d", &amount, &a, &b);
            items[i].first = amount;
            items[i].second = 100 * a + b;

        }
        M++;
        int best = bestPrice(items, M, 200); //200 since we can buy at most 2 of an bulkier item (up to 100 in quantity) to get a smaller amount
        //now loop through and modify for minimums greater than amount
        for (int i = 198; i >= 0; i--)
        { 
            best = min(dp[i], best);
            dp[i] = best;
        }
        cin.ignore();
        printf("Case %d:\n", entry);
        string line;
        getline(cin, line);
        istringstream iss(line);
        while (iss >> amount)
        {
            printf("Buy %d for $%0.2f\n", amount, dp[amount - 1] / 100.0);
        }
        
    }
}
