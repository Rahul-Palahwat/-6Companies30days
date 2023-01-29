class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int> nums ,int index , int count , int k , int p , vector<int> temp){
        if(count > k || index >= nums.size()){
            if(temp.size() >0)
            if(count <= k){
                st.insert(temp);
            }
            return;
        }
        if(temp.size() >0)
        if(count <= k){
            st.insert(temp);
        }
        temp.push_back(nums[index]);
        if(nums[index] % p ==0){
            solve(nums , index+1 , count+1 , k ,p,temp);
        }else{
            solve(nums , index+1 , count , k , p , temp);
        }
        return;
        
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        vector<int> t;
        for(int i=0;i<nums.size();i++){
            vector<int> temp;
            solve(nums , i , 0 , k , p ,temp);
        }
        return st.size();
    }
};