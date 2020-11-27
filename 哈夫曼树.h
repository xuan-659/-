#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"����Ȩ����.h"



//�������
void MakeTree(HFMTree* p, ElementType e, int w, HFMTree* l, HFMTree* r);

//��ʼ����������
void CreateTree(HFMTree* p);

//�����������
void CreateHFMTree(HFMTree *p, int w[], int m ,char arr[]);

//�������
void PreOrderTree(HFMTree* bt);
void PreOrder(HFMTNode* t);

//�������
HFMTNode* NewNode(ElementType e, int w, HFMTNode* ln, HFMTNode* rn);

//����������
void HFMTreeCode(HFMTree* p, int len);
void HFMCode(HFMTNode* FBT, int len);

//����
void DecodeTree(HFMTree* p, int code[], int len);

void Decode(HFMTNode* p, int code[], int len);
