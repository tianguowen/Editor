#ifndef PAGELIST_H
#define PAGELIST_H

#define ONE_LINE_CHAR_NUM 100 //一行中有100个字符
#include "Page_Node.h"
#include <string.h>

typedef Page_Node Elemtype_Page;
typedef int Statue;

typedef struct PNode {
	Elemtype_Page Page_data;
	struct PNode *next;
}LNode_Page,*Link_Page,*Position_Page;

typedef struct {
	Link_Page head;
	Link_Page tail;
	int Page_Len;
}LinkList_Page;

//接口
Statue Make_Head_Node_Page(Link_Page P);
void Assign_Page_Node(Link_Page p, Elemtype_Page e);
Statue Make_Node_Page(Link_Page p, Elemtype_Page e);
Statue Change_Page_Beg_Data(Link_Page s, int Beg_Beg_Line_Num, int Beg_Page_Num);
Statue Append_Page(LinkList_Page *L, Link_Page s);
Statue Make_Book(LinkList_Page *L, char *s);//s代表读入文件的路径名称。
Statue InitList(LinkList_Page *L);
void Free_Node_Page(Link_Page *p);
Statue ClearList(LinkList_Page *L);
int Sum_Char_Num_Page(LinkList_Page *L);
int Sum_Line_Num_Page(LinkList_Page *L);
int Sum_Line_Num_Page_Link(Link_Page s);
int Sum_Char_Num_Page_Link(Link_Page s);
Statue Append_Page(LinkList_Page *L, Link_Page s);


#endif // !PAGELIST_H
