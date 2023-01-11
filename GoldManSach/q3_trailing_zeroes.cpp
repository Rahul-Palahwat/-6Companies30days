class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int temp=5;
        // int i=1;
        while(n>=temp){
            ans+=(n/temp);
            temp*=5;
            // i++;
        }
        return ans;
    }
};