#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*struct student{
    int id;
    int c;
    int m;
    int e;
    int a; //平均分
}stu[3000];
int n, m;   //总人数 和 查询人数
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i <n; i++){
         scanf("%d %d %d %d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
        &stu[i].a = (&stu[i].c + &stu[i].m + &stu[i].e) / 3
    }

    
    return 0;
}*/
struct Student{
    int id;
    int grade[4];
}stu[2010];

char course[4] = {'A', 'C', 'M', 'E'}; //按优先级输出
int Rank[10000000][4] = {0};   //对应4门课程的排名 acme
int now;   //用now表示当前按now号排序stu数组

bool cmp(Student a, Student b){
    return a.grade[now] > b.grade[now];
}

int main(){
    int m, n;
    scanf("%d %d",&n, &m);
    for(int i = 0;i < n; i++){
        scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
    }
    for(now = 0; now < 4; now++){
        sort(stu, stu + n, cmp);
        Rank[stu[0].id][now] = 1;
        for(int i = 1; i < n; i++){
            if(stu[i].grade[now] == stu[i - 1].grade[now]){
                Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
            }else{
                Rank[stu[i].id][now] = i + 1;
            }
        }
    }
    int query;  //查询考生的id；    单词的意思是疑问
    for(int i = 0; i < m; i++){
        scanf("%d", &query);
        if(Rank[query][0] == 0){      //应为没有id的考生平均分都是0
            printf("N/A\n");
        }else{
            int k = 0;
            for(int  j  =  0;  j  <  4;  j++) {
                if(Rank[query][j]  <  Rank[query][k]){
                    k  =  j;
                }
            }
            printf("%d %c\n", Rank[query][k], course [k]);

        }
    }



    return 0;

}


