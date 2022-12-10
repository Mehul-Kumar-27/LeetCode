
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>

using namespace std;

/// If the node is visited and it is not the parent then the cycle is present

bool isCycleUsingDFS(unordered_map<int, list<int>>& adj,unordered_map<int , bool>& visited, int node, unordered_map<int , int>& parent){
    
    visited[node] = true;
    
    
    
    for(auto i : adj[node]){
        if(visited[i] == false){
            parent[i] = node;
            bool cycle = isCycleUsingDFS(adj, visited, i , parent);
        }
        else if (i != parent[node]){
            return true;
        }
    }
    
    return false;
    
    
    
    
    
}



unordered_map<int , list<int>> prepareAdjList(vector<vector<int>>&edges , int E){
    unordered_map<int, list<int>> adj;
    
    for(int i = 0 ; i < E ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return adj;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Creating Adjacency List
    
     unordered_map<int, list<int>> adj = prepareAdjList(edges, m);
    
    // Creating visited data structure
    
    unordered_map<int , bool> visited;
    unordered_map<int , int> parent;
    
    
    
    // For discoennected component we vist every node
    
    for(int i=0 ; i < n ; i++){
        
        
        if(visited[i] == false){
            
            bool isCycle = isCycleUsingDFS(adj, visited , i, parent);
           if(isCycle){
            return "Yes";
           } 
        }
        
        
        
        
    }
    
    return "No";
    
}
