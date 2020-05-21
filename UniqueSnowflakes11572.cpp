//solution to UVa 11572: Unique Snowflakes
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

//use DP with auxiliary RB tree data structure (included) to find the maximum subarray with unique elements
//DP based on extending max array ending at index i to find the array at i+1 and
//taking the max (res) over all i
//runs in O(n log n) with O(n) excess memory for the RB tree
int maxUniqueContSub(int* arr, int N)
{
    map<int, int> included; 
    int running = 0;
    int res = 0;
    int prevIn = 0;

    for (int i = 0; i < N; i++)
    {
        if (included.find(arr[i]) == included.end())
        {
            running++;
            included.insert(make_pair(arr[i], i));
            res = max(res, running);
        }

        else
        {
            if (included[arr[i]] < prevIn) 
            {
                running++;
                included[arr[i]] = i;
                res = max(res, running);
            }

            else
            {
                running = running - (included[arr[i]] - prevIn);
                prevIn = included[arr[i]] + 1;
                included[arr[i]] = i; 
            } 
         }
        
    } 
    
    return res;
}

int main()
{
    int N;
    int* arr;
    int TC;
    int oldN;
    int index;
    
    scanf("%d", &TC);

    while(TC--)
    {
        scanf("%d", &N);
        oldN = N;
        arr = new int[N];
        index = 0;

        while (N--)
        {
            scanf("%d", arr + index++);
        }

        printf("%d\n", maxUniqueContSub(arr, oldN));
        delete[] arr;
        arr = nullptr;
    }
    return 0;

}
