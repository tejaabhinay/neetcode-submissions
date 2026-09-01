class Solution {
public:
    bool bfs(int n,vector<vector<int>> &adj,int src,vector<bool> &visited){
        queue<pair<int,int>> q;
        visited[src]=true;
        q.push({src,-1});
        while(!q.empty()){
            int u=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push({v,u});
                }
                else if(parent!=v){
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto &e:edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
         if(bfs(n, adj, 0, visited))
            return false;

        // Check connectivity tree= nocycle+connectivity
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return false;
        }

        return true;
    }
};
