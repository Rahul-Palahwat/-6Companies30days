class Solution {
public:
    // unordered_map<string , int> mp;
    // void solve(string s , int index , string temp){
    //     if(index >= s.length()){
    //         if(temp.length() > 0){
    //             mp[temp]++;
    //         }
    //         return;
    //     }
    //     solve(s , index+1 , temp);
    //     temp+=s[index];
    //     solve(s , index+1 , temp);
    //     return;
    // }
    // int numMatchingSubseq(string s, vector<string>& words) {
    //     solve(s , 0 , "");
    //     int ans = 0;
    //     for(auto it: words){
    //         if(mp.find(it) != mp.end()){
    //             ans++;
    //         }
    //     }
    //     return ans;
    // }
    
    
    bool solve(string f , string s){
        int i=0,j=0;
        while(j<s.length() && i<f.length()){
            if(f[i] == s[j]){
                i++;
            }
            j++;
        }
        if(i == f.length()){
            return true;
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> mp;
        for(auto it: words){
            if(mp.find(it) != mp.end()){
                ans+=mp[it];
            }else{
                if(solve(it , s)){
                    ans++;
                    mp[it]=1;
                }else{
                    mp[it] = 0;
                }
            }
        }
        return ans;
    }
};