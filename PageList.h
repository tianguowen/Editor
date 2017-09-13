#ifndef PAGELIST_H
#define PAGELIST_H

#define ONE_LINE_CHAR_NUM 100 //一行中有100个字符
#include "Page_Node.h"
#include <string.h>

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

//接口
Statue Make_Head_Node_Page(Link_Page P);
void Assign_Page_Node(Link_Page p, Elemtype_Page e);
Statue Make_Node_Page(Link_Page p, LinkList_Line *e);
Statue Change_Page_Beg_Data(Link_Page s, int Beg_Beg_Line_Num, int Beg_Page_Num);
Statue Append_Page(LinkList_Page *L, Link_Page s);
Statue Make_Book(LinkList_Page *L, char *s);
Statue InitList_Page(LinkList_Page *L);
void Free_Node_Page(Link_Page p);
int Sum_Char_Num_Page(LinkList_Page *L);
int Sum_Line_Num_Page(LinkList_Page *L);
int Sum_Line_Num_Page_Link(Link_Page s);
int Sum_Char_Num_Page_Link(Link_Page s);
int If_Jump_The_Page(LinkList_Page *page, Link_Page p, Link_Page p2, int Beg_Line_Num, int Need_Del_Line_Num, int Jump_Page_Num);
Statue Pos_Page_And_Line(LinkList_Page *page, Link_Page p, Link_Line l, int Del_Line_Num);
Statue Change_Page_Line_Information(Link_Page p, int Beg_Line_Num, int Beg_char_pos);
Statue Pos_Page_Num(LinkList_Page *page, Link_Page p, int Del_Page_Num);
Statue Prio_Page_Link(LinkList_Page *L, Link_Page p, Link_Page p1);
Statue Dele_Page_Link(LinkList_Page *L, Link_Page p, int Del_Page_Num, int Need_Del_Page_Num);
Statue Dele_Line_Page(LinkList_Page *L, Link_Line get_line, int Del_Line_Num, int Need_del_line_Num);
Statue Insert_Page_Bef(LinkList_Page *L, Link_Page p, Link_Page q);
Statue Split_Page(LinkList_Page *L, int Line_Num);
Statue Insert_Line_Page(LinkList_Page *L, int Ins_Line_Num, Link_Line Ins_Line);
void Print_Page(LinkList_Page *P);
#endif // !PAGELIST_H
