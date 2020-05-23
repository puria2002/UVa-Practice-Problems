//solution to Uva 599: The Forrest for the Trees
#include<iostream>
#include<bitset>
#include<string>
using namespace std;
int main()
{
    bitset<26> connected;
    int N;
    char c;
    string s;
    ios::sync_with_stdio(0);
    cin >> N;
    int edges;
    int acorns;
    int vertices;
    while (N--)
    {
        connected.reset();
        edges = 0;
        vertices = 0;
        acorns = 0;
        while (cin >> s, s[0] != '*')
        {
            connected[s[1] - 65] = true;
            connected[s[3] - 65] = true;
            edges++;

        }
        cin >> s;
        vertices = s.length() / 2 + 1;

        for (int i = 0; i < s.length(); i += 2)
        {
            if(!connected[s[i] - 65]) acorns++;
        }

        cout << "There are "<< vertices - edges - acorns<< " tree(s) and "<< acorns<< " acorn(s).\n";
    }


}