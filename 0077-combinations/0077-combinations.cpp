class Solution {
public:
    vector<vector<int>> ans;
    void comb(int n, int k, vector<int>& output,int last)
    {
        
        if(k==0)
        {
            ans.push_back(output);
            return;
        }

        for(int i = last+1; i <= n; i++)
        {
            output.push_back(i);
            comb(n,k-1,output,i);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> output;
        comb(n,k,output,0);

        return ans;
    }
};