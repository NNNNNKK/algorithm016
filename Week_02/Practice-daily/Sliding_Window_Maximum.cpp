/*Description
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 提示：
你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
*/
//单调双端队列
/* 
解题思路，用一个单调的双端队列来解题
队首为搜索窗口的最大值的索引，每次滑动窗口时比较最大值的索引是否与超过当前索引
插入当前元素的索引，必须维护队列的单调性
每次滑动窗口时，返回的是队首索引对应的元素
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<nums.size();i++) {
            if(!dq.empty()&&dq.front()==i-k) 
                dq.pop_front();
            while(!dq.empty()&&nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
               res.push_back(nums[dq.front()]);
        }
        return res;
    }
};