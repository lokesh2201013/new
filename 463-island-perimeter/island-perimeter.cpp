class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int perimeter = 0;
        
        for(int i = 0; i < g.size(); i++) {
            for(int j = 0; j <g[0].size() ;j++) {
                if(g[i][j] == 1) {
                    perimeter += 4; 
            
                    if(j > 0 && g[i][j - 1] == 1)
                        perimeter -= 2;
      
                    if(i > 0 && g[i - 1][j] == 1)
                        perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};