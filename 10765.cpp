//Solution to UVa 10765: Doves and Bombs
#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

char visited[10000]; //0 if not visited, 1 if in DFS, 2 if completed DFS
int parent[10000]; //DFS parent
int label[10000]; //DFS position
int reach[10000]; //farthest vertex reachable 
int pos; //current DFS position

typedef struct target
{
    int pigeon;
    int vertex;

    target(int p, int v):
    pigeon(p), vertex(v)
    {

    }

    bool operator>(const target& tar) const
    {
        if (pigeon > tar.pigeon) return true;

        if (pigeon < tar.pigeon) return false;

        return (vertex < tar.vertex);
    }

}target;

//Run Tarjan's to find articulation points...
void articulation(const vector<vector<int>>& adj, set<target, greater<target>>& targets, int m, int v)
{
    if (visited[v] == 2) 
    {
        pos = -1;
        return;
    }

    pos++;
    label[v] = pos;
    reach[v] = pos;

    visited[v] = 1;

    for (int i : adj[v])
    {
        if (parent[v] == i) continue;

        if (visited[i] == 0)
        {
            parent[i] = v;
            articulation(adj, targets, m, i);
            reach[v] = min(reach[v], reach[i]);

        }
        else //taking a back edge 
        {
            reach[v] = min(reach[v], label[i]);
        }
        
    }

    visited[v] = 2;
    int pigeons = 0;

    if (label[v] == 0) //something wrong with this case...
    {
        for (int i : adj[v])
        {
            if (parent[i] == v) pigeons++;
        }
    }

    else
    {
        for (int i : adj[v])
        {
            if (parent[i] == v && reach[i] >= label[v])
            {
                pigeons++;
            }
        }
        pigeons++;
    }
    
    target tar(pigeons, v);
    if (targets.size() < m)
    {
        targets.insert(tar);
    }

    else
    {
        if (tar > *(--targets.end()))
        {
            targets.erase(--targets.end());
            targets.insert(tar);
        }
    }
    
    
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, s1, s2;

    while (cin >> n >> m, n | m)
    {
        memset(visited, 0, sizeof visited);
        memset(parent, -1, sizeof parent);
        pos = -1;
        vector<vector<int>> adj (n);

        while (cin >> s1 >> s2, s1 != -1)
        {
            adj[s1].push_back(s2);
            adj[s2].push_back(s1); 
        }

        set<target, greater<target> > targets; //an inorder traversal of this will produce output
        for (int i = 0; i < n; i++)
        {
            articulation(adj, targets, m, i);
        }

        for (target t: targets)
        {
            cout << t.vertex << " " << t.pigeon << "\n";
        }

        cout << "\n";
    }
}