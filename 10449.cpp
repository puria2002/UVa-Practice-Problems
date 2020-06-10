//Solution to UVa 10449: Traffic 
#include<iostream>
#include<vector>
using namespace std;

long long distances[200];

void bellmanFord(vector<int>& costs, vector<pair<int, int>>& edges, int n)
{
    distances[0] = 0;
    for (int i = 1; i < n; i++)
    {
        distances[i] = 2000000000;
    }

    for (int j = 1; j < n - 1; j++)
    {
        for (const pair<int, int>& edge: edges)
        {
            if (distances[edge.first] == 2000000000) continue;

            if (distances[edge.second] > distances[edge.first] + (costs[edge.second] - costs[edge.first]) * (costs[edge.second] - costs[edge.first]) * (costs[edge.second] - costs[edge.first]))
            {
                distances[edge.second] = distances[edge.first] + (costs[edge.second] - costs[edge.first]) * (costs[edge.second] - costs[edge.first]) * (costs[edge.second] - costs[edge.first]);
            }
        }
    }

    //check for negative weight cycles!
    for (const pair<int, int>& edge : edges)
    {   
        if (distances[edge.second] > distances[edge.first] + (costs[edge.second] - costs[edge.first]) * (costs[edge.second] - costs[edge.first]) * (costs[edge.second] - costs[edge.first]))
        {
            distances[edge.second] = -2000000000; //part of negative weight cycle...(thus ruining the city's economy!)
        }
    }

}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, r , q;
    int c = 0;
    int sour, des;
    while (cin >> n)
    {
        c++;
        vector<int> costs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> costs[i];
        }
        cin >> r;

        vector<pair<int, int>> edges(r);
        for (int i = 0; i < r; i++)
        {
            cin >> sour >> des;
            sour--;
            des--;
            edges[i].first = sour;
            edges[i].second = des;
        }
        cout << "Set #" << c << "\n";
        bellmanFord(costs, edges, n);
        cin >> q;
        while (q--)
        {
            cin >> des;
            des--;
            if (distances[des] < 3 || distances[des] == 2000000000) cout << "?\n";
            else cout << distances[des] << "\n";
        }

    }
}