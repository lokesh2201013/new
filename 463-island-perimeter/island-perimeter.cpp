class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) 
    {
        int c = 0;
        int rows = g.size();
        int cols = g[0].size();
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(g[i][j] == 1)
                {
                    if(j == 0 || g[i][j - 1] == 0)
                    {
                        c++;
                    }
                    if(i == 0 || g[i - 1][j] == 0)
                    {
                        c++;
                    }
                    if(j == cols - 1 || g[i][j + 1] == 0)
                    {
                        c++;
                    }
                    if(i == rows - 1 || g[i + 1][j] == 0)
                    {
                        c++;
                    }
                }
            }
        } 
        return c;
    }
};
