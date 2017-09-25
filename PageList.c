#include "PageList.h"

Statue Make_Head_Node_Page(Link_Page *P)
{
	*P = (Link_Page)malloc(sizeof(LNode_Page));
	(*P)->Page_data.Beg_Line_Num = 0;
	(*P)->Page_data.Page_Num = 0;
	(*P)->next = NULL;
	if (*P)
	{
		return OK;
	}
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
		Assign_Node(s1, s2);
		s1 = s1->next;
		s2 = s2->next;
	}
}
Statue Make_Node_Page(Link_Page *p, LinkList_Line *e)
{
	*p = (Link_Page)malloc(sizeof(LNode_Page));
	Creat_Page_Node(&((*p)->Page_data), e);
	(*p)->next = NULL;
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

	int Incre_Page_Num = L->Page_Len;
	int Incre_Beg_Line_Num = Sum_Line_Num_Page(L);
	L->tail->next = s;
	Link_Page p = s;
	int index = 1;
	while (p->next != NULL) {
		p = p->next;
		++index;
	}
	Link_Page t = L->tail;
	L->tail = p;
	L->Page_Len += index;
	Link_Page ptr = s;
	Change_Page_Beg_Data(ptr, Incre_Beg_Line_Num + 1, Incre_Page_Num + 1);//�ı�ҳ����Ϣ
	if (t == L->head)
		Change_Page_Line_Information(ptr, 1, 1);
	else
	{
		Change_Page_Line_Information(ptr,t->Page_data.data.tail->data.Line_Num + 1,t->Page_data.data.tail->data.Beg_Pos + ptr->Page_data.data.tail->data.Line_String.length);
	}//�ı�ҳ�ڵ�����Ϣ
	return OK;
}
Statue Make_Book(LinkList_Page *L,char *s)//s�����ļ���·������
{
	char text[1024];//text��ȡ�ļ��Ļ�������
	FILE *fp=fopen(s, "r");
	printf("what fuck");
	int index = 0;
	char **Line_Text;//����洢���ַ�������
	Line_Text = (char**)malloc(ONE_PAGE_LINE_NUM * sizeof(char*));
	for (int i = 0; i < ONE_PAGE_LINE_NUM; ++i)
	{
		Line_Text[i] = (char*)malloc(ONE_LINE_CHAR_NUM * sizeof(char));
	}//����Line_Text���ڴ�ռ䣻
	while (1)
	{
		int i = 0;
		int if_break = 0;
		while (index < ONE_PAGE_LINE_NUM)
		{
			i = 0;
			while ((text[i] = fgetc(fp)) != '.'&&text[i]!=EOF)
			{
				++i;
			}
			if (text[i] == EOF)
			{
				if_break = 1;
				break;
			}
			text[i + 1] = '\0';
			strcpy(Line_Text[index], text);
			++index;
			memset(text, 0, sizeof(text));
		}
		LinkList_Line *L_Line;
		Init_Line_Page(&L_Line, Line_Text);
		Link_Page p;
		Make_Node_Page(&p, L_Line);
		Append_Page(L, p);
		if (if_break)
			break;
		index = 0;
		i = 0;
		int k=0;
		while (k < ONE_PAGE_LINE_NUM)
		{
			memset(Line_Text[k], 0, sizeof(Line_Text[0]));
			++k;
		}//ȫ�����Line_Text�ַ������飬������һ��ѭ��ʹ��
	}
	for (int j = 0; j < sizeof(Line_Text); ++j)
	{
		free(Line_Text[j]);
	}//�ͷ�Line_Text���ڴ�ռ䣻
	free(Line_Text);
}
Statue InitList_Page(LinkList_Page **L)
{
	*L = (LinkList_Page*)malloc(sizeof(LinkList_Page));
	Link_Page p;
	Make_Head_Node_Page(&p);
	(*L)->head = p;
	(*L)->tail = p;
	(*L)->Page_Len = 0;
	return OK;
}
void Free_Node_Page(Link_Page p)
{
	Destory_PageNode(&p->Page_data);
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
int If_Jump_The_Page(LinkList_Page *page,Link_Page *p,Link_Page *p2,int Beg_Line_Num, int Need_Del_Line_Num,int Jump_Page_Num)
//�����ж�Ҫɾ���������Ƿ��ҳ�������ҳ�򷵻ظ�Jump_Page_Num,����Ҫɾ��ҳ����ʼ�ڵ�ָ�뷵�ظ�p;
{
	Link_Line l;
	Pos_Page_And_Line(page, p, &l, Beg_Line_Num);
	int Finish_Line_Num = Beg_Line_Num + Need_Del_Line_Num;
	Link_Page ps = *p;
	*p = (*p)->next;
	int index = 0;
	while (ps->next->Page_data.data.tail->data.Line_Num <= Finish_Line_Num)
	{
		++index;
		ps = ps->next;
	}
	*p2 = ps;
	Jump_Page_Num = index;
	if (*p2 == *p || *p2 == (*p)->next)
		return 0;
	else
		return 1;
}
Statue Pos_Page_And_Line(LinkList_Page *page,Link_Page *p, Link_Line *l, int Del_Line_Num)
{
	Link_Page ptr = page->head;
	if (Del_Line_Num > Sum_Line_Num_Page(page))
		return ERROR;
	int sum = 0;
	while (ptr != NULL)
	{
		if ((ptr->next)->Page_data.Beg_Line_Num > Del_Line_Num)
			break;
		else
			ptr = ptr->next;
	}
	*p = ptr;
	Link_Line ltr = (ptr->Page_data).data.head->next;
	while (ltr != NULL)
	{
		if (ltr->data.Line_Num == Del_Line_Num)
			break;
		else
			ltr = ltr->next;
	}
	*l = ltr;
}
Statue Change_Page_Line_Information(Link_Page p, int Beg_Line_Num,int Beg_char_pos)//�ı�������е�ҳ�漰�е���Ϣ
{
	Link_Page ptr = p;
	while (ptr != NULL)
	{
		Change_Line_Beg_Data(ptr->Page_data.data.head->next, Beg_Line_Num, Beg_char_pos);
		Beg_Line_Num += Sum_Line_Num_Line(ptr->Page_data.data) + 1;
		Beg_char_pos += Sum_Char_Num_Line(&ptr->Page_data.data) + 1;
		ptr = ptr->next;
	}
}
Statue Pos_Page_Num(LinkList_Page *page, Link_Page *p, int Del_Page_Num)
{
	Link_Page ptr = page->head->next;
	while (ptr != NULL)
	{
		if (ptr->Page_data.Page_Num == Del_Page_Num)
		{
			*p = ptr;
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}
}
Statue Prio_Page_Link(LinkList_Page *L, Link_Page p, Link_Page *p1)//��λ��ҳָ��p֮ǰ��һ���ڵ�ָ��
{
	Link_Page ptr = L->head;
	while (ptr->next != p)
	{
		ptr = ptr->next;
	}
	*p1 = ptr;
	return OK;
	if (!(*p1))
		return ERROR;
}
Statue Dele_Page_Link(LinkList_Page *L, Link_Page *p,int Del_Page_Num, int Need_Del_Page_Num)
//ֱ�ӽ���ɾ��ҳ�Ĳ���,p���ڻ�ȡɾ���е�����
{
	Link_Page ptr;
	Pos_Page_Num(L, &ptr, Del_Page_Num);//��ȡ����Ҫɾ����ҳ��ʼ�ڵ�
	Link_Page s = ptr;//s��Ҫɾ��ҳ��������һ���ڵ�
	int index = 1;
	while (index != Need_Del_Page_Num)
	{
		s = s->next;
	}
	Link_Page prio_ptr;
	Prio_Page_Link(L, ptr, &prio_ptr);
	*p = ptr;
	prio_ptr->next= s->next;
	s->next = NULL;
	Change_Page_Beg_Data(prio_ptr->next, prio_ptr->Page_data.data.tail->data.Line_Num + 1, prio_ptr->Page_data.Page_Num + 1);
	//�ı�������ĺ���ҳ������Ϣ
	Change_Page_Line_Information(prio_ptr->next, prio_ptr->Page_data.data.tail->data.Line_Num + 1,
		prio_ptr->Page_data.data.tail->data.Beg_Pos + prio_ptr->Page_data.data.tail->data.Line_String.length);
	//�ı�������������е�ҳ������Ϣ
}
Statue Dele_Line_Page(LinkList_Page *L, Link_Line *get_line,int Del_Line_Num,int Need_del_line_Num)//ɾ��һ�к������������������
{
	Link_Page ptr;
	Link_Line ltr;
	Pos_Page_And_Line(L, &ptr, &ltr, Del_Line_Num);
	Link_Page ptr1,ptr2;//ptr1��Ҫɾ��ҳ����ʼ�ڵ㣬ptr2���ս�ڵ㡣
	int Jump_Page_Num;//Ҫɾ��ҳ�ڵ�ĳ���
	If_Jump_The_Page(L, &ptr1, &ptr2, Del_Line_Num, Need_del_line_Num, Jump_Page_Num);
	Link_Line s;//���ڱ�����ɾ�����нڵ�
	if (ptr->next == NULL)//�����һҳɾ���У����Բ���Ҫ�ı����ҳ�����ݣ�ֻ��Ҫ������ҳ���ڵ�����Ϣ
	{
		if (ptr->Page_data.data.head->next == ltr)
		{
			Dele_Link(&ptr->Page_data.data, ltr, Need_del_line_Num, &s);
			ptr->Page_data.Beg_Line_Num = ptr->Page_data.data.head->next->data.Line_Num;
		}
		else
		{
			Dele_Link(&ptr->Page_data.data, ltr, Need_del_line_Num, &s);
		}
	}
	else if(Sum_Line_Num_To_Tail(ltr)>=Need_del_line_Num)//ɾ���е���Ŀ����絽��һҳȥ������ֻ���ڱ�����ɾ������Ϣ
	{
		Dele_Link(&ptr->Page_data.data, ltr, Need_del_line_Num, &s);
		Change_Page_Line_Information(ptr->next,
			ptr->Page_data.data.tail->data.Line_Num + 1,
			ptr->Page_data.data.tail->data.Beg_Pos + ptr->Page_data.data.tail->data.Line_String.length);
		Change_Page_Beg_Data(ptr->next, 
			ptr->Page_data.data.tail->data.Line_Num + 1,ptr->Page_data.Page_Num+1);
	}
	else if (Jump_Page_Num == 0)//���ҳ����ֻ�ǿ絽��һҳ�����ǲ���Ҫɾҳ����
	{
		int next_page_del_num = Need_del_line_Num - Sum_Line_Num_To_Tail(ltr);
		Dele_Link(&ptr->Page_data.data, ltr, Sum_Line_Num_To_Tail(ltr),&s);
		Link_Line s2;
		Dele_Link(&ptr->next->Page_data.data, ptr->Page_data.data.head->next, next_page_del_num, &s2);
		Change_Page_Line_Information(ptr->next, ptr->Page_data.data.tail->data.Line_Num + 1,
			ptr->Page_data.data.tail->data.Beg_Pos + ptr->Page_data.data.tail->data.Line_String.length);
		Change_Page_Beg_Data(ptr->next, ptr->next->Page_data.data.head->next->data.Line_Num,
			ptr->next->Page_data.Page_Num);
		Append_Link_Line(s, s2);
	}
	else//���ҳ�������м��ҳ�����Խ�����ҳ��ҳ��ɾ������
	{
		Link_Page p;//���ڼ��䱻ɾ����ҳ��Ϣ��
		Dele_Page_Link(L, &p, ptr1->Page_data.Page_Num, Jump_Page_Num);//ֱ��ɾ����ҳ�ڵ㲢������������
		int next_page_del_num = Need_del_line_Num - Sum_Line_Num_Page_Link(p) - Sum_Line_Num_To_Tail(ltr);
		Dele_Link(&ptr->Page_data.data, ltr, Sum_Line_Num_To_Tail(ltr), &s);
		Link_Line s2;
		Dele_Link(&ptr->next->Page_data.data, ptr->Page_data.data.head->next, next_page_del_num, &s2);
		Change_Page_Line_Information(ptr->next, ptr->Page_data.data.tail->data.Line_Num + 1,
			ptr->Page_data.data.tail->data.Beg_Pos + ptr->Page_data.data.tail->data.Line_String.length);
		Change_Page_Beg_Data(ptr->next, ptr->next->Page_data.data.head->next->data.Line_Num,
			ptr->next->Page_data.Page_Num);
		Link_Line ps = s;
		while(ps->next!=NULL)
		{
			ps = ps->next;
		}
		p->Page_data.data.tail->next = s2;
		ps->next = p->Page_data.data.head->next;//��ɾ���ĵ�����Ϣȫ����ᵽs������ȥ
	}
	*get_line = s;
	return OK;
}
Statue Insert_Page_Bef(LinkList_Page *L, Link_Page p,Link_Page q)
//��q��ָ��ҳ��ڵ����p�ڵ�֮ǰ
{
	Link_Page l;
	Prio_Page_Link(L, p, &l);//l��Ϊp�ڵ��ǰһ���ڵ�
	p->next = l->next;
	l->next = p;//�Ѿ��������µ�ҳ��ڵ�
	//����������Ҫ�ı�ҳ�漰ҳ���ڵ�����Ϣ
	Change_Page_Beg_Data(p, l->Page_data.data.tail->data.Line_Num + 1, l->Page_data.Page_Num + 1);
	Change_Page_Line_Information(p, l->Page_data.data.tail->data.Line_Num + 1,
		l->Page_data.data.tail->data.Beg_Pos + l->Page_data.data.tail->data.Line_String.length);
	return OK;
}
Statue Split_Page(LinkList_Page *L, int Line_Num)
//��Line_Num֮ǰ����ҳ���Ѳ�����
{
	Link_Page ptr;
	Link_Line ltr;
	Link_Line Bef_ltr;
	Pos_Page_And_Line(L, &ptr, &ltr, Line_Num);
	PriorPos(&ptr->Page_data.data, ltr, &Bef_ltr);
	Bef_ltr->next = NULL;
	ptr->Page_data.data.tail = Bef_ltr;
	Link_Page Ins_p;
	LinkList_Line List_tmp;
	Change_Link_To_LinkList(&List_tmp,ltr);
	Make_Node_Page(&Ins_p, &List_tmp);
	Insert_Page_Bef(L, ptr->next, Ins_p);
}
Statue Insert_Line_Page(LinkList_Page *L, int Ins_Line_Num, Link_Line Ins_Line)
//��Ins_Line_Num���к�֮ǰ����Link_Line��������
{
	Link_Page ptr;
	Link_Line ltr;
	Pos_Page_And_Line(L, &ptr, &ltr, Ins_Line_Num);//��λ�к���ָ����ҳ����ָ��
	InsBefore(&ptr->Page_data.data, ltr, Ins_Line);	
	Change_Page_Beg_Data(ptr->next, ptr->Page_data.data.tail->data.Line_Num + 1, ptr->Page_data.Page_Num + 1);
	Change_Page_Line_Information(ptr->next, ptr->Page_data.data.tail->data.Line_Num + 1,
		ptr->Page_data.data.tail->data.Beg_Pos + ptr->Page_data.data.tail->data.Line_String.length);
}
void Print_Page(LinkList_Page *P)
{
	Link_Page p = P->head->next;
	printf("page_Num      Beg_Line_Num      Line_Num       Beg_Pos       data\n");
	while (p != NULL)
	{
		printf("%d     %d     ", p->Page_data.Page_Num, p->Page_data.Beg_Line_Num);
		Print_Line(&p->Page_data.data);
		p = p->next;
	}
}
Statue Count_Real_Char_Num(LinkList_Page *p)
{
	Link_Page ptr = p->head->next;
	int char_num = 0;
	while (ptr != NULL)
	{
		char_num += count_line_char_num(&ptr->Page_data.data);
		ptr = ptr->next;
	}
	return char_num;
}
Statue Count_Real_Word_Num(LinkList_Page *p)
{
	Link_Page ptr = p->head->next;
	int word_num = 0;
	while (ptr != NULL)
	{
		word_num += count_line_word_num(&ptr->Page_data.data);
		ptr = ptr->next;
	}
	return word_num;
}
int Count_some_word_num(LinkList_Page *p, char *s)
{
	HString s_tmp;
	StrAssign(&s_tmp, s);
	Link_Page ptr = p->head->next;
	int sum = 0;
	while (ptr != NULL)
	{
		sum += count_line_word_frequent(&ptr->Page_data.data, &s_tmp);
		ptr = ptr->next;
	}
	return sum;
}