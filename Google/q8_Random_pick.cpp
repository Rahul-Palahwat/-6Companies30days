class Solution {
public:
    vector<int> temp;
    Solution(vector<int>& w) {
        temp.resize(w.size(),0);
        temp[0] = w[0];
        for(int i=1;i<w.size();i++){
            temp[i] = w[i]+temp[i-1];
        }
    }
    
    int pickIndex() {
        int x = temp.back();
        int find = rand()%x;
        // int start = 0, end = temp.size()-1;
        // while(start < end){
        //     int mid = (start+end) /2;
        //     if(temp[mid] == find){
        //         return mid;
        //     }else if(temp[mid] > find){
        //         end = mid-1;
        //     }else{
        //         start = mid+1;
        //     }
        // }
        // return start;
        return upper_bound(temp.begin(),temp.end(),find)-temp.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */