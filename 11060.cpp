//solution to UVa 11060: Beverages
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<cstring>
using namespace std;

unordered_map<string, int> label; //strings to vertices
int degree[101]; //degree of each vertex
set<pair<int , int> > degTree; //a quick way to implement an updatadable priority queue for sorting
deque<int> toposort; //holds the valid topological sort
string names[101]; //maps vertex to input string name

//relatively involved implementation of a BFS topological sort to fulfill the input ordering criterion

void BFStoposort(vector< vector<int> >& adj)
{
    while (!degTree.empty())
    {
        pair<int, int> start = *(degTree.begin());
        degTree.erase(degTree.begin());
        toposort.push_back(start.second);
        for (int i : adj[start.second])
        {
            auto pos = degTree.find(make_pair(degree[i], i));
            (degree[i])--;
            degTree.erase(pos);
            degTree.insert(make_pair(degree[i], i)); //update with new degree
        }
        
    }
}


int main()
{
    cin.tie();
    ios::sync_with_stdio(0);
    int N, M;
    string name;
    int c = 0;
    while (cin >> N)
    {
        c++;
        vector< vector < int > > adj (N + 1);
        label.clear();
        degTree.clear();
        toposort.clear();
        memset(degree, 0, sizeof degree);

        for (int i = 1; i <= N; i++)
        {
            cin >> name;
            label[name] = i;
            names[i] = name;
        }

        cin >> M;
        string name1, name2;
        while (M--)
        {
            cin >> name1 >> name2;
            adj[label[name1]].push_back(label[name2]);
        } //initalize the graph properly

        for (int i = 1; i <= N; i++)
        {
            for (int j: adj[i])
            {
                degree[j]++;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            degTree.insert(make_pair(degree[i], i));
        }

        BFStoposort(adj);
        cout << "Case #" << c << ": Dilbert should drink beverages in this order:";
        for (int i : toposort)
        {
            cout << " " << names[i];
        }
        cout << ".\n\n";


    }
    return 0;
}