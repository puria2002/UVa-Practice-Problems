//Solution to UVa 111057: Exact Sum
#include<iostream>
#include<algorithm>
using namespace std;

//use binary search after sort for O(N log N) time complexity

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    int* prices, *midIndex, *secondIndex;
    while (cin >> N)
    {
        prices = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> prices[i];
        }

        cin >> M;
        sort(prices, prices + N);
        bool done = false;
        midIndex = lower_bound(prices, prices + N, (M + 1) / 2); //first slot that compares >= M / 2
        if (!(M & 1))
        {
            
            if (midIndex - prices < N - 1 && *(midIndex + 1) == M /2)
            {
                cout << "Peter should buy books whose prices are " << M / 2 << " and "<< M / 2<<".\n\n";
                done = true;
            }
        }
        while (!done)
        {
            secondIndex = lower_bound(prices, midIndex, M - *(midIndex));
            if (*secondIndex + *midIndex == M)
            {
                done = true;
                cout << "Peter should buy books whose prices are " << *secondIndex << " and "<< *midIndex<<".\n\n";
            }

            else
            {
                midIndex++;
            }
            
        }

        delete[] prices;
    }
}