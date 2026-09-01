class Solution {
public:
    void bfs(int n,vector<vector<int>> &adj,int src,vector<bool> &visited){
        queue<int> q;
        visited[src]=true;
        q.push(src);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto &e:edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(n,adj,i,visited);
            }
        }
        return count;
    }
};
