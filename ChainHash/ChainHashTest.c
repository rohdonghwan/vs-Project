#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Member.h"
#include"ChainHash.h"

typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
}Menu;

Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1)�߰� (2)���� (3)�˻� (4)��� ���� (5)���� (6)���� : ");
		scanf("%d",&ch);
	} while (ch <TERMINATE || ch >DUMP);
	return(Menu)ch;
}

int main()
{
	Menu menu;
	ChainHash hash;
	Initialize(&hash, 13);
	do {
		int result;
		Member x;
		Node *temp;
		switch (menu = SelectMenu()) {
		case ADD:
			x = ScanMember("�߰�", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result)
				printf("\a���� : �߰��� �����߽��ϴ�(%s).\n",
				(result == 1) ? "�̹� ��ϵ�" : "�޸� ����");
			break;

		case DELETE : 
			x = ScanMember("����", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result == 1)
			{
				printf("\a���� : �� ��ȣ�� �����Ͱ� �������� �ʽ��ϴ�.\n");
				break;
			}
		case SEARCH : 
			x = ScanMember("�˻�", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == NULL)
				printf("\a�˻��� �����߽��ϴ�.\n");
			else {
				printf("�˻��� �����߽��ϴ�. : ");
				PrintLnMember(&temp->data);
			}
			break;
		case CLEAR:
			Clear(&hash);
			break;
		
		case DUMP:
			Dump(&hash);
			break;
		}
	} while (menu != TERMINATE);
	Terminate(&hash);


	return 0;
}