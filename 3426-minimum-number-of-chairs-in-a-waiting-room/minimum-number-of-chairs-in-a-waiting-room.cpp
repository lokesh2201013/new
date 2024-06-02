class Solution {
public:
    int minimumChairs(string s) {
        int currentChairs = 0; 
        int maxChairs = 0;      
        
        for(char event : s) {
            if(event == 'E') {
                currentChairs++;
                if(currentChairs > maxChairs) {
                    maxChairs = currentChairs;
                }
            } else if(event == 'L') {
                currentChairs--;
            }
        }
        
        return maxChairs;
    }
};
