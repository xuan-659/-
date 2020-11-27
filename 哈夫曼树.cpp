#include"哈夫曼树.h"

//创建结点
void MakeTree(HFMTree* p, ElementType e, int w, HFMTree* l, HFMTree* r)
{
	
	p->root = NewNode(e, w, l?l->root:NULL, r?r->root:NULL);
}

//初始化哈夫曼树
void CreateTree(HFMTree* p)
{
	p->root = NULL;
}


//构造哈夫曼树
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

//先序遍历
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

void HFMCode(HFMTNode* FBT, int len)//len初始值为0
{
	static int a[10];//定义静态数组a，保存每个叶子的编码，数组长度至少是树深度减一
	if (FBT != NULL)//访问到叶子结点时输出其保存在数组a中的0和1序列编码
	{
		if (FBT->lChild == NULL && FBT->rChild == NULL)
		{
			int i;
			printf("字符为%c的编码：", FBT->element);
			for (i = 0; i < len; i++)
				printf("%d", a[i]);
			printf("\n");
		}
		else//访问到非叶子结点时分别向左右子树递归调用，并把分支上的0、1编码保存到数组a
		{   //的对应元素中，向下深入一层时len值增1
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
			printf("解码错误！找不到对应字符！\n");
			return;
		}
		if (code[i] == 1)
			p = p->lChild;
		else if (code[i] == 0)
			p = p->rChild;
		else
		{
			printf("解码错误！找不到对应字符！\n");
			return;
		}
	}
	printf("该编码对应的字符为：%c", p->element);
}




//创建结点
HFMTNode* NewNode(ElementType e, int w, HFMTNode* ln, HFMTNode* rn)
{
	HFMTNode* p = (HFMTNode*)malloc(sizeof(HFMTNode));
	p->element = e;
	p->w = w;
	p->lChild = ln;
	p->rChild = rn;
	return p;
}
