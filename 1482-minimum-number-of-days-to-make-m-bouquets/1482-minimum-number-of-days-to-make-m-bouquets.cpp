class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int bouqet, int adj, int day)
    {
        int nbouqet = 0;
        int flower = 0;
        for(int bloom : bloomDay)
        {
            if(bloom<=day)
            {
                flower++;
                if(flower==adj)
                {
                    nbouqet++;
                    flower=0;
                }
            }else{
                flower=0;
            }
        }

        return (nbouqet>=bouqet);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int left = 1, right = INT_MIN;
        for(int day : bloomDay)
        {
            right = max(right, day);
        }
        
        if(n/k < m)
            return -1;
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(isPossible(bloomDay,m,k,mid))
            {
                right = mid -1;
            }else{
                left = mid +1;
            }
        }
        return left;
    }
};