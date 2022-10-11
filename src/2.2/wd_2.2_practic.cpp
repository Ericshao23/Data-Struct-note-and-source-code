// 【2010年统考真题】
// 将数组中的元素循环左移
#include<iostream>
#include<cstdio>

using namespace std;
// 将数组ab得到数组ba(a表示数组中的前p个元素，b表示数组中剩余的n-p个元素)
// 求逆
void Reverse(int R[], int begin, int end){
    int i, temp;
    for(i = 0; i < (end - begin) / 2; i++){
        temp = R[begin + i];
        R[begin + i] = R[end - i];
        R[end -i] = temp;
    }
}

//数组左移p位
void Converse(int R[], int n, int p){
    Reverse(R, 0, p - 1);
    Reverse(R, p, n - 1);
    Reverse(R, 0, n - 1);
}


int main(){
    int p;
    cin>>p;
    int R[7] = {1,2,3,4,5,6,7};
    Converse(R, 7, 4);
    for(int i = 0; i < 7; i++){
        cout<<R[i]<<endl;
    }
}