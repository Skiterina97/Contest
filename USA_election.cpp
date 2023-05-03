#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>

using namespace std;

bool cmp(pair<string,long long> &x, pair<string,long long> &y)
{
  if (x.second > y.second)
  {
    return true;
  }
  else if (x.second == y.second)
  {
    return x.first < y.first;
  }
  else
  {
    return false;
  }
}

int main()
{
  long long chisloShtatov, chisloGolosov, chislennostShtata;
  string shtatName, kandidatName;
  map <string, map<string, long long>> shtatKandidat;
  std::tr1::unordered_map <string, long long> shtatChislennost, res;
  vector<pair<string,long long>> resultat;

  cin >> chisloShtatov;
  for (long long i = 0; i < chisloShtatov; i++)
  {
    cin >> shtatName >> chislennostShtata;
    shtatChislennost[shtatName] = chislennostShtata;
  }

  cin >> chisloGolosov;
  for (long long i = 0; i < chisloGolosov; i++)
  {
    cin >> shtatName >> kandidatName;
    res[kandidatName] = 0;
    shtatKandidat[shtatName][kandidatName]++;
  }

  for (auto elem: shtatChislennost)
  {
    long long maxInShtat = 0;
    string maxChuvak;
    for (auto iter = shtatKandidat[elem.first].begin(); iter != shtatKandidat[elem.first].end(); iter++)
    {
      if (iter->second > maxInShtat)
      {
        maxInShtat = iter->second;
        maxChuvak = iter->first;
      }
      else if (iter->second == maxInShtat && iter->first < maxChuvak)
      {
        maxChuvak = iter->first;
      }
    }
    res[maxChuvak] = res[maxChuvak] + shtatChislennost[elem.first];
  }

  for (auto elem: res)
  {
    resultat.emplace_back(pair<string,long long>(elem.first, elem.second));
  }

  sort(resultat.begin(), resultat.end(), cmp);

  for (auto elem: resultat)
  {
    cout << elem.first << " " << elem.second << endl;
  }

  return 0;
}
