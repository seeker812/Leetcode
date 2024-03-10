class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(),pivot);

        int less = 0, greater = 0, equal = 0;

        for(auto val : nums)
        {
            if(val<pivot)
                less++;
            else if(val==pivot)
                equal++;
            else
                greater++;
        }

        int left = 0, right = less + equal;

        for(auto val : nums)
        {
            if(val < pivot)
            {
                ans[left] = val;
                left++;
            }   
            else if( val > pivot)
            {
                ans[right] = val;
                right++;
            }
                
        }

        return ans;
    }
};