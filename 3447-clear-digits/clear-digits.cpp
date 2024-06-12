class Solution {
public:
    string clearDigits(string s) {
        stack<char> a;
        int c = 0;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] >= '0' && s[i] <= '9') {
                c++;
            } else if(c > 0) {
                c--;
            } else {
                a.push(s[i]);
            }
        }

        string ans;
        while(!a.empty()) {
            ans += a.top();
            a.pop();
        }

        return ans;
    }
};
