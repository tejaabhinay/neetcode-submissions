class Solution {
public:
    void bfs(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                    q.push({i,j});
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0&&nr < n && nc >= 0 &&nc < m&&grid[nr][nc]==INT_MAX){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
    }
};
