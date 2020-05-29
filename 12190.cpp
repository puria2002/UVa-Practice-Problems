//Solution to UVa 12190: Electric Bill
#include<iostream>

using namespace std;

double consumption(int price)
{
    if (price <= 200) return price / 2.0;
    else if (price <= 29900) return (price - 200) / 3.0 + 100;
    else if (price <= 4979900) return (price - 29900) / 5.0 + 10000;
    else return (price - 4979900) / 7.0 + 1000000;
}

int price(int consumption)
{
    if (consumption <= 100) return 2 * consumption;
    else if (consumption <= 10000) return 200 + (consumption - 100) * 3;
    else if (consumption <= 1000000) return 29900 + (consumption - 10000) * 5;
    else return 4979900 + (consumption - 1000000) * 7;
}



//we try to guess the consumption via binary search
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, tot;
    while (cin >> A >> B, A | B)
    {
        tot = consumption(A);
        //now we go search 1 up to tot to see if we can find the appropriate consumption
        int low = 1;
        int high = tot;
        int mid;
        while ((mid = (high + low) / 2))
        {
            int p1 = price(mid);
            int p2 = B + p1;
            double cons2 = consumption(p2);
            if (cons2 + mid > tot) //this happens if mid is too big
            {
                high = mid;
            }
            else if (cons2 + mid < tot) //this happens if mid is too small
            {
                low = mid + 1;
            }
            else break;
           
        }
        cout << price(mid) << "\n";
    }
}