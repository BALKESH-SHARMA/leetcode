class Solution {
public:
    void bfs(vector<vector<char>>& board,int row,int col,int rowSize,int colSize){
        queue<pair<int,int>>q;
        q.push({row,col});
        board[row][col]='#';
        vector<pair<int,int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
                auto[r,c]=q.front();q.pop();
                for(auto [dr,dc]:dirs){
                    int nr=r+dr;
                    int nc=c+dc;
                    if(nr>=0 && nc>=0 && nr<rowSize && nc<colSize && board[nr][nc]=='O'){
                        board[nr][nc]='#';
                        q.push({nr,nc});
                    }
                }
            
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        if(m==1 || n==1 || m==2 || n==2)return ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if(board[i][j]=='O')
                    bfs(board,i,j,m,n);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='#')board[i][j]='O';
            }
        }
        return ;
    }
};