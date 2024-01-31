class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int i=0,j=num.size()-1;
        while(i<j){
            int sum=num[i]+num[j];
            if(sum==t)return{i+1,j+1};
            else if(sum>t)j--;
            else i++;
        }
        return{};
    }
};