//solution to UVa 10487: Closest Sums
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//Simple brute force solution with sorting to allow for quicker pruning of search branches
int main()
{
    ios::sync_with_stdio(0);
    int n, m, q, optimal, prev, curr;
    int c = 1;
    int* arr;
    while (cin >> n, n)
    {
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        } 
        sort(arr, arr + n);
        cin >> m;
        cout<< "Case " << c++ << ":"<< endl;
        while (m--)
        {
            cin >> q;
            optimal = arr[0] + arr[1];
            for (int i = 0; i < n - 1; i++)
            {
                prev = arr[i] + arr[i + 1]; 

                for (int j = i + 2; j < n; j++)
                {
                    curr = arr[i] + arr[j];
                    if (abs(curr - q) > abs(prev - q))
                    {
                        break;
                    }
                    else
                    {
                        prev = curr;
                    }
                }
                if (abs(prev - q) < abs(optimal - q)) optimal = prev;

            }
            cout <<"Closest sum to "<< q<< " is "<< optimal << "."<< endl;
        }
        delete[] arr;
    }
}