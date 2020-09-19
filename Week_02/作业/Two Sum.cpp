//解题方法
//用hash表来存储数组中的值及其下标，遍历整个数组，每次计算出另一个加数，然后再hash表中查找，找到了则返回这两个数的下标。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++) {
            int findNumber=target-nums[i];
            if(mp.find(findNumber)!=mp.end()) {
                res.push_back(i);
                res.push_back(mp[findNumber]);
                return res;
            }
            mp[nums[i]]=i;
        }
        return res;
    }
};