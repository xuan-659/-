#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"��������.h"
#define BOOL bool
#define TRUE true
#define FALSE false

typedef int ElemType;
//ѭ�����нṹ�嶨��
typedef struct queue
{
	int front;
	int rear;
	int maxSize;
	ElemType* element;
}Queue;

//����һ��������mSize����Ԫ�Ŀն���
void create(Queue* Q, int mSize);

//����һ���Ѵ��ڵĶ��У����ͷŶ���ռ�õ�����ռ�
void Destroy(Queue* Q);

//�ж϶����Ƿ�Ϊ�գ����ǣ��򷵻�TRUE�����򷵻�FALSE
BOOL isEmpty(Queue* Q);

//�ж϶�ջ�Ƿ����������ǣ��򷵻�TRUE�����򷵻�FALSE
BOOL IsFULL(Queue* Q);

//��ȡ��ͷԪ�أ���ͨ��x���ء��������ɹ����򷵻�TRUE�����򷵻�FALSE
BOOL Front(Queue* Q, ElemType* x);

//�ڶ���Q�Ķ�β����Ԫ��x����Ӳ��������������ɹ����򷵻�TRUE�����򷵻�FALSE
BOOL EnQueue(Queue* Q, ElemType x);

//�Ӷ���Q��ɾ����ͷԪ�أ����Ӳ��������������ɹ����򷵻�TRUE�����򷵻�FALSE
BOOL DeQueue(Queue* Q);

//���������ȫ��Ԫ�أ�ʹ���лָ�����ʼ״̬(Q->front=Q->rear=0),�����ͷſռ�
void Clear(Queue* Q);