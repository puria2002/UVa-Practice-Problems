//solution to UVa 11136: Hoax or what
#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

//problem is made trivial by storing 
//data in a RB tree that allows for repeat elements

//aproximately O(klogk + N) where N is days and k is total bills (each of the N queries is O(1), k updates are O(logk))
//naive array data structure on the other hand would be O(Nk)
 

int main()
{
    int N;
    multiset<int> urn;
    int c, bill;
    unsigned long long payment; //bills are int's but payment could overflow

    while(scanf("%d", &N), N)
    {   payment = 0;
        urn.clear();
        while (N--)
        {
            scanf("%d", &c);
            while (c--)
            {
                scanf("%d", &bill);
                urn.insert(bill);
            }

            payment += *(--urn.end()) - *(urn.begin());
            urn.erase(urn.begin());
            urn.erase(--urn.end());
        }
        printf("%lld\n", payment);
    }
}
