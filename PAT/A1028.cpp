#include <cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Student{
    int id;
    char name[10];
    int score;
}stu[maxn];
bool cmp1(Student a, Student b){
    return a.id < b.id;           //按准考证排序
}
bool cmp2(Student a, Student b){
    int s = strcmp(a.name, b.name);
    if(s != 0) return s < 0;
}
int main() {

    return 0;
}
