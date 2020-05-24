//solution to UVa 927: Integer Sequences from Addition of Terms
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//fairly trivial arithmetic series question

long long eval(const vector<int>& arr, int d, int k)
{
    double n = (-1 + sqrt(1 + 8 * (float) k / d)) / 2; //huge potential for floating point errors here 
    int x = (int) ceil(n - 0.001);
    long long res = 0;
    int size = arr.size();
    for (int i = size - 1; i > 0; i--)
    {
        res = (res + arr[i]) * x; //efficient polynomial evaluation
    }
    res += arr[0];
    return res;
}

int main()
{
    int TC, deg, d, k;
    vector<int> arr;
    ios::sync_with_stdio(0);
    cin >> TC;
    while (TC--)
    {
        cin >> deg;
        deg++;
        arr = vector<int> (deg);
        for (int i = 0; i < deg; i++)
        {
            cin >> arr[i];
        }

        cin >> d >> k;
        cout<< eval(arr, d, k) << endl;

    }

}