class Solution {
public:
    unordered_map<string,int> mp,vis;
    
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        for(int i=0;i<=n-k;i++){
            string temp = s.substr(i,k);
            // cout<<temp<<endl;
            mp[temp]=1;
        }
        if(mp.size() == pow(2,k)){
            return true;
        }
        return false;
    }
};