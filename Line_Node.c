#include"Line_Node.h"

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