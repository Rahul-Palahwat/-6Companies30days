class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n=profits.size();
    vector<pair<int,int>> projects(n);
    for(int i=0;i<n;i++) projects[i]={profits[i],capital[i]}; 
    int i=0;
    sort(projects.begin(),projects.end(),[&](pair<int,int> a,pair<int,int> b){ return a.second<b.second;});
    priority_queue<int> maxProfit;
    while(k--){
        while(i<n && w>=projects[i].second) maxProfit.push(projects[i++].first);
        
        if(!maxProfit.empty()) w+=maxProfit.top(),maxProfit.pop();
    }
    return w;
}
//     int solve(vector<int> capital , int w){
//         int start = 0;
//         int end = capital.size()-1;
//         while(start < end){
//             int mid = (start+end)/2;
//             if(capital[mid] == w){
//                 return w;
//             }
//             if(capital[mid] > w){
//                 end = mid-1;
//             }else{
//                 start = mid+1;
//             }
//         }
//         return capital[start];
//     }
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         int ans = 0;
//         unordered_map<int,vector<int>> mp;
//         unordered_map<int,int> m;
//         for(int i=0;i<profits.size();i++){
//             mp[capital[i]].push_back(profits[i]);
//             m[capital[i]] = 0;
//         }
//         for(int i=0;i<profits.size();i++){
//             sort(mp[capital[i]].begin(),mp[capital[i]].end(),greater<int>());
//         }
//         // for(auto it : mp){
//         //     cout<<it.first<<"f ";
//         //     for(auto i: it.second){
//         //         cout<<i<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         sort(capital.begin(),capital.end());
//         int i=0;
//         // k+=1;
//         while(k-- && i<capital.size()){
//             i++;
//             int cap = solve(capital , w);
//             if(cap > w){
//                 return ans;
//             }
//             // cout<<m[cap]<<"rit"<<endl;
//             cout<<cap<<"cap"<<mp[cap][m[cap]]<<endl;
//             ans+=mp[cap][m[cap]];
//             // cout<<m[cap]<<"value"<<endl;
//             w+=mp[cap][m[cap]];
//             m[cap]++;
//             // cout<<"Hello"<<endl;
            
//             // cout<<w<<endl;
//         }
//         return ans;
//     }
};