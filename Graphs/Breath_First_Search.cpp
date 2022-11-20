#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>

using namespace std;

void prepareList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, bool> &visted, unordered_map<int, set<int>> &adjList, vector<int> &ans, int node)
{
    queue<int> q;

    q.push(node);
    visted[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();

        q.pop();

        ans.push_back(frontNode);

        for (auto i : adjList[frontNode])
        {
            if (!visted[i])
            {
                q.push(i);
                visted[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visted;

    prepareList(adjList, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visted[i])
        {
            bfs(visted, adjList, ans, i);
        }
    }

    return ans;
}