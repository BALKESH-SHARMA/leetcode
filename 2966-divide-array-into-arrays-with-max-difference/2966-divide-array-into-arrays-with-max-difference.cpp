class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i+2<nums.size();i++){
            if(i%3==0){
                if((nums[i+2]-nums[i])<=k){
                    ans.push_back({nums[i],nums[i+1],nums[i+2]});
                }
                else return {};
            }
        }
        return ans;
    }
};