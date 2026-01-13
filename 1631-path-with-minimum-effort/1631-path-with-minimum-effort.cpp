class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n= heights[0].size();
        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        effort[0][0]=0;

        pq.push({0,{0,0}});
        vector<pair<int,int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto [currEffort,cell] = pq.top();
            pq.pop();
            int r = cell.first;
            int c = cell.second;
            if(r==m-1 && c==n-1)return currEffort;
            if(currEffort>effort[r][c])continue;
            for(auto [dr,dc]:dirs){
                int nr = dr+r;
                int nc = dc+c;
                if (nr < 0 || nc < 0 || nr >= m || nc >= n)continue;
                int edgeCost = abs(heights[r][c]-heights[nr][nc]);
                int nextEffort = max(currEffort,edgeCost);
                if(nextEffort<effort[nr][nc]){
                    effort[nr][nc]=nextEffort;
                    pq.push({effort[nr][nc],{nr,nc}});
                }
            }
        }
        return 0;
    }
};