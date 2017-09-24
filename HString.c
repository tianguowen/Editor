#include "HString.h"

Statue StrAssign(HString *T,char *chars)
{
    if(T->ch)
    free(T->ch);//释放原有的空间
    int char_num=strlen(chars)+1;//去掉最后的‘/0’字符
    if(char_num==0)
    {
        T->ch=NULL;
        T->length=0;
    }
    else
    {
        T->ch=(char*)malloc(sizeof(char)*char_num);
        if(!T->ch)
        return FALSE;
        int i=0;
        while(i<char_num)
        {
            (T->ch)[i]=chars[i];
            ++i;
        }
        T->length=char_num;
    } 
}
Statue StrCopy(HString *T,HString S)
{
    if(T->ch)
    free(T->ch);
    int string_num=S.length;
    if(string_num==0)
    {
        printf("S is a empty string\n");
        return FALSE;
    }
    else
    {
        T->ch=(char *)malloc(sizeof(char)*string_num);
        if(!T->ch)
        return FALSE;
        int i=0;
        while(i<string_num)
        {
            (T->ch)[i]=(S.ch)[i];
            ++i;
        }
        T->length=S.length;
    }
}
Statue StrEmpty(HString S)
{
    if(S.length==0)
    return TRUE;
    else
    {
        return FALSE;
    }
}
Statue StrCompare(HString T,HString S)
{
    if(StrEmpty(T)||StrEmpty(S))
    {
        printf("has a empty string\n");
        return FALSE;
    }
    else
    {
        if(T.length>S.length)
        return 1;
        else if (T.length<S.length)
        return -1;
        else
        {
            int i=0;
            for(i=0;i<T.length;++i)
            {
                if(T.ch[i]>S.ch[i])
                return 1;
                else if (T.ch[i]<S.ch[i])
                return -1;
                else
                continue;
            }
            if(i==T.length)
            return 0;
        }
    }
}
int StrLength(HString S)
{
    return S.length;
}
Statue ClearString(HString *S)
{
    memset(S->ch,0,sizeof(char)*S->length);
    S->length=0;
}
Statue Concat(HString *T,HString S1,HString S2)
{
    if(T->ch)
    free(T->ch);
    T->ch=(char *)malloc((S1.length+S2.length)*sizeof(char));
    if(!T->ch)
    return FALSE;
    else
    {
        int i=0;
        for(i=0;i<S1.length+S2.length;++i)
        {
            if(i<S1.length)
            {
                (T->ch)[i]=S1.ch[i];
                ++i;
            }
			else
			{
				(T->ch)[i] = S2.ch[i];
			}
        }
        T->length=S1.length+S2.length;
        return OK;
    }
}
Statue SubString(HString *Sub,HString S,int pos,int len)
{
    if(Sub->ch)
    free(Sub->ch);
    if(!len)
    {
        Sub->ch=NULL;
        Sub->length=0;
    }
    if(Sub->ch&&pos>=1&&pos<=StrLength(S)&&len>=0&&len<=StrLength(S)-pos+1)
    {
        char tmp_ch[100];
        int index,i;
        for(i=0,index=pos-1;index<pos-1+len;++index)
        {
            tmp_ch[i]=S.ch[index];
            ++i;
            ++index;
        }
        StrAssign(Sub,tmp_ch);
        return OK;
    }
    else
    {
        return FALSE;
    }
}
void get_next(HString T,int next[])
{
    int len=T.length;
    next[0]=0;
    for(int i=1;i<len;++i)
    {
        int k=next[i-1];
        //k表示的是当前字符与第几个字符进行比对
        //k==0表示前一个字符的next值==0，所以前一个
        //字符没有对称项，所以当前字符与第一个字符匹配
        //如果匹配上表示有一个对称，当前字符的next值为1
        //依次推理下去下一个字符与第二个字符匹配，如果匹配上
        //则next值＋1，如果不匹配则k值回跳寻找对称项
        while(T.ch[i]!=T.ch[k]&&k!=0)
        k=next[k-1];
        if(T.ch[i]==T.ch[k])
        next[i]=k+1;
        else
        {
            next[i]=0;
        }
    }
}
int Index(HString S,HString T,int pos)
{
    int next[100];
    get_next(T,next);
    int i=pos;
    int j=1;
    while(i<S.length&&j<T.length)
    {
        if(j==0||S.ch[i]==T.ch[j])
        {
            ++i;++j;
        }
        else
        j=next[j];
    }
    if(j>=T.length)
    return i-T.length;//这个返回值是数组下标
    {
        return 0;
    }
}
Statue Replace(HString *S,HString T,HString V)//用V替换S主串中所有与T相等且不重叠的子串
{
    int pos=0;
    if(T.length==V.length)//两个替换字符长度相同，所以我们可以不用重新分配内存
    {
        while(pos=Index(*S,T,pos))//循环找出与S中与T匹配的字符串
        {
            for(int j=0;j<T.length;++j,++pos)
            (S->ch)[pos]=T.ch[j];
        }
    }
    else if (T.length>V.length)
    {
        while(pos=Index(*S,T,pos))
        {
            for(int j=0;j<V.length;++j,++pos)
            (S->ch)[pos]=T.ch[j];
            int i=pos;
            int k=T.length-V.length;
            for(;i<S->length;++i)
            (S->ch)[i]=(S->ch)[i+k];//后面的字符向前移动
        }
		char *s_tmp;
		s_tmp = (char*)realloc(S->ch, S->length);//重新分配数据区，将替换后删除的数据截断
		S->ch = s_tmp;
    }
    else
    {
        while(pos=Index(*S,T,pos))
        {
            int k=V.length-T.length;
            S->length+=k;
			char *s_tmp;
			s_tmp = (char*)realloc(S->ch, S->length);//重新分配数据区，将替换后删除的数据截断
			S->ch = s_tmp;
            int j=S->length-1;
            int i=pos;
            for(;j>=i+V.length;--j)
            (S->ch)[j]=(S->ch)[j-k];//已经留出空间
            for(int j=0;j<V.length;++j,++pos)
            (S->ch)[pos]=T.ch[j];       
        }
    }
}
Statue StrInsert(HString *S,int pos,HString T)
{
    int k=T.length;
    S->length+=k;
	char *s_tmp;
	s_tmp = (char*)realloc(S->ch, S->length);//重新分配数据区，将替换后删除的数据截断
	S->ch = s_tmp;
    int j=S->length-1;
    for(;j>=pos-1+k;--j)
    (S->ch)[j]=(S->ch)[j-k];
    for(int i=pos-1,m=0;m<T.length;++i,++m)
    (S->ch)[i]=T.ch[m];
    return OK;
}
Statue StrDelete(HString *S,int pos,int len)
{
    int i=pos-1;
    for(;i<pos-1+len;++i)
    {
        (S->ch)[i]=(S->ch)[i+len];
    }
    S->length-=len;
	char *s_tmp;
	s_tmp = (char*)realloc(S->ch, S->length);//重新分配数据区，将替换后删除的数据截断
	S->ch = s_tmp;
    return OK;
}
Statue DestoryString(HString *S)
{
    free(S->ch);
    free(S);
    return OK;
}
void HStringPrint(HString *S)
{
	printf("%s\n", S->ch);
}
int count_real_char_num(HString *S)
{
	char *ptr = S->ch;
	int char_num = 0;
	int i = 0;
	while (ptr[i] != '\0')
	{
		if (isalnum(ptr[i]))
		{
			++char_num;
			++i;
		}
		else
		{
			++i;
		}
	}
	return char_num;
}
int judge_if_word(char *s, int pos)
{
	while (s[pos] != '\0' && (isalnum(s[pos])||s[pos]=='-'||s[pos]=='\''))
	{
		++pos;
	}
	return pos;
}
int count_real_word_num(HString *S)
{
	int index = 0;
	int word_num = 0;
	while (index <= S->length)
	{
		int k = judge_if_word(S->ch, index);
		if (k == index)
		{
			++index;
		}
		else
		{
			index = k+1;
			++word_num;
		}
	}
	return word_num;
}