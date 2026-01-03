class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int col,vector<vector<bool>>& vis){
        if(col<0 || col>=grid[0].size() || row<0 || row>=grid.size() || vis[row][col] || grid[row][col]=='0') return;
        vis[row][col]=true;
        dfs(grid,row,col+1,vis);
        dfs(grid,row,col-1,vis);
        dfs(grid,row+1,col,vis);
        dfs(grid,row-1,col,vis); 
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,vis);
                    ans++;
                }    
            }
        }
        return ans;
    }
};