#ifndef PAGE_NODE_H
#define PAGE_NODE_H

#include "LinkList_Line.h"

typedef struct {
	LinkList_Line data;//һ��ҳ�ڵ��а���������
	int Page_Num;
	int Beg_Line_Num;
}Page_Node;

#endif // !PAGE_NODE_H
