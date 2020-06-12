//Solution to UVa 1056: Degrees of Separation
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
 
int mat[50][50];

//simple floyd warshall
int main()
{
    int P , R;
    int INF = 1000000000;
    string x, y;
    int c = 0;
    unordered_map<string, int> people;

    while (cin >> P >> R, P | R)
    {
        people.clear();
        cout << "Network " << ++c << ": " ;

        for (int i = 0; i < P; i++)
        {
            for (int j = 0; j < P; j++)
            {
                mat[i][j] = INF;
            }
        }
        int counter  = 0;
        while (R--)
        {
            cin >> x >> y;
            if (people.find(x) == people.end())
            {
                people[x] = counter++;
            } 
            if (people.find(y) == people.end())
            {
                people[y] = counter++;
            }
            mat[people[x]][people[y]] = 1;
            mat[people[y]][people[x]] = 1;

        }

        //run the floyd warshall
        for (int k = 0; k < P; k++)
        {
            for (int i = 0; i < P; i++)
            {
                if (mat[i][k] == INF) continue;
                
                for (int j = 0; j < P; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < P; i++)
        {
            for (int j = 0; j < P; j++)
            {
                if (i == j) continue;
                maxi = max(maxi, mat[i][j]);
            }
        }
        if (maxi == INF) cout << "DISCONNECTED\n";
        else cout << maxi << "\n";
        cout << "\n";
    }

}