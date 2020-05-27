//solution to UVa 11790: Murica's Skyline
#include<iostream> 
#include<algorithm>
#include<cstring>
using namespace std;
//DP arrays

int* increasing;
int* decreasing;

void subseq(int* heights, int*widths, int N)
{
    for(int i = 0; i < N; i++)
    {
        increasing[i] = widths[i];
        decreasing[i] = widths[i];
        for (int j = 0; j < i; j++)
        {
            if (heights[j] > heights[i])
            {
                decreasing[i] = max(widths[i] + decreasing[j], decreasing[i]);
            }
            else if (heights[j] < heights[i])
            {
                increasing[i] = max(widths[i] + increasing[j], increasing[i]);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int TC, N, *heights, *widths, inc, dec;
    cin >> TC;
    for (int j = 1; j <= TC; j++)
    {
        cin >> N;
        heights = new int[N];
        widths = new int[N];
        increasing = new int[N];
        decreasing = new int[N];

        memset(increasing, -1, N * sizeof(int));
        memset(decreasing, -1, N * sizeof(int));

        for (int i = 0; i < N; i++)
        {
            cin >> heights[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> widths[i];
        }
        subseq(heights, widths, N);
        int inc = *max_element(increasing, increasing + N);
        int dec = *max_element(decreasing, decreasing + N);
        cout << "Case "<<j<<".";
        if (inc >= dec)
        {
            cout << " Increasing (" << inc << "). Decreasing (" << dec << ").\n";
        }
        else
        {
            cout << " Decreasing (" << dec << "). Increasing (" << inc << ").\n";
        }
        
        delete[] heights;
        delete[] widths;
        delete[] increasing;
        delete[] decreasing;
    }
}