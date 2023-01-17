class Solution {
public:
    int findIntegers(int n) {
        int fib[31];
        fib[0]=1;
        fib[1]=2;
        for(int i=2;i<31;i++){
            fib[i] = fib[i-1]+fib[i-2];
        }
        int ans = 0, count=30 , flag=0;
        while(count >=0){
            if(n&(1<<count)){
                ans+=fib[count];
                if(flag){
                    return ans;
                }
                flag=1;
            }else{
                flag=0;
            }
            count--;
        }
        return ans+1;
    }
};