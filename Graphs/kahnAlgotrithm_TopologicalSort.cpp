#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    // Prepare Data structures
    queue<int> bfsQueue;
    vector<int> ans;
    vector<int> inDegrees(v);
    // prepared adjList

    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < e; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        inDegrees[edges[i][1]]++;
    }

    ////// Kahn's Algorithm

    for (int i = 0; i < inDegrees.size(); i++)
    {
        if (inDegrees[i] == 0)
        {
            bfsQueue.push(i);
        }
    }

    while (!bfsQueue.empty())
    {

        int frontNode = bfsQueue.front();
        bfsQueue.pop();

        ans.push_back(frontNode);

        for (auto i : adjList[frontNode])
        {
            inDegrees[i]--;

            if (inDegrees[i] == 0)
            {
                bfsQueue.push(i);
            }
        }
    }

    return ans;
}