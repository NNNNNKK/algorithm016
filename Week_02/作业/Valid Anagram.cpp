/*题目描述：Given two strings s and t , write a function to determine if t is an anagram of s.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
*/
//sort solution,time complexit:n*log(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
// hash solution,time complexit:O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};
//array solution time,complexit:O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int ch[26]={0};
        for(int i=0;i<s.size();i++) {
            ch[s[i]-'a']++;
            ch[t[i]-'a']--;
        }
        for(int j=0;j<26;j++) {
            if(ch[j])
                return false;
        }
        return true;
    }
};


