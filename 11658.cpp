//solution to UVa 11658: Best Coalitions
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;

//direct access table for memoization
int dp[100][5000];

int minSum(int* shareholders, int index, int target, int running, int N)
{
    if (running > target) return running; //prune 

    if (index == N) 
    {
        if (running <= target) return 50000; //insufficient case
        else return running; //end of recursion
    }

    if (dp[index][running] != -1) return dp[index][running]; //memoized

    return dp[index][running] = min(minSum(shareholders, index + 1, target, running + shareholders[index], N),
                                    minSum(shareholders, index + 1, target, running, N));


}
int main()
{
    int n, x;
    double in;
    int holder;
    int a ,b;
    int shareholders[100];

    //avoiding floating point errors is painful but neccessary to pass all edge cases
    while (scanf("%d %d", &n, &x), n | x)
    {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < x - 1; i++)
        {
            scanf("%d.%d", &a, &b);

            shareholders[i] = 100 * a + b;
        }
        
        scanf("%d.%d", &a, &b);

        holder = 100 * a + b;

        for (int i = x; i < n; i++)
        {
            scanf("%d.%d", &a, &b);

            shareholders[i - 1] = 100 * a + b;
        }
        int target = 5000 - holder;
        int res = minSum(shareholders, 0, target, 0, n - 1);
        in = (double) holder * 100 / (holder + res);
        printf("%0.2lf\n", in); 
    }
}