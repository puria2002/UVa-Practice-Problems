//solution to UVa 12532: Interval Product
#include<iostream>
#include<vector>
using namespace std;


//simple problem if using an augmented segment tree data structure

int left(int n)
{
    return n << 1;
}

int right(int n)
{
    return ((n << 1) + 1);
}

class SegmentTree
{
    private:
        vector<char> st;
        vector<int>& arr;
        int n;
        void build(int p, int L, int R)
        {
            if (L == R)
            {
                if (arr[L] == 0) st[p] = 0;
                else if (arr[L] > 0) st[p] = 1;
                else st[p] = -1;
            }
            else
            {
                build(left(p), L, (L + R) / 2);
                build(right(p), (L + R) / 2 + 1, R);
                st[p] = st[left(p)] * st[right(p)];
            }
            
        }

        char query(int p, int L, int R, int i, int j)
        {
            if (L == i && R == j)
            {
                return st[p];
            }
            else if (i > (L + R) / 2)
            {
                return query(right(p), (L + R) / 2 + 1,  R, i , j); 
            }
            else if (j <= (L + R) / 2)
            {
                return query(left(p), L, (L + R) / 2, i, j);
            }
            else
            {
                char c1 = query(left(p), L, (L + R) / 2, i, (L + R) / 2);
                char c2 = query(right(p), (L + R) / 2 + 1,  R, (L + R) / 2 + 1 , j);
                return c1 * c2;
            }
        }

        char update(int index, int value, int p, int L, int R)
        {
            if (index < L || index > R) return st[p];
            else if (L == R && index == L)
            {
                if (value > 0) st[p] = 1;
                else if (value < 0) st[p] = -1;
                else st[p] = 0;
                return st[p];
            }
            else
            {
                st[p] = update(index, value, left(p), L, (L + R) / 2) * update(index, value, right(p), (L + R) / 2 + 1, R);
                return st[p];
            }
            

        }

        public:
            SegmentTree(vector<int>& a):
            arr(a), n(a.size())
            {
                st = vector<char> (4 * n);
                build(1, 0, n - 1);
            }

            char query(int i, int j)
            {
                return query(1, 0, n - 1, i, j);
            }

            void update(int index, int value)
            {
                update(index, value, 1, 0, n - 1);
                 
            }

};

int main()
{
    ios::sync_with_stdio(0);
    int N, K;
    char c;
    int i, k;
    vector<int> arr;
    while(cin >> N >> K)
    {
        arr.clear();
        arr = vector<int> (N);

        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }
        SegmentTree tree(arr);
        while (K--)
        {
            cin >> c;
            cin >> i;
            cin >> k;
            if (c == 'C')
            {
                tree.update(i - 1, k);
            }
            else
            {
                c = tree.query(i - 1, k - 1);
                if (c > 0) cout << "+";
                else if (c == 0) cout << "0";
                else cout<< "-";
            }
            
        }
        cout << endl;
    }
}