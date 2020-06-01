//Solution to UVa 11953: Battleships
#include<iostream>
#include<cstring>
using namespace std;

int visited[100][100]; //0 for univisted, 1 for visited.
int tot;
char grid[100][100];


//simple traversal on the "special" graph
void traverse(int i, int j, int N)
{
    if (grid[i][j] == '.') return;

    if (visited[i][j] == 1) return;

    bool valid = false;

    if (grid[i][j] == 'x') valid = true;
    visited[i][j] = 1;
    int dir = 0;

    if (i < N -1)
    {
        if (grid[i + 1][j] == 'x'  || grid[i + 1][j] == '@') dir = 2;
    }

    if (i > 0)
    {
        if (grid[i - 1][j] == 'x'  || grid[i - 1][j] == '@') dir = -2;
    }

    if (j > 0)
    {
        if (grid[i][j - 1] == 'x'  || grid[i][j - 1] == '@') dir = -1;
    }

    if (j < N - 1)
    {
        if (grid[i][j + 1] == 'x'  || grid[i][j + 1] == '@') dir = 1;
    }

    if (dir == 0)
    {
        if (valid) tot++;
        return;
    }

    else if (dir == 1)
    {
        j++;
        while (j < N && (grid[i][j] == '@' || grid[i][j] == 'x'))
        {
            if (grid[i][j] == 'x') valid = true;
            visited[i][j] = 1;
            j++;
        }
        if (valid) tot++;
        return;
    }
    
    else if (dir == -1)
    {
        j--;
        while (j >= 0 && (grid[i][j] == '@' || grid[i][j] == 'x'))
        {
            if (grid[i][j] == 'x') valid = true;
            visited[i][j] = 1;
            j--;
        }
        if (valid) tot++;
        return;
    }

    else if (dir == 2)
    {
        i++;
        while (i < N && (grid[i][j] == '@' || grid[i][j] == 'x'))
        {
            if (grid[i][j] == 'x') valid = true;
            visited[i][j] = 1;
            i++;
        }
        if (valid) tot++;
        return;
    }

    else
    {
        i--;
        while (i >= 0 && (grid[i][j] == '@' || grid[i][j] == 'x'))
        {
            if (grid[i][j] == 'x') valid = true;
            visited[i][j] = 1;
            i--;
        }
        if (valid) tot++;
        return;
    }
    
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, N;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> N;
        tot = 0;

        memset(visited, 0, sizeof visited);

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> grid[j][k];
            }
        }
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                traverse(j, k, N);
            }
        }

        cout << "Case " << i << ": " << tot << "\n";
    }
    return 0;
}