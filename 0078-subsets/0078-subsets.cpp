class Solution {
public:
    vector<vector<int>>ans;
    void powerset(vector<int>& nums,int idx, vector<int>& output)
    {
        if(idx==nums.size())
        {
            ans.push_back(output);
            return;
        }

        output.push_back(nums[idx]);
        powerset(nums,idx+1,output);
        output.pop_back();
        powerset(nums,idx+1,output);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        powerset(nums,0,temp);

        return ans;
    }
};