#include "PageList.h"

Statue Make_Head_Node_Page(Link_Page P)
{
	P = (Link_Page*)malloc(sizeof(Link_Page));
	P->next = NULL;
	if (P)
		return OK;
	else
	{
		return ERROR;
	}
}
void Assign_Page_Node(Link_Page p, Elemtype_Page e)
{
	Link_Line s1 = (p->Page_data).data.head->next;
	Link_Line s2 = e.data.head->next;
	while (s1 != NULL)
	{
		Assign_Line(s1, s2);
		s1 = s1->next;
		s2 = s2->next;
	}
}
Statue Make_Node_Page(Link_Page p, LinkList_Line e)
{
	p = (Link_Page*)malloc(sizeof(Link_Page));
	Creat_Page_Node(&(p->Page_data), e);
	p->next = NULL;
}