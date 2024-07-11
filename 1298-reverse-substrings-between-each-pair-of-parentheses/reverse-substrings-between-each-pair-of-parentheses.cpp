
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> n;
        for (char c : s) {
            if (c == ')') {
                string p;
                while (n.top() != '(') {
                    p += n.top();
                    n.pop();
                }
                n.pop();
                for (char ch : p) {
                    n.push(ch);
                }
            } else {
                n.push(c);
            }
        }
        
        string a;
        while (!n.empty()) {
            a += n.top();
            n.pop();
        }
        
        reverse(a.begin(), a.end());
        return a;
    }
};
