#ifndef LINE_NODE_H
#define LINE_NODE_H

#include "HString.h"
typedef struct {
	HString Line_String;//�ı��洢
	int Line_Num;//�ı��к�
	int Beg_Pos;//�ı�����ʼ��ַ
}Line_Node;

void DestoryLine_Node(Line_Node *s);
void Assign_Line_Node(Line_Node *s, Line_Node t);
#endif