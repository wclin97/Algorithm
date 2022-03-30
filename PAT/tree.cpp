const int maxn = 1000;

struct node{
    int data;
    int child[maxn];   //由于最大未知，浪费空间 ，可以用vector代替    vector child;
}Node[maxn];