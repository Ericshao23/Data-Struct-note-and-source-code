// 静态分配
#define MaxSize 10          // 定义最大长度
typedef struct{
    ElemType data[MaxSize]; // 用静态“数组”存放数据元素
    int length;             // 顺序表当前的长度
}SqList;                    // 顺序表类型定义

// 插入
#define MaxSize 20 
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

// 初始化顺序表（静态分配）
void InitList(SqList &L){
    L.length = 0;
}

// 在顺序表中第i处插入元素e
bool ListInset(SqList &L, int i, int e){
    if(i <= 1 || i >= L.lengtg + 1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}
int main(){
    SqList L;
    InitList(L);
    /// 代码, 顺序表中插入元素
    ListInsert(L, 3, 3);
    return 0;
}

// 删除
bool ListDelete(SqList &L, int i, int &e){
    if(i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for(int j = i; j < L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

// 按位查找
ElemType GetElem(SqList L, int i){
    return L.data[i-1];
}

// 按值查找
int LocateElem(SqList L, ElemType e){
    for(int i = 0 ; i < L.length; i++){
        if(L.data[i] == e){
            return i + 1;
        }
    }
    return 0;
}



// 动态分配
#define InitSize 10     // 顺序表的初始长度
typedef struct{
    Elemtype *data;     // 指示动态分配数组的指针
    int MaxSize;        // 顺序表的最大容量
    int length;         // 顺序表的当前长度
}SeqList;               // 顺序表的类型定义（动态分配方式）

// 顺序表初始化（动态分配）
void InitList(SeqList &L){
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组长度
void IncreaseSize(SeqList &L, int len){
    ElemType *p = L.data;
    L.data = (ElemType *)malloc(sizeof(ELemType) * (L.MaxSize + len));
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}
// 动态申请和释放内存空间
// C——申请 malloc
L.data = (Elemtype *)malloc(sizeof(ElemType) * InitSize)
// C++ —— 申请
L.data = new ELemType[InitSize]
// 释放 free\delete

// 结构类型的比较
struct{
    int num;
    int people;
}Customer;

bool isCustomerEqual(Customer a, Cuctomer b){
    if(a.num == b.num && a.people == b.people){
        return true;
    }
    else{
        return false;
    }
}
