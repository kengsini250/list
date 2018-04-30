#include<stdio.h>
#include<stdlib.h>
#include "listh.h"

#define filename "test.txt"

void display(INPUT input);
void menu();

void main()
{
    LIST list;
    INPUT input;
	int pos,choose=0;

    make(&list);
	menu();

	while (choose!=9)
	{
		printf("Input choose : ");
		scanf("%d", &choose);
		system("cls");
		switch (choose)
		{
		case 1:
			printf("Input No : ");
			scanf("%d", &input.no);
			while (input.no != 0)
			{
				addEND(&list, input);
				printf("Input No : ");
				scanf("%d", &input.no);
			}
			break;
		case 2:
			printf("input pos : ");
			scanf("%d", &pos);
			deletePOS(&list, pos);
			break;
		case 3:
			deleteEND(&list);
			break;
		case 4:
			printf("input data : ");
			scanf("%d", &input.no);
			printf("input pos : ");
			scanf("%d", &pos);
			addPOS(&list, input, pos);
			break;
		case 5:
			if (empty(&list))
				printf("No data\n");
			else
			{
				printf("------------list-----------\n\n");
				func(&list, display);
				printf("\n------------list-----------\n\n");
			}
			break;
		case 6:
			saveFile(&list,filename);
			break;
		case 7:
			loadFile(&list, filename);
			break;
		case 8:
			printf("input data : ");
			scanf("%d", &pos);
			find(&list, pos);
			break;
		case 9:break;
		}
		menu();
	}
	clear(&list);
	printf("END\n");
}

void display(INPUT input)
{
    printf("No : %d\n",input.no);
}

void menu()
{
	printf("\n\t\v1 : add             \t\v2 : delete pos\n");
	printf("\t\v3 : delete            \t\v4 : add pos\n");
	printf("\t\v5 : display\n\n");
	printf("\t\v6 : save              \t\v7 : load\n");
	printf("\t\v8 : find\n");
	printf("\t\v9 : end&clear\n\n");
}
