class Solution {
public:
    int area=0;
    void dfs(vector<vector<int>>& grid,int row,int col,vector<vector<bool>>& visited){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col] == 0 || visited[row][col])return;
        area++;
        visited[row][col] = true; 
        dfs(grid,row-1,col,visited);
        dfs(grid,row+1,col,visited);
        dfs(grid,row,col+1,visited);
        dfs(grid,row,col-1,visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    area=0;
                    dfs(grid,i,j,visited);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};