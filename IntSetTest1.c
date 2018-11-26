#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "IntSet.h"

int main()
{
	IntSet s1, s2, s3;
	Initialize(&s1, 24);
	Initialize(&s2, 24);
	Initialize(&s3, 24);

	Add(&s1, 10);
	Add(&s1, 15);
	Add(&s1, 20);
	Add(&s1, 25);

	Assign(&s2, &s1);
	Add(&s2, 12);
	Remove(&s1, 20);
	Assign(&s3, &s2);

	printf("s1 = "); PrintLn(&s1);
	printf("s2 = "); PrintLn(&s2);
	printf("s3 = "); PrintLn(&s3);

	printf("���� s1�� 15�� ��� ��%s.\n", IsMember(&s1, 15) > 0 ? "���ϴ�" : "�� �ʽ��ϴ�");
	printf("���� s2�� 25�� ��� ��%s.\n", IsMember(&s2, 25) > 0 ? "���ϴ�":"�� �ʽ��ϴ�");
	printf("���� s1�� s2�� ���� ��%s.\n", Equal(&s1, &s2) ? "���ϴ�" : "�� �ʽ��ϴ�.");
	printf("���� s1�� s2�� ���� ��%s.\n", Equal(&s2, &s3) ? "���ϴ�" : "�� �ʽ��ϴ�");

	Terminate(&s1);
	Terminate(&s2);
	Terminate(&s3);
	
	return 0;
}