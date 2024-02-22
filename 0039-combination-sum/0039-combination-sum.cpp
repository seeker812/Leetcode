class Solution {
public:
vector<vector<int>>ans;
    void csum(vector<int>& nums, int target,int idx, vector<int>& output)
    {
        
        if(target<0||idx==nums.size())
            return; 
        if(target==0)
        {
            ans.push_back(output);
            return;
        }
        output.push_back(nums[idx]);
        csum(nums,target-nums[idx],idx,output);
        output.pop_back();
        csum(nums,target,idx+1,output);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>output;
        csum(candidates,target,0,output);

        return ans;
    }
};