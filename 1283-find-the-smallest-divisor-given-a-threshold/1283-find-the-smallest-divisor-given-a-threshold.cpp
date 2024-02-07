class Solution {
public:
    bool isPossible(vector<int>& nums, double divisor, int threshold)
    {
        int total = 0;

        for(int val : nums)
        {
            total += ceil(val/(double)divisor);
        }

        return (total<=threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6;
        int ans = -1;
        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(isPossible(nums,mid,threshold))
            {
                ans = mid;
               right = mid -1;
            }else
            {
                left = mid +1;
            }
        }

        return ans;
    }
};