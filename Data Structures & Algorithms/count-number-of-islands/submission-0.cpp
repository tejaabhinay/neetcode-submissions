class Solution {
public:

    void dfs(vector<vector<char>>& grid,int r,int c,vector<vector<bool>>& visited){
        visited[r][c]=1;
        
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0&&nr<grid.size()
                &&nc>=0&&nc<grid[0].size()
                &&!visited[nr][nc]
                && grid[nr][nc]=='1'){
                    dfs(grid,nr,nc,visited);
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    count++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return count;
    }
};
