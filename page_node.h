#ifndef PAGE_NODE_H
#define PAGE_NODE_H

#include "LinkList_Line.h"

typedef struct {
	LinkList_Line data;//一个页节点中包含行链表
	int Page_Num;
	int Beg_Line_Num;
}Page_Node;

void Creat_Page_Node(Page_Node *p,LinkList_Line *s)
{
	p->data = *s;
	p->Beg_Line_Num = 0;
	p->Page_Num = 0;
}

void Destory_Page_Node(Page_Node *p)
{
	DestroyList(&p->data);
	free(p);
}
#endif // !PAGE_NODE_H
