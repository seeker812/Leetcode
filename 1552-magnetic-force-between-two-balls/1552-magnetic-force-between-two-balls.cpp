class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mforce)
    {
        int balls = 1;
        int lastpos = position[0];
        for(int pos : position)
        {
            if(pos - lastpos >=mforce)
            {
                balls++;
                lastpos = pos;
            }
        }

        return (balls>=m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int left = 0, right = position[n-1]  -position[0];

        while(left<=right)
        {
            int mid = left + (right - left )/2;

            if(isPossible(position,m,mid))
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }

        return right;
    }
};