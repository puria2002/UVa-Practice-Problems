//solution to UVa 624: CD
#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;

//input size is small enough to use recursive backtracking instead of dynamic programming
//K will be the total number of people
pair<bitset<20>, int> best(int c, int N, bitset<20> set, int sum, int* tracks, int K)
{
    if (sum > N) return make_pair(set, -1);
    if (c == K) return make_pair(set, sum);
    //start with the c = 0 logic: 
    pair<bitset<20>, int> r1;
    pair<bitset<20>, int> r2;
    r1 = best(c + 1, N, set, sum, tracks, K);
    set[c] = 1;
    r2 = best(c + 1, N, set, sum + tracks[c], tracks, K);
    if (r1.second > r2.second) return r1;
    return r2;

}

int main()
{
    ios::sync_with_stdio(0);
    int N, k;
    int* tracks;
    bitset<20> set;
    pair<bitset<20>, int> res;
    while (cin >> N >> k)
    {
        set.reset();
        tracks = new int[k];
        for (int i = 0; i < k; i++)
        {
            cin >> tracks[i];
        }

        res = best(0, N,set , 0, tracks, k); 
        for (int i = 0; i < k; i++)
        {
            if ((res.first)[i]) cout << tracks[i]<< " ";
        }
        cout << "sum:" << res.second<< endl;
        delete[] tracks;
    }
} 