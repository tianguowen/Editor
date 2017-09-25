#include "PageList.h"
int main()
{
	char *s = "file.txt";
	LinkList_Page *p;
	InitList_Page(&p);
	Make_Book(p, s);
	int char_num = Count_Real_Char_Num(p);
	int word_num = Count_Real_Word_Num(p);
	int word_some_num = Count_some_word_num(p, "charge");
	printf("the all char num is %d\n", char_num);
	printf("the all word num is %d\n", word_num);
	printf("the he word num is %d", word_some_num);
}