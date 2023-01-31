class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        int leftmax = 0,rightmin = n;
        for(auto it: left){
            leftmax = max(leftmax, it);
        }
        for(auto it: right){
            rightmin = min(rightmin , it);
        }
        return max(leftmax , n-rightmin);
    }
};