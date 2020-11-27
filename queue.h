#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"哈夫曼树.h"
#define BOOL bool
#define TRUE true
#define FALSE false

typedef int ElemType;
//循坏队列结构体定义
typedef struct queue
{
	int front;
	int rear;
	int maxSize;
	ElemType* element;
}Queue;

//创建一个能容纳mSize个单元的空队列
void create(Queue* Q, int mSize);

//销毁一个已存在的队列，即释放队列占用的数组空间
void Destroy(Queue* Q);

//判断队列是否为空，若是，则返回TRUE，否则返回FALSE
BOOL isEmpty(Queue* Q);

//判断堆栈是否已满，若是，则返回TRUE，否则返回FALSE
BOOL IsFULL(Queue* Q);

//获取队头元素，并通过x返回。若操作成功，则返回TRUE，否则返回FALSE
BOOL Front(Queue* Q, ElemType* x);

//在队列Q的队尾插入元素x（入队操作）。若操作成功，则返回TRUE，否则返回FALSE
BOOL EnQueue(Queue* Q, ElemType x);

//从队列Q中删除队头元素（出队操作）。若操作成功，则返回TRUE，否则返回FALSE
BOOL DeQueue(Queue* Q);

//清除队列中全部元素，使队列恢复到初始状态(Q->front=Q->rear=0),但不释放空间
void Clear(Queue* Q);