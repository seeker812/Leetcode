class Solution {
public:
    int minInsertions(string s) {
        int  n = s.size();
        int ans = 0;
        int open = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                open++;
            }else if(i + 1 < n && s[i] == ')' && s[i+1] == ')' && open == 0)
            {
                ans++;
                i++;
            }else if(i + 1 < n && s[i] == ')' && s[i+1] == ')')
            {
                open--;
                i++;
            }else if(s[i] == ')' && open == 0)
            {
                ans+=2;
            }else
            {
                ans++;
                open--;
            }
        }

        return ans + open*2;
    }
};