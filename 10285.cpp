//Solution to UVa 10285
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int heights[100][100];

bool isValid(int x, int y, int R, int C)
{
    if (x >= R || x < 0 || y >= C || y < 0) return false;
    return true;
}
int process(int i, int j, int R, int C, int* dp)
{
    if (dp[C * i + j] != -1) return dp[C * i + j];

    int dr[] = {0, 0, 1, -1};
    int dc[] = {-1, 1, 0, 0};
    int m = 0;


    for (int k = 0; k < 4; k++)
    {
        int x = i + dr[k];
        int y = j + dc[k];
        if (isValid(x , y, R, C))
        {
            if (heights[x][y] < heights[i][j])
            {
                m = max(m, process(x, y, R, C, dp));
            }
        }
    }

    return dp[C * i + j] = 1 + m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R, C;
    cin >> N;
    string slope;
    while (N--)
    {
        cin >> slope >> R >> C;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> heights[i][j];
            }
        }
        int* dp = new int[R * C];
        //C * i + j is indeximng
        memset(dp, -1, R * C * sizeof(int));
        int res = 0;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                res = max(res, process(i, j, R, C, dp));
            }
        }
        cout << slope << ": " << res << "\n";
        delete[] dp;
    }
}