#include"����Ȩ����.h"

void AdjustDown(HFMTree heap[], int current, int border)		//���µ����ͽ�������
{
	int p = current;
	int minChild;
	HFMTree temp;
	while (2 * p + 1 <= border)										//��p����Ҷ�ڵ㣬��ִ�е���
	{
		if ((2 * p + 2 <= border) && (heap[2 * p + 1].root->w > heap[2 * p + 2].root->w))
			minChild = 2 * p + 2;									//�Һ��Ӵ��ڣ��ҽ�С����minChildָ��p���Һ���
		else
			minChild = 2 * p + 1;									//�Һ��Ӳ����ڣ���ϴ���minChildָ��p������
		if (heap[p].root->w<= heap[minChild].root->w)
			break;													//����ǰ��㲻��������С�ĺ��ӣ����������
		else														//����p������С���ӽ���
		{
			temp = heap[p];
			heap[p] = heap[minChild];
			heap[minChild] = temp;
			p = minChild;											//��������ѭ���������Ԫ�ص�λ��(����ǰ����Ԫ�ص�λ��)
		}
	}
}

void CreateHeap(HFMTree heap[], int n)
{
	int i;
	for (i = (n - 2) / 2; i > -1; i--)
		AdjustDown(heap, i, n - 1);
}

void AdjustUp(HFMTree heap[], int current)					//����AdjustUp
{
	int p = current;
	HFMTree temp;
	while (p > 0)
	{
		if (heap[p].root->w< heap[(p - 1) / 2].root->w)						//��pָ���Ԫ��С����˫�׽�㣬����˫�׽�㽻��
		{
			temp = heap[p];
			p = (p - 1) / 2;									//��p��������ǰ����Ԫ�ص�˫�׽��λ��
		}
		else													//��pָ���Ԫ�ز�С����˫�׽�㣬��������				
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