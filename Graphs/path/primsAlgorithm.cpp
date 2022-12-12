#include <iostream>
#include<list>
#include<unordered_map>
#include<vector>

using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Prepare Data structures
    
    unordered_map<int, list<pair<int,int>>> adjList;
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    vector<pair<pair<int,int>,int>> ans;
    
    /// Prepare adjList
    
    for(int i = 0 ; i < g.size() ;i++ ){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;
        
        adjList[u].push_back(make_pair(wt,v));
        adjList[v].push_back(make_pair(wt,u));
    }
    
    for(int i = 0 ; i < n+1 ; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    
    /// Marking source key and mst
    key[1] = 0;
    
    
    
    /// Performing search
    
    for(int j = 0 ; j < n+1 ; j++){
        int min = INT_MAX;
        
        int i;
        /// Find minimum key whose mst = false
        for(int index = 1 ; index <= n ; index++){
            
            if(mst[index] != true && key[index] < min){
                i = index;
                min = key[index];
            }
        }
        
        /// Mark mst of i true
            mst[i] = true;
        /// Move to its adjacent nodes
        
            for(auto node : adjList[i]){
                int wt1 = node.first;
                int v1 = node.second;
                
                if(wt1 < key[v1] && mst[v1] == false){
                    key[v1] = wt1;
                    parent[v1] = i;
                }
            }
        
    }
    
    for(int i = 2 ; i <= n ; i++){
        ans.push_back({{parent[i] , i}, key[i]});
    }
    
    
    return ans;
    
    
}
