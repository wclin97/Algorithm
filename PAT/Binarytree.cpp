#include <cstdio>
#include<queue>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;

    int layer;   //非必须
};
node* root = NULL;

//build a new node and insert
node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;   //返回该节点，使用时 node1->lchild = newNode(i);

}
//search and modify: judge nownode ,judge lchild, judge rchild until mownode is NULL;
void search(node* root, int x, int newdata){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        root->data = newdata;
    }
    search(root->lchild, x, newdata);
    search(root->rchild, x, newdata);
}

//insert
void insert(node* &root, int x){     //attention &, 修改root指向的内容时不需要
    if(root == NULL){
        root = newNode(x);
        return;        // void return means finish function 
    }
    if(/*turn left*/1){
        insert(root->lchild, x);
    }else{
        insert(root->rchild, x);
    }
}

//build a tree
node* Create(int data[], int n){
    node* root = NULL;               //define root is NULL not no exist.
    for(int i = 0; i < n; i++){
        insert(root, data[i]);
    }
    return root;
}
//binarytree traverse
void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d\n",root->data);

    preorder(root->lchild);
    preorder(root->rchild);
}
//inorder
void inorder(node* root){
    if(root == NULL){
        return;
    }
    preorder(root->lchild);
    printf("%d\n",root->data);
    preorder(root->rchild);
}

//postorder
void postorder(node* root){
    if(root == NULL){
        return;
    }
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d\n",root->data);
}

//layerorder
void layerorder(){
    queue<node*> q;  //队列里存地址,如果队列使用node型当需要修改队列元素时就无法修改，node*可以通过地址访问
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);

    }
}

//pre and in order string rebuild tree;
int pre[100], in[100];
node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL;  // 先序序列长度小于0,说明该分支建树完成
    }
    node* root = new node;    //新建一个节点存储根节点
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == pre[preL]){     //在中序序列中找到根节点
            break;  
        }
    }
    int numLeft = k - inL;
    
    root->lchild = create(preL + 1, preL + numLeft, inL, k -1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

    return root;
}
//先中求后序列



//二叉树的静态实现
/*
struct node{
typename data;
int lchild;
int rchild;
}Node[maxn];
*/