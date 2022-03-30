#include <cstdio>


int partition(int A[], int left, int right){
    int temp = A[left];
    while(left < right) {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] < temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

//快速排序(递归实现)，left与right处置为序列首尾下标
void quickSort(int A[], int left, int right){
    if(left < right){
        int pos = partition(A, left, right);     //left位置已对，分别对左边和和右边递归
        quickSort(A, left, pos - 1);
        quickSort(A, pos + 1, right);
    }
}
int main() {
    
    return 0;
}

