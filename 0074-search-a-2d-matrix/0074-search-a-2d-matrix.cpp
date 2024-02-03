class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target, int row)
    {
        int left = 0, right = matrix[row].size()-1;
        while(left<= right)
        {
            int mid = left + (right - left)/2;

            if(matrix[row][mid]==target)
                return true;
            
            if(matrix[row][mid]>target)
                right = mid-1;
            
            if(matrix[row][mid]<target)
                left = mid +1;
            
        }

        return false;
    }

    int binarySearchTwo(vector<vector<int>>& matrix, int target)
    {
        int left = 1, right = matrix.size() -1;

        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(matrix[mid][0]==target)
                return mid;
            if(matrix[mid][0] < target)
                left = mid +1;
            if(matrix[mid][0] > target)
                right = mid-1;
        }

        return right;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = binarySearchTwo(matrix, target);

        return binarySearch(matrix, target, row);
    }
};