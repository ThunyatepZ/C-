#include <iostream>
#include <stack>
using namespace std;

int oper(char p)
{
    if (p == '+' || p == '-')
    {
        return 1;
    }
    if (p == '*' || p == '/')
    {
        return 2;
    }
    if (p == '^')
    {
        return 3;
    }
    return 0;
}

int main()
{
    string equation;
    stack<char> st;
    string result;
    getline(cin, equation);

    for (int i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '(')
        {
            st.push(equation[i]);
        }
        else if (equation[i] == ')')
        {
            while (!st.empty())
            {
                if (st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                else
                {
                    st.pop();
                    break;
                }
            }
        }
        else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')
        {
            while (!st.empty() && oper(equation[i]) <= oper(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(equation[i]);
        }
        else
        {
            result += equation[i];
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << result;
}