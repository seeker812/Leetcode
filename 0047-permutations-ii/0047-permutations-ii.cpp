class Solution {
public:
    vector<vector<int>>ans;
    void permutation(vector<int>& nums,vector<int>& output,vector<bool>& visited)
    {
        if(output.size() == nums.size())
        {
            ans.push_back(output);
            return;
        }
        int temp = 20;
        for(int i = 0; i < nums.size(); i++)
        {
            if(temp == nums[i] || visited[i] == true)
                continue;
            visited[i] = true;
            output.push_back(nums[i]);
            permutation(nums,output,visited);
            output.pop_back();
            visited[i] = false;
            temp = nums[i];
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>output;
        vector<bool>visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        permutation(nums,output,visited);
        return ans;
    }
};