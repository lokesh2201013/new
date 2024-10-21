class Solution {
public:
    vector<string> stringSequence(string t) {
        vector<string> a;
        string s = "a";
        a.push_back(s);
        
        int i = 0;
        
        while (s != t) {
            if (s[i] == t[i]) {
                i++;
                s += 'a';
                a.push_back(s);
            } else {
                while (s[i] != t[i]) {
                    s[i]++;
                    a.push_back(s);
                }
            }
        }
        
        return a;
    }
};
