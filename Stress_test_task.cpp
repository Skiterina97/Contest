#include <iostream>
#include <set>

using namespace std;

int main()
{
  int n, error = 0;
  string slovo, otvetPeti;

  (cin >> n).get();
  set <string> udarnoeSlovo, slovarnoeSlovoBezUdareniya;

  for (int i = 0; i < n; i++)
  {
    getline(cin, slovo);
    udarnoeSlovo.insert(slovo);
    for (int j = 0; j < slovo.size(); j++)
    {
      if (isupper(slovo[j]))
      {
        slovo[j] = tolower(slovo[j]);
        slovarnoeSlovoBezUdareniya.insert(slovo);
        break;
      }
    }
  }

  getline(cin, otvetPeti);

  size_t pos = 0, globalPos = 0;
  string word;

  while ((pos = otvetPeti.find(" ", globalPos)) != string::npos)
  {
    word = otvetPeti.substr(globalPos, pos - globalPos);
    if (word == "")
    {
      globalPos++;
      continue;
    }

    if (udarnoeSlovo.find(word) == udarnoeSlovo.end())
    {
      int udarenie = 0;
      for (int j = 0; j < word.size(); j++)
      {
        if (isupper(word[j]))
        {
          word[j] = tolower(word[j]);
          udarenie++;
        }
      }
      if (udarenie != 1)
      {
        error++;
      }
      else if (slovarnoeSlovoBezUdareniya.find(word) != slovarnoeSlovoBezUdareniya.end())
      {
        error++;
      }
    }
    globalPos = pos + 1;
  }

  string lastWord;
  lastWord = otvetPeti.substr(globalPos, string::npos);

  if (lastWord != "" && udarnoeSlovo.find(lastWord) == udarnoeSlovo.end())
  {
    int udarenie = 0;
    for (int j = 0; j < lastWord.size(); j++)
    {
      if (isupper(lastWord[j]))
      {
        lastWord[j] = tolower(lastWord[j]);
        udarenie++;
      }
    }
    if (udarenie != 1)
    {
      error++;
    }
    else if (slovarnoeSlovoBezUdareniya.find(lastWord) != slovarnoeSlovoBezUdareniya.end())
    {
      error++;
    }
  }

  cout << error;

  return 0;
}
