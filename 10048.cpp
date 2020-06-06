//Solution to UVa 10048: Audiophobia 
#include<iostream> 
#include<vector>
#include<algorithm> 
#include<cstring>
using namespace std;

char visited[100];


//classic minMax problem
//General method is: make the "pseudo" MST
//The path in the MST contains the minMax
//easiset way to find the path is to implement a DFS
//on the MST

class UFDS {
private:
	vector<int> p, rank, setSizes;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
			} else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
			numSets--;
		}
	}
	int setSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};

typedef struct edge{

    int v1, v2, w;

    bool operator<(const edge& e2) const{
        return w < e2.w;

    }
}edge;

int DFS(int c1, int c2, const vector<vector<pair<int, int>>>& adj, int m)
{
    //basically start at c1 and do a DFS till we reach c2...
    //return the max along this path, stored in m

    if (c1 == c2) return m;

    visited[c1] = 1;
    int res = -(1 << 31);
    for (pair<int, int> edg: adj[c1])
    {
        if (visited[edg.second] == 0)
        {
            res = max(DFS(edg.second, c2, adj, max(m, edg.first)), res);
        }

    }
    visited[c1] = 2;
    return res;
}

int main()
{   
    cin.tie(0);
    ios::sync_with_stdio(0);

    int C, S, Q;
    edge e;
    int c = 0;
    int c1, c2;
    bool first = true;

    while (cin >> C >> S >> Q, C | S | Q)
    {
        if (first)
        {
            first = false;
        }
        
        else cout << "\n";

        vector<edge> edgelist(S);

        for (int i = 0; i < S; i++)
        {
            cin >> e.v1  >> e.v2 >> e.w;
            e.v1--; //transform to 0 based indexing
            e.v2--;
            edgelist[i] = e;
        }
        sort(edgelist.begin(), edgelist.end());

        UFDS cycles (C);
        vector<vector<pair<int, int>>> adj (C);

        for (edge edg : edgelist)
        {
            if (cycles.isSameSet(edg.v1, edg.v2))
            {
                continue;
            }

            cycles.unionSet(edg.v1, edg.v2);
            adj[edg.v1].push_back(make_pair(edg.w, edg.v2));
            adj[edg.v2].push_back(make_pair(edg.w, edg.v1));

            if (cycles.numDisjointSets() == 1) break;
        }

        //adj now has a pesudo MST
        cout << "Case #" << ++c << "\n";

        while (Q--)
        {
            cin >> c1 >> c2;
            c1--;
            c2--;
            if (cycles.isSameSet(c1, c2))
            {
                memset(visited, 0, sizeof visited);
                cout << DFS(c1, c2, adj, 0) << "\n";
            }
            else cout << "no path\n";
        }

    }
}