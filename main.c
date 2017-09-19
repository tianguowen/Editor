#include "PageList.h"
int main()
{
	char *s = "file.txt";
	LinkList_Page *p;
	InitList_Page(&p);
	Make_Book(p, s);
	Print_Page(p);
}