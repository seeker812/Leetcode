class Solution {
public:
    int perform(char ch, int a , int b)
    {
        if(ch == '+')
            return a + b;
        else if(ch == '-')
            return a - b;
        else if(ch == '*')
            return a * b;
        else
            return a/b;
    }

    int precedence(char ch)
    {
        if(ch == '/' || ch == '*')
            return 2;
        if(ch == '+' || ch == '-')
            return 1;
        
        return 0;
    }

    string refine(string s)
    {
        string ans = "";
        for(int idx = 0; idx < s.size(); idx++)
        {
            char ch = s[idx];
            if(ch == ' ')
                continue;
            if(ch == '+')
            {
                if(ans.size() == 0 || ans.back() == '(')
                    continue;
                if(ans.back()== '+' || ans.back() == '-')
                    continue;
                else
                    ans.append("+");
            }else if(ch == '-')
            {
                if(ans.size() == 0 || ans.back() == '(')
                    ans.append("0-");
                else if(ans.back() == '-')
                    ans[ans.size()-1] = '+';
                else if(ans.back() == '+')
                    ans[ans.size()-1] = '-';
                else
                    ans.append("-");
            }else
            {
                ans.push_back(ch);
            }
        }

        return ans;


    }
    int calculate(string expression) {

        expression = refine(expression);
        cout<<"new"<<expression;
        stack<char>operators;
	    stack<int>operand;

        for(int idx = 0; idx < expression.size(); idx++)
        {
            char ch = expression[idx];
            if(ch>= '0' && ch <= '9')
            {
                string val = "";
                while(expression[idx] <='9' && expression[idx]>='0')
                {
                    val+=expression[idx];
                    idx++;
                }
                idx--;
                operand.push(stoi(val));
            }else if(ch == '(')
            {
                operators.push(ch);
            }else if( ch == ')')
            {
                while(operators.top() != '(')
                {
                    int b  = operand.top();
                    operand.pop();
                    int a = operand.top();
                    operand.pop();

                    operand.push(perform(operators.top(),a,b));
                    operators.pop();
                }
                operators.pop();
            }else if( ch == '/' || ch == '*' || ch == '+' || ch == '-')
            {
                
                while(operators.size() > 0 && operators.top() != '(' && precedence(operators.top()) >= precedence(ch))
                {
                    int b  = operand.top();
                    operand.pop();
                    int a = operand.top();
                    operand.pop();

                    operand.push(perform(operators.top(),a,b));
                    operators.pop();
                }

                operators.push(ch);
            }
        }

         while(operators.size() > 0 )
                {
                    int b  = operand.top();
                    operand.pop();
                    int a = operand.top();
                    operand.pop();

                    operand.push(perform(operators.top(),a,b));
                    operators.pop();
                }
        return operand.top();

    }
};