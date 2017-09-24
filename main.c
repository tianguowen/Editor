#include "PageList.h"
int main()
{
	char *s = "file.txt";
	LinkList_Page *p;
	InitList_Page(&p);
	Make_Book(p, s);
	Print_Page(p);
	int char_num = Count_Real_Char_Num(p);
	int word_num = Count_Real_Word_Num(p);
	printf("the all char num is %d\n", char_num);
	printf("the all word num is %d\n", word_num);
}