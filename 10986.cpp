//Solution to UVa 10986: Sending email
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

unsigned int shortestPath(int S, int T, vector<vector<pair<int, int>>>& adj, int n)
{
    unsigned int* distances = new unsigned int[n];
    memset(distances, -1, n * sizeof(unsigned int));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances[S] = 0;

    for (pair<int, int>& edge : adj[S])
    {
        distances[edge.second] = edge.first;
        pq.push(edge);
    }

    while (pq.size())
    {
        pair<int, int> top = pq.top();
        pq.pop();

        if (top.first != distances[top.second]) continue; //lazy deletion

        if (top.second == T)
        {
            delete[] distances;
            return top.first;
        }

        for (pair<int,int>& edge : adj[top.second])
        {
            if (edge.first + top.first < distances[edge.second])
            {
                distances[edge.second] = edge.first + top.first;
                pq.push(make_pair(distances[edge.second], edge.second));
            }
        }


    }

    delete[] distances;
    return -1;
}

int main()
{
    int N, n, m, S, T, s1, s2, w;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> n >> m >> S >> T;
        vector<vector<pair<int, int>>> adj (n);
        while (m--)
        {
            cin >> s1 >> s2 >> w;
            adj[s1].push_back(make_pair(w, s2));
            adj[s2].push_back(make_pair(w, s1));
        }

        cout << "Case #"  << i << ": ";
        int res = shortestPath(S, T, adj, n);
        if (res == -1) cout << "unreachable\n";
        else cout << res << "\n";

    }
}