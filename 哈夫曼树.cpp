#include"��������.h"

//�������
void MakeTree(HFMTree* p, ElementType e, int w, HFMTree* l, HFMTree* r)
{
	
	p->root = NewNode(e, w, l?l->root:NULL, r?r->root:NULL);
}

//��ʼ����������
void CreateTree(HFMTree* p)
{
	p->root = NULL;
}


//�����������
void CreateHFMTree(HFMTree *p,int w[], int m, char arr[])
{
	PriorityQueue PQ;
	HFMTree x, y, z;
	CreatePQ(&PQ, 10);
	for (int i = 0; i < m; i++)
	{
		MakeTree(&x, arr[i], w[i], NULL, NULL);
 		Append(&PQ, x);
	}
	while (PQ.n > 1)
	{
		Serve(&PQ, &x);
		Serve(&PQ, &y);
	if (x.root->w < y.root->w)
		MakeTree(&z, NULL, x.root->w + y.root->w, &x, &y);
	else 
		MakeTree(&z, NULL, x.root->w + y.root->w, &y, &x);
	Append(&PQ, z);
	}
	Serve(&PQ, p);
}

//�������
void PreOrderTree(HFMTree* bt) {
	PreOrder(bt->root);
	printf("\n");
}

void PreOrder(HFMTNode* t) {
	if (!t)
		return;
	printf("%d ", t->w);
	PreOrder(t->lChild);
	PreOrder(t->rChild);
}

void HFMTreeCode(HFMTree* p, int len)
{
	HFMCode(p->root, len);
}

void HFMCode(HFMTNode* FBT, int len)//len��ʼֵΪ0
{
	static int a[10];//���徲̬����a������ÿ��Ҷ�ӵı��룬���鳤������������ȼ�һ
	if (FBT != NULL)//���ʵ�Ҷ�ӽ��ʱ����䱣��������a�е�0��1���б���
	{
		if (FBT->lChild == NULL && FBT->rChild == NULL)
		{
			int i;
			printf("�ַ�Ϊ%c�ı��룺", FBT->element);
			for (i = 0; i < len; i++)
				printf("%d", a[i]);
			printf("\n");
		}
		else//���ʵ���Ҷ�ӽ��ʱ�ֱ������������ݹ���ã����ѷ�֧�ϵ�0��1���뱣�浽����a
		{   //�Ķ�ӦԪ���У���������һ��ʱlenֵ��1
			a[len] = 1;
			HFMCode(FBT->lChild, len + 1);
			a[len] = 0;
			HFMCode(FBT->rChild, len + 1);
		}
	}
}

void DecodeTree(HFMTree* p, int code[], int len)
{
	Decode(p->root, code, len);
}

void Decode(HFMTNode* p, int code[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (p == NULL)
		{
			printf("��������Ҳ�����Ӧ�ַ���\n");
			return;
		}
		if (code[i] == 1)
			p = p->lChild;
		else if (code[i] == 0)
			p = p->rChild;
		else
		{
			printf("��������Ҳ�����Ӧ�ַ���\n");
			return;
		}
	}
	printf("�ñ����Ӧ���ַ�Ϊ��%c", p->element);
}




//�������
HFMTNode* NewNode(ElementType e, int w, HFMTNode* ln, HFMTNode* rn)
{
	HFMTNode* p = (HFMTNode*)malloc(sizeof(HFMTNode));
	p->element = e;
	p->w = w;
	p->lChild = ln;
	p->rChild = rn;
	return p;
}
