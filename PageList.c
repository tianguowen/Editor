#include "PageList.h"

Statue Make_Head_Node_Page(Link_Page P)
{
	P = (Link_Page*)malloc(sizeof(Link_Page));
	P->next = NULL;
	if (P)
		return OK;
	else
	{
		return ERROR;
	}
}
void Assign_Page_Node(Link_Page p, Elemtype_Page e)
{
	Link_Line s1 = (p->Page_data).data.head->next;
	Link_Line s2 = e.data.head->next;
	while (s1 != NULL)
	{
		Assign_Line(s1, s2);
		s1 = s1->next;
		s2 = s2->next;
	}
}
Statue Make_Node_Page(Link_Page p, LinkList_Line *e)
{
	p = (Link_Page*)malloc(sizeof(Link_Page));
	Creat_Page_Node(&(p->Page_data), e);
	p->next = NULL;
}
Statue Change_Page_Beg_Data(Link_Page s, int Beg_Beg_Line_Num, int Beg_Page_Num)
{
	int i = 0;
	int	j = 0;
	Link_Page ptr = s;
	while (ptr != NULL)
	{
		ptr->Page_data.Beg_Line_Num = Beg_Beg_Line_Num + i;
		ptr->Page_data.Page_Num = Beg_Page_Num + j;
		++j;
		i += ptr->Page_data.data.len;
		ptr = ptr->next;
	}
}
Statue Append_Page(LinkList_Page *L, Link_Page s)
{
	L->tail->next = s;
	Link_Page p = s;
	int index = 1;
	while (p->next != NULL) {
		p = p->next;
		++index;
	}
	int Incre_Page_Num = L->Page_Len;
	int Incre_Beg_Line_Num = Sum_Line_Num_Page(L);
	L->tail = p;
	L->Page_Len += index;
	Link_Page ptr = s;
	Change_Page_Beg_Data(ptr, Incre_Beg_Line_Num + 1, Incre_Page_Num + 1);//
	return OK;
}
Statue Make_Book(LinkList_Page *L,char *s)//s代表文件的路径名称
{
	FILE *fp;//定义文件句柄
	char text[1024];//text读取文件的缓冲数组
	fp=fopen(s, "w");
	int index = 0;
	char *Line_Text[ONE_PAGE_LINE_NUM];//定义存储的字符串数组
	for (int i = 0; i < ONE_PAGE_LINE_NUM; ++i)
	{
		Line_Text[index] = (char*)malloc(ONE_LINE_CHAR_NUM * sizeof(char));
	}//分配Line_Text的内存空间；
	while (1)
	{
		while (fgets(text, ONE_LINE_CHAR_NUM, fp) != NULL&&index < ONE_PAGE_LINE_NUM)
		{
			strcpy(Line_Text[index],text);//字符串赋值；
			++index;
		}
		LinkList_Line *L_Line;
		Init_Line_Page(L_Line, Line_Text);
		Link_Page *p;
		Make_Node_Page(p, L_Line);
		Append_Page(L, L_Line);
		if (index != ONE_PAGE_LINE_NUM - 1)
			break;
		index = 0;
		int i = 0;
		while (i < ONE_PAGE_LINE_NUM)
		{
			memset(Line_Text[i], NULL, sizeof(Line_Text[0]));
		}//全部清空Line_Text字符串数组，留作下一次循环使用
	}
	for (int i = 0; i < ONE_PAGE_LINE_NUM; ++i)
	{
		free(Line_Text[index]);
	}//释放Line_Text的内存空间；
}
Statue InitList(LinkList_Page *L)
{
	L = (LinkList_Page*)malloc(sizeof(LinkList_Page));
	Link_Page *p;
	Make_head_Node(p);
	L->head = p;
	L->tail = p;
	L->Page_Len = 0;
	return OK;
}
void Free_Node_Page(Link_Page p)
{
	Destroy_Page_Node(&p->Page_data.data);//先调用LinkList_Line的析构函数
	free(p);
}
int Sum_Char_Num_Page(LinkList_Page *L)
{
	int sum = 0;
	Link_Page ptr = L->head;
	while (ptr != NULL)
	{
		sum += Sum_Char_Num_Line(&ptr->Page_data.data);
		ptr = ptr->next;
	}
	return sum;
}
int Sum_Line_Num_Page(LinkList_Page *L)
{
	int sum = 0;
	Link_Page ptr = L->head;
	while (ptr != NULL)
	{
		sum += ptr->Page_data.data.len;
		ptr = ptr->next;
	}
	return sum;
}
int Sum_Line_Num_Page_Link(Link_Page s)
{
	Link_Page ptr = s;
	int sum = 0;
	while (ptr != NULL)
	{
		sum += Sum_Line_Num_Line(ptr->Page_data.data);
		ptr = ptr->next;
	}
	return sum;
}
int Sum_Char_Num_Page_Link(Link_Page s)
{
	int sum = 0;
	Link_Page ptr = s;
	while (ptr != NULL)
	{
		sum += Sum_Char_Num_Line(&ptr->Page_data.data);
		ptr = ptr->next;
	}
	return sum;
}
Statue Pos_Page_And_Line(LinkList_Page *page,Link_Page p, Link_Line l, int Del_Line_Num)
{
	Link_Page ptr = page->head;
	int sum;
	if (Del_Line_Num > Sum_Line_Num_Page(page))
		return ERROR;
	int sum = 0;
	while (ptr != NULL)
	{
		
	}
}
Statue Dele_Line_Page(LinkList_Page *L, int Del_Line_Num)//删除一行后对整本书进行行序调整
{
	Link_Page ptr = L->head;

}