//Solution to UVa 10611: The Playboy Chimp
#include<iostream>
#include<algorithm>
using namespace std;

//simple binary search with built in C++ STL functions
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, Q, query, *arr, *lower, *upper;
    cin >> N;

    arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cin >> Q;

    while (Q--)
    {
        cin >> query;
        
        lower = lower_bound(arr, arr + N, query); //points to the first lady chimp with height equal or greater 
        if (lower == arr) cout << "X ";
        else cout << *(--lower) << " ";

        upper = upper_bound(arr, arr + N, query); //points to first lady chimp with greater height
        if (upper == arr + N) cout << "X\n";
        else cout << *upper << "\n";
    }

    delete[] arr;
    return 0;
}