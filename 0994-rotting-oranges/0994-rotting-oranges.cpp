class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                    if(grid[i][j]==2)q.push({i,j});
                    if(grid[i][j]==1)fresh++;
                }
            }
        
        int time=0;
        vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                auto[row,col] = q.front();
                q.pop();
                for(auto [dr,dc] : dirs){
                    int nr= row+dr;
                    int nc= col+dc;
                    if (nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return fresh==0?time:-1;
    }
};