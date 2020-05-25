//solution to UVa 574: Sum It Up
#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include<unordered_map>
using namespace std;

//unfortunately a very ugly recursive backtracking solution is employed...
//still, the run time is 0.000s (despite list copying being time consuming)
list<string> printsums(int t, int n, int index, int* arr, int bitmask, int sum)
{
    list<string> r1;

    if (sum  > t) return r1; //prune
    if (sum == t)
    { 
        bool first = true;
        string s;
        for (int i = 0; i < n; i++)
        {
            if (bitmask & (1 << i))
            {
                if (first)
                {
                    s = to_string(arr[i]);
                    first = false;
                }
                else
                {
                    s += "+" +to_string(arr[i]);
                }
                
            }  
        }
        r1.emplace_back(s);
        return r1; 
    }
    if (index == n) return r1;
    r1 = printsums(t, n, index + 1, arr, bitmask, sum);
    //including
    bitmask |= (1 << index);
    list<string> r2 = printsums(t, n, index + 1, arr, bitmask, sum + arr[index]);
    r2.splice(r2.end(), r1);
    return r2;
}

int main()
{
    ios::sync_with_stdio(0);
    int t, n;
    int* arr;
    unordered_map<string, int> m1;
    while(cin >> t >> n, n)
    {
        m1.clear();
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout<< "Sums of "<<t<<":"<<endl;
        list<string> res = printsums(t, n, 0, arr, 0, 0);
        if (res.empty())
        {
            cout << "NONE" << endl;
        }
        else
        {
            for (string s: res)
            {
                if (m1.find(s) == m1.end())
                {
                    cout<< s << endl;
                    m1[s] = 1;
                }
            }
        }
        

        delete[] arr;
    }
}