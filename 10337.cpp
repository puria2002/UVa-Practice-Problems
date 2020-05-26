//solution to UVa 10337: Flight Planner
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<unsigned long long, unsigned int> memo;


//simple top down DP is possible!
unsigned int minFuel(int pos, int alt, int* arr, int X)
{
    //disqualify all impossible flight locations
    if (alt > pos) return 1 << 31;
    //base case of recursion 
    if (pos == 0 && alt == 0) return 0;

    unsigned long long index = pos;
    index <<= 32;
    index += alt;

    if (memo.find(index) != memo.end()) return memo[index];

    unsigned int inc, same, dec;

    same = minFuel(pos - 1, alt, arr, X) + 30 - arr[(X / 100) * alt + pos - 1]; 

    if (alt + 1 == 10)
    {
        dec = 1 << 31; //impossible
    }
    else
    {
        dec = minFuel(pos - 1, alt + 1, arr, X) + 20 - arr[(X / 100) * (alt + 1) + pos - 1]; 
    }

    if (alt - 1 == -1)
    {
        inc = 1 << 31; //impossible 
    }
    else
    {
        inc = minFuel(pos - 1, alt - 1, arr, X) + 60 - arr[(X / 100)* (alt - 1) + pos - 1]; 
    }
    memo[index] = min(same, min(dec, inc)); 
    return memo[index];
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N, X;
    cin >> N;
    int* arr;
    while (N--)
    {
        memo.clear(); 
        cin >> X;
        arr = new int[10 * (X / 100)]; //(i, j) becomes (10 * i + j) for row, col
        for (int i = 9; i >=0; i--)
        {
            for (int j = 0; j < X / 100; j++)
            {
                cin >> arr[(X / 100) * i + j];
            }
        }
        cout << minFuel(X / 100, 0, arr, X) << "\n\n";

        delete[] arr;
        arr = nullptr;
    }
}