#include <iostream>
#include <cstring>
#include <stack>
#include <map>

int isBalance(char *exp)
{
    // create map
    std::map<char, char> mapping;
    mapping[')'] = '(';
    mapping['}'] = '{';
    mapping[']'] = '[';
    
    // create map iteratior
    std::map<char, char>::iterator itr;
    
    // create stack
    std::stack<char> stk;
    
    for(int i=0; i < strlen(exp); i++)
    {
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            stk.push(exp[i]);
        }
        else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if(stk.empty())
            {
                return false;
            }
            else
            {
                char temp = stk.top();
                itr = mapping.find(exp[i]);
                if(temp == itr -> second) // itr->first is key, itr->second is value
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return stk.empty() ? true : false;
}


int main()
{
   char A[] = "{([a+b]*[c-d])/e}";
   std::cout << isBalance(A) << std::endl;

   char B[] = "{([a+b]}*[c-d])/e}";
   std::cout << isBalance(B) << std::endl;

   char C[] = "{([{a+b]*[c-d])/e}";
   std::cout << isBalance(C) << std::endl;
    return 0;
}
