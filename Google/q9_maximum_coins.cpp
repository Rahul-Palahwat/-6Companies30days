class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(),piles.end(),greater<int>());
        int i=1,j=piles.size()-1;
        while(i<j){
            ans+=piles[i];
            i+=2;
            j--;
        }
        return ans;
    }
};