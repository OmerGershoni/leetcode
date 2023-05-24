// https://leetcode.com/problems/valid-parentheses/

#include <stack> 

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> leftParentheses;

        for (int i = 0; i < s.size(); ++i)
        {
            if (isleftParenthesis(s[i]))
            {
                leftParentheses.push(s[i]);
            }
            else if (false == leftParentheses.empty())
            {
                if (leftParentheses.top() != getMatchParenthesis(s[i]))
                {
                    return false;
                }
                else
                {
                   leftParentheses.pop(); 
                }
            }
            else
            {
                return false;
            }
        } 

        return leftParentheses.empty();
    }

    bool isleftParenthesis(char c)
    {
        return (c == '(' || c == '[' || c == '{');
    }

    char getMatchParenthesis(char leftParenthesis)
    {
        switch(leftParenthesis)
        {
            case ')':
                return '(';
            case ']':
                return '[';                
            case '}':
                return '{';
            default:
                return '\0';
        }
    }   
};
