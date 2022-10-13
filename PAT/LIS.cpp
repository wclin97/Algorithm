#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100;
int A[N], dp[N];
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++){
    scanf("%d",&A[i]);
  }
  int ans = -1;  //记录最大的dp[i]
  for(int i = 1; i <= n; i++){   //从小到大计算dp
    dp[i] = 1;                    //边界初始条件
    for(int j = 1; j < i; j++){                     //1.存在j < i, A[j] <= A[i],dp[j] + 1 > dp[i] 后者为边界条件
      if(A[i] >= A[j] && (dp[j] + 1 > dp[i])){     //2.不存在则dp[i] = 1 该值在判断之前已经初始化
        dp[i] = dp[j] + 1;
      }                                 
    }
    ans = max(ans, dp[i]);
  }

  printf("%d\n",ans);
  return 0;
}