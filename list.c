#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "listh.h"

static void copy(Node*p,INPUT input);

void make(LIST*p)
{
    *p=NULL;
}

void addPOS(LIST * p, INPUT input, int find)
{
	int pos=1;
	Node *new;
	Node *head = *p;
	Node *add;

	if (find > count(p))
	{
		printf("\n no data!\n");
		printf("total : %d\n\n", count(p));
		return;
	}
	else
		head = *p;

	new = (Node*)malloc(sizeof(Node));
	copy(new, input);
	new->next = NULL;

	if (head == NULL)
		*p = new;
	else
	{
		while ((head->next != NULL)&&(pos<find))
		{
			pos++;
			add = head;
			head = head->next;
		}
		//------pos------------------
		//--------|--------------------
		//------add-------head----
		//-----------\-----/-----------
		//------------new------------
		add->next = new;
		new->next = head;
	}
}

void addEND(LIST*p,INPUT input)
{
    Node *now;
    Node *head=*p;//p--指向链表的指针
    
    now=(Node*)malloc(sizeof(Node));
    copy(now,input);
    now->next=NULL;

    if(head==NULL)
        *p=now;
    else
    {
		while (head->next != NULL)
			head = head->next;
		head->next = now;		
    }
}

void deletePOS(LIST * p,  int find)
{
	int pos = 1;
	Node *del;
	Node *head = *p;
	if (find > count(p))
	{
		printf("\n no data!\n");
		printf("total : %d\n\n", count(p));
		return;
	}
	if (head == NULL)
	{
		printf("\n no data!\n");
		return;
	}
	else
	{
		while ((head->next != NULL) && (pos < find))
		{
			pos++;
			del = head;
			head = head->next;
		}
		//------pos------------------
		//--------|--------------------
		//------del-----(head)----
		//----------\-------\----------
		//----------next=next---------
		del->next = head->next;
		free(head);
	}

}

void deleteEND(LIST * p)
{
	Node *head = *p;
	Node *d;
	if(head==NULL)
	{
		printf("\n no data!\n");
		return;
	}
	else
	{
		while (head->next != NULL)
		{
			d = head;
			head = head->next;
		}
		//---NULL--------
		//---/-------------
		//--d--------------
		//------head------
		//---------\--------
		//--------free-----
		d->next = NULL;
		free(head);
		printf("delete\n");
		return;
	}
}

void saveFile(LIST * p, char * filename)
{
	FILE*out;
    Node *head=*p;
	int end = 0;
	if((out=fopen(filename,"w+"))==NULL)
	{
		printf("open false\n");
		return;
	}
	
	if (head == NULL)
	{
		fprintf(out,"\nNo data!\n");
		return;
	}
	else
	{
		while (1)
		{
			fprintf(out,"%d\n",head->input.no);
			if(head->next == NULL) break;
			head=head->next;
		}
	}
	fprintf(out, "%d\n", end);
	fclose(out);
	printf("Finish\n");
}

void loadFile(LIST * p, char * filename)
{
	FILE*in;
	int input;
	if ((in = fopen(filename, "r")) == NULL)
	{
		printf("open false\n");
		return;
	}
	while (1)
	{
		Node *now;
		Node *head = *p;
		fscanf(in, "%d", &input);
		if (input == 0) break;
		now = (Node*)malloc(sizeof(Node));
		now->input.no = input;
		now->next = NULL;

		if (head == NULL)
			*p = now;
		else
		{
			while (head->next != NULL)
				head = head->next;
			head->next = now;
		}
	}
	printf("Finish\n");
	fclose(in);
}

void find(LIST * p, int find)
{
	int count = 1;
	Node *head = *p;
	while (head!=NULL)
	{
		if (find==head->input.no)
		{
			printf("Done! pos : %d\n",count);
			return;
		}
		head = head->next;
		count++;
	}
	printf("No data\n");
}

bool empty(LIST*p)
{
    if(*p==NULL) return true;
    else return false;
}

int count(LIST * p)
{
	Node *next = *p;
	int count=0;
	while (next!= NULL)
	{
		++count;
		next = next->next;
	}

	return count;
}

void func(LIST *p,void(*pfun)(INPUT input))
{
    Node*head=*p;
    while(head!=NULL)
    {
        (*pfun)(head->input);
        head=head->next;
    }
}

void clear(LIST*p)
{
    Node *head;
    while(*p!=NULL)
    {
        head=(*p)->next;
        free(*p);
        *p=head;
    }
	system("cls");
}

void copy(Node*p,INPUT input)
{
    p->input=input;
}
