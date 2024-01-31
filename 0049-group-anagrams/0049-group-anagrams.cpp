class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>mp;
        vector<vector<string>>ans;
        int i=0;
        for(string x:strs){
            string temp=x;
            sort(x.begin(),x.end());
            if(mp.find(x)==mp.end()){
                mp[x]=i;
                ans.push_back({temp});
                i++;
            }
            else{
                ans[mp[x]].push_back({temp});
            }
        }
        
        // int i=0;
        // for(string x:st){
        //     for(string y:strs){
        //         string temp=y;
        //         sort(temp.begin(),temp.end());
        //         if(temp==x)ans[i].push_back(y);
        //     }
        //     i++;
        // }
        return ans;
    }
};