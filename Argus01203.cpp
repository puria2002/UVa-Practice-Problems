//solution to Uva01203: Argus
#include<stdio.h>
#include<queue>
#include<cstring> 
using namespace std;

//a min heap data structure makes the problem trivial

typedef struct query
{
    int ID;
    int period;
    query(int id, int per):
    ID(id), period(per)
    {

    }

    bool operator> (const query q2) const
    {
        if (period > q2.period) return true;
        if (period < q2.period) return false;
        else
        {
            return (ID > q2.ID);
        }
        
    }

}query;

int main()
{
    priority_queue<query, vector<query>, greater<query>> queue; //create a min heap based on the struct above
    int time = 0; //tracks the current running time
    int K, ID, period; 
    int periods[3000]; //direct access table for period from ID (alternatively use a hash table) 
    query top(0,0);
    char s[20];
    while (scanf("%s", s), strcmp("#", s))
    {
        scanf("%d %d", &ID, &period);
        periods[ID - 1] = period;
        queue.push(query(ID, period));
        //NOTE: would be techincally faster to make_heap on the whole input O(N) instead
        //of insert in a buffered manner (O(N log N)) but this will suffice for the time constraint
    }
    
    scanf("%d", &K);
    while (K--)
    {
        top = queue.top();
        time = top.period;
        queue.pop();
        queue.push(query(top.ID, time + periods[top.ID - 1]));
        printf("%d\n", top.ID); 
    }
    return 0;
}
