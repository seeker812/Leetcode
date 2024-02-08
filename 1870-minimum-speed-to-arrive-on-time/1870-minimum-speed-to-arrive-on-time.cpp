class Solution {
public:
    bool isPossible(vector<int>& dist, int speed, double hour)
    {
        double total = 0;
        for(int i = 0; i<dist.size()-1; ++i)
        {
            total += ceil((double)dist[i]/speed);
        }

        total += (double)dist.back()/speed;

        return total <=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int  left  =1, right = 1e7;
        int ans = -1;
        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(isPossible(dist,mid,hour))
            {
                ans = mid;
                right = mid-1;
            }else
            {
                
                left = mid +1;
            }
        }

        return ans;
    }
};