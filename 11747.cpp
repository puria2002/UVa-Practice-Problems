//Solution to UVa 11747: Heavy Cycle Edges
#include<iostream>
#include<list>
#include<vector>
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

typedef struct edge{

    int v1;
    int v2;
    int w;

    bool operator<(const edge& e2) const
    {
        return (w < e2.w);
    }

}edge;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    edge e;
    while (cin >> n >> m, n | m)
    {
        UFDS cycles(n);
        list<edge> edgelist;

        while (m--)
        {
            cin >> e.v1 >> e.v2 >> e.w;
            edgelist.emplace_back(e);
        }

        edgelist.sort();

        auto p = edgelist.begin();
        
        while (1)
        {
            if (p == edgelist.end()) break; //end of edgelist

            if (cycles.isSameSet(p->v1, p->v2))
            {
                p++;
                continue;
            }

            cycles.unionSet(p->v1, p->v2);
            edgelist.erase(p++);

            if (cycles.numDisjointSets() == 1) break; //completed MST
            
        }

        if (edgelist.size() == 0)
        {
            cout << "forest";
        }
        else
        {
            bool first = true;
            for (edge e: edgelist)
            {
                if (first)
                {
                    cout << e.w;
                    first = false;
                }
                else cout << " " << e.w;
            }
        }
        cout << "\n";
        
    }

    
}