class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto it: words){
            mp[it]++;
        }
        map<int , vector<string> , greater<int> > m;
        for(auto it: mp){
            m[it.second].push_back(it.first);
        }
        vector<string> ans;
        for(auto it: m){
            sort(it.second.begin(), it.second.end());
            for(auto i: it.second){
                if(k>0){
                    ans.push_back(i);
                    k--;
                }
            }
        }
        return ans;
    }
};