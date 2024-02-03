class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double temp=0;
        int i=0;
        double ans=INT_MIN;
        while(i<k){
            temp+=nums[i];
            i++;
        }
        ans=temp/k;
        int j=0;
        while(i<n){
            temp+=nums[i];
            temp-=nums[j];
            double avg=temp/k;
            if(avg>ans)ans=avg;
            i++;
            j++;
        }
        return ans;
    }
};