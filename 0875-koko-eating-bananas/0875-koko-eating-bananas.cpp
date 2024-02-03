class Solution {
public:
    bool isPossible(vector<int>& piles, int hours, int speed)
    {
        long sum = 0;

        for(long banana : piles)
        {
            sum += banana / speed;
            if((banana % speed)!=0)
                sum++;
        }

        if(sum<=hours)
            return true;
        
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxp = INT_MIN;
        for(int banana : piles)
        {
            maxp = max(maxp,banana);
        }
        int left = 1, right = maxp;
        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(isPossible(piles,h,mid))
            {
                right = mid -1;
            }else
            {
                left = mid +1;
            }
        }

        return left;
    }
};