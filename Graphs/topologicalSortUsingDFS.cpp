#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include <stack>

using namespace std;



void dfsTransversal(unordered_map<int , list<int>> &adjList,vector<bool>&visited, stack<int> &dfsStack, int node ){
    
    
    // Mark the node visited
    
    visited[node] = true;
    
    for(auto i : adjList[node]){
        if(visited[i] == false){
            dfsTransversal(adjList, visited, dfsStack, i);
        }
    }
    
    dfsStack.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // prepared adjList
    
    unordered_map<int , list<int>> adjList;
    
    for(int i = 0 ; i < e ; i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
    }
    
    // Prepare data structures
    
    vector<bool>visited(v);
    stack<int> dfsStack;
    vector<int> ans;
    
    // for disconnected component
    
    for(int i = 0 ; i < v ; i++){
        
        if(visited[i] == false){
            dfsTransversal(adjList,visited,dfsStack,i);
        }
    }
    
    while(!dfsStack.empty()){
        int node = dfsStack.top();
        ans.push_back(node);
        
        dfsStack.pop();
    }
    
    return ans;
    
    
}