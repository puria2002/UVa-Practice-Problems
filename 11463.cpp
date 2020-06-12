//Solution to UVa 11463
#include<iostream>
#include<algorithm>
using namespace std;

int mat[100][100];
int INF = 1000000000;

//We use Floyd Warshall. Two ended BFS would work as well
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N,R, u , v, s , d;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> N >> R;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                mat[i][j] = INF;
            }
        }
        while (R--)
        {
            cin >> u >> v;
            mat[u][v] = 1;
            mat[v][u] = 1;
        }

        for (int k = 0; k < N - 1; k++)
        {
            for (int i = 0; i < N; i++)
            {
                if (mat[i][k] == INF) continue;
                for (int j = 0; j < N; j++)
                {
                    if (mat[k][j] == INF) continue;
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        cin >> s >> d;
        int maxi = 0;
        for (int j = 0; j < N; j++)
        {
            if (mat[N - 1][j] == INF) continue;
            mat[s][j] = min (mat[s][j], mat[s][N - 1] + mat[N - 1][j]);
            mat[d][j] = min (mat[d][j], mat[d][N - 1] + mat[N - 1][j]);
            if (j == s) maxi = max(maxi, mat[d][j]);
            else if (j == d) maxi = max(maxi, mat[s][j]);
            else 
            maxi = max(maxi, mat[s][j] + mat[d][j]);
        }


        cout << "Case " << i << ": ";
        cout << maxi << "\n";
    }


}