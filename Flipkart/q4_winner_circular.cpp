class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i+1);
        }
        while(q.size() > 1){
            int x = k;
            while(x>1){
                int t = q.front();
                q.pop();
                q.push(t);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
};