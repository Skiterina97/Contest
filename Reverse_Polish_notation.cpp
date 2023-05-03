#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  string polskayaZapis;
  vector <int> stack;

  getline(cin, polskayaZapis);

  for (auto c: polskayaZapis)
  {
    switch (c)
    {
      case ' ':
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        stack.push_back(c - 48);
        break;
      case '+':
        {
          int a, b;
          a = stack.back();
          stack.pop_back();
          b = stack.back();
          stack.pop_back();
          stack.push_back(a + b);
          break;
        }
      case '-':
        {
          int a, b;
          a = stack.back();
          stack.pop_back();
          b = stack.back();
          stack.pop_back();
          stack.push_back(b - a);
          break;
        }
      case '*':
        {
          int a, b;
          a = stack.back();
          stack.pop_back();
          b = stack.back();
          stack.pop_back();
          stack.push_back(a * b);
          break;
        }
    }
  }

  cout << stack.back();

  return 0;
}
