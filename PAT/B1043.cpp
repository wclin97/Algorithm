#include <cstdio>
#include <iostream>
#include <string>
// PATest
using namespace std;
int hashTable[200] = {0};

int main() {
  string str;
  getline(cin, str);
  int len = str.size();
  for (int i = 0; i < len; i++) {
    hashTable[str[i]]++;
  }  
  while (1) {
    int prtf = 0;
    if (hashTable['P'] > 0) {
      printf("P");
      hashTable['P']--;
      prtf++;
    }
    if (hashTable['A'] > 0) {
      printf("A");
      hashTable['A']--;
      prtf++;
    }
    if (hashTable['T'] > 0) {
      printf("T");
      hashTable['T']--;
      prtf++;
    }
    if (hashTable['e'] > 0) {
      printf("e");
      hashTable['e']--;
      prtf++;
    }
    if (hashTable['s'] > 0) {
      printf("s");
      hashTable['s']--;
      prtf++;
    }
    if (hashTable['t'] > 0) {
      printf("t");
      hashTable['t']--;
      prtf++;
    }
    if (prtf == 0){
      printf("\n");
       break;
    }
  }

  return 0;
}