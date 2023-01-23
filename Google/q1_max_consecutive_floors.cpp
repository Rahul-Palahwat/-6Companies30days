class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        sort(special.begin(),special.end());
        int i=0;
        while(special[i] < bottom){
            i++;
        }
        ans = special[i]-bottom;
        i++;
        for(;i<special.size() && special[i] <= top;i++){
            ans = max(ans , special[i] - special[i-1]-1);
        }
        ans  = max(ans , top - special[special.size()-1]);
        return ans;
    }
};