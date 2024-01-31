class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int i=0,j=num.size()-1;
        while(i<j){
            if(num[i]+num[j]==t)return{i+1,j+1};
            else if(num[i]+num[j]>t)j--;
            else i++;
        }
        return{};
    }
};