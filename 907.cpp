//Solution to UVa 907: Winterim Backpacking Trip
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[601][301];
//backtracking on implict DAG with stops constraint 
int minimize(int v, int K, int N, vector<int>& distances, int stops)
{
    //start at a vertex and choose the next vertex...any next vertex
    //yea so basically it's not a stop if you go to endpoint soooo...
    if (stops > K) return 1 << 30;
    if (v == N + 1) return 0;
    int res = 1 << 30;
    int walking;
    if (dp[v][stops] != -1) return dp[v][stops]; 
    for (int i = v + 1; i < N + 1; i++)
    {
        walking = max(distances[i] - distances[v], minimize(i, K, N, distances, stops + 1));
        res = min(walking, res);
    }
    walking = max(distances[N + 1] - distances[v], minimize(N + 1, K, N, distances, stops)); //not a stop!
    res = min(walking, res);
    return dp[v][stops] = res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;

    while (cin >> N >> K)
    {
        memset(dp, -1, sizeof dp);
        vector<int> distances(N + 2);
        distances[0] = 0;
        for (int i = 1; i < N + 2; i++)
        {
            cin >> distances[i];
            distances[i] += distances[i - 1];

        } 
        cout << minimize(0, K, N, distances, 0) << "\n";


    }
}