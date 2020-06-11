//Solution to UVa 11634: Generate Random Numbers
#include<iostream>
using namespace std;

//we use floyd's, though a simple DAT would be faster at the cost of more memory
int cycLength(int seed)
{
    int tortoise = (seed * seed / 100) % 10000;
    int hare = (tortoise * tortoise / 100) % 10000;
    while (hare != tortoise)
    {
        tortoise = (tortoise * tortoise / 100) % 10000;
        hare = (hare * hare / 100) % 10000;
        hare = (hare * hare / 100) % 10000;
    }
    hare = seed;
    int len = 0;
    while (hare != tortoise)
    {
        hare = (hare * hare / 100) % 10000;
        tortoise = (tortoise * tortoise / 100) % 10000;

        len++;
    }
    tortoise = (hare * hare / 100) % 10000;
    len++;
    while (tortoise != hare)
    {
        tortoise = (tortoise * tortoise / 100) % 10000;
        len++;

    }

    return len;



}

int main()
{
    int seed;
    cin.tie(0);
    ios::sync_with_stdio(0);
    while (cin >> seed, seed)
    {
        cout << cycLength(seed) << "\n";
    }
}