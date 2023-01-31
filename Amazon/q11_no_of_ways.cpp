class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001];
    int solve(int d, int k){
        if(d>=k){
            return d==k;
        }
        if(dp[k][d] == 0){
            dp[k][d] = (1+ solve(d+1 , k-1) + solve(abs(d-1) , k-1) )%mod;
        }
        return dp[k][d]-1;
    }
    int numberOfWays(int s, int e, int k) {
        return solve(abs(s-e),k);
    }
};