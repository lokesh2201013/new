class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int gain = 0;

        for (char charInString : s) {
            if (!st.empty() && 
               ((charInString == 'a' && st.top() == 'b' && y > x) || 
                (charInString == 'b' && st.top() == 'a' && x >= y))) {
                gain += (st.top() == 'a' ? x : y);
                st.pop();
            } else {
                st.push(charInString);
            }
        }

        string remaining;
        while (!st.empty()) {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        for (char charInString : remaining) {
            if (!st.empty() && ((charInString == 'a' && st.top() == 'b') || 
                                (charInString == 'b' && st.top() == 'a'))) {
                gain += (st.top() == 'a' ? x : y);
                st.pop();
            } else {
                st.push(charInString);
            }
        }

        return gain;
    }
};
