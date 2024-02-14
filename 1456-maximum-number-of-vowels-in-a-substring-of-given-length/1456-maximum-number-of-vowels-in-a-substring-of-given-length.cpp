class Solution {
public:
    bool isVowel(char s){
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        //unordered_map<char, int> mp;
        int n = s.size();
        int ans = INT_MIN, count = 0;
        for(int i=0;i<k;i++){
            //mp[s[i]]++;
            if(isVowel(s[i]))
                count++;
        }
        int p =0;
        for(int i=k;i<n;i++){
            ans = max(ans, count);
            //mp[s[p]]--;
            if(isVowel(s[p]))
                count--;
            //mp[s[i]]++;
            if(isVowel(s[i]))
                count++;
            p++;
        }
        ans = max(ans, count);
        return ans;
    }
};