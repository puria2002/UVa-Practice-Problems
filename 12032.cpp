//Solution to UVa 12032: The Monkey and the Oiled Bamboo
#include<iostream>
#include<algorithm>
using namespace std;

bool can(int* ladder, int K, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (ladder[i + 1] - ladder[i] > K) return false;
        if (ladder[i + 1] - ladder[i] == K) K--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int TC, N, min, max, mid;
    cin >> TC;
    int ladder[100000];
    ladder[0] = 0;
    for (int i = 1; i <= TC; i++)
    {
        cin >> N;
        for (int i =1; i <= N; i++)
        {
            cin >> ladder[i];
        }

        //binary search over all possible K to see which is the smallest that returns true on can()
        min = ladder[1] - ladder[0];
        max = ladder[N] - ladder[0];
        //search over the range min--max
        while (mid = (max + min) / 2, max != min)
        {
            if(can(ladder, mid, N)) max = mid; //mid can climb the ladder
            else min = mid + 1; //mid can't climb the ladder
        }
        cout << "Case " << i << ": " << max << "\n";
    }

}