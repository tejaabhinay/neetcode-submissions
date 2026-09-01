class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &p:prerequisites){
            int course=p[0];
            int prereq=p[1];
            adj[prereq].push_back(course);
        }


        vector<int> indegree(numCourses,0);

        
        for(int u=0;u<numCourses;u++){
            for(int v:adj[u]){
                indegree[v]++;
            }
        }
        queue<int> q;

        int completed =0;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            completed++;
            for(int v : adj[u]){

                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);

            }
        }

        return completed==numCourses;
    }
};
