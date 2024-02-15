class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=nums[0]+nums[1];
        long long p=0;
        for(int i=2;i<nums.size();i++){
            if(sum>nums[i]) p=sum+nums[i];
            sum+=nums[i];
        }
        return p==0?-1:p;
    }
};