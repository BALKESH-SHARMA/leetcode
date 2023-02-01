#include <bits/stdc++.h>
#include<string>
#include<math.h>
using namespace std;
#define ll long long
#define ld long double
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
string gcdOfStrings(string str1, string str2) {
        if((str1+str2)==(str2+str1)){
            return str1.substr(0, __gcd(str1.size(),str2.size()));
        }
        return "";
    }
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int tc = 1;
// cin >> tc;
for (int t = 1; t <= tc; t++)
{
  string str1="ABCABC";
  string str2="ABC";
// cout << 'Case #' << t << ':';
cout<<gcdOfStrings(str1,str2);
}
}