#include"哈夫曼树.h"



int main()
{

	//测试数据3  ABC 1 2 3 2 1 1
	HFMTree p;
	int num;	//字符的数量
	printf("请输入字符的数量:\n");
	scanf_s("%d", &num);
	char* arr = (char*)malloc(num * sizeof(char));
	int* w = (int*)malloc(num * sizeof(int));
	
	int decode[10];		//解码,最大长度不超过10
	int decodeLen;

	printf("请输入字符:\n");
	getchar();
	for (int i = 0; i < num; i++)
	{
		arr[i] = getchar();
	}
	printf("请输入这些字符对应的权值:\n");
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d", &w[i]);
	}

	CreateHFMTree(&p, w, num, arr);
	PreOrderTree(&p);
	HFMTreeCode(&p,0);

	printf("请输入解码的字符的长度:\n");
	scanf_s("%d", &decodeLen);
	for (int i = 0; i < decodeLen; i++)
		scanf_s("%d", &decode[i]);

	DecodeTree(&p, decode, decodeLen);
	free(w);
	free(arr);
	return 0;

}