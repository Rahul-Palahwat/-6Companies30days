class Solution {
public:
    int solve(int n){
        if(n==1 || n==0){
            return 1;
        }
        return n*solve(n-1);
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> rev;
        // sort(nums.begin(), nums.end());
        for(auto it: nums){
            string temp = to_string(it);
            reverse(temp.begin(),temp.end());
            rev.push_back(stoi(temp));
        }
        int ans = 0;
        int mod = 1e9+7;
        unordered_map<int,long> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-rev[i]]++;
        }
        for(auto it: mp){
            if(it.second > 1){
                ans=(ans+((it.second * (it.second-1))/2))%mod;
            }
        }
        return ans;
    }
};