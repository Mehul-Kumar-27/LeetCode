#include<queue>
#include<unordered_map>
#include<list>
#include<vector>
#include<iostream>

using namespace std;


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // data structures
    
    queue<int> q;
    vector<int> inDegree(n+1);
    unordered_map<int , list<int>> adjList;
    int nodesPrinted = 0;
    
  // prepare adjList
    
    for(int i = 0 ; i < edges.size() ; i++){
        adjList[edges[i].first].push_back(edges[i].second);
        
        inDegree[edges[i].second]++;
    }
    
    // push in queue
    
    for(int i = 1 ; i < inDegree.size() ; i++){
        
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        
        int frontNode = q.front();
        q.pop();
        
        nodesPrinted++;
        
        for(auto i : adjList[frontNode]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
    }
    
    if(nodesPrinted == n){
        return false;
    }else{
        return true;
    }
}