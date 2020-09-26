//解题思路：采用数组缓存+递归的方式。

class Solution {
public:
    int step[1000]={0};//数组缓存
    int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    if(step[n]!=0)
        return step[n];
    else {
        step[n]=climbStairs(n-1)+climbStairs(n-2);
        return step[n];
    }
    }
};