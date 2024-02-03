class Solution {
public:
    string reverseWords(string s) {
        int i=s.size()-1;
        while(i>=0 &&s[i]==' ')i--;
        int j=i;
        string ans="";
        while(i>=0&&j>=0){
            if(s[i]==' '){
                ans+=s.substr(i+1,j-i);
                while(i>=0&&s[i]==' ')i--;
                if(i<0)continue;
                j=i;
                ans+=' ';
                continue;
            }
            if(i==0){
                    ans+=s.substr(i,j+1);
                }
            i--;  
        }
        return ans;
    }
};