#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>

using namespace std;


bool isCycle(unordered_map<int , list<int>>&adj , unordered_map<int, bool>&visited, int node){
    queue<int> q;
    q.push(node);
    
    visited[node] = true;
    
    while(!q.empty()){
        
        int frontNode = q.front();
        q.pop();
        
        int timesVisited = 0;
        
        for(auto i : adj[frontNode]){
            if(visited[i] == false){
                visited[i] = true;
                q.push(i);
            }else{
                timesVisited++;
            }
            
        }
        
        if(timesVisited >= 2){
            return true;
        }
    }
    
    return false;
    
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Creating Adjacency List
    
    unordered_map<int, list<int>> adj;
    
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Creating visited data structure
    
    unordered_map<int , bool> visited;
    bool isCyclePresent;
    
    // For discoennected component we vist every node
    
    for(int i=0 ; i < n ; i++){
        
        if(visited[i] == false){
            isCyclePresent = isCycle(adj, visited, i);
            
        }
        
        if(isCyclePresent == true){
            return "Yes";
        }
    }
    
    return "No";
    
}
