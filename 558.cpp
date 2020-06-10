//Solution to UVa 558: Wormholes
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define INF 20000000;

//simple Bellman Ford

bool isNegCycle(vector<vector<pair<int, int>>>& adj, int N)
{
    long long* distances = new long long[N];
    
    for (int i = 0; i < N; i++)
    {
        distances[i] = INF;
    }
    //basically relax every edge at least once..
    distances[0] = 0;

    for (int i = 0; i < N - 1; i++) 
    {
        for (int j = 0; j < N; j++)
            for (const pair<int,int>& edge : adj[j])
            {
                if (distances[edge.second] > edge.first + distances[j]) //relax the edge 
                {
                    distances[edge.second] = edge.first + distances[j];
                }
            }
    }

    for (int j = 0; j < N; j++)
    {
        for (const pair<int, int>& edge : adj[j])
        {
            if (distances[edge.second] > edge.first + distances[j])
            {
                delete[] distances;
                return true;
            } 
        }
    }

    delete[] distances;
    return false;

}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int c, x, y, t, n, m;
    cin >> c;
    while(c--)
    {
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        while (m--)
        {
            cin >> x >> y >> t;
            adj[x].push_back(make_pair(t, y));
        }

        bool res = isNegCycle(adj, n);
        if (res) cout << "possible\n";
        else cout << "not possible\n";

    }
}