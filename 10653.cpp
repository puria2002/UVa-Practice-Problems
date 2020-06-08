//Solution to UVa 10653: Bombs! No they are mines!!
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

bool isValid(int x, int y, int R, int C, bool* isEdge)
{
    if (x >= R || x < 0 || y >= C || y < 0) return false;

    return isEdge[C * x + y];
}

int shortestPath(pair<int, int> start, pair<int, int> stop, bool* isEdge, int R, int C)
{
    queue<pair<int, int>> vertices;
    //need some data structure to layer our vertices of course...

    int* layer = new int[R * C];
    char* visited = new char[R * C];
    memset(visited, 0, R * C);

    vertices.push(start);

    layer[C * start.first + start.second] = 0;
    visited[C* start.first + start.second] = 1;
    while (!vertices.empty())
    {
        pair<int, int> top = vertices.front();
        vertices.pop();
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int row = top.first + dr[i];
            int col = top.second + dc[i];
            if (isValid(row, col, R, C, isEdge))
            {
                if (visited[C * row + col] == 0)
                {
                    layer[C * row + col] = layer[C * top.first + top.second] + 1;
                    if (row == stop.first && col == stop.second)
                    {
                        int res = layer[C * row + col];
                        delete[] layer;
                        delete[] visited;
                        return res;
                    }
                    visited[C * row + col] = 1;
                    vertices.push(make_pair(row, col));
                }

            }
        }
        visited[C * top.first + top.second] = 2;
    }

    delete[] layer;
    delete[] visited;
    return 1 << 30;
 }

int main()
{
    int R, C, rows;
    cin.tie(0);
    ios::sync_with_stdio(0);
    int row, N, col;
    pair<int,int> start, stop;
    while (cin >> R>> C, R | C)
    {
        bool* isEdge = new bool[R * C];
        
        memset(isEdge, 1, R * C); //initalize to true for all

        //indexing as follows:
        //(i,j) corresonds to C * i + J 
        cin >> rows;
        while (rows--)
        {
            cin >> row >> N;
            while(N--)
            {
                cin >> col;
                isEdge[C * row + col] = false;
            }
        }
        cin >> start.first >> start.second >> stop.first >> stop.second;
        cout << shortestPath(start, stop, isEdge, R, C) << "\n";


        delete[] isEdge;
    }

}