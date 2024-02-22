class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>to(n+1),tbo(n+1);
        int size=trust.size();
        for(int i=0;i<size;i++){
            tbo[trust[i][1]]++;
            to[trust[i][0]]++;
        }
        for(int i=1;i<=n;i++){
            if(tbo[i]==n-1 && to[i]==0)return i;
        }
        return -1;
    }
};