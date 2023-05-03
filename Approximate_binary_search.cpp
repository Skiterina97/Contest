#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, a, m, b; //число элементов массива, элементы массива, число запросов, элементы запроса
  vector<int> chisla, zapros;

  //задаём массив чисел
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    chisla.push_back(a);
  }

  sort(chisla.begin(), chisla.end());

  //задаём массив запросов
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> b;
    zapros.push_back(b);
  }

  for (int i = 0; i < zapros.size(); i++)
  {
    if (zapros[i] >= chisla[n - 1])
    {
      zapros[i] = chisla[n - 1];
      continue;
    }

    if (zapros[i] <= chisla[0])
    {
      zapros[i] = chisla[0];
      continue;
    }


    int k, l(-1), r(n), dop;
    dop = zapros[i];

    while (r - l > 1)
    {
      k = (l + r) / 2;
      if (chisla[k] < zapros[i])
      {
        l = k;
      }
      else
      {
        r = k;
      }
    }

    if (zapros[i] - chisla[l] <= chisla[r] - zapros[i])
    {
      zapros[i] = chisla[l];
    }
    else
    {
      zapros[i] = chisla[r];
    }
  }

  for (int i = 0; i < zapros.size(); i++)
  {
    cout << zapros[i] << endl;
  }

  return 0;
}
