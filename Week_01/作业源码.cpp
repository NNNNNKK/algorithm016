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

/*********************************设计循环双端队列********************************************************/

class MyCircularDeque {
public:
    vector<int> buffer;
    int front;//队列首索引
    int rear;//循环队列尾地址
    int cnt;//rong
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cnt=k+1;//多留一个位置，因为rear指向尾部得下一个指针
        buffer.assign(cnt,0);
        front=0;
        rear=0;
    }
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        front=(front-1+cnt)%cnt;
        buffer[front]=value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        rear=(rear+1)%cnt;
        buffer[rear]=value; 
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1)%cnt;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        rear=(rear-1+cnt)%cnt;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return buffer[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return buffer[(rear-1+cnt)%cnt];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(front==rear)
            return true;
        else 
            return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if((rear+1)%cnt==front)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

#endif//MYHOMEWORK_01