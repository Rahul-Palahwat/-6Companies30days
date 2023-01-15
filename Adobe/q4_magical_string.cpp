class Solution {
public:
    int magicalString(int n) {
        
        queue<int>q;
        q.push(2);
        int cnt=1;
        for(int i=2; i<n; ++i){
            int num=q.front();
            q.pop();
            if(num==1){
                cnt++;
            }
            int l;
            if(q.back()==2){
                l=1;
            }
            else{
                l=2;
            }
            for(int j=0; j<num; ++j){
                q.push(l);
            }
        }
        if(n==0){return 0;}
        return cnt;
    }
        
        
        
        // 122112122
        // int dp[9];
        // dp[0]=1;
        // dp[1]=1;
        // dp[2]=1;
        // dp[3]=2;
        // dp[4]=3;
        // dp[5]=3;
        // dp[6]=4;
        // dp[7]=4;
        // dp[8]=4;
        // int ans = 0;
        // int q = n/9;
        // if(q>0){
        //     ans+=(dp[8]*q);
        //     n=n%9;
        // }
        // if(n>0){
        //     ans+=dp[n-1];
        // }
        // return ans;
    // }
};