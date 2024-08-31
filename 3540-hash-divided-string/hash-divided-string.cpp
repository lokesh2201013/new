class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        int n = s.size();

        for(int i = 0; i < n; i += k) {
            int c = 0;
            for(int j = i; j < i + k && j < n; j++) {
                c += s[j] - 'a';
            }
            int h = c % 26;
            char asi = static_cast<char>(h + 'a');
            ans += asi;
        }

        return ans;
    }
};
