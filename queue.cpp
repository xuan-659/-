#include"queue.h"




//创建一个能容纳mSize个单元的空队列
void create(Queue* Q, int mSize)
{
	Q->maxSize = mSize;
	Q->element = (ElemType*)malloc(sizeof(ElemType) * mSize);
	Q->front = Q->rear = 0;
}

//销毁一个已存在的队列，即释放队列占用的数组空间
void Destroy(Queue* Q)
{
	Q->maxSize = 0;
	free(Q->element);
	Q->front = Q->rear = -1;
}

//判断队列是否为空，若是，则返回TRUE，否则返回FALSE
BOOL isEmpty(Queue* Q)
{
	return Q->front == Q->rear;
}

//判断堆栈是否已满，若是，则返回TRUE，否则返回FALSE
BOOL IsFULL(Queue* Q)
{
	return (Q->rear + 1) % Q->maxSize == Q->front;
}

//获取队头元素，并通过x返回。若操作成功，则返回TRUE，否则返回FALSE
BOOL Front(Queue* Q, ElemType* x)
{
	if (isEmpty(Q))				//空队列处理
		return FALSE;
	*x = Q->element[(Q->front + 1) % Q->maxSize];
	return TRUE;
}

//在队列Q的队尾插入元素x（入队操作）。若操作成功，则返回TRUE，否则返回FALSE
BOOL EnQueue(Queue* Q, ElemType x)
{
	if (IsFULL(Q))				//溢出处理
		return FALSE;
	Q->rear = (Q->rear + 1) % Q->maxSize;
	Q->element[Q->rear] = x;
	return TRUE;
}

//从队列Q中删除队头元素（出队操作）。若操作成功，则返回TRUE，否则返回FALSE
BOOL DeQueue(Queue* Q)
{
	if (isEmpty(Q))
		return FALSE;				//空队列处理
	Q->front = (Q->front + 1) % Q->maxSize;
	return TRUE;
}

//清除队列中全部元素，使队列恢复到初始状态(Q->front=Q->rear=0),但不释放空间
void Clear(Queue* Q)
{
	Q->front = Q->rear = 0;
}
