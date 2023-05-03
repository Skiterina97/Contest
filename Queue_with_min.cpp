#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  long long n, a;
  vector <long long> komanda;
  stack <long long> stack1, stack1min, stack2, stack2min;
  cin >> n;

  for (long long j = 0; j < n; j++)
  {
    cin >> a;
    komanda.push_back(a);
  }

  long long i = 0;
  while(i < n)
  {
    while (komanda[i] != 0 && i < n)
    {
      stack1.push(komanda[i]);
      if (stack1min.empty() || stack1.top() < stack1min.top())
      {
        stack1min.push(stack1.top());
      }
      else
      {
        stack1min.push(stack1min.top());
      }

      i++;
    }

    if (stack2.empty())
    {
      while(!stack1.empty())
      {
        stack2.push(stack1.top());

        if (stack2min.empty() || stack2.top() < stack2min.top())
        {
          stack2min.push(stack2.top());
        }
        else
        {
          stack2min.push(stack2min.top());
        }

        stack1.pop();
        stack1min.pop();
      }
    }

    while(komanda[i] == 0 && i < n)
    {
      if (!stack2min.empty())
      {
        if (!stack1.empty())
        {
          cout << min(stack1min.top(), stack2min.top()) << endl;
        }
        else
        {
          cout << stack2min.top() << endl;
        }

        stack2min.pop();
        stack2.pop();
      }
      else
      {
        if (!stack1.empty())
        {
          while(!stack1.empty())
          {
            stack2.push(stack1.top());

            if (stack2min.empty() || stack2.top() < stack2min.top())
            {
              stack2min.push(stack2.top());
            }
            else
            {
              stack2min.push(stack2min.top());
            }
           stack1.pop();
           stack1min.pop();
          }

          cout << stack2min.top() << endl;

          stack2min.pop();
          stack2.pop();
        }
        else
        {
          cout << -1 << endl;
        }
      }

      i++;
    }
  }

  return 0;
}
