class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>outdeg(n,0);
        for(int i=0;i<n;i++){
            outdeg[i]=graph[i].size();
            for(int j=0;j<graph[i].size();j++)
            adj[graph[i][j]].push_back(i);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto& v:adj[front]){
                outdeg[v]--;
                if(outdeg[v]==0){
                    q.push(v);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(outdeg[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};