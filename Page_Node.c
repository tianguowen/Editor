#include "Page_Node.h"


void Creat_Page_Node(Page_Node *p, LinkList_Line *s)
{
	p->data = *s;
	p->Beg_Line_Num = 0;
	p->Page_Num = 0;
}

void Destory_PageNode(Page_Node *p)
{
	DestroyList(&p->data);
	free(p);
}