#include<iostream>

using namespace std;

long m, a;

long gcd(long c, long b)
{
  if (b == 0)
  {
    return c;
  }
  return gcd(b, c % b);
}

long Euler (long n)
{
  long rez = n;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      rez -= rez / i;
      while (n % i == 0)
      {
        n /= i;
      }
    }
  }
  if (n > 1)
  {
    rez -= rez / n;
  }
  return rez;
}

long long pow(long k, long n)
{
  if (n == 0)
  {
    return 1;
  }
  long long dop1, dop2;
  dop1 = pow(k, n / 2);
  dop2 = (dop1 % m) * (dop1 % m);

  if (n % 2 == 1)
  {
    dop2 = (k % m) * (dop2 % m);
  }
  return dop2;
}

int main()
{
  cin >> m >> a;

  if (gcd(m, a) != 1)
  {
    cout << -1;
  }
  else
  {
    long phi = Euler(m);
    long obr = 1;

    obr = obr * pow(a, phi - 1) % m;
    cout << obr;
  }

  return 0;
}
