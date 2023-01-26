/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n = m.length();
        int ans = -1;
        int peak=0;
        // Binary search concept
        int start = 0,end = n-1;
        // find the peak
        while(start < end){
            int mid = (start+end)/2;
            if(m.get(mid) < m.get(mid+1)){
                start = peak = mid+1;
            }else{
                end = mid-1;
            }
        }
        //find ans in the left
        int l=0,r=peak;
        while(l<=r){
            int mid = (l+r)/2;
            int temp = m.get(mid);
            if(temp == target){
                return mid;
            }else if(temp > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        //find ans in the right
        l=peak,r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            int temp = m.get(mid);
            if(temp == target){
                return mid;
            }else if(temp > target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};