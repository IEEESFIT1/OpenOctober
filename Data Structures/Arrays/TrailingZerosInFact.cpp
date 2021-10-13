/*Given an integer n, return the number of trailing zeroes in n!.*/

class Solution {
public:
    int trailingZeroes(int n) {
         int ans=0;
        for(int i=5; i<=n; i=i*5){
            ans+=n/i;
        }
        return ans;
    }
};
