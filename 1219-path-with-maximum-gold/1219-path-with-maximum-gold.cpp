class Solution {
public:
    int maxgold(vector<vector<int>>& grid, int row, int col)
    {
        if(row<0 || row >= grid.size() || col<0 || col >=grid[0].size())
        {
            return 0;
        }

        if(grid[row][col]==0 ||grid[row][col]==-1)
        {
            return 0;
        }

        int temp = grid[row][col];
        grid[row][col] = -1;
        int left = maxgold(grid,row,col-1);
        int right = maxgold(grid,row,col+1);
        int top = maxgold(grid,row-1,col);
        int bottom = maxgold(grid,row+1,col);
        grid[row][col] = temp;
        return temp + max(max(left,right),max(top,bottom));
    }
    int getMaximumGold(vector<vector<int>>& grid) {

        int mmaxgold = 0;
        for(int row=0; row<grid.size();row++)
        {
            for(int col=0; col<grid[0].size();col++)
            {
                if(grid[row][col]!=0)
                {
                    int temp = maxgold(grid,row,col);
                    mmaxgold = max(mmaxgold,temp);
                }
            }
        }
        
        return mmaxgold;
    }
};