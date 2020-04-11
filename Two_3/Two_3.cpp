#include <iostream>
/*双链表的操作*/
typedef struct DNode {
    int data;
    struct DNode* prior, * next;
};


/*单链表的操作*/
typedef struct LNode //建立结构体
{
    int data;     //elementype表示一种数据类型，可能是int/char等等
    struct LNode* next;   //next 指针，用于链表结构指向下一个节点
}LNode, * LinkList;


LinkList List_HeadInsert(LinkList& L) {
    LNode* s; int x;
    L = (LinkList)malloc(sizeof(LNode));//创建头节点
    L->next = NULL;//初始空链表
    int a[7] = { 0,10,5,15,5,30,25 };
    for (int i = 0; i < 7; i++)
    {
        s = (LNode*)malloc(sizeof(LNode));//创建节点
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}//创建链表

/*p40-1*/
void  Del_X(LinkList &L,int x) { 
    LNode* s;
    if (L == NULL) return;
    if (L->data == x) {
        s = L;
        L = L->next;
        free(s);
        Del_X(L, x);
    }
    else
    {
        Del_X(L->next, x);
    }
}

/*40-2*/
void Del_X2(LinkList &L, int x) {
    LNode* p = L->next, * r = L, * q;
    while (p != NULL) {
        if (p->data != x) {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}


void List(LinkList L)  //打印链表
{
    LNode* p;
    p = L;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}



int main()
{
    LNode* L;
    List_HeadInsert(L);
    printf("操作前：\n");
    List(L);
    printf("+++++++++++++++++++\n");
    printf("操作后：\n");
    Del_X2(L, 5);
    List(L);

}


