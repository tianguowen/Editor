#ifndef PAGELIST_H
#define PAGELIST_H

#define ONE_LINE_CHAR_NUM 100 //һ������100���ַ�
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

//�ӿ�
Statue Make_Head_Node_Page(Link_Page P);
void Assign_Page_Node(Link_Page p, Elemtype_Page e);
Statue Make_Node_Page(Link_Page p, LinkList_Line *e);
Statue Change_Page_Beg_Data(Link_Page s, int Beg_Beg_Line_Num, int Beg_Page_Num);//�ı�s�Ժ��ҳ����Ϣ������ҳ���ڲ�������Ϣ����ı�
Statue Append_Page(LinkList_Page *L, Link_Page s);
Statue Make_Book(LinkList_Page *L, char *s);//s�����ļ���·������
Statue InitList(LinkList_Page *L);
void Free_Node_Page(Link_Page p);
int Sum_Char_Num_Page(LinkList_Page *L);
int Sum_Line_Num_Page(LinkList_Page *L);
int Sum_Line_Num_Page_Link(Link_Page s);
int Sum_Char_Num_Page_Link(Link_Page s);
Statue Pos_Page_And_Line(LinkList_Page *page, Link_Page p, Link_Line l, int Del_Line_Num);
Statue Change_Page_Line_Information(Link_Page p, int Beg_Line_Num, int Beg_char_pos);//�ı�������е�ҳ�漰�е���Ϣ
Statue Dele_Line_Page(LinkList_Page *L, int Del_Line_Num, int Need_del_line_Num);//ɾ��һ�к������������������
#endif // !PAGELIST_H
