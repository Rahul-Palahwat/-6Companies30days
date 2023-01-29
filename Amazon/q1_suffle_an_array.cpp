class Solution {
public:
    vector<int> ans;
    Solution(vector<int>& nums) {
        ans = nums;
    }
    
    vector<int> reset() {
        return ans;
    }
    
    vector<int> shuffle() {
        int n = ans.size();
        vector<bool> vis(n,0);
        int count = 0;
        vector<int> temp;
        while(count < n){
            int x = rand()%n;
            if(vis[x]){
                continue;
            }
            vis[x] = true;
            temp.push_back(ans[x]);
            count++;
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */