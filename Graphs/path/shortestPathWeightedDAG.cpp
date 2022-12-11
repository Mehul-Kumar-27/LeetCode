#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);

        adjList[u].push_back(p);
    }

    void printGraph()
    {

        for (auto i : adjList)
        {

            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "}";
            }
            cout << endl;
        }
    }

    void topologicalOrder(vector<bool> &visited, stack<int> &order, int node)
    {

        visited[node] = true;

        for (auto i : adjList[node])
        {

            if (visited[i.first] == false)
            {
                topologicalOrder(visited, order, i.first);
            }
        }

        order.push(node);
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 2, 3);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printGraph();

    // Determination of shortest path in DAG using Topological sort

    /// Data structures used

    vector<bool> visited(6);
    stack<int> order;
    vector<int> distance(6);

    /// Obtain the topological Order

    for (int i = 0; i < 6; i++)
    {
        if (visited[i] == false)
        {
            g.topologicalOrder(visited, order, i);
        }
    }

    for (int i = 0; i < distance.size(); i++)
    {
        distance[i] = INT_MAX;
    }

    distance[1] = 0;

    while (!order.empty())
    {
        int frontNode = order.top();
        order.pop();

        if (distance[frontNode] != INT_MAX)
        {
            for (auto i : g.adjList[frontNode])
            {
                if (distance[i.first] > distance[frontNode] + i.second)
                {
                    distance[i.first] = distance[frontNode] + i.second;
                }
            }
        }
    }

    for (int i = 0; i < distance.size(); i++)
    {
        int d = distance[i];

        if (d == INT_MAX)
        {
            d = -1;
        }

        cout << d + " ,";
    }

    return 0;
}
////
