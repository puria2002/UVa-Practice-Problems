//Solution to UVa 429: Word Transformation 
#include<iostream> 
#include<vector>
#include<string>
#include<queue> 
#include<unordered_map>
#include<sstream>
#include<cstring>
using namespace std;

unordered_map<string, int> indices;
char visited[200];
int layer[200]; 
bool isConnected(const string& s1, const string& s2)
{
    if (s1.length() != s2.length()) return false;

    int len = s1.length();
    int differences = 0;
    for (int i = 0; i < len; i++)
    {
        if (s1[i] != s2[i]) differences++;
        if (differences > 1) return false;
    }
    return true;
}

int shortestPath(int s, int d, vector<vector<int>>& adj)
{
    queue<int> vertices;
    vertices.push(s);
    layer[s] = 0;
    visited[s] = 1;
    while (!vertices.empty())
    {
        int top = vertices.front();
        vertices.pop();
        for (int i : adj[top])
        {
            if (visited[i] == 0)
            {
                vertices.push(i);
                visited[i] = 1;
                layer[i] = layer[top] + 1;
                if (i == d) return layer[i];
            }
        }

        visited[top] = 2;

    }

    return 1 << 30;
}

//simple single pair shortest path on an unweighted graph...
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    string word, word1, word2;
    string dict[200];
    bool first = true;
    while (N--)
    {
        if (first)
        {
            first = false;
        }
        else cout << "\n";
        indices.clear();
        int count = 0;
        while (cin >> word, word[0] != '*')
        {
            dict[count] = word;
            indices[word] = count++;
        }
        //process dict for the graph.
        vector<vector<int>> adj(count);
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (isConnected(dict[i], dict[j])) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        cin.ignore();
        while (1)
        {
            string line;
            getline(cin, line);
            istringstream iss(line);
            if (!(iss >> word1 >> word2)) break;
            memset(visited, 0, sizeof visited);
            cout << word1 << " " << word2 <<  " " << shortestPath(indices[word1], indices[word2], adj) << "\n";

        }

        
       

    }
}