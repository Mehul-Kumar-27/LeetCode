#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{

public:
    unordered_map<int, vector<int>> adjList;

    void addEdges(int u, int v, bool direction)
    {
        adjList[u].push_back(v);

        if (direction == false)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adjList)
        {

            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ,";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph;

    cout << "Enter the number of edges" << endl;

    int e;
    cin >> e;

    cout << "Is the graph directed " << endl;
    cout << "Press 1 for directed 0 for un directed" << endl;

    int direction;
    cin >> direction;

    for (int i = 0; i < e; i++)
    {
        cout << "Enter the nodes" << endl;

        int u, v;
        cin >> u >> v;

        graph.addEdges(u, v, 0);
    }

    graph.printGraph();

    return 0;
}