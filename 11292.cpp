//solution to UVa 11292: Dragon of Loowater
#include<iostream>
#include<algorithm>
using namespace std;
int minCost(int* dragon, int* knights, int n, int m)
{
    int cost = 0;
    int running = 0;
    for (int i = 0; i < n ; i++)
    {
        while (knights[running] < dragon[i] && running < m)
        {
            running++;
        }
        if (running == m) return -1;
        else cost += knights[running];
        running++;
    }
    return cost;

} 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    int* dragon, *knights;
    while (cin >> n >> m, n | m)
    {
        dragon = new int[n];
        knights = new int[m];
        for(int i = 0; i < n; i++)
        {
            cin >> dragon[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> knights[i];
        }
        sort(dragon, dragon + n);
        sort(knights, knights + m);
        int res = minCost(dragon, knights, n, m);
        if (res == -1) cout << "Loowater is doomed!\n";
        else cout << res << "\n";

        delete[] dragon;
        delete[] knights;
        
    }

}