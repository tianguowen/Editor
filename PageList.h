#ifndef PAGELIST_H
#define PAGELIST_H

#include"Page_Node.h"

typedef Page_Node Elemtype;
typedef int Statue;

typedef struct PNode {
	Elemtype Page_data;
	struct PNode *next;
}LNode_Page,*Link_Page,*Position_Page;

#endif // !PAGELIST_H
