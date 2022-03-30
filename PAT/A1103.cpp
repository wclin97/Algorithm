#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//n,p,k  n = n1^p+n2^p......+nk^p

int n, k, p, maxFacSum = -1;
vector<int> fac, ans, temp;
int power(int x ){     //计算p次方
    int ans = 1;
    for(int i = 0; i < p; i++){
        ans *= x;
    }
    return ans;
}
void init(){   //预处理p次方小于n的数并存储
    int i = 0, temp = 0;
    while(temp <= n){
        fac.push_back(temp);
        temp = power(++i);
    }
}
//DFS函数，当前访问fac[index]，nowK为当前选中数
//sum为当前选中数的和，facSum为当前选中的底数之和
void DFS(int index, int nowK, int sum, int facSum){
    if(sum == n &&nowK == k){     //找到满足条件的序列
        if(facSum > maxFacSum){   //底数和更优
            ans = temp; // 更新底数序列
            maxFacSum = facSum;
        }
        return;
    }
    if(sum > n || nowK > k) return;   //超过边界不会产生答案，返回
    if(index - 1 >= 0){ //fac[0]不用选择
        temp.push_back(index);
        DFS(index,nowK + 1, sum + fac[index], facSum + index); //选
        temp.pop_back(); //去掉刚加进去的，相当于没选
        DFS(index - 1, nowK, sum, facSum); //index从大到小开始选保证字典序最大，且不选相当于一次不选，否则递归无法返回
    }
}

int main(){
    scanf("%d%d%d",&n, &k, &p);
    init();
    DFS(fac.size() - 1, 0, 0, 0);
    if(maxFacSum == -1) printf("Impossible\n");
    else{
        printf("%d = %d^%d", n, ans[0], p);
        for(int i = 1; i < ans.size(); i++){
            printf(" + %d^%d",ans[i], p);
        }
    }
    return 0;
}