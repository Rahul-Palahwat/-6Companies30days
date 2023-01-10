class Solution {
public:
    // bool possible(string s,int i){
    //     int n = s.length();
    //     int j = n-i-1;
    //     i=0;
    //     while(j<n){
    //         if(s[i] == s[j]){
    //             i++;
    //             j++;
    //         }else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
   
    string longestPrefix(string &s) {
    long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
    for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
        int first = s[i] - 'a', last = s[j] - 'a';
        h1 = (h1 * 26 + first) % mod;
        h2 = (h2 + mul * last) % mod;
        mul = mul * 26 % mod;
        if (h1 == h2)
            len = i + 1;
    }
    return s.substr(0, len);
        
        // string pre = "",post="";
        // int n = s.length();
        // int sz = 0;
        // string ans="";
        // int j=n-1;
        // string temp = s;
        // reverse(s.begin(),s.end());
        // unordered_map<string,int> mp;
        // string str="";
        // for(int i=0;i<n-1;i++){
        //     str+=s[i];
        //     mp[str]=1;
        // }
        // for(int i=0;i<n-1;i++){
        //     pre+=temp[i];
        //     if(mp.find(pre) != mp.end()){
        //         ans = pre;
        //     }
        // }
        // return ans;
        // int ans=0,flag=0;
        // int n=s.length();
        // for(int i=0;i<n-1;i++){
        //     if(possible(s,i)){
        //         flag=1;
        //         ans = i;
        //     }else{
        //         continue;
        //     }
        // }
        // if(flag==0){
        //     return "";
        // }
        // string st="";
        // for(int i=0;i<=ans;i++){
        //     st+=s[i];
        // }
        // return st;
    }
};