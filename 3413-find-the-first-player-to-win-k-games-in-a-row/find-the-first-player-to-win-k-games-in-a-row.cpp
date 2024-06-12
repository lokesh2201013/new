
class Solution {
public:
    int findWinningPlayer(std::vector<int>& s, int k) {
        int n = s.size();
        std::deque<int> pq;
        
        for (int i = 1; i < n; i++) {
            pq.push_back(i);
        }
        
        int ele = 0, w = 0;
        
        while (true) {
            int num = pq.front();
            pq.pop_front();
            
            if (s[num] < s[ele]) {
                w++;
                pq.push_back(num);
            } else {
                w = 1;
                pq.push_back(ele);
                ele = num;
            }
            
            if (w == k || w >= n - 1) return ele;
        }
        
        return 1; 
    }
};