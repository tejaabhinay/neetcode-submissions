class Solution {
public:
    int bfs(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<tuple<int,int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto [r,c,time]=q.front();
            q.pop();
            ans=time;
            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0&&nr < n && nc >= 0 &&nc < m&&grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    q.push({nr, nc,time+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
