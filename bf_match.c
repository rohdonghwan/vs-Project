#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int bf_match(const char txt[], const char pat[])
{
	int pt = 0;
	int pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			pt = pt - pp + 1;
			pp = 0;
		}
	}
	if (pat[pp] == '\0')
		return pt - pp;
	return -1;
}
int main()
{
	int idx;
	char s1[256];
	char s2[256];
	while (1){
		puts("����-������");
	printf("�ؽ�Ʈ : ");
	scanf("%s", s1);
	printf("���� : ");
	scanf("%s", s2);
	idx = bf_match(s1, s2);
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);
}
	return 0;
}