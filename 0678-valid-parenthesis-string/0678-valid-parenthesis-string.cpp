class Solution {
public:
    
    bool checkValidString(string s) {
        
        int star = 0;
        stack<int>st;
        for(char ch : s)
        {
            if(ch == '(')
                st.push(star);
            else if(ch == '*')
                star++;
            else
            {
                if(st.size() > 0)
                    st.pop();
                else if(star > 0)
                    star--;
                else
                    return false;
            }
        }

        while(st.size() > 0)
        {
            int rstar = star - st.top();
            if(rstar > 0)
                star--;
            else
                return false;
        
            st.pop();
        }
        return true;
    }
};