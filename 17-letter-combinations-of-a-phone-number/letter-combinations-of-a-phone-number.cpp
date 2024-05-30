class Solution {
    std::string ans;
    void give(const std::string& d, std::vector<std::string>& a, int i, const std::vector<std::string>& m, int n) {
        if (i == n) {
            a.push_back(ans);
            return;
        }
        int num = d[i] - '2';
        for (char c : m[num]) {
            ans += c;
            give(d, a, i + 1, m, n);
            ans.pop_back();
        }
    }
public:
    std::vector<std::string> letterCombinations(const std::string& d) {
         if(d.size()==0)
        {
            return {};
        }
        std::vector<std::string> a;
        std::vector<std::string> m = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = d.size();
        give(d, a, 0, m, n);
        return a;
    }
};
