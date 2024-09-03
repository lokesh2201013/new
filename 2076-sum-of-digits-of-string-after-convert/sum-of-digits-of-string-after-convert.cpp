class Solution {
public:
    int getLucky(string s, int k) {
        string st;
        for(int i = 0; i < s.size(); i++) {
            st += to_string(s[i] - 'a' + 1);
        }

        int sum = 0;
        while(k > 0) {
            sum = 0;
            for(int i = 0; i < st.size(); i++) {
                sum += st[i] - '0';
            }
            st = to_string(sum);
            k--;
        }
        return sum;
    }
};
