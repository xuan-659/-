#include"��������.h"



int main()
{

	//��������3  ABC 1 2 3 2 1 1
	HFMTree p;
	int num;	//�ַ�������
	printf("�������ַ�������:\n");
	scanf_s("%d", &num);
	char* arr = (char*)malloc(num * sizeof(char));
	int* w = (int*)malloc(num * sizeof(int));
	
	int decode[10];		//����,��󳤶Ȳ�����10
	int decodeLen;

	printf("�������ַ�:\n");
	getchar();
	for (int i = 0; i < num; i++)
	{
		arr[i] = getchar();
	}
	printf("��������Щ�ַ���Ӧ��Ȩֵ:\n");
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d", &w[i]);
	}

	CreateHFMTree(&p, w, num, arr);
	PreOrderTree(&p);
	HFMTreeCode(&p,0);

	printf("�����������ַ��ĳ���:\n");
	scanf_s("%d", &decodeLen);
	for (int i = 0; i < decodeLen; i++)
		scanf_s("%d", &decode[i]);

	DecodeTree(&p, decode, decodeLen);
	free(w);
	free(arr);
	return 0;

}