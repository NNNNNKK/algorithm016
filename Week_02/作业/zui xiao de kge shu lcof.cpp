//剑指offer 40
//排序法
//暴力法,时间复杂度：nlog(n)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res;
        for(int i=0;i<k;i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
//采用heap，即priority_queue，实际执行速度比排序法慢。
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++)
            pq.push(arr[i]);
        while(pq.size()>k)
            pq.pop();
        for(int j=0;j<k;j++) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};