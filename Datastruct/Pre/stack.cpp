

#include <iostream>       
#include <stack>          


int main ()
{
  std::stack<int> mystack;

  mystack.push(10);
//  mystack.push(20);

  mystack.top();

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}