class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1){
            return 1.0/n;
        }else{
            return 1.0/2;
        }
    }
};