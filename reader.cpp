
/*
const int maxn = 10000;
int dp[maxn] = {-1};

int F(int n){
  if(n ==0 || n ==1) return 1;
  if(dp[n] != -1) return dp[n];
  else{
    dp[n] = F(n - 1) + F(n - 2);
  }
}

*/

//状态转移方程 dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];

//重叠子问题就是 一个问题可以分解为若干个子问题，而且其中的子问题会重复出现（overlapping substructure）

//最优子问题就是 一个问题 的最优解  可以由其子问题的最优解构造出来 （optimal substructure）


//数塔问题（二叉树找出根节点到叶子结点的最长路径）
//dp数组存放最长长度 f数组为该节点权值

//dp[1][1] = max(dp[2][1], dp[2][2]) + f[1][1];

//dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];

#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int main(){
  int n;
  scanf("%d",&n);
  for(;;){

    //此处将数塔存入二维数组中,n为层数
  }

  //边界,将最底层的f的dp设置为本身
  for(int j = 1; j <= n; j++){
    dp[n][j] = f[n][j];
  }

  //从最底层向上计算

  for(int i = n - 1; i >= 1; i--){
    for(int j = 1;j <= i; j++){
      dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];//状态转移方程
    }
  }
  printf("%d is the max lcs\n",dp[1][1]);
  return 0;
}