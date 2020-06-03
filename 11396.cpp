//Solution to UVa 11396: Claw Decomposition
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

char color[401]; //1 if unvisited, 0 if white, -1 if black
bool bipartite;

//DFS bipartite graph check...
void isBipartite(vector< vector<int> >& adj, int index, int prev)
{
    if (!bipartite) return;
    if (color[index] != 1) return;


    color[index] = ~prev; //pass in -1 as a default parameter...

    for (int i : adj[index])
    {
        if (color[i] == 1)
        {
            isBipartite(adj, i, color[index]);
        }
        else if (color[i] == color[index])
        {
            bipartite = false;
            return;
        }
    }


}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int V, a, b;
    while (cin >> V, V)
    {
        vector< vector<int> > adj (V + 1);
        bipartite = true;
        memset(color, 1, sizeof color);

        while (cin >> a >> b, a | b)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= V && bipartite; i++)
        {
            isBipartite(adj, i, -1);
        }
    
        if (bipartite)
        {
            cout << "YES\n";
        }

        else cout << "NO\n";
    }

    return 0;
}