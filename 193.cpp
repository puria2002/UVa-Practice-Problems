//Solution to UVa 193: Graph Coloring 
#include<iostream>
#include<vector>
#include<bitset>
using namespace std;


//recursive backtracking for max black colors
pair<bitset<100>, int> bestColoration(vector<vector<int>>& adj, int N, int v, bitset<100> colors, int sum)
{
    if (v == N) return make_pair(colors, sum); //end of recursion tree

    pair<bitset<100>, int> r1, r2;
    bool valid = true;
    //if coloring white 
    r1 = bestColoration(adj, N,  v + 1, colors, sum);
    //if coloring black

    //check for validity
 
    for (int i : adj[v])
    {
        valid = valid && (!colors[i]);
        if (!valid) break;
    }

    if (valid)
    {
        colors[v] = 1;  
        r2 = bestColoration(adj, N,  v + 1, colors, sum + 1);
        if (r1.second > r2.second) return r1;
        else return r2;
    }

    else
    {
        return r1; //prune
    }

}

int main()
{
    ios::sync_with_stdio(0);
    int TC, n, k;
    int i,j;
    vector<vector<int>> adj;
    bitset<100> colors;
    cin >> TC;
    while (TC--)
    {
        cin >> n >> k;
        adj = vector<vector<int>> (n); 
        colors = bitset<100>();
        while (k--)
        {
            cin >> i >> j;
            (adj[i - 1]).push_back(j - 1);
            (adj[j - 1]).push_back(i - 1);
        }

        pair<bitset<100>, int> res = bestColoration(adj, n, 0, colors, 0);
        cout<< res.second << endl;
        bool first = true;
        for (int i = 0; i < n; i++)
        {
            if ((res.first)[i])
            {
                if (first) 
                {
                    cout<< i + 1;
                    first = false;
                }
                else
                cout<< " " << i+1; 
            }
        }
        cout<<endl;
        
    }
 
}