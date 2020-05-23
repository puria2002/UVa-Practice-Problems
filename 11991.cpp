//solution to Uva 11991: An Easy Problem from Rujia Liu?
#include<stdio.h>
#include<vector>
using namespace std;

//best data structure to use is unusual:
//use a graph represented as an adjacency list
//pretty cut and dry otherwise!

int main()
{
    vector<int>* adj = new vector<int> [1000000];
    int N, TC, entry, rank;
    while (scanf(("%d %d"), &N, &TC) != EOF)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &entry); 
            (adj[entry - 1]).push_back(i + 1);
        }

        while (TC--)
        {
            scanf("%d %d", &rank, &entry);
            if (rank > adj[entry - 1].size()) printf("0\n");
            else printf("%d\n", adj[entry - 1][rank - 1]);
        }
        for (int i = 0; i < 1000000; i++)
        {
            adj[i].clear();
        }
    }
    delete[] adj;
    adj = nullptr;
    return 0;
}