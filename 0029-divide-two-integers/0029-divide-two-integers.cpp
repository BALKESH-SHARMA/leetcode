class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        bool sign=true;
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) sign=false;
        long long n=abs((long long)dividend),d=abs((long long)divisor);
        long long ans=0;
        int cnt=0;
        while((cnt+1)<32 && n>=(d<<(cnt+1))){
            cnt++;
        }
        for(int p=cnt;p>=0;p--){
            if(n==0) break;
            if(n>=(d<<p)){
                ans+=1LL<<p;
                n-=d<<p;
            }
        }
        if(ans>INT_MAX){
            if(sign) return INT_MAX;
            else return INT_MIN;
        }
        if(sign) return (int)ans;
        return int(-ans);
    }
};