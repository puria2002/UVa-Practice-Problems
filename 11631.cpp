//Solution to UVa 11631: Dark roads

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

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

typedef struct edge
{
    int x, y, z;

    bool operator<(const edge& e2) const
    {
        return (z < e2.z);
    }

} edge;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n , m;
    int tot, expenditure; 
    while (cin >> m >> n, n | m)
    {
        //m is the number of junctions, n is roads
        UFDS cycles(m);
        vector<edge> edgelist(n);
        edge e;
        tot = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> e.x >> e.y >> e.z;
            edgelist[i] = e;
            tot += e.z;
        }

        sort(edgelist.begin(), edgelist.end());
        //Use Kruskal's
        expenditure = 0;
        for (edge e: edgelist)
        {
            if (cycles.isSameSet(e.x, e.y)) continue;

            cycles.unionSet(e.x, e.y);
            expenditure += e.z;

            if (cycles.numDisjointSets() == 1) break;
        }

        cout << tot - expenditure << "\n";
    }
}