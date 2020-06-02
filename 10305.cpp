//Solution to UVa 10305: Ordering Tasks
#include<iostream>
#include<deque>
#include<vector>
#include<cstring>
using namespace std;
int visited[101];

//Produce a simple topological sort on the graph; guaranteed to be no back edges from the problem statement

void process(vector<vector<int> >& adj, deque<int>& toposort, int index)
{
    if (visited[index] == 2) return;

    visited[index] = 1;
    for (int i : adj[index])
    {
        if (visited[i] == 0) //no back edges means only possibilities are 0 or 2
        {
            process(adj, toposort, i);
        }
    }
    visited[index] = 2;
    toposort.push_front(index);
    return;
}

int main()
{
    
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, source, tail;
    while (cin >> n >> m, n | m)
    {
        memset(visited, 0, sizeof visited);
        vector<vector<int>> adj(n + 1);

        while (m--)
        {
            cin >> source >> tail;
            adj[source].push_back(tail);
        }

        deque<int>  toposort;

        for (int i = 1; i <= n; i++)
        {
            process(adj, toposort, i);
        }

        cout << toposort.front();
        for (deque<int>::iterator p = ++toposort.begin(); p < toposort.end(); p++)
        {
            cout << " " << *p;
        }
        cout << "\n";
    }
    return 0;
}