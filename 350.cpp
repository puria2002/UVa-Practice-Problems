//Solution to UVa 350: Pseudo-Random Numbers
#include<iostream>
using namespace std;

//Simple tortoise and hare
int cycLength(unsigned long long Z, unsigned long long I, unsigned long long M, unsigned long long L)
{
    unsigned long long tortoise = L;
    unsigned long long hare = L;
    do
    {
        tortoise *= Z;
        tortoise %= M;
        tortoise += I;
        tortoise %= M;

        hare *= Z;
        hare %= M;
        hare += I;
        hare %= M;

        hare *= Z;
        hare %= M;
        hare += I;
        hare %= M;

    }while (tortoise != hare);

    hare = L;
    while (hare != tortoise)
    {
        hare *= Z;
        hare %= M;
        hare += I;
        hare %= M;

        tortoise *= Z;
        tortoise %= M;
        tortoise += I;
        tortoise %= M;

    }
    //now hare is at position u 
    tortoise = Z * hare;
    tortoise %= M;
    tortoise += I;
    tortoise %= M; 

    int length = 1;
    while (tortoise != hare)
    {
        tortoise *= Z;
        tortoise %= M;
        tortoise += I;
        tortoise %= M;
        length++;
    }
    return length;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    unsigned long long Z, I, M, L;
    int c = 0;
    while (cin >> Z >> I >> M >> L, Z | I | M | L)
    {
        Z %= M;
        I %= M;
    
        cout << "Case " << ++c << ": " << cycLength(Z, I, M, L) << "\n";

    }
    
}