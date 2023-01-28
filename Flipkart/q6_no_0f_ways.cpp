class Solution {
public:
    // int ans = 0;
    // void solve(string num , int index ,string prev,string s){
    //     // cout<<index<<" index "<<prev<<" "<<s<<endl;
    //     if(index > num.length()){
    //         return;
    //     }
    //     if(index == num.length()){
    //         if(s.length() == 0){
    //             ans++;
    //         }else{
    //             if(s[0] == '0'){
    //                 return;
    //             }
    //             if(s>=prev){
    //                 ans++;
    //             }
    //         }
    //         return;
    //     }
    //     if(s.length() != 0){
    //         if(s[0] == '0'){
    //             return;
    //         }
    //         if(s.length() < prev.length()){
    //             return;
    //         }
    //         if(s < prev){
    //             return;
    //         }
    //     }
    //     string temp = "";
    //     for(int i=index;i<num.length();i++){
    //         temp+=num[i];
    //         solve(num , i+1 ,s, temp);
    //     }
    //     return;
    // }
    // int numberOfCombinations(string num) {
    //     solve(num,0,"","");
    //     return ans;
    // }
    int numberOfCombinations(string num) {
        if (num[0] == '0') return 0;
        long N = num.size(), ans = 0, mod = 1e9 + 7;
        vector<vector<long>> lcp(N + 1, vector<long>(N + 1)), dp(N + 1, vector<long>(N + 1));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (num[i] == num[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
        auto le = [&](int k, int i, int j) {
            int len = lcp[k][i];
            return len >= j + 1 - i || num[k + len] < num[i + len];
        };
        for (int j = 0; j < N; ++j) dp[0][j] = 1;
        for (int i = 1; i < N; ++i) {
            if (num[i] == '0') continue;
            for (int j = i, k = i - 1, sum = 0; j < N; ++j) {
                dp[i][j] = sum; // case 1
                if (k < 0) continue; // if k < 0, case 2 (equal length) is invalid but we still need to continue to handle case 1, so we should use `continue` here.
                if (num[k] > '0' && le(k, i, j)) dp[i][j] = (dp[i][j] + dp[k][i - 1]) % mod; // case 2
                sum = (sum + dp[k][i - 1]) % mod; // update the sum used in case 1.
                --k;
            }
        }
        for (int i = 0; i < N; ++i) ans = (ans + dp[i][N - 1]) % mod;
        return ans;
    }
};