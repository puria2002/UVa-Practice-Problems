//Solution to Uva 11906: Knight in War Grid
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int grid[100][100];

//let -1 denote invalid, 0 denote unvisited, 1 denote visited, 2 denote queued

int even, odd;


//can implement either a DFS or a BFS. We do a BFS.

bool isValid(int x, int y, int R, int C)
{
    if (x >= R || x < 0 || y >= C || y < 0) return false;

    if (grid[x][y] == -1) return false;

    return true;
}

void BFS(int R, int C, int M, int N)
{
    queue<pair<int, int> > vertices;

    vertices.push(make_pair(0,0));
    
    if (min (M, N) != 0)
    {
        if (M != N)
        {
            while (!vertices.empty())
            {
                int count = 0;
                pair<int, int> vertex = vertices.front();
                vertices.pop();

                if (isValid(vertex.first + M, vertex.second + N, R, C))
                {
                    count++;
                    if (grid[vertex.first + M][vertex.second + N] == 0)
                    {
                        vertices.push(make_pair(vertex.first + M, vertex.second + N));
                        grid[vertex.first + M][vertex.second + N] = 2;
                    }
                }

                if (isValid(vertex.first - M, vertex.second - N, R, C))
                {
                    count++;
                    if (grid[vertex.first - M][vertex.second - N] == 0)
                    {
                        vertices.push(make_pair(vertex.first - M, vertex.second - N));
                        grid[vertex.first - M][vertex.second - N] = 2;
                    }
                }

                if (isValid(vertex.first + N, vertex.second + M, R, C))
                {
                    count++;
                    if (grid[vertex.first + N][vertex.second + M] == 0)
                    {
                        vertices.push(make_pair(vertex.first + N, vertex.second + M));
                        grid[vertex.first + N][vertex.second + M] = 2;
                    }
                }

                if (isValid(vertex.first - N, vertex.second - M, R, C))
                {
                    count++;
                    if (grid[vertex.first - N][vertex.second - M] == 0)
                    {
                        vertices.push(make_pair(vertex.first - N, vertex.second - M));
                        grid[vertex.first - N][vertex.second - M] = 2;
                    }
                }

                if (isValid(vertex.first - M, vertex.second + N, R, C))
                {
                    count++;
                    if (grid[vertex.first - M][vertex.second + N] == 0)
                    {
                        vertices.push(make_pair(vertex.first - M, vertex.second + N));
                        grid[vertex.first - M][vertex.second + N] = 2;
                    }
                }

                if (isValid(vertex.first + M, vertex.second - N, R, C))
                {
                    count++;
                    if (grid[vertex.first + M][vertex.second - N] == 0)
                    {
                        vertices.push(make_pair(vertex.first + M, vertex.second - N));
                        grid[vertex.first + M][vertex.second - N] = 2;
                    }
                }

                if (isValid(vertex.first - N, vertex.second + M, R, C))
                {
                    count++;
                    if (grid[vertex.first - N][vertex.second + M] == 0)
                    {
                        vertices.push(make_pair(vertex.first - N, vertex.second + M));
                        grid[vertex.first - N][vertex.second + M] = 2;
                    }
                }

                if (isValid(vertex.first + N, vertex.second - M, R, C))
                {
                    count++;
                    if (grid[vertex.first + N][vertex.second - M] == 0)
                    {
                        vertices.push(make_pair(vertex.first + N, vertex.second - M));
                        grid[vertex.first + N][vertex.second - M] = 2;
                    }
                }

                grid[vertex.first][vertex.second] = 1;
                if (count & 1) odd++;
                else even++;
            }
        }

        else
        {
            while (!vertices.empty())
            {
                int count = 0;
                pair<int, int> vertex = vertices.front();
                vertices.pop();

                if (isValid(vertex.first + M, vertex.second + N, R, C))
                {
                    count++;
                    if (grid[vertex.first + M][vertex.second + N] == 0)
                    {
                        vertices.push(make_pair(vertex.first + M, vertex.second + N));
                        grid[vertex.first + M][vertex.second + N] = 2;
                    }
                }

                if (isValid(vertex.first - M, vertex.second - N, R, C))
                {
                    count++;
                    if (grid[vertex.first - M][vertex.second - N] == 0)
                    {
                        vertices.push(make_pair(vertex.first - M, vertex.second - N));
                        grid[vertex.first - M][vertex.second - N] = 2;
                    }
                }


                if (isValid(vertex.first - M, vertex.second + N, R, C))
                {
                    count++;
                    if (grid[vertex.first - M][vertex.second + N] == 0)
                    {
                        vertices.push(make_pair(vertex.first - M, vertex.second + N));
                        grid[vertex.first - M][vertex.second + N] = 2;
                    }
                }

                if (isValid(vertex.first + M, vertex.second - N, R, C))
                {
                    count++;
                    if (grid[vertex.first + M][vertex.second - N] == 0)
                    {
                        vertices.push(make_pair(vertex.first + M, vertex.second - N));
                        grid[vertex.first + M][vertex.second - N] = 2;
                    }
                }


                grid[vertex.first][vertex.second] = 1;
                if (count & 1) odd++;
                else even++;
            }
        }
        
    }

    else
    {
        int a = max(M, N);

        while (!vertices.empty())
        {
            int count = 0;
            pair<int, int> vertex = vertices.front();
            vertices.pop();

            if (isValid(vertex.first + a, vertex.second, R, C))
            {
                count++;
                if (grid[vertex.first + a][vertex.second] == 0)
                {
                    vertices.push(make_pair(vertex.first + a, vertex.second));
                    grid[vertex.first + a][vertex.second] = 2;
                }
            }
            if (isValid(vertex.first - a, vertex.second, R, C))
            {
                count++;
                if (grid[vertex.first - a][vertex.second] == 0)
                {
                    vertices.push(make_pair(vertex.first - a, vertex.second));
                    grid[vertex.first - a][vertex.second] = 2;
                }
            }
            if (isValid(vertex.first, vertex.second + a, R, C))
            {
                count++;
                if (grid[vertex.first][vertex.second + a] == 0)
                {
                    vertices.push(make_pair(vertex.first, vertex.second + a));
                    grid[vertex.first][vertex.second + a] = 2;
                }
            }
            if (isValid(vertex.first, vertex.second - a, R, C))
            {
                count++;
                if (grid[vertex.first][vertex.second - a] == 0)
                {
                    vertices.push(make_pair(vertex.first, vertex.second - a));
                    grid[vertex.first][vertex.second - a] = 2;
                }
            }

            grid[vertex.first][vertex.second] = 1;
            if (count & 1) odd++;
            else even++;

        }
        

    }
    
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC, R, C, M, N, W, x , y;

    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        cin >> R >> C >> M >> N >> W;
        memset(grid , 0, sizeof grid);
        even = 0;
        odd = 0;
        while (W--)
        {
            cin >> x >> y;
            grid[x][y] = -1;
        }

       BFS(R, C, M, N);
       cout << "Case " << i << ": " << even << " " << odd << "\n";
    }

}