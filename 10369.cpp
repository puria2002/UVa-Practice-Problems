//Solution to UVa 10369: Arctic Network
#include<iostream> 
#include<vector>
#include<algorithm>
#include<cmath> 
#include<cstdio>
using namespace std;

pair<int, int> post[500];
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
    int v1, v2;
    double w;

    bool operator<(const  edge& e2) const
    {
        return w < e2.w;
    }
}edge;

int main()
{
    int N, S, P;
    cin >> N;
    edge e;
    while (N--)
    {
        cin >> S >> P;
        UFDS cycles(P);
        for (int i = 0; i < P; i++)
        {
            cin >> post[i].first >> post[i].second;
        }
        vector<edge> edgelist;
        for (int i = 0; i < P - 1; i++)
        {
            for (int j = i + 1; j < P; j++)
            {
                e.w = sqrt((post[i].first-post[j].first) * (post[i].first-post[j].first)
                + (post[i].second-post[j].second) * (post[i].second-post[j].second));
                e.v1 = i;
                e.v2 = j;
                edgelist.push_back(e);

            }
        }
        sort(edgelist.begin(), edgelist.end());
        for (edge edg: edgelist)
        {
            if (cycles.isSameSet(edg.v1, edg.v2)) continue;

            cycles.unionSet(edg.v1, edg.v2);
            if (cycles.numDisjointSets() == S)
            {
                printf("%.2f\n", edg.w);
                break;
            }
        }
    }
}