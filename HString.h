#ifndef STRING_H
#define STRING_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define INITIAL_LENGTH 100
#define REALLOC_LENGTH 10
typedef int Statue;
#define TRUE 1
#define ERROR 0
#define OK 1
#define FALSE 0

typedef struct {
    char *ch;
    int length;
}HString;

Statue StrAssign(HString *T,char *chars);//字符串常量赋值给HString
Statue StrCopy(HString *T,HString S);//串的赋值操作
Statue StrEmpty(HString S);//判断串是否为空
Statue StrCompare(HString T,HString S);//比较两个串的大小
int StrLength(HString S);//返回串之长度
Statue ClearString(HString *S);//清空串
Statue Concat(HString *T,HString S1,HString S2);//T返回S1和S2的连接成果
Statue SubString(HString *Sub,HString S,int pos,int len);//Sub返回S自pos起len个字符的子串
int Index(HString S,HString T,int pos);//S:主串，T:模式串，返回S中包含T子串的第一个位置
Statue Replace(HString *S,HString T,HString V);//用V替换S主串中所有与T相等且不重叠的子串
Statue StrInsert(HString *S,int pos,HString T);//在S的pos个字符前插入T
Statue StrDelete(HString *S,int pos,int len);//从S中pos个字符开始起始长度为len的字符子串
Statue DestoryString(HString *S);//销毁我们的字符串
void HStringPrint(HString *S);//打印该HString;
int count_real_char_num(HString *S);//计算该HString中字母和数字的字符数
int judge_if_word(char *s,int pos);//自此pos字符开始往后判断，如果遇到空格或者标点符号则返回该标点位置;
int count_real_word_num(HString *S);//计算该HString中的单词数
int count_word_frequent(HString *S, HString *s1);
#endif