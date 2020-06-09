//Solution to UVa 10801: Lift Hopping
#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<cstring>
#include<cmath>
using namespace std;
unsigned int distances[100][5];

typedef struct dij
{
    int t, fl, el;

    bool operator>(const dij& e2) const
    {
        return t > e2.t;
    }
}dij;

unsigned int shortestPath(int k, vector<vector<int>>& elevators, vector<vector<int>>& floors, int* T)
{
    //trying to find the shortest path the any vertex on the kth floor

    memset(distances, -1, sizeof distances);

    priority_queue<dij, vector<dij>, greater<dij>> pq;
    dij e;

    for (int i : elevators[0])
    {
        e.t = 0;
        e.el = i;
        e.fl = 0;
        pq.push(e);
        distances[0][i] = 0;
    }

    while(pq.size())
    {
        dij top = pq.top();
        pq.pop();
        if (top.t != distances[top.fl][top.el]) continue; //Lazy deletiob
        if (top.fl == k) return top.t; 
        
        //now we make traverse our graph
        for (int elev : elevators[top.fl]) //switiching elevators logic
        {
            if (top.t + 60 < distances[top.fl][elev])
            {
                distances[top.fl][elev] = top.t + 60;
                e.t = distances[top.fl][elev];
                e.fl = top.fl;
                e.el = elev;
                pq.push(e);
            }
        }

        for (int floor : floors[top.el])//continue w/ same elevator
        {
            if (top.t + T[top.el] * abs(floor - top.fl) < distances[floor][top.el])
            {
                distances[floor][top.el] = top.t + T[top.el] * abs(floor - top.fl);
                e.t = distances[floor][top.el];
                e.fl = floor;
                e.el = top.el;
                pq.push(e);
            }
        }

    }

    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k, T[5], floor;
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++) cin >> T[i];
        vector<vector<int>> floors(n); //floors accessible by elevator
        vector<vector<int>> elevators(100); //elevators accesible by floor

        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            istringstream iss(line);
            while (iss >> floor)
            {
                floors[i].push_back(floor);
                elevators[floor].push_back(i);
            }
        }

        unsigned int res = shortestPath(k, elevators, floors, T);
        if (res == -1) cout << "IMPOSSIBLE\n";
        else cout << res << "\n";
    }
}