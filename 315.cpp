//Solution to UVa 315: Network
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstring>
using namespace std;
int label[101]; //DFS position of each vertex
int reach[101];
int visited[101]; //0 for not visited, 1 for in queue, 2 for complete
int parent[101]; //DFS parent of each vertex 
int tot;
int pos;
//Do a DFS algo to find articulation points (Tarjan's)
void articulation(vector<vector<int> >& adj, int v)
{

    pos++; //everytime you call, pos gets updated

    reach[v] = pos;
    label[v] = pos; // highest v can reach up in the tree...

    visited[v] = 1;

    for (int j : adj[v])
    {
        if (parent[v] == j) continue;

        if (visited[j] == 0)
        {
            parent[j] = v;
            articulation(adj, j);
            reach[v] = min(reach[v], reach[j]);
        }

       if (visited[j] == 1) //i.e. taking a back edge..can only do this once so use label to min
        {
            reach[v] = min(reach[v], label[j]);
        }
        
 
    }

    visited[v] = 2;

    if (label[v] != 1)
    {
        for (int j : adj[v])
        {
            if (parent[v] == j) continue;

            if (parent[j] == v && label[v] <= reach[j]) //can't outreach so we have an articulation
            {
                tot++;
                break;
            }

        }
    }

    else 
    {
        int children = 0;

        for (int j : adj[v])
        {
            if (parent[j] == v) children++;
            if (children > 1) break;
        }

        if (children > 1) tot++;
    }





}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, v1, v2; 
    bool placed[101][101];
    while (cin >> N, N)
    {
        memset(parent, 0, sizeof parent);
        memset(visited, 0, sizeof visited);
        memset(placed, 0, sizeof placed);

        tot = 0;
        pos = 0;
        vector<vector<int> > adj (N + 1);
        cin.ignore();
        do
        {
            string line;
            getline(cin, line);
            istringstream iss(line);
            iss >> v1;
            while (iss >> v2)
            {
                if (!placed[v1][v2])
                {
                    adj[v1].push_back(v2);
                    adj[v2].push_back(v1); 
                    placed[v1][v2] = true;
                    placed[v2][v1] = true;
                }
            } 
        }
        while (v1);

        articulation(adj, 1); 
        cout << tot << "\n";

    }

    return 0;
}