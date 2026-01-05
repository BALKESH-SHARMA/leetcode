class Solution {
public:
    void dfs(vector<vector<int>>& city,vector<bool>& visited,int curr){
        visited[curr]=true;
        for(int next=0;next<city.size();next++){
            if(city[curr][next]==1 && !visited[next])dfs(city,visited,next);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                ans++;
            }
        }
        return ans;
        
    }
};