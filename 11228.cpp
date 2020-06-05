//Solution to UVa 11228: Transportation System
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

//pretty typical MST with Kruskal's.
//Note that constructing the graph takes some time
//overall algo runs in O(n^2logn)
typedef struct edge
{
    double weight;
    int v1;
    int v2;

    bool operator<(const edge& e2) const
    {
        return (weight < e2.weight);
    }

}edge;

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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, r;
    cin >> T;
    pair<int, int> cities[1000];
    
    double roads, railways;
    for (int i = 1; i <= T; i++)
    {
        cin >> n >> r;
        roads = 0;
        railways = 0;
        
        for (int j = 0; j < n; j++)
        {
            cin >> cities[j].first >> cities[j].second; //cities impliclty labeled now
        }

        vector<edge> edgelist ((n * (n - 1)) / 2);
        int c = 0;
        edge e;

        UFDS states(n); 
        UFDS cycles(n);
        //process the raw input
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {   
                e.weight = sqrt((cities[k].second - cities[j].second) * (cities[k].second - cities[j].second) +
                (cities[k].first - cities[j].first) * (cities[k].first - cities[j].first));

                e.v1 = j;
                e.v2 = k;

                edgelist[c++] = e;

                if (e.weight <= r) states.unionSet(j , k);

            }
        }

        //now we have all we need to process via Kruskal's!
        sort(edgelist.begin(), edgelist.end());


        for (edge edg : edgelist)
        {
            if (!cycles.isSameSet(edg.v1, edg.v2))
            {
                cycles.unionSet(edg.v1, edg.v2);

                if (states.isSameSet(edg.v1, edg.v2))
                {
                    roads += edg.weight;
                }
                else railways += edg.weight;
            }
            
            if (cycles.numDisjointSets() == 1) break;
        }
        cout << "Case #" << i << ": " << states.numDisjointSets() << " " << round(roads) << " " << round(railways) << "\n";
    }
}