/*解法：采用hash表记录每个元素及其出现的频次，然后遍历该hash表，把hash表的value和key
组成pair放在大顶堆中,然后从大于k开始把top()的第一个值放入结果数组中。
时间复杂度为O(nlog(n-k))*/

//codes:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> um;
        for(auto &a:nums)
            um[a]++;
        priority_queue<pair<int,int> pq;
        for(auto it = map.begin(); it != map.end(); it++) {
            pq.push(make_pair(it->second,it->first));
            if(pq.size()>um.size()-k) {
                res.push(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }

};