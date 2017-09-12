#ifndef LINKLIST_LINE_H
#define LINKLIST_LINE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Line_Node.h"
#define TRUE 1;
#define FALSE 0;
#define OK 1;
#define ERROR 0
#define GREATER 1
#define LESS -1
#define EQUAL 0
#define ONE_PAGE_LINE_NUM 20//每页设置20行
typedef Line_Node ElemType;
typedef int Statue;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode_Line,*Link_Line,*Position_Line;

typedef struct {
    Link_Line head;
	Link_Line tail;
	int len;
}LinkList_Line;

//接口
Statue Make_head_Node(Link_Line P);
Statue MakeNode(Link_Line P,ElemType e);
Statue MakeNode_Char(Link_Line p, char *s);
void FreeNode(Link_Line P);
Statue InitList(LinkList_Line *L);
Statue Init_Line_Page(LinkList_Line *L,char *s[ONE_PAGE_LINE_NUM]);
Statue DestroyList(LinkList_Line *L);
Statue ClearList(LinkList_Line *L);
int Sum_Char_Num_Line(LinkList_Line *L);
int Sum_Line_Num_Line(LinkList_Line L);
int Sum_Line_Num_Line_Link(Link_Line s);
int Sum_Char_Num_Line_Link(Link_Line s);
int Sum_Line_Num_To_Tail(Link_Line s);
void Insert_Change_After(Link_Line s,int add_line_num,int add_beg_pos);//插入节点后后续行号的修改，后续行号和地址是完整的
void Delete_Change_After(Link_Line s, int sub_line_num, int sub_beg_pos);//删除节点后后续行号修改，后续行号和地址是完整的
int Get_Link_Length(Link_Line s);//给定一个节点测定他后续的链表长度
void Change_Line_Beg_Data(Link_Line s, int beg_line_num, int beg_beg_pos);//对以s为头节点的链表进行行号和起始地址赋值，该链表的行号和地址都为空或者不完整的
Statue Assign_Node(Link_Line h, Link_Line s);
Statue Append(LinkList_Line *L, Link_Line s);
Statue Append_Link_Line(Link_Line s1, Link_Line s2);
Statue InsBefore(LinkList_Line *L, Link_Line p, Link_Line s);
Statue Dele_Link(LinkList_Line *L, Link_Line p, int Del_Line_Num,Link_Line s);
Statue ListEmpty(LinkList_Line L);
int ListLength(LinkList_Line L);
Position_Line PriorPos(LinkList_Line *L, Link_Line p,Link_Line q);
Position_Line NextPos(LinkList_Line L, Link_Line p);
Statue Change_String(Link_Line p, char *s);
Statue Change_String_Copy(Link_Line p, HString s);
Statue Change_String_Replace(Link_Line p, HString T, HString V);
Statue Change_String_Insert(Link_Line p, int pos, HString T);
Statue Change_String_Delete(Link_Line p, int pos, int len);

#endif
