class Solution {
public:
    vector<vector<int>> ans;
    void csum(vector<int>& nums,int target, int idx, vector<int>& output)
    {
        if(target<0)
            return;
        if(idx==nums.size())
        {
            if(target==0)
                ans.push_back(output);
            
            return;
        }

        output.push_back(nums[idx]);
        csum(nums,target-nums[idx],idx+1,output);
        output.pop_back();

        if(output.size()>0 && output.back()==nums[idx])
            return;
        
        csum(nums,target,idx+1,output);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>output;
        sort(candidates.begin(),candidates.end());
        csum(candidates,target,0,output);

        return ans;
    }
};