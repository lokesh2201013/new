class Solution {
public:
    string repeatLimitedString(string si, int r) {
        map<char, int> m;
        for (int i = 0; i < si.size(); i++) {
            m[si[i]]++;
        }
        string a;
        stack<pair<char, int>> mc;
        for (auto it : m) {
            mc.push({it.first, it.second});
        }
        pair<char, int> s;
        while (!mc.empty()) {
            if (mc.top().second == 0) {
                mc.pop();
                continue;
            }
            if (s.second == 0) {
                for (int i = 0; i < r && mc.top().second > 0; i++) {
                    a += mc.top().first;
                    mc.top().second--;
                }
                if (mc.top().second != 0) {
                    s = mc.top();
                    mc.pop();
                }
            } else if (s.second > 0 && !mc.empty()) {
                a += mc.top().first;
                mc.top().second--;
                if (mc.top().second == 0) {
                    mc.pop();
                }
                mc.push(s);
                s = {'\0', 0};
            } else if (s.second > 0 && mc.empty()) {
                break;
            }
        }
        return a;
    }
};
