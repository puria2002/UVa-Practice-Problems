//solution to Uva 11503: Virtual Friends
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

//trivial with a UFDS + hashing
//use a modified UFDS with a hashtable of string keys

class UFDS {
private:
	unordered_map<string, string> p;
    unordered_map<string,int> rank;
    unordered_map<string, int> setSizes;
	int numSets;

public:
	UFDS():
    p(), rank(), setSizes(), numSets(0)
    {
		
	}
    bool isPresent(string s)
    {
        return (p.find(s) != p.end());
    }
    void insert(string s)
    {
        rank[s] = 0;   
        p[s] = s;
        setSizes[s] = 1;
        numSets++;
    }

	string findSet(string i) {
		return (i.compare(p[i]) == 0) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(string i, string j) {
		return findSet(i).compare(findSet(j)) == 0;
	}
	void unionSet(string i, string j) {
		if (!isSameSet(i, j)) {
			string x = findSet(i), y = findSet(j);
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
	int setSize(string i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};

int main()
{
    int TC, F;
    ios::sync_with_stdio(0);
    cin >> TC;
    string friend1;
    string friend2;
    UFDS network;
    while (TC--)
    {
        network = UFDS();
        cin >> F;
        while (F--)
        {
            cin >> friend1 >> friend2;
            if (!network.isPresent(friend1)) network.insert(friend1);
            if (!network.isPresent(friend2)) network.insert(friend2);
            network.unionSet(friend1, friend2);
            cout << network.setSize(friend1) << endl;
        }
    }

}