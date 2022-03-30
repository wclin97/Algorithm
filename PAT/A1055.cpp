#include <cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int Age[maxn]  ={0};
struct Person{
    int name;
    int age;
    int worth;
}all[maxn], valid[maxn];
bool cmp(Person a, Person b){
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age > b.age;
    return strcmp(a.name, b.name) < 0;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s%d%d",all[i].name, &all[i].age, &all[i].worth);
    }
    int validNum = 0;
    for(int i = 0; i <= k; i++){
        if(Age[all[i].age] < 100){
            Age[all[i].age]++;
            valid[validNum++] = all[i];    //将成员all的所有项复制到valid中
        }
    }
    int m, ageL, ageR;
    for(int i = 0; i <= k; i++){
        scanf("%d%d%d", &m, &ageL, &ageR);
        printf("Case #%d:\n", i);
        int printfNum = 0;
        for(int j = 0; j < validNum && printfNum < m; j++){
            if(valid[j].age)
        }
    }
    return 0;
}
