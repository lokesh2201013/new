class Solution {
    private:
    bool isPalindrome(const string& str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(str[left])) {
                left++;
            }

            while (left < right && !isalnum(str[right])) {
                right--;
            }

            if (tolower(str[left]) != tolower(str[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

public:
    string firstPalindrome(vector<string>& w) {
        for(int i = 0; i < w.size(); i++) {
            if (isPalindrome(w[i])) {
                return w[i];
            }
        }
        return "";
    }
};