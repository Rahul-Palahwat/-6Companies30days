class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
       // slope of every point with selected point
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                //calculating the slope
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                if(pt[j][1]-pt[i][1]<0 &&(pt[j][0]-pt[i][0])==0 ) //infinite slop for Perpendicular line
                mp[abs(x)]++; 
                else
               //storing the slop into map
                    mp[x]++;
            }
            // same slope w.r.t.that selected point
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;
    }
//     int maxPoints(vector<vector<int>>& pt) {
//         int n = pt.size();
//         int ans = 1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i==j){
//                     continue;
//                 }
//                 int count=0;
//                 int num = pt[j][1]-pt[i][1];
//                 int den = pt[j][0]-pt[i][0];
//                 if(den == 0){
//                     int c = -1*num*pt[j][0];
//                     for(auto it: pt){
//                         if(it[0] == (-1*c)/num){
//                             count++;
//                             ans = max(ans,count);
//                         }
                        
//                     }
//                 }else{
//                     int c = pt[j][1]*den - num*pt[j][0];
//                     for(auto it: pt){
//                         int left = it[1]*den;
//                         int right = it[0]*num + c;
//                         if(left == right){
//                             count++;
//                             // cout<<count<<"count"<<endl;
//                             ans = max(ans,count);
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
};