class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        unordered_map<char,int> mp;
        int j=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            while(mp.size() >= 3){
                ans+=(s.length()-i);
                if(mp[s[j]] > 1){
                    mp[s[j]]--;
                    j++;
                }else{
                    mp.erase(s[j]);
                    j++;
                }
            }

        }
        return ans;
    }
};