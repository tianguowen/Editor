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
Statue Make_Node_Page(Link_Page p, LinkList_Line *e)
{
	p = (Link_Page*)malloc(sizeof(Link_Page));
	Creat_Page_Node(&(p->Page_data), e);
	p->next = NULL;
}
int Sum_Line_Num_Page(LinkList_Page *L)
{
	int sum = 0;
	Link_Page ptr = L->head;
	while (ptr != NULL)
	{
		sum += ptr->Page_data.data.len;
		ptr = ptr->next;
	}
	return sum;
}
Statue Change_Page_Beg_Data(Link_Page s, int Beg_Beg_Line_Num, int Beg_Page_Num)
{
	int i = 0;
	int	j = 0;
	Link_Page ptr = s;
	while (ptr != NULL)
	{
		ptr->Page_data.Beg_Line_Num = Beg_Beg_Line_Num + i;
		ptr->Page_data.Page_Num = Beg_Page_Num + j;
		++j;
		i += ptr->Page_data.data.len;
		ptr = ptr->next;
	}
}
Statue Append_Page(LinkList_Page *L, Link_Page s)
{
	L->tail->next = s;
	Link_Page p = s;
	int index = 1;
	while (p->next != NULL) {
		p = p->next;
		++index;
	}
	int Incre_Page_Num = L->Page_Len;
	int Incre_Beg_Line_Num = Sum_Line_Num_Page(L);
	L->tail = p;
	L->Page_Len += index;
	Link_Page ptr = s;
	Change_Page_Beg_Data(ptr, Incre_Beg_Line_Num + 1, Incre_Page_Num + 1);//
	return OK;
}