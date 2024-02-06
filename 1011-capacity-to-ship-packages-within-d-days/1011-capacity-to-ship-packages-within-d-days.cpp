class Solution {
public:
    bool isPossible(vector<int>& weights, int capacity, int days)
    {
        int nships = 1;
        int load = 0;

        for(int w : weights)
        {
            if(capacity<w) return false;
            if(load + w <= capacity)
            {
                load += w;
            }else
            {
                load = w;
                nships++;
            }
        }

        return (nships<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long left = 1, right =0;
        for(int w : weights)
        {
            right += w;
        }

        while(left<=right)
        {
            long mid = left + (right -left )/2;

            if(isPossible(weights, mid, days))
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