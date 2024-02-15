class Solution {
public:
    int total = 0;
    void powerset(vector<vector<int>>& mat,int row, int col, int curr,int freecell)
    {
        if(row<0 || row >=mat.size() || col<0 || col>=mat[0].size())
        {
            return;
        }
        
        if(mat[row][col]==-1 || mat[row][col]==-2)
        {
            return;
        }
        
        
        if(mat[row][col]==2)
        {
            if(freecell == curr)
            {
                total++;
                
            }
            return;
        }
        mat[row][col] = -2,
        
        //top or up 
        powerset(mat,row-1,col,curr+1,freecell);
        
        //down 
        powerset(mat,row+1,col,curr+1,freecell);
        
        //right
        powerset(mat,row,col+1,curr+1,freecell);
        
        //left
        powerset(mat,row,col-1,curr+1,freecell);
        
        
        mat[row][col] = 0;
    
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int freecell = 1;
        pair<int, int> start;
        pair<int, int> end;
        for(int row = 0; row<m; row++)
        {
            for(int col = 0; col<n;  col++)
            {
                if(grid[row][col]==0)
                {
                    freecell++;
                }else if(grid[row][col]==1)
                {
                    start.first = row;
                    start.second = col;
                }else if(grid[row][col]==2)
                {
                    end.first = row;
                    end.second = col;
                }
            }
        }
        cout<<start.first<<" "<<start.second<<endl;
        cout<<end.first<<" "<<end.second<<endl;
        powerset(grid,start.first,start.second,0,freecell);

        return total;

    }
};