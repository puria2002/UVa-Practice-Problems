//Solution to UVa 11280: Flying to Fredericton
#include<iostream>
#include<vector> 
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<string, int> cities;

long long INF = 2000000000;

vector<long long> bellmanFord(vector<vector<pair<int, int> > >& adj)
{
    int N = adj.size();
    vector<long long> distance1(N);
    vector<long long> distance2(N);

    vector<long long>* distances = &distance1;
    vector<long long>* oldDistances = &distance2;

    vector<long long>* temp;

    vector<long long> res(N);

    res[0] = INF; //unreachable

    for (int i = 1; i < N; i++)
    {
        (*distances)[i] = INF;
        (*oldDistances)[i] = INF;
    }

    (*distances)[0] = 0;
    (*oldDistances)[0] = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((*oldDistances)[j] == INF) continue;

            for (const pair<int, int>& edge : adj[j])
            {
                if ((*distances)[edge.second] > (*oldDistances)[j] + edge.first)//relax the edge
                {
                    (*distances)[edge.second] = (*oldDistances)[j] + edge.first; 
                }
            }
        }
        res[i] = (*distances)[N - 1];
        temp = oldDistances;
        oldDistances = distances;
        distances = temp;
        copy(oldDistances->begin(), oldDistances->end(), distances->begin());
    }
    return res;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC, M, N, cost, Q, stop;
    cin >> TC;
    string name, source, dest;
    for (int i = 1; i <= TC; i++)
    {
        if (i != 1) cout << "\n";
        cin >> N;
        cities.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> name;
            cities[name] = i;
        }

        cin >> M;
        vector<vector<pair<int, int> > > adj (N);

        while (M--)
        {
            cin >> source >> dest >> cost;

            adj[cities[source]].push_back(make_pair(cost, cities[dest]));
        }

        cin >> Q;
        vector<long long> res = bellmanFord(adj);
        cout << "Scenario #" << i << "\n";
        while (Q--)
        {
            cin >> stop;
            if (stop > N - 2) stop = N - 2;

            if (res[stop + 1] == INF) cout << "No satisfactory flights\n";
            else cout << "Total cost of flight(s) is $" << res[stop + 1] << "\n";
        }

    }
    
}