#ifndef LINE_NODE_H
#define LINE_NODE_H

#include "HString.h"
typedef struct {
	HString Line_String;//文本存储
	int Line_Num;//文本行号
	int Beg_Pos;//文本的起始地址
}Line_Node;

void DestoryLine_Node(Line_Node *s);
void Assign_Line_Node(Line_Node *s, Line_Node t);
#endif