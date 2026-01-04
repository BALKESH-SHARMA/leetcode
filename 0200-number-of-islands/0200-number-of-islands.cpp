class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    bfs(grid, i, j, dirs);
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<char>>& grid,int r, int c,vector<pair<int,int>>& dirs) {
        queue<pair<int,int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '1') {
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
    }
};
