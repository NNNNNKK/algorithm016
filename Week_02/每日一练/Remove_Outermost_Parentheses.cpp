/*
题解1：采用括号计数的方法
从字符串第二个元素开始遍历，分别计数左右括号的个数，当个数不等式，这个符号即为要输出的符号，当左括号数目与右括号数目相等时，重置计数
*/
class Solution {
public:
    string removeOuterParentheses(string S) {
        int L=1;int R=0;
        string ans;
        for(int i=1;i<S.size();i++){
            if(S[i]=='(')L++;
            else R++;
            if(R!=L)ans.push_back(S[i]);
            else {
                i++;L=1;R=0;
            }
        }
        return ans;
    }
};
/*
方法2：用栈来解决，栈中只压入左括号，遇到右括号时就弹出左括号，压入或者弹出后栈不为空，则该字符即为可以输出的字符。
*/
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
		stack<char> mystack;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == ')')
				mystack.pop();
			if (!mystack.empty())
				res+=S[i];
			if (S[i] == '(')
				mystack.push('(');
		}
		return res;
    }
};
