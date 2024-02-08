class Solution {
public:
    bool isPossible(vector<int>& time, int totalTrips, long long currTime)
    {
        long long total = 0;

        for(int t : time)
        {
            total += (currTime/t);
        }

        return total >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left =1, right = 1e14;
        // long long ans = 0;
        while(left<=right)
        {
            long long mid = left + (right - left)/2;

            if(isPossible(time,totalTrips,mid))
            {
                // ans = mid;
                right = mid -1;
            }else
            {
                left = mid +1;
            }
        }

        return left;
    }
};