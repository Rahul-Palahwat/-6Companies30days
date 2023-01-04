class Solution {
public:
    string getHint(string secret, string guess) {
        int cows=0,bulls=0;
        unordered_map<char,int> mp,mpg;
        for(int i=0;i<guess.length();i++){
            mp[secret[i]]++;
            mpg[guess[i]]++;
            if(secret[i] == guess[i]){
                cows++;
            }
        }
        for(auto it:mp){
            if(mpg.find(it.first) != mpg.end()){
                bulls+=min(mp[it.first],mpg[it.first]);
            }
        }
        bulls-=cows;
        string ans="";
        string f=to_string(cows);
        ans+=f;
        ans+="A";
        string s =to_string(bulls);
        ans+=s;
        ans+="B";
        return ans;
    }
};