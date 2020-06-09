
//Solution to UVa 1112: Mice and Maze
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int success(int E, int T, vector<vector<pair<int , int>>>& adj, int N)
{
    priority_queue<pair<int, int >, vector<pair<int, int>>, greater<pair<int, int> >> pq;

    unsigned int* distances = new unsigned int[N + 1];
    memset(distances, -1, (N + 1) * sizeof(unsigned int));
    distances[E] = 0;
    for (pair<int, int> edge : adj[E])
    {
        distances[edge.second] = edge.first;
        pq.push(make_pair(edge.first, edge.second));
    }
    int count = 1; //there exists a mouse on the entry cell, therefore start counting at 1
    while (pq.size()) //while non empty queue
    {
        pair<int, int> top = pq.top();
        pq.pop();


        if (top.first > T) break; //exceeded the premissible time

        if (top.first != distances[top.second]) continue; //Lazy deletion

        count++;

        for (pair<int, int>& edge : adj[top.second])
        {
            if (top.first + edge.first < distances[edge.second])
            {
                distances[edge.second] = top.first + edge.first;
                pq.push(make_pair(distances[edge.second], edge.second));
            }
        }




    }

    delete[] distances;
    return count;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int TC, N, E, T, M;
    int source, dest, time;

    cin >> TC;
    bool first = true;
    while (TC--)
    {   
        if (first)
        {
            first = false;
        }
        else cout << "\n";
        cin >> N >> E >> T >> M;
        vector<vector<pair<int , int>>> adj (N + 1);
        while (M--)
        {
            cin >> dest >> source >> time;

            adj[source].push_back(make_pair(time, dest)); //reverse the edges for a faster algorithm
        }

        cout << success(E, T, adj, N) << "\n";


    }
}