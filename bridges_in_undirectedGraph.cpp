#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
void dfs(int node, int parent, int timer,unordered_map<int, bool> &vis, vector<int> &low, vector<int> &dis,unordered_map<int, list<int> > &adj,
       vector<vector<int>> &result ){
    
     vis[node] = true;
     dis[node] = low[node] = timer++;
    
    for(auto nbr : adj[node]){
        
        /// When the neghbiour is the parent of the node
        if(nbr == parent)
            continue;
        
        if(!vis[nbr]){
            /// When the node is no visited and neither isthe parent
            dfs(nbr, node, timer, vis, low, dis, adj, result);
            /// While returning we check wether to change the low of node as the low of neghbiour may would have changed
            low[node] = min(low[node], low[nbr]);
            
            // This is the condition of bridge for an edge
            if(low[nbr] > dis[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
            // If the node is visited and also it is not the parent this would result in a back edge 
            // We update the minimum value of the low of node
            
            low[node] = min(low[node], dis[nbr]);    
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, bool> vis;
    unordered_map<int, list<int> > adj;
    /// prepare adjList
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> low(v);
    vector<int> dis(v);
    int parent = -1;
    int timer = 0;
    
    for(int i = 0; i < v; i++){
        low[i] = -1;
        dis[i] = -1;
    }
    vector<vector<int>> result;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, vis, low, dis, adj, result);
        }
    }
    return result;

}