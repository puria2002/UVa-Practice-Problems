//Solution to UVa 12442: Forwarding Emails
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int neighbor[50001];
int visited[50001];
int reach[50001];
int run[50001];

//simple DFS (on a special "linear" graph, so rather simple) with a manually implemented stack for cycle logic.
int getSize(int v)
{
    if (visited[v] == 2) return reach[v];
    stack<int> vertices;
    vertices.push(v);
    int running = 0;
    while (1)
    {
        visited[v] = 1;
        if (visited[neighbor[v]] == 2)
        {
            vertices.pop();
            visited[v] = 2;
            reach[v] = reach[neighbor[v]] + 1;
        }

        else if (visited[neighbor[v]] == 1) //i.e. neighbor[v] is on stack, causing a cycle / back edge
        {   
            //pop down to neighbor[v] and store the total!
            int start = neighbor[v];
            int cycle = ++running - run[start];
            
            while (vertices.top() != start)
            {
                reach[vertices.top()] = cycle;
                visited[vertices.top()] = 2;
                vertices.pop();
            }
            reach[start] = cycle;
            visited[start] = 2;
            vertices.pop();
        }

        else
        {
            run[v] = ++running;
            vertices.push(neighbor[v]);

        }
        if (!vertices.empty()) v = vertices.top();
        else break;
        
    }

    return reach[v];


}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, N, u, v;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> N;
        memset(visited, 0, sizeof visited);
        for (int j = 0; j < N; j++)
        {
            cin >> u >> v;
            neighbor[u] = v;
        }

        int res = 0;
        int m = 0;

        for (int j = 1; j <= N; j++)
        {
            if (getSize(j) > m)
            {
                m = getSize(j);
                res = j;
            }
        }
        cout << "Case " << i << ": " << res << "\n";
    }

    return 0;
}
