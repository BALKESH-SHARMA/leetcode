class Solution {
public:
    int bfs(vector<vector<char>>& maze,int row,int col,vector<pair<int,int>>& dirs){
        queue<pair<int,int>>q;
        q.push({row,col});
        maze[row][col]='+';
        int step=0;
        while(!q.empty()){
            int size = q.size();
            step++;
            while(size--){
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy]:dirs){
                int nx = x+dx;
                int ny = y+dy; 
                
                if(nx>=maze.size() || nx<0 || ny>=maze[0].size() || ny<0 || maze[nx][ny]=='+') continue;
                
                if(nx == maze.size()-1 || nx==0 || ny == maze[0].size()-1 || ny==0) return step;
                q.push({nx,ny});
                maze[nx][ny] = '+';
                
            }
            }
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        return bfs(maze,entrance[0],entrance[1],dirs);
    }
};