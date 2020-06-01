#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visited[20][20]; //let it be 0 by default, -1 if water, 1 if in DFS, 2 if complete

//Union Find Data Structure to monitor connected components
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
bool isValid(int i, int M)
{
    if (i >= M || i < 0) return false;

    return true;
}
int connectionSize(int i, int j, UFDS& connections, int M, int N)
{
    if (visited[i][j] == 2)
    {
        int index = N * i + j;
        return connections.setSize(index);
    }

    if (visited[i][j] == -1) return 0;
    
    else
    {
        //now we must implement a DFS...
        visited[i][j] = 1;
        int index = N * i + j;
        int dr[] = {1,0,-1, 0}; 
        int dc[] = {0, 1, 0,-1};

        for (int d = 0; d < 4; d++) 
        {
            if (isValid(i + dr[d], M))//start by checking if valid square row wise
            { 
                int col = j + dc[d];
                if (col == N) col = 0;
                else if (col == -1) col = N - 1; //for "taping" together ends of map

                if (visited[i + dr[d]][col] == 0)
                {
                    connectionSize(i + dr[d], col, connections, M , N);
                    connections.unionSet(index, N * (i + dr[d]) + col);
                }

                else if (visited[i + dr[d]][col] == 2) 
                {
                    connections.unionSet(index, N * (i + dr[d]) + col);
                }
            }
        }

        visited[i][j] = 2;
        return connections.setSize(index);
    }
    

}

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, X, Y;
    char c, c2;
    while (cin >> M >> N)
    {
        cin >> c; //first char
        visited[0][0] = -1;
        for (int j = 1; j < N; j++)
        {
            cin >> c2;
            if (c2 == c) visited[0][j] = -1; //first input by default assumed water
            else visited[0][j] = 0;
        }

        for (int i = 1; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> c2;
                if (c2 == c) visited[i][j] = -1; //first input by default assumed water
                else visited[i][j] = 0;
            }
        }

        cin >> X >> Y;

        if (visited[X][Y] == -1) //if our assumption falls through!
        {
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    visited[i][j] = (visited[i][j] == -1) ? 0 : -1;
                }
            }
        }

        UFDS connections(M * N);
        connectionSize(X, Y, connections, M, N);
        int m = 0;

        for (int i = 0; i < M; i ++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!connections.isSameSet(N * i + j, N * X + Y))
                {
                    m = max(connectionSize(i, j, connections, M, N), m);
                }
            }
        }
        cout << m << "\n";
    }
}