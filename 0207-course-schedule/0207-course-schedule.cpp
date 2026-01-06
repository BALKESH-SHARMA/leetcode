class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = p.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int>indeg(numCourses,0);
        for(int i=0;i<n;i++){
            indeg[p[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)q.push(i);
        }
        int processed=0;
        while(!q.empty()){
            processed++;
            int front=q.front();q.pop();
            for(auto& node:adj[front]){
                indeg[node]--;
                if(indeg[node]==0)q.push(node);
            }
        }
        return processed==numCourses;
    }
};