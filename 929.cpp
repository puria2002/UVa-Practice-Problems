//Solution to UVa 929: Number Maze
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

bool isValid(int x, int y, int N, int M)
{
    if (x < 0 || x >= N || y < 0 || y >= M) return false;

    return true;
}


unsigned int shortestPath(pair<int, int> source, pair<int, int> end, int* weights, int N, int M)
{
    unsigned int* distances = new unsigned int[N * M];
    
    memset(distances, -1, N * M * sizeof(unsigned int)); //all distances initially infinite 
    priority_queue< pair<unsigned int, int>, vector<pair<unsigned int, int>> ,greater<pair<unsigned int, int>> > pq;


    int dr[] = {0,0,1,-1};
    int dc[] = {1,-1,0,0};

    distances[M * source.first + source.second] = weights[M * source.first + source.second]; //direct access to best distance estimate



    if (source == end) return distances[M * source.first + source.second];

    for (int i = 0; i < 4; i++)
    {
        int row = source.first + dr[i];
        int col = source.second + dc[i];

        if (isValid(row, col, N, M))
        {
            distances[M * row + col] = weights[M * row + col] + distances[M * source.first + source.second];
            pq.push(make_pair(distances[M * row + col], M * row + col));
        }
    }

    while (pq.size())
    {
        pair<int, int> top = pq.top();

        pq.pop(); //Pop off the pq

        if (top.first != distances[top.second]) continue; //lazy deletion/update; same fundamental algorithm but no heap_decrease_key

        if (top.second == M * end.first + end.second)
        {
            delete[] distances;
            return top.first;
        }



        int r = top.second / M;
        int c = top.second % M;
        for (int i = 0; i < 4; i++)
        {
            int row = r + dr[i];
            int col = c + dc[i];
            if (isValid(row, col, N, M))
            {   
                if (top.first + weights[M * row + col] < distances[M * row  + col])
                {
                    //add to the PQ!
                    distances[M * row  + col] = top.first + weights[M * row + col];
                    pq.push(make_pair(distances[M * row  + col], M * row + col));

                }
            }
        }


    }

    delete[] distances;
    return -1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC, N, M, res;
    cin >> TC;
    while (TC--)
    {
        cin >> N >> M;
        int* weights = new int[N * M];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> weights[M * i + j];
            }
        }
        cout << shortestPath(make_pair(0,0), make_pair(N - 1 , M - 1), weights, N, M) << "\n";

        delete[] weights;
    }
}