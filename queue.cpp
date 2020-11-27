#include"queue.h"




//����һ��������mSize����Ԫ�Ŀն���
void create(Queue* Q, int mSize)
{
	Q->maxSize = mSize;
	Q->element = (ElemType*)malloc(sizeof(ElemType) * mSize);
	Q->front = Q->rear = 0;
}

//����һ���Ѵ��ڵĶ��У����ͷŶ���ռ�õ�����ռ�
void Destroy(Queue* Q)
{
	Q->maxSize = 0;
	free(Q->element);
	Q->front = Q->rear = -1;
}

//�ж϶����Ƿ�Ϊ�գ����ǣ��򷵻�TRUE�����򷵻�FALSE
BOOL isEmpty(Queue* Q)
{
	return Q->front == Q->rear;
}

//�ж϶�ջ�Ƿ����������ǣ��򷵻�TRUE�����򷵻�FALSE
BOOL IsFULL(Queue* Q)
{
	return (Q->rear + 1) % Q->maxSize == Q->front;
}

//��ȡ��ͷԪ�أ���ͨ��x���ء��������ɹ����򷵻�TRUE�����򷵻�FALSE
BOOL Front(Queue* Q, ElemType* x)
{
	if (isEmpty(Q))				//�ն��д���
		return FALSE;
	*x = Q->element[(Q->front + 1) % Q->maxSize];
	return TRUE;
}

//�ڶ���Q�Ķ�β����Ԫ��x����Ӳ��������������ɹ����򷵻�TRUE�����򷵻�FALSE
BOOL EnQueue(Queue* Q, ElemType x)
{
	if (IsFULL(Q))				//�������
		return FALSE;
	Q->rear = (Q->rear + 1) % Q->maxSize;
	Q->element[Q->rear] = x;
	return TRUE;
}

//�Ӷ���Q��ɾ����ͷԪ�أ����Ӳ��������������ɹ����򷵻�TRUE�����򷵻�FALSE
BOOL DeQueue(Queue* Q)
{
	if (isEmpty(Q))
		return FALSE;				//�ն��д���
	Q->front = (Q->front + 1) % Q->maxSize;
	return TRUE;
}

//���������ȫ��Ԫ�أ�ʹ���лָ�����ʼ״̬(Q->front=Q->rear=0),�����ͷſռ�
void Clear(Queue* Q)
{
	Q->front = Q->rear = 0;
}
