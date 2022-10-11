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

// 【2011 年统考真题】
// 求两个等长升序序列A和B的中位数

// 方法一 暴力，时间复杂度O(n)
int M_search(int A[], int B[], int n){
    int temp;
    int count=0;
    for(int i = 0, j = 0;(i < n || j< n)&& count < n;){
        if (A[i] <= B[j]){
            temp = A[i];
            i++;
            count++;
        }
        else{
            temp = B[j];
            j++;
            count++;
        }
    }
    return temp;
}

// 方法二，分别求两个升序序列的中位数记为a和b
// I:若a=b，则a或b即为所求中位数
// II:若a<b，则舍弃A中较小一半和B中较大一半
// III:若a>b，则舍弃A中较大一半和B中较小一半
// 当两个序列各剩余一个元素时，较小者为所求元素
int M_search_opt(int A[], int B[], int n){
    // 分别为A和B的首位，末尾和中位数
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    while(s1 != d1 || s2 != d2){
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2]){
            return A[m1];
        }
        if(A[m1] < B[m2]){
            // 元素个数为奇数，保留中间点
            if((s1 + d1) % 2 == 0){
                s1 = m1;
                d2 = m2;
            }
            else{
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        else{
            if((s1+d1)%2 == 0){
                d1 = m1;
                s2 = m2;
            }
            else{
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}

int main(){
    int A[5] = {2, 4, 6, 8, 20};
    int B[5] = {11, 13, 15, 17, 19};
    cout<<M_search_opt(A, B, 5);
}

// 【2020年统考真题】 
// I:a=b=c时，距离最小
// II:不妨假设a<=b<=c,则|a-b|+|b-c|+|c-a|=2(c-a)
//#define INT_MAX 0x7fffffff
int abs_(int a){
    if(a<0){
        return -a;
    }
    else{
        return a;
    }
}

bool xls_min(int a, int b, int c){
    if(a <= b && a <= c){
        return true;
    }
    else{
        return false;
    }
}

int findMinofTrip(int A[], int n, int B[], int m, int C[], int p){
    int i = 0, j = 0, k = 0, D_min = INT_MAX;
    while(i < n && j < m && k < p && D_min > 0){
        int D = abs_(A[i] - B[j]) + abs_(B[j]-C[k]) + abs_(C[k] - A[i]);
        if(D < D_min){
            D_min = D;
        }
        if (xls_min(A[i], B[j], C[k])){
            i++;
        }
        else{
            if(xls_min(B[j], C[k], A[i])){
                j++;
            }
            else{
                k++;
            }
        }
    }
    return D_min;
}

int main(){
    int S1[3] = {-1, 0, 9};
    int S2[4] = {-25, -10, 10, 11};
    int S3[5] = {2, 9, 17, 30, 41};
    cout<<findMinofTrip(S1, 3, S2, 4, S3, 5);
}