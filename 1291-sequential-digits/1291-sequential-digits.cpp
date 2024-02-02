class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s="123456789";
        for(int i=0;i<9;i++){
            string x="";
            for(int j=i;j<9;j++){
                x+=s[j];
                int temp=stoi(x);
                if(temp>=low && temp<=high){
                    ans.push_back(temp);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};