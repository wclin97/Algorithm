#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct Student{
    char id[15];
    int score;
    int rank;
    int place;
    int place_rank;

}stu[30010];
bool cmp(Student a, Student b){
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}
int main() {
    int n,k,num = 0; //n考场数，k为该考场人数,num考生总数
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &k);
        for(int j = 1; j <= k; j++){
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].place = i;
            num++;
        }
        sort(stu + num - k,stu + num ,cmp);
        stu[num - k].place_rank = 1;
        for(int j = num -k + 1; j < num; j++){
            if(stu[j].score == stu[j - 1].score)
                stu[j].place_rank = stu[j - 1].place_rank;
            else
                stu[j].place_rank = j + 1 - (num - k);
        }
    }
    printf("%d\n",num);
    sort(stu, stu + num, cmp);
    int r = 1;
    for(int i = 0; i < num; i++){
        if(i > 0 && stu[i].score != stu[i -1].score){
            r = i + 1;
        }
        printf("%s %d %d %d",stu[i].id, r, stu[i].place, stu[i].place_rank);
        if(i - 1 <= num) printf("\n");
    }

    return 0;
}
