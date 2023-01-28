class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(auto it: s){
            mp[it]++;
        }
        string ans = "";
        for(auto it: order){
            if(mp.find(it) != mp.end()){
                while(mp[it]--){
                    ans+=it;
                }
            }
        }
        for(auto it: mp){
            while(it.second > 0){
                ans+=it.first;
                it.second--;
            }
        }
        return ans;
    }
};