//solution to UVa 10026: Shoemaker's Problem
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct job
{
    int N;
    int days;
    int fine;
    bool operator<(const job j2) const
    {
        if ((double) days / fine < (double) j2.days / j2.fine) return true;

        else if ((double) days / fine == (double) j2.days / j2.fine) return 
        (N < j2.N);

        else return false;
    }
}job;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    job jobs[1000];
    int TC, N;
    cin >> TC;
    while (TC--)
    {
        cin >> N;
        for (int i = 0 ; i < N; i++)
        {
            cin >> jobs[i].days >> jobs[i].fine;
            jobs[i].N = i + 1;
        }
        sort(jobs, jobs + N, less<job>());
        cout << jobs[0].N;
        for (int i = 1; i < N; i++)
        {
            cout << " " << jobs[i].N;
        }
        cout << "\n";
        if (TC) cout << "\n";
        
    }
}
