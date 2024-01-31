class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        if(t.size()==0)return {};
        if(t.size()==1)return {0};
        vector<int>s;
        vector<int>ans(t.size(),0);
        
        for(int i=t.size()-1;i>=0;i--){
            
            while(!s.empty() && t[i]>=t[s.back()]){
                s.pop_back();
            }
            if(!s.empty()){
                ans[i]=s.back()-i;
            }
            s.push_back(i);
        }
        return ans;
    }
    
};