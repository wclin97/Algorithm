#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100;
//队列q，起点入队。while非空时，在while循环中访问并将下一层未入栈过得节点入队，将他们的层号加1
//01矩阵，求出所有1组成的块数量

struct node{
    int x, y;
}Node;
int X[] = {0, 0, 1, -1};
int Y[] = {0, 0, 1, -1};
int n, m; //mxn matrix
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

bool judge(int x, int y){
    if(x >= n || x < 0 || y>=m || y < 0) return false;

     if(matrix[x][y] == 0 || x < 0 || inq[x][y] == true) return false;

    return true;
}
void BFS(int x, int y){
    queue<node> Q;
    Node.x = x, Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)){
                Node.x = newX, Node.y = newY;
                Q.push(Node);
                inq[newX][newY]  = true;
            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            scanf("%d",&matrix[x][y]);
        }
    }
    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(matrix[x][y] == 1 && inq[x][y] == false){
                ans++;
                BFS(x, y);
            }
        }
    }
    printf("%d\n", ans);
        return 0;
}