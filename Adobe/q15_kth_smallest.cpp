class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        for(auto it: q){
            int index = it[0];
            int trim = it[1];
            priority_queue<pair<string,int>> maxh;
            for(int i=0;i<nums.size();i++){
                int j = nums[i].length()-1;
                int len = trim;
                string temp = "";
                while(len--){
                    temp+=nums[i][j];
                    j--;
                }
                reverse(temp.begin(),temp.end());
                // cout<<temp<<" ";
                maxh.push({temp , i});
                if(maxh.size() > index){
                    maxh.pop();
                }
            }
            // cout<<maxh.top().first<<"first"<<maxh.top().second<<"second"<<endl;
            ans.push_back(maxh.top().second);
        }
        return ans;
    }
};