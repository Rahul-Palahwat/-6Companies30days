class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i< cards.size();i++){
            mp[cards[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it: mp){
            if(it.second.size() > 1){
                int temp=INT_MAX;
                for(int i=1;i<it.second.size();i++){
                    temp = min(temp , it.second[i]-it.second[i-1]);
                }
                ans = min(ans , temp+1);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};