#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"优先权队列.h"



//创建结点
void MakeTree(HFMTree* p, ElementType e, int w, HFMTree* l, HFMTree* r);

//初始化哈夫曼树
void CreateTree(HFMTree* p);

//构造哈夫曼树
void CreateHFMTree(HFMTree *p, int w[], int m ,char arr[]);

//先序遍历
void PreOrderTree(HFMTree* bt);
void PreOrder(HFMTNode* t);

//创建结点
HFMTNode* NewNode(ElementType e, int w, HFMTNode* ln, HFMTNode* rn);

//哈夫曼编码
void HFMTreeCode(HFMTree* p, int len);
void HFMCode(HFMTNode* FBT, int len);

//解码
void DecodeTree(HFMTree* p, int code[], int len);

void Decode(HFMTNode* p, int code[], int len);
