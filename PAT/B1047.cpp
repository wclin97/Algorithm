#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int hashTable[1001] = {0};

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    int len = str.size();
    int num = 0;
    int flag = 0;
    int score = 0;
    for (int j = 0; j < len; j++) {
      if (str[j] != '-' && flag == 0)
        num = num * 10 + (str[j] - '0');
      else if (str[j] == '-')
        flag++;

      if (str[j] = ' ') {
        j++;
        while (j < len) {
          score = score * 10 + str[j] - '0';
        }
      }
    }
    hashTable[num] += score;
  }
  int maxsoc = 0;
  int team;
  for (int i = 1; i <= 1000; i++) {
    if (hashTable[i] > maxsoc) {
      maxsoc = hashTable[i];
      team = i;
    }
  }
  printf("%d %d", team, maxsoc);

  return 0;
}




//scanf(%d%-d %d,&team,&teamnum,&score);