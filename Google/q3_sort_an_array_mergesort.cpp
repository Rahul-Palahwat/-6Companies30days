class Solution {
public:
    void merge(vector<int>& nums , int l ,int mid , int r){
        vector<int> one, two;
        for(int i=l;i<=mid;i++){
            one.push_back(nums[i]);
        }
        for(int i=mid+1;i<=r;i++){
            two.push_back(nums[i]);
        }
        int start = l;
        int i=0,j=0;
        while(i<one.size() && j<two.size()){
            if(one[i]<two[j]){
                nums[start] = one[i];
                i++;
            }else{
                nums[start] = two[j];
                j++;
            }
            start++;
        }
        while(i<one.size()){
            nums[start] = one[i];
            i++;
            start++;
        }
        while(j<two.size()){
            nums[start] = two[j];
            j++;
            start++;
        }
        return;
    }
    void mergeSort(vector<int>& nums ,int l , int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(nums, l ,mid);
            mergeSort(nums , mid+1 ,r);
            merge(nums , l ,mid ,r);
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums ,0 , nums.size()-1);
        return nums;
    }
};