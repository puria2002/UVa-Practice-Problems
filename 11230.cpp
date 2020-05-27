//solution to UVa 11230: Annoying Painting Tool
#include <iostream>
#include<bitset>

using namespace std;
//Simple greedy approach
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    bitset<10000> painting;
    bitset<10000> canvas;
    int total, n, m, r ,c;
    char color;
    while (cin >> n >> m >> r >> c, n | m | r | c)
    {
        total = 0;
        painting.reset();
        canvas.reset();
        //n is rows, m is cols, so index (i,j) 
        //corresponds to m*i + j
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> color;
                painting[m * i + j] = color - 48;
            }
        }
        //now we can paint over r rows and c columns!
        for (int i = 0; i <= n - r; i++) //loop over all the possible rows
        {
            for (int j = 0; j <= m - c; j++) //for each row loop over the columns
            {
                if (painting[m * i + j] != canvas[m * i + j])
                {
                    total++;
                    //need to invert everything in an r by c chunk 
                    for (int a = i; a <= i + r - 1; a++)
                    {
                        for (int b = j; b <= j + c - 1; b++)
                        {
                            canvas[m * a + b] = (canvas[m * a + b] == 0) ? 1 : 0;
                        }
                    }


                }
            }
            //check to make sure the remainder of the row has been properly painted
            for (int j = m - c + 1; j < m; j++)
            {
                if (painting[m * i + j] != canvas[m * i + j])
                {
                    total = -1;
                    break;
                }
            }
            if (total == -1) break; 
        }

        //check to make sure remaining rows have been properly painted
        if (total != -1)
        {
            for (int i = n - r + 1; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (painting[m * i + j] != canvas[m * i + j])
                    {
                        total = -1;
                        break;
                    }
                }
                if (total == -1) break;
            }
        }
        cout << total << "\n";
    }
}