class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string f = to_string(num1);
        string s = to_string(num2);
        string t = to_string(num3);

        
        f = string(4 - f.size(), '0') + f;
        s = string(4 - s.size(), '0') + s;
        t = string(4 - t.size(), '0') + t;

        char a = min({f[0], s[0], t[0]});
        char b = min({f[1], s[1], t[1]});
        char c = min({f[2], s[2], t[2]});
        char d = min({f[3], s[3], t[3]});

 
        string an = string(1, a) + b + c + d;

        int ans = stoi(an);

        return ans;
    }
};