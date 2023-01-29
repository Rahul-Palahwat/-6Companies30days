class Solution {
public:
//     bool check(string s){
//         int n = s.length();
//         if(n%2 != 0){
//             return false;
//         }
//         int i=0,j=n/2;
//         while(j<n){
//             if(s[i]!=s[j]){
//                 return false;
//             }
//             i++;
//             j++;
//         }
//         return true;
//     }
//     int distinctEchoSubstrings(string text) {
//         unordered_set<string> st;
//         int n = text.length();
//         for(int i=0;i<n;i++){
//             string s ="";
//             for(int j=i;j<n;j++){
//                 s+=text[j];
//                 if(check(s)){
//                     // cout<<s<<endl;
//                     st.insert(s);
//                 }
//             }
//         }
        
//         return st.size();
//     }
    
    
    // using second approach
    int distinctEchoSubstrings(string text) {
        set<string> st;
        int n = text.length();
        for(int i=1;i<=n/2;i++){
            int count = 0;
            for(int l=0,r=i;r<n;r++,l++){
                if(text[l] == text[r]){
                    count++;
                }else{
                    count = 0;
                }
                if(count == i){
                    string temp = text.substr(l , r-l+1);
                    st.insert(temp);
                    count--;
                }
            }
        }
        
        return st.size();
    }
    
    

};