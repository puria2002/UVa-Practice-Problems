//Solution to UVa 10397: Connect the Campus

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
    int v1, v2;
    double w;

    bool operator<(const edge& e2) const
    {
        return w < e2.w;
    }
}edge;

int main()
{
    pair<int, int> buildings[750];

    int N, M;

    double cable;
    int x, y;
    edge e;
    while (cin >> N)
    {
        cable = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> buildings[i].first >> buildings[i].second;
        }

        vector<edge> edgelist;
         for (int i = 0; i < N - 1; i++)
         {
            for (int j = i + 1; j < N; j++)
            {
                e.w = sqrt((buildings[i].first - buildings[j].first) * (buildings[i].first - buildings[j].first)
                + (buildings[i].second - buildings[j].second) * (buildings[i].second - buildings[j].second));

                e.v1 = i;
                e.v2 = j;
                edgelist.push_back(e);
            }
         }
         cin >> M;
         UFDS cycles(N);
         while (M--)
         {
            cin >> x >> y;
            cycles.unionSet(x - 1, y - 1);
         }

         //run Kruskal's
         sort(edgelist.begin(), edgelist.end()); 
         for (edge edg: edgelist)
         {
            if (cycles.isSameSet(edg.v1, edg.v2)) continue;

            cycles.unionSet(edg.v1, edg.v2);
            cable += edg.w;

            if (cycles.numDisjointSets() == 1) break;
         }

         printf("%.2f\n", cable);
    }


}