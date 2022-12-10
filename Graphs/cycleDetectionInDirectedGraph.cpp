#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<vector>


using namespace std;
bool cycleDetection(unordered_map<int , list<int>> &adjList,unordered_map<int , bool>&visited, unordered_map<int , bool>&isInStack, int node){
    
    visited[node] = true;
    
    isInStack[node] = true;
    
    for(auto i : adjList[node]){
        
        if(visited[i] == false){
            bool cycle = cycleDetection(adjList, visited,isInStack, i);
            if(cycle){
                return true;
            }
        }
        else if(visited[i] == true && isInStack[i] == true){
            return true;
        }
    }
    
    isInStack[node] = false;
    
    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // prepare adjList
    
    unordered_map<int , list<int>> adjList;
    
    for(int i = 0 ; i < edges.size() ; i++){
        adjList[edges[i].first].push_back(edges[i].second);
    }
    
    
    // Prepare data structures
    
    unordered_map<int , bool>visited;
    unordered_map<int , bool>isInStack;
    
    
    //// For disconnected component we make this for loop
    
    for(int i = 1 ; i <= n; i++){
        
        if(visited[i] == false){
            bool cycle = cycleDetection(adjList, visited, isInStack, i);
            if(cycle){
            return true;
            }
        }
        
    }
    
    return false;
}