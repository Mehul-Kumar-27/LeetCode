#include<queue>
#include<unordered_map>
#include<stack>
#include<list>
#include<iostream>

using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Data Structures required
    
    queue<int> q;
    unordered_map<int , list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int , int> parent;
    vector<int> ans;
    
    
    // Prepare adjList
    
    for(int i = 0 ; i < edges.size() ; i++){
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }
    
    // BFS transversal and obtaining the parent data structure
    
    visited[s] = true;
    parent[s] = -1;
    
    q.push(s);
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto i : adjList[frontNode]){
            
            if(visited[i] == false){
                visited[i] = true;
                parent[i] = frontNode;
                q.push(i);
            }
        }
    }
    
    int currentNode = t;
    
    while(currentNode != -1){
        ans.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    
    
    
    reverse(ans.begin(), ans.end());
    
    
    
    return ans;
	
}
