//Solution to UVa 924: Spreading the News
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

//Simply model the situation as BFS.

int layer[2500]; //holds the day told




pair<int, int> search(int source, vector<vector<int>>& adj, char* visited)
{
    if (adj[source].size() == 0) return make_pair(0,0); //special logic for an "island"

    layer[source] = 0;
    queue<int> vertices;
    vertices.push(source);
    visited[source] = 1;
    int maxDay = 0;
    int maxNum = 0;

    int runningDay = 0;
    int runningNum = 0;

    //Begin the BFS

    while (!vertices.empty())
    {
        int top = vertices.front();
        vertices.pop();

        if (layer[top] == runningDay)
        {
            runningNum++;
        }

        else
        {
            if(runningNum > maxNum)
            {
                maxDay = runningDay;
                maxNum = runningNum;  
            }

            runningDay = layer[top];
            runningNum = 1;
        }
        
        for (int j : adj[top])
        {
            if (visited[j] == 0)
            {
                visited[j] = 1;
                layer[j] = layer[top] + 1;
                vertices.push(j);
            }
        }
        visited[top] = 2;
    }

    if (runningNum > maxNum)
    {
        maxDay = runningDay;
        maxNum = runningNum;
    }
    if (maxDay == 0) return make_pair(1, 1); //Boom max not allowed to be on day 0

    return make_pair(maxNum, maxDay);
}


int main()
{
    int E, T, N, entry;
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (cin >> E)    
    {
        vector<vector<int>> adj(E);
        char* visited = new char[E];
        for (int i = 0; i < E; i++)
        {
            cin >> N;
            while (N--)
            {
                cin >> entry;
                adj[i].push_back(entry);
            }
        }

        cin >> T;
        while (T--)
        {
            memset(visited, 0, E);
            cin >> entry;
            pair<int, int> res = search(entry, adj, visited);
            if (res.first == 0) cout << 0 << "\n";
            else cout << res.first << " " << res.second << "\n";
        }

        delete[] visited;
    }
}