#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;



void prepareList(unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges)
{

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfs(vector<int> &component, int node, unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adjList)
{
    component.push_back(node);
    visited[node] = 1;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(component, i, visited, adjList);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, set<int>> adjList;

    prepareList(adjList, edges);

    vector<vector<int>> ans;

    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        vector<int> component;
        if (!visited[i])
        {
            dfs(component, i, visited, adjList);
            ans.push_back(component);
        }
    }
    return ans;
}