#ifndef PAGE_NODE_H
#define PAGE_NODE_H

#include "LinkList_Line.h"

typedef struct {
	LinkList_Line data;//һ��ҳ�ڵ��а���������
	int Page_Num;
	int Beg_Line_Num;
}Page_Node;

void Creat_Page_Node(Page_Node *p, LinkList_Line *s);
void Destory_PageNode(Page_Node *p);
#endif // !PAGE_NODE_H
