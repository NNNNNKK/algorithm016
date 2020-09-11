/**********************************************第一周刷题代码******************************************/

/***********************删除排序数组中的重复项*********************************************************/
#ifndef MYHOMEWORK_01
#define MYHOMEWORK_01
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0,difNumber,difIndex;
        for(int i=0;i<nums.size();i++) {
            if(i==0) {difNumber=nums[0];count++;difIndex=1;continue;}
            if(difNumber!=nums[i]) {
                count++;
                nums[difIndex++]=nums[i];
                difNumber=nums[i];
            }
        }
        return count;
    }
};
//时间复杂度分析:单循环且不嵌套任何循环，所以时间复杂度为O(n);空间复杂度：O(1)

/*********************************旋转数组*********************************************************/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int count=nums.size(); 
       int rotateStep=k%count;//移动的实际步数
       vector<int> temp(count);
       for(int i=0;i<count;i++) {
           if(i+rotateStep<=count-1)
                temp[i+rotateStep]=nums[i];
            else
                temp[i+rotateStep-count]=nums[i];
       }
       nums=temp;
    }
};
//时间复杂度分析：单循环，所以时间复杂度为O(n)；空间复杂度：由于开辟了一个与nums一样大小的数组，所以空间复杂度为O(n)。

/*********************************合并有序数列********************************************************/
 //递归法思路：先比较大小到一个链表为空的时候。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //递归终止条件，当某个链表为空时结束递归
        if(l1==nullptr) return l1;
        if(l2==nullptr) return l2;
        if(l1->val<l2->val) {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        } 
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
};
//时间复杂度：由于要遍历两个链表的节点，所以时间复杂度为O(M+N)，即O(n);由于没有采用其它额外的内存开销，所以空间复杂度为O(1)。

/*********************************两数之和********************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> hash;
        vector<int> result;
        int numsSize = nums.size();
        for(int i=0;i<nums.size();i++) {
           int findNumber=target-nums[i];
           if(hash.find(findNumber)!=hash.end()){
               result.push_back(hash[findNumber]);
               result.push_back(i);
               return result;
           }
           hash[nums[i]]=i;
        }
        return result;
    }
};
//时间复杂度与空间复杂度都是O(n)。

/*********************************移动零********************************************************/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int notZeroIndex=nums[0]==0?0:1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=0) {
                nums[notZeroIndex]=nums[i];
                if(notZeroIndex<i) nums[i]=0;
                notZeroIndex++;
            }
        }
    }
};
//时间复杂度为O(n),空间复杂度为0(1)。

/*********************************加1********************************************************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      for(int i=digits.size()-1;i>=0;i--){
        digits[i]++;
        if(digits[i]==10)
            digits[i]=0;
        else
            return digits;
      }
      digits.insert(digits.begin(),1);
      return digits;
    }
};
//时间复杂度分析：单循环的复杂度为O(n),vector的插入操作的时间复杂度为O(n)，所以总的时间复杂度为O(n)。空间复杂度为O(1)。

#endif//MYHOMEWORK_01