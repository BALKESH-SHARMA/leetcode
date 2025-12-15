class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(st.find(board[i][j])!= st.end())return false;
                st.insert(board[i][j]);
            }
            st.clear();
        }
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')continue;
                if(st.find(board[i][j])!= st.end())return false;
                st.insert(board[i][j]);
            }
            st.clear();
        }
        for (int boxRow = 0; boxRow < 3; boxRow++) {
          for (int boxCol = 0; boxCol < 3; boxCol++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char c = board[boxRow*3 + i][boxCol*3 + j];
                    if (c == '.') continue;
                    if (st.find(c) != st.end()) return false;
                    st.insert(c);
                }
            }
            st.clear();
          }
        }
        return true;
    }
};