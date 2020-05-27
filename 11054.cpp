//solution to UVa 11054: Wine Trading in Gergovia
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//simple greedy solution
long long minTravel(vector<pair<int, int>>& sellers, vector<pair<int,int>>& buyers)
{
    long long tot = 0;
    int j = 0;
    int i = 0;
    while(i < buyers.size() && j < sellers.size())
    {
        if (sellers[j].second * -1 > buyers[i].second)
        {
            tot += (buyers[i].second) * abs(buyers[i].first - sellers[j].first); //provide buyer with wine and move on
            sellers[j].second += buyers[i].second;
            i++;
        }
        else if (sellers[j].second * -1 == buyers[i].second)
        {
            tot += (buyers[i].second) * abs(buyers[i].first - sellers[j].first);
            j++; 
            i++;
        }
        else
        {
            tot += (-1 * sellers[j].second) * abs(buyers[i].first - sellers[j].first);
            buyers[i].second -= (-1 * sellers[j].second);
            j++;
        }
 
    }
    return tot;
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    vector<pair<int,int>> buyers, sellers;
    int N, in;
    long long res;
    while (cin >> N, N)
    {
        buyers.clear();
        sellers.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> in;
            if (in < 0) sellers.push_back(make_pair(i, in));
            else if (in > 0) buyers.push_back(make_pair(i, in));
        }

        res = minTravel(sellers, buyers);
        cout << res << "\n";
    }
}