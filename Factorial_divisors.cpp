#include<iostream>
#include<vector>

using namespace std;

int main()
{
  long n, dop, counter, kolvo = 1;
  cin >> n;

  if (n == 1)
  {
    cout << 1;
    return 0;
  }

  // решето Ёратосфена
  vector<long> helpPrime(n + 1, 1);

  helpPrime[0] = helpPrime[1] = 0;

  for (int i = 2; i <= n; ++i)
  {
    if (!helpPrime[i] || i * 1ll * i > n)
    {
      continue;
    }
    for (int j = i * i; j <= n; j += i)
    {
      helpPrime[j] = 0;
    }
  }

  // все простые числа от 1 до n
  vector<long> prime;

  for (long i = 2; i <= n + 1; i++)
  {
    if (helpPrime[i] == 1)
    {
      prime.push_back(i);
    }
  }

  for (long i = 0; i < prime.size(); i ++)
  {
    long counter1 = 0;

    for (long j = 2; j <= n; j++)
    {
      dop = j;
      while (dop % prime[i] == 0)
      {
        counter1++;
        dop = dop / prime[i];
      }
    }

    kolvo *= counter1 + 1;
  }

  cout << kolvo;

  return 0;
}
