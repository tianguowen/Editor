#ifndef PAGELIST_H
#define PAGELIST_H


#include "Page_Node.h"

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

//½Ó¿Ú
Statue Make_Head_Node_Page(Link_Page P);
void Assign_Page_Node(Link_Page p, Elemtype_Page e);
Statue Make_Node_Page(Link_Page p, Elemtype_Page e);
Statue InitList(LinkList_Page *L);
void Free_Node_Page(Link_Page *p);
Statue DestroyList(LinkList_Page *L);
Statue ClearList(LinkList_Page *L);
int Sum_Char_Num_Page(LinkList_Line *L);
int Sum_Line_Num_Page(LinkList_Line L);
int Sum_Line_Num_Page_Link(Link_Line s);
int Sum_Char_Num_Page_Link(Link_Line s);


#endif // !PAGELIST_H
