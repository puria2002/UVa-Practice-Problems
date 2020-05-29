//Solution to UVa 11003: Boxes
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1000][6005];
//Two constraints: boxes with lower serial numbers cannot be stacked on those with higher numbers.
//total weight of boxes above cannot exceed load.
//this is the slow method
//faster is decide if you place a box or not...keep in my mind the
//minimum new bearable load.
/*int maxBoxes(pair<int, int>* boxes, int N, int load)
{
    if (N == 0) return 0; //end of recursion; no more boxes possible.
    if (load > 3000) return 0; //no more stacking possible

    if (dp[N - 1][load] != -1) return dp[N-1][load];
    
    //first try to find the top box, then the next, etc. etc. down to the ground level
    dp[N-1][load] = 0;
    for (int i = 0; i < N; i++)
    {
        if (load <= boxes[i].second)
        dp[N-1][load] = max(dp[N-1][load], 1 + maxBoxes(boxes, i, load + boxes[i].first)); //slow O(N) step!
    }

    return dp[N-1][load];
}*/
int maxBoxes (pair<int, int>* boxes, int cur, int bearable, int N)
{
    if (bearable < 0) return -(1 <<30); //broke a box
    if (cur == N) return 0;


    if (dp[cur][bearable] != -1) return dp[cur][bearable];

    int placedBearable = min(bearable - boxes[cur].first, boxes[cur].second);
    int placed = 1 + maxBoxes(boxes, cur + 1, placedBearable, N);
    int notPlaced = maxBoxes(boxes, cur + 1, bearable, N); 
    return dp[cur][bearable] = max(placed, notPlaced);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    pair<int, int> boxes[1000];
    while (cin >> N, N)
    {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < N; i++)
        {
            cin >> boxes[i].first >> boxes[i].second;
        }

        cout << maxBoxes(boxes, 0,  6000, N) <<"\n";
    }
}