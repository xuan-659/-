#include"优先权队列.h"

void AdjustDown(HFMTree heap[], int current, int border)		//向下调整和建堆运算
{
	int p = current;
	int minChild;
	HFMTree temp;
	while (2 * p + 1 <= border)										//若p不是叶节点，则执行调整
	{
		if ((2 * p + 2 <= border) && (heap[2 * p + 1].root->w > heap[2 * p + 2].root->w))
			minChild = 2 * p + 2;									//右孩子存在，且较小，则minChild指向p的右孩子
		else
			minChild = 2 * p + 1;									//右孩子不存在，或较大，则minChild指向p的左孩子
		if (heap[p].root->w<= heap[minChild].root->w)
			break;													//若当前结点不大于其最小的孩子，则调整结束
		else														//否则将p和其最小孩子交换
		{
			temp = heap[p];
			heap[p] = heap[minChild];
			heap[minChild] = temp;
			p = minChild;											//设置下轮循环待考察的元素的位置(即当前下移元素的位置)
		}
	}
}

void CreateHeap(HFMTree heap[], int n)
{
	int i;
	for (i = (n - 2) / 2; i > -1; i--)
		AdjustDown(heap, i, n - 1);
}

void AdjustUp(HFMTree heap[], int current)					//函数AdjustUp
{
	int p = current;
	HFMTree temp;
	while (p > 0)
	{
		if (heap[p].root->w< heap[(p - 1) / 2].root->w)						//若p指向的元素小于其双亲结点，则与双亲结点交换
		{
			temp = heap[p];
			p = (p - 1) / 2;									//将p上移至当前考察元素的双亲结点位置
		}
		else													//若p指向的元素不小于其双亲结点，则调整完毕				
			break;
	}

}

void CreatePQ(PriorityQueue* PQ, int mSize)
{
	PQ->maxSize = mSize;
	PQ->n = 0;
	PQ->elements = (HFMTree*)malloc(mSize * sizeof(HFMTree));
}

void Destroy(PriorityQueue* PQ)
{
	free(PQ->elements);
	PQ->n = 0;
	PQ->maxSize = 0;
}

int IsEmpty(PriorityQueue* PQ)
{
	if (PQ->n == 0)
		return 1;
	else
		return 0;
}

int IsFull(PriorityQueue* PQ)
{
	if (PQ->n == PQ->maxSize)
		return 1;
	else
		return 0;
}

int Size(PriorityQueue* PQ)
{
	return PQ->n;
}

void Append(PriorityQueue* PQ, HFMTree x)
{
	if (IsFull(PQ)) return;
	PQ->elements[PQ->n] = x;
	PQ->n++;
	AdjustUp(PQ->elements, PQ->n - 1);
}

void Serve(PriorityQueue* PQ, HFMTree* x)
{
	if (IsEmpty(PQ))
		return;
	*x = PQ->elements[0];
	PQ->n--;
	PQ->elements[0] = PQ->elements[PQ->n];
	AdjustDown(PQ->elements, 0, PQ->n - 1);
}