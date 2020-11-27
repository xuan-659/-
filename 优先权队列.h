#pragma once
#include<stdio.h>
#include<stdlib.h>


typedef char ElementType;

typedef struct HFMTNode {
	ElementType element; //结点的数据域
	int w; //结点的权值
	HFMTNode* lChild; //结点的左孩子指针
	HFMTNode* rChild; //结点的右孩子指针
}HFMTNode;

typedef struct HFMTree {
	HFMTNode* root;
}HFMTree;


typedef struct priorityQueue {
	HFMTree* elements;		//存储元素的数组
	int n;						//优先权队列中元素的数量
	int maxSize;				//优先权队列的容量
}PriorityQueue;


void AdjustDown(HFMTree heap[], int current, int border);		//向下调整和建堆运算
void CreateHeap(HFMTree heap[], int n);
void AdjustUp(HFMTree heap[], int current);					//函数AdjustUp
void CreatePQ(PriorityQueue* PQ, int mSize);						//创建一个优先权队列
void Destroy(PriorityQueue* PQ);									//销毁一个优先权队列，释放其占用的内存空间
int IsEmpty(PriorityQueue* PQ);									//判断优先权队列是否为空
int IsFull(PriorityQueue* PQ);										//判断优先权队列是否已满
int Size(PriorityQueue* PQ);										//获取当前优先权队列中元素的数量
void Append(PriorityQueue* PQ, HFMTree x);						//在优先级队列中增加一个新元素
void Serve(PriorityQueue* PQ, HFMTree* x);						//取出优先级最高的元素，利用参数x返回，并在优先权队列中删除该元素