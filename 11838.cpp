//Solution to UVa 11838: Come and Go
#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

stack<int> vertices;
int visited[2001];
int pos;
int reach[2001];
int label[2001];
bool valid;
void isSCC(vector<vector<int>>& adj, int v, int N)
{
    if (visited[v] == 2) return;

    reach[v] = ++pos;
    label[v] = pos;

    visited[v] = 1;
    vertices.push(v);
    for (int i : adj[v])
    {
        if (visited[i] == 0)
        {
            isSCC(adj, i, N);
        }

        if (visited[i] == 1) // on stack
        {
            reach[v] = min(reach[v], reach[i]);
        }
    }

    if (reach[v] == label[v])
    {
        int count = 0;
        while (1)
        {
            int top = vertices.top();
            visited[top] = 2;
            vertices.pop();
            count++;
            if (top == v) break;

        }
        if (count != N) valid = false;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, V, W, P;
    while (cin >> N >> M, N | M)
    {
        vector<vector<int>> adj (N + 1);
        valid = true;
        vertices.empty();
        memset(visited, 0, sizeof visited);

        pos = 0;

        while (M--)
        {
            cin >> V >> W >> P;
            adj[V].push_back(W);
            if (P == 2)
            {
                adj[W].push_back(V);
            }
        }

        for (int i = 1; i <= N && valid; i++)
        {
            isSCC(adj, i, N);
        }
        cout << valid << "\n";
    }

}