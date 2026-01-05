class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool>& keys,int curr){
        keys[curr]=true;
        for(int next=0;next<rooms[curr].size();next++){
            int roomKey=rooms[curr][next];
            if(!keys[roomKey]){
                dfs(rooms,keys,roomKey);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<bool>keys(n,false);
        dfs(rooms,keys,0);
        for(int i=0;i<n;i++){
            if(!keys[i])return false;
        }
        return true;
    }
};