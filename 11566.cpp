//solution to UVa 11566: Let's Yum Cha!
#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstring> 
using namespace std;
int dp[100][23][11010]; //(index, dishes , cost) direct access table for memoization


int optimalFavor(int* prices, int* favors, int N, int x, int T, int K, int index, int dishes, int cost)
{ 
    if (dishes > 2 * (N)) return -(1 << 30); //impossible
    double charge = 0.1 * (cost + N * T);
    if (ceil(charge) + cost + N * T > N * x) return -(1 << 30); //impossible
    if (index == K) return 0; // nothing more possible

    if (dp[index][dishes][cost] != -1) return dp[index][dishes][cost];
    //buy none of this dimsum
    int none;
    none = optimalFavor(prices, favors, N, x, T, K, index + 1, dishes, cost);
    //buy one
    int one;
    one = favors[index] + optimalFavor(prices, favors, N, x, T, K, index + 1, dishes + 1, cost + prices[index]);
    //buy two
    int two;
    two = 2 * favors[index] + optimalFavor(prices, favors, N, x, T, K, index + 1, dishes + 2, cost + 2 * prices[index]);
    return dp[index][dishes][cost] = max(none, max(one, two));
} 

int main()
{
    int N, x, T, K;
    int favors[100];
    int prices[100]; 
    int favor;
    double res;
    while (scanf("%d %d %d %d", &N, &x, &T, &K), N | x | T | K)
    { 
        N++;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < K; i++)
        {
            scanf("%d", prices + i);
            favors[i] = 0;
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &favor);
                favors[i] += favor;
            }
        }

        favor = optimalFavor(prices, favors, N, x, T, K, 0, 0, 0);
        res = (double) favor / N;
        printf("%.2lf\n", res);


    }   
}