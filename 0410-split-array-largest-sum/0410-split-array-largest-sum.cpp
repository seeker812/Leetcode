class Solution {
public:
    bool isPossible(vector<int>& books, int allowedStuds, long maxLoad,int N)
    {
        int currLoad = 0;
        int reqStuds = 1;
        
        for(int i = 0; i<N; i++)
        {
            if(currLoad + books[i] <= maxLoad)
            {
                currLoad +=books[i];
            }else
            {
                currLoad = books[i];
                reqStuds++;
            }
        }
        
        return (reqStuds <= allowedStuds);
    }
    int splitArray(vector<int>& A, int M) {
        int N = A.size();
        if(N<M)
            return -1;
        long left = INT_MIN, right =0;
        for(int i = 0; i<N; i++)
        {
            right += A[i];
            left = max((int)left,A[i]);
            
        }
        
        // int ans = 0;
        while(left<=right)
        {
            long mid = left + (right - left)/2;
            
            if(isPossible(A,M,mid,N))
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