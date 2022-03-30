#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int hashTable[30] = {0};

int  main(){
    string str;
    int len; 
    getline(cin,str);
    len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z') hashTable[str[i] - 'a']++;
        if(str[i] >= 'A' && str[i] <= 'Z') hashTable[str[i] - 'A']++;
    }
    int k = 0;
    for(int i = 0; i < 26; i++){
        if(hashTable[i] > hashTable[k]) k = i;
            
    }
    printf("%c %d\n", 'a' + k, hashTable[k]);
    return 0;
}