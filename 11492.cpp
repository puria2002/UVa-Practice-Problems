//Solution to UVa 11492: Babel
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;
unordered_map<string, vector<string>> languages;
unordered_map<string, vector<string>> words;

unsigned int shortestPath(string& O, string& D)
{
    unordered_map<string, unsigned int> distances;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int,  string>>> pq;

    for (const pair<string, vector<string>>& word : words)
    {
        distances[word.first] = -1;
    }

    for (const string& word : languages[O])
    {
        distances[word] = word.size();
        pq.push(make_pair(word.size(), word));
    }

    while (pq.size())
    {
        pair<int, string> top = pq.top();
        pq.pop();

        if (distances[top.second] != top.first) continue; //lazy deletion

        const string& l1 = words[top.second][0];
        const string& l2 = words[top.second][1];

        if (l1.compare(D) == 0 || l2.compare(D) == 0) return top.first;

        for (const string& word : languages[l1])
        {
            if (word[0] == top.second[0]) continue; //no edge exists 

            if (word.size() + top.first < distances[word])
            {
                distances[word] = word.size() + top.first;
                pq.push(make_pair(word.size() + top.first, word));

            }
        }

        for (const string& word : languages[l2])
        {
            if (word[0] == top.second[0]) continue; //no edge exists 

            if (word.size() + top.first < distances[word])
            {
                distances[word] = word.size() + top.first;
                pq.push(make_pair(word.size() + top.first, word));
                
            }
        }

    }

    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string O, D, l1, l2, P;
    int M;
    //To quickly enumerate edges, we need a hash table for each language holding the words associated with it.
    //additionally, for each word, we must quickly determine what languages it is associated with
    while (cin >> M, M)
    {
        cin >> O >> D;

        languages.clear();
        words.clear();

        while (M--)
        {
            cin >> l1 >> l2 >> P;
            languages[l1].push_back(P); //language->Word
            languages[l2].push_back(P); 
            words[P].push_back(l1); //word-> languages!
            words[P].push_back(l2);
        }
        int res = shortestPath(O, D);
        if (res == -1) cout << "impossivel\n";
        else cout << res << "\n";
    }
}