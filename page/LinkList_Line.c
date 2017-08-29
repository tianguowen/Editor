#include "LinkList_Line.h"
//接口实现


Statue Make_head_Node(Link_Line P) {
	if (P) {
		P = (LNode_Line*)malloc(sizeof(LNode_Line));
		P->next = NULL;
		return OK;
	}
	else
		return ERROR;
}
Statue MakeNode(Link_Line P, ElemType e) {
	if (P) {
		P = (LNode_Line*)malloc(sizeof(LNode_Line));
		StrCopy(&(P->data).Line_String,e.Line_String);
		(P->data).Line_Num = (P->data).Beg_Pos = 0;
		P->next = NULL;
		return OK;
	}
	else
		return ERROR;
}
void FreeNode(Link_Line P)
{
	DestoryLine_Node(&P->data);
	free(P);
}
Statue InitList(LinkList_Line *L) {
	L = (LinkList_Line*)malloc(sizeof(LinkList_Line));
	LNode_Line *p;
	Make_head_Node(p);
	L->head = p;
	L->tail = p;
	L->len = 0;
	return OK;
}
Statue DestroyList(LinkList_Line *L) {
	while (L->head != NULL) {
		LNode_Line *p = L->head;
		L->head = L->head->next;
		p->next = NULL;
		FreeNode(p);
	}
	L->head = L->tail = NULL;
	L->len = 0;
	free(L);
}
Statue ClearList(LinkList_Line *L) {
	while (L->head != L->tail) {
		LNode_Line *p = L->head;
		L->head = L->head->next;
		p->next = NULL;
		FreeNode(p);
	}
	memset(L->head,0,sizeof(LNode_Line));
	L->len = 0;
}
int Sum_Char_Num(LinkList_Line *L)
{
	Link_Line ptr = L->head;
	int sum = 0;
	while (ptr != NULL)
	{
		sum += (ptr->data).Line_String.length;
		ptr = ptr->next;
	}
}
int Sum_Line_Num(LinkList_Line L)
{
	ListLength(L);
}
int Sum_Line_Num_Link(Link_Line s)
{
	Link_Line ptr = s;
	int index = 0;
	while (ptr != NULL)
	{
		++index;
	}
	return index;
}
int Sum_Char_Num_Link(Link_Line s)
{
	Link_Line ptr = s;
	int index = 0;
	while (ptr != NULL)
	{
		index += (ptr->data).Line_String.length;
	}
	return index;
}
void Insert_Change_After(Link_Line s,int add_line_num,int add_beg_pos)
{
	Link_Line ptr = s;
	while (ptr != NULL)
	{
		(ptr->data).Line_Num += add_line_num;
		(ptr->data).Beg_Pos += add_beg_pos;
		ptr = ptr->next;
	}
}
void Delete_Change_After(Link_Line s, int sub_line_num, int sub_beg_pos)
{
	Link_Line ptr = s;
	while (ptr != NULL)
	{
		(ptr->data).Line_Num -= sub_line_num;
		(ptr->data).Beg_Pos -= sub_beg_pos;
		ptr = ptr->next;
	}
}
int Get_Link_Length(Link_Line s)
{
	int i = 0;
	Link_Line ptr = s;
	while (ptr != NULL)
	{
		++i;
		ptr = ptr->next;
	}
	return i;
}
void Change_Line_Beg_Data(Link_Line s, int beg_line_num, int beg_beg_pos)
{
	int i = 0;
	int	j = 0;
	Link_Line ptr = s;
	while (ptr != NULL)
	{
		(ptr->data).Line_Num = beg_line_num+i;
		(ptr->data).Beg_Pos = beg_beg_pos+j;
		++i;
		j += (ptr->data).Line_String.length;
	}
}
Statue Assign_Node(Link_Line h, Link_Line s)
{
	Assign_Line_Node(&h->data, s->data);
	h->next = s->next;
}
Statue Append(LinkList_Line *L, Link_Line s) {
	L->tail->next = s;
	LNode_Line *p = s;
	int index = 1;
	while (p->next!= NULL) {
		p = p->next;
		++index;
	}
	int incre_Num = Sum_Char_Num(L);
	int incre_Line_Num = L->len;//s开头的链表需要增加的行号；
	L->tail = p;
	L->len += index;
	Link_Line ptr = s;
	Change_Line_Beg_Data(ptr, incre_Line_Num+1, incre_Num+1);//
	return OK;
}
Statue InsBefore(LinkList_Line *L, Link_Line p, Link_Line s) {
	int s_length = Get_Link_Length(s);
	Link_Line ptr_s = s;
	Change_Line_Beg_Data(ptr_s, (p->data).Line_Num, (p->data).Beg_Pos);
	LNode_Line *ptr = L->head;
	while (ptr->next != p)
	{
		ptr = ptr->next;
	}
	ptr->next = s;
	Link_Line ptr_s = s;
	while (ptr_s->next != NULL)
	{
		ptr_s = ptr_s->next;
	}
	ptr_s->next = p;
	Insert_Change_After(p, Sum_Line_Num_Link(s), Sum_Char_Num_Link(s));
	p = s;
	return OK;
}
Statue Dele_Link(LinkList_Line *L, Link_Line p, int Del_Line_Num, Link_Line s)
{
	Link_Line ptr;
	PriorPos(*L,p,ptr);
	Link_Line p1 = ptr;
	int index = 0;
	while (index != Del_Line_Num)
	{
		p1 = p1->next;
	}
	s = ptr->next;
	ptr->next = p1->next;
	p1->next = NULL;
	Delete_Change_After(ptr->next, Sum_Line_Num_Link(s), Sum_Char_Num_Link(s));
	return OK;
}
Statue ListEmpty(LinkList_Line L) {
	if (L.head==L.tail)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int ListLength(LinkList_Line L) {
	int index = 0;
	LNode_Line *p = L.head;
	while (p ->next!= NULL) {
		p = p->next;
		++index;
	}
	return index;
}
Position_Line PriorPos(LinkList_Line L, Link_Line p,Link_Line q) {
	if (p == L.head)
		return NULL;
	else {
		q = L.head;
		while (q->next != p) {
			q = q->next;
		}
		return q;
	}
}
Position_Line NextPos(LinkList_Line L, Link_Line p) {
	if (p->next == NULL)
		return NULL;
	else
		return p->next;
}
Statue Change_String(Link_Line p,char *s)
{
	int i = (p->data).Line_String.length;
	StrAssign(&(p->data).Line_String, s);
	int j = (p->data).Line_String.length - i;
	Insert_Change_After(p->next, 0, j);
}
Statue Change_String_Copy(Link_Line p, HString s)
{
	int i = (p->data).Line_String.length;
	StrCopy(&(p->data).Line_String, s);
	int j = (p->data).Line_String.length - i;
	Insert_Change_After(p->next, 0, j);
}
Statue Change_String_Replace(Link_Line p, HString T, HString V)
{
	int i = (p->data).Line_String.length;
	Replace(&(p->data).Line_String, T,V);
	int j = (p->data).Line_String.length - i;
	Insert_Change_After(p->next, 0, j);
}
Statue Change_String_Insert(Link_Line p, int pos, HString T)
{
	int i = (p->data).Line_String.length;
	StrInsert(&(p->data).Line_String, pos,T);
	int j = (p->data).Line_String.length - i;
	Insert_Change_After(p->next, 0, j);
}
Statue Change_String_Delete(Link_Line p, int pos, int len)
{
	int i = (p->data).Line_String.length;
	StrDelete(&(p->data).Line_String, pos,len);
	int j = (p->data).Line_String.length - i;
	Insert_Change_After(p->next, 0, j);
}