class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxi=INT_MIN,mini = INT_MAX;
        priority_queue<int> maxh;
        priority_queue<int,vector<int>,greater<int>> minh;
        for(auto it: nums){
            maxh.push(it);
            minh.push(it);
        }
        int i=0,j=nums.size()-1;
        while(nums[i] == minh.top()){
            i++;
            minh.pop();
            if(i >= nums.size() || minh.size() <=0){
                break;
            }
        }
        if(minh.size() == 0){
            return 0;
        }
        while(nums[j] == maxh.top() && j>=0){
            j--;
            maxh.pop();
            if(j < 0 || maxh.size() <=0){
                break;
            }
        }
        return j-i+1;
    }
};