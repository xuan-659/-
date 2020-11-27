#pragma once
#include<stdio.h>
#include<stdlib.h>


typedef char ElementType;

typedef struct HFMTNode {
	ElementType element; //����������
	int w; //����Ȩֵ
	HFMTNode* lChild; //��������ָ��
	HFMTNode* rChild; //�����Һ���ָ��
}HFMTNode;

typedef struct HFMTree {
	HFMTNode* root;
}HFMTree;


typedef struct priorityQueue {
	HFMTree* elements;		//�洢Ԫ�ص�����
	int n;						//����Ȩ������Ԫ�ص�����
	int maxSize;				//����Ȩ���е�����
}PriorityQueue;


void AdjustDown(HFMTree heap[], int current, int border);		//���µ����ͽ�������
void CreateHeap(HFMTree heap[], int n);
void AdjustUp(HFMTree heap[], int current);					//����AdjustUp
void CreatePQ(PriorityQueue* PQ, int mSize);						//����һ������Ȩ����
void Destroy(PriorityQueue* PQ);									//����һ������Ȩ���У��ͷ���ռ�õ��ڴ�ռ�
int IsEmpty(PriorityQueue* PQ);									//�ж�����Ȩ�����Ƿ�Ϊ��
int IsFull(PriorityQueue* PQ);										//�ж�����Ȩ�����Ƿ�����
int Size(PriorityQueue* PQ);										//��ȡ��ǰ����Ȩ������Ԫ�ص�����
void Append(PriorityQueue* PQ, HFMTree x);						//�����ȼ�����������һ����Ԫ��
void Serve(PriorityQueue* PQ, HFMTree* x);						//ȡ�����ȼ���ߵ�Ԫ�أ����ò���x���أ���������Ȩ������ɾ����Ԫ��