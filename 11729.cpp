//solution to UVa 11729: Commando War
#include<iostream> 
#include<algorithm>
using namespace std;
//quick and easy greedy solution
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, B, J;
    pair<int, int>* soldiers;
    pair<int, int> soldier;
    int c = 0;
    while (cin >> N, N)
    {
        soldiers = new pair<int, int>[N];
        for (int i = 0; i < N; i++)
        {
            cin >> B >> J;
            soldier = make_pair(J, B);
            soldiers[i] = soldier;

        }
        //sort in decreasing order based on job time
        sort(soldiers, soldiers + N, greater<pair<int, int>>());
        int time = 0;
        int m = 0;
        for (int i = 0; i < N; i++)
        {
            time += soldiers[i].second;
            m = max(m, soldiers[i].first + time);
        }
        cout << "Case "<< ++c <<": "<<m<<"\n";
        delete[] soldiers;
    }
}