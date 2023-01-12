class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_map<int,int> f;
        for(auto it: nums){
            mp[it]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]] > 0){
                if(f.find(nums[i]) != f.end()){
                    if(f[nums[i]] > 1){
                        f[nums[i]]--;
                    }else{
                        f.erase(nums[i]);
                    }
                    mp[nums[i]]--;
                    f[nums[i]+1]++;
                }else{
                    int t = nums[i];
                    if(mp[t+1] > 0 && mp[t+2] > 0){
                        mp[t]--;
                        mp[t+1]--;
                        mp[t+2]--;
                    }else{
                        // cout<<t<<" "<<f[t]<<endl;
                        return false;
                    }
                    // cout<<t+3<<"t+3"<<endl;
                    f[t+3]+=1;
                }
            }
        }
        return true;
        
    }
};