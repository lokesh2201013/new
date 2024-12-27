class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        if(n.size()==0)return 0;
        map<int, int> m; 
        for (int i = 0; i < n.size(); i++) {
            m[n[i]]++;
        }

        int maxLength = 0, currentLength = 0, previousKey;
        auto it = m.begin();
        previousKey = it->first;
        currentLength = 1;
        it++;

        for (; it != m.end(); it++) {
            if (it->first == previousKey + 1) { 
                currentLength++;
                previousKey = it->first;
                maxLength = max(currentLength, maxLength);
            } else {
                currentLength = 1; 
                previousKey = it->first;
            }
        }

        return max(maxLength, currentLength);
    }
};
