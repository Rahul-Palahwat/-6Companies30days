class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int,int> mp;
        int j=0;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            while(mp.size() >=3){
                if(mp[fruits[j]] == 1){
                    mp.erase(fruits[j]);
                }else{
                    mp[fruits[j]]--;
                }
                j++;
            }
            ans = max(ans , i-j+1);
        }
        return ans;
    }
};