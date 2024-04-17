class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one  = 0, two = nums.size()-1;

        while(one<=two)
        {
            if(nums[one] == 0)
            {
                swap(nums[one], nums[zero]);
                one++;
                zero++;

            }else if(nums[one] == 1)
            {
                one++;
            }else
            {
                swap(nums[one],nums[two]);
                two--;
            }
        }

       
    }
};