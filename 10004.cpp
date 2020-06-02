#include<iostream> 
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char color[199]; //1 if unvisited, -1 if white, 0 if black


bool isBipartite(vector<vector <int>>& adj)
{
    queue<int> vertices;
    //start of by coloring node 0 white and implement BFS from there.
    color[0] = -1;
    vertices.push(0);
    while (!vertices.empty())
    {
        int i = vertices.front();
        vertices.pop();
        for (int j : adj[i])
        {
            if (color[j] == 1)
            {
                color[j] = ~color[i];
                vertices.push(j);
            }

            else if (color[j] == color[i])

            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, l;
    int i, j;
    while (cin >> n, n)
    {
        memset(color, 1, sizeof color);
        vector<vector<int>> adj (n);
        cin >> l;
        while (l--)
        {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        if(isBipartite(adj))
        {
            cout << "BICOLORABLE.\n";
        }

        else
        {
            cout << "NOT BICOLORABLE.\n";
        }
    }

    return 0;
}