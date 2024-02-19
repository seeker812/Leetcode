class Solution {
public:
    vector<vector<int>>ans;
    void permutation(vector<int>& nums,int idx, vector<bool>& visited, vector<int>& output)
    {
        if(idx==nums.size())
        {
            ans.push_back(output);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                output.push_back(nums[i]);
                permutation(nums,idx+1,visited,output);
                output.pop_back();
                visited[i] = false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>visited(nums.size(),false);
        vector<int>output;
        permutation(nums,0,visited,output);

        return ans;
    }
};