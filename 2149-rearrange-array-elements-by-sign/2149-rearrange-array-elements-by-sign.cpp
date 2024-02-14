class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size(), e = 0, o = 1;
        vector<int> ret(n);
        for(int i = 0;i < n;i++){
            if(nums[i] > 0){
                ret[e] = nums[i];
                e = e + 2;
            }
            else{
                ret[o] = nums[i];
                o += 2;
            }
        }
        return ret;
    }
    
};