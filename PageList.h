#ifndef PAGELIST_H
#define PAGELIST_H

#include "Page_Node.h"

typedef Page_Node Elemtype;
typedef int Statue;

typedef struct PNode {
	Elemtype Page_data;
	struct PNode *next;
}LNode_Page,*Link_Page,*Position_Page;

typedef struct {
	Link_Page head;
	Link_Page tail;
	int Page_Len;
}LinkList_Page;

//½Ó¿Ú
Statue Make_Head_Node_Page(Link_Page *P);
Statue Make_Node_Page(Link_Page *p, ElemType e);
Statue InitList(LinkList_Page *L);
void Free_Node_Page(Link_Page *p);
Statue DestroyList(LinkList_Page *L);
Statue ClearList(LinkList_Page *L);


#endif // !PAGELIST_H
