class Solution {
public:
    bool check(int x, vector<vector<int>>&s){
    int n=s.size();
    for (int i=0; i<n;i++){
        if((1<<i)&x){
            for (int j = 0; j<n; j++){
                if((s[i][j] == 0 and ((1<<j)&x)) or (s[i][j] == 1 and !((1<<j)&x))) return false;
                }
            }
        }
    return true;
    }
    int maximumGood (vector<vector<int>>&s) {
        int ans = 0, n=s.size();
        for (int i=1;i<(1<<n); i++){
            if (check(i, s)){
                ans = max(ans, __builtin_popcount (i));
            }
        }
        return ans;
    }
};