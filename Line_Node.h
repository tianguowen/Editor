#ifndef LINE_NODE_H
#define LINE_NODE_H

#include "HString.h"
typedef struct {
	HString Line_String;//�ı��洢
	int Line_Num;//�ı��к�
	int Beg_Pos;//�ı�����ʼ��ַ
}Line_Node;

void DestoryLine_Node(Line_Node *s)
{
	DestoryString(&s->Line_String);
}

void Assign_Line_Node(Line_Node *s, Line_Node t)
{
	StrCopy(&s->Line_String, t.Line_String);
	s->Line_Num = t.Line_Num;
	s->Line_String = t.Line_String;
}
#endif