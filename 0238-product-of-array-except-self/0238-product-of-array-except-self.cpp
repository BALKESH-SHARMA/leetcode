class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        double x=1;
        double y=1;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
                if(zero==2)break;
            }
            x*=nums[i];
            if(nums[i]){
                y*=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(zero==2){
                nums[i]=0;
            }
            else if(zero==1){
                if(nums[i]==0)nums[i]=y;
                else nums[i]=0;
            }
            else{
                nums[i]=int(x/nums[i]);
            }
        }
        return nums;
    }
};