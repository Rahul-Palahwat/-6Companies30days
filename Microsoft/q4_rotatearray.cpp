class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0,total=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            total+=(i*nums[i]);
        }
        int maxi = total;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            total+=(sum)-(nums[i]*n);
            maxi = max(maxi,total);
        }
        return maxi;
    }
};