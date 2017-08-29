#ifndef LINE_NODE_H
#define LINE_NODE_H

#include "HString.h"
typedef struct {
	HString Line_String;//文本存储
	int Line_Num;//文本行号
	int Beg_Pos;//文本的起始地址
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