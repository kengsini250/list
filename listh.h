#ifndef LISTH_H_
#define LISTH_H_
#include<stdbool.h>

//声明
struct test
{
    int no;
};
//定义
typedef struct test INPUT;

//链表的实现
typedef struct node
{
    INPUT input;
    struct node*next;
}Node;
//定义
typedef Node *LIST;


void make(LIST*p);

void addPOS(LIST*p, INPUT input,int find);
void addEND(LIST*p,INPUT input);

void deletePOS(LIST*p, int find);
void deleteEND(LIST*p);

void saveFile(LIST*p, char*filename);
void loadFile(LIST*p, char*filename);

void find(LIST*p, int find);

bool empty(LIST*p);
int count(LIST*p);
void func(LIST *p,void(*pfun)(INPUT input));
void clear(LIST*p);


#endif
