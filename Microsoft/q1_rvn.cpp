class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> st;
        for(auto it: tokens){
            if(it == "+" || it == "-" || it == "*" || it =="/"){
                int t1 = (st.top());
                st.pop();
                int t2 = (st.top());
                int temp;
                st.pop();
                if(it == "+"){
                    temp = t1+t2;
                }else if(it == "-"){
                    temp = t2-t1;
                }else if(it == "*"){
                    temp=t2*t1;
                }else{
                    temp = t2/t1;
                }
                st.push(temp);
            }else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};