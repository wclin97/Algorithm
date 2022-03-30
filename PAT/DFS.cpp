//n件物品，重量存在w[i]，价值为c[i]，背包容量V，求最大价值n从1->20
#include <cstdio>
const int  maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];  //w为重量，c为价值
using namespace std;
 void DFS(int index, int sumW, int sumC){
     if(index == n){   //返回接口
         if(sumW <= V && sumC > maxValue) maxValue = sumC;
     }
     return;
    //岔路
    DFS(index + 1, sumW, sumC);   //不选index号物品
    DFS(index + 1, sumW + w[index], sumC + c[index]);
 }

 int main(){
     //scanf();   扫描输入参数 
     DFS(0, 0, 0);   //从头遍历
     //printf();   打印最大价值
     return 0;
 }