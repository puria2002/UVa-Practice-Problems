//solution to UVa 514: Rails
#include<stdio.h>
#include<stack>
using namespace std;
//check if arr can be formed by simulating process with a stack
bool isStackable(int* arr, int N)
{
    //use O(N) auxiliary memory for the stack representing the train station
    stack<int> station;

    //monitor the first train not in station
    int currpos = 1;

    for (int i = 0; i < N; i++)
    {
        if (!station.empty() && station.top() == arr[i])
        {
            station.pop();
            continue;
        }
        if (currpos > arr[i]) return false; //impossible to add from station

        //internal loop executes at most N times 
        //over all iterations of the outerloop combined, maintaining O(N)

        for (int j = currpos; j < arr[i]; j++)
        {
            station.push(j); 
        } 
        currpos = arr[i] + 1; 


    } 
    return true;

}

int main(void)
{
    int N;
    int* arr;
    int index;
    int oldN;
    bool isValid;

    while(scanf("%d", &N), N != 0)
    {   
        oldN = N;
        arr = new int[N];
        while(scanf("%d", arr), arr[0] != 0)
        {
            N = oldN;
            index = 1;
            //input into array except for the first element (already assigned)
            while (--N)
            {
                scanf("%d", arr + index);
                index++; 
            }

            isValid = isStackable(arr, oldN);
            if (isValid) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
        delete[] arr;
        arr = nullptr;
    }
}
