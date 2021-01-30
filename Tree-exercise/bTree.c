#include <stdio.h>
#include <stdlib.h>
#include "bTree.h"

//����������
//��ֵ���������������������Ľڵ�ֵ����С�ڸ������������Ľڵ����Ǵ��ڵ��ڸ��������data����������ڣ�idΪ�����±꣬Ĭ�������һ��Ϊ����
bTree buildbTreebydata(Elemtype *nodes, int num) {
	if (num <= 0) { return NULL; }
	//�ȷ�����Ŀռ�
	bTree root = (bNode*)malloc(sizeof(bNode));
	root->id = 0; root->data = nodes[0]; root->lchild = root->rchild = NULL;
	for (int i = 1; i < num; i++) {
		buildbTreebydata_Pre(root,i,nodes[i]);
	}
	return root;
}
//���ڰ�ֵ����������������ֵ�Ĵ�С���Ѿ������õĶ��������˶�
void buildbTreebydata_Pre(bTree root,int id,Elemtype data) {
	if (data < root->data) {
		if (!root->lchild) {//������Ϊ��
			root->lchild = (bNode*)malloc(sizeof(bNode));
			root->lchild->id = id;
			root->lchild->data = data;
			root->lchild->lchild = root->lchild->rchild = NULL;
		}
		else {//��������Ϊ�գ��ݹ����
			buildbTreebydata_Pre(root->lchild,id,data);
		}
	}
	else {
		if (!root->rchild) {//������Ϊ��
			root->rchild = (bNode*)malloc(sizeof(bNode));
			root->rchild->id = id;
			root->rchild->data = data;
			root->rchild->lchild = root->rchild->rchild = NULL;
		}
		else {//��������Ϊ�գ��ݹ����
			buildbTreebydata_Pre(root->rchild, id, data);
		}
	}
}

//��˫�ױ�ʾ������������
//bTree buildbTreefrompTree(pTree root) {
//}

//��ӡ�ڵ���Ϣ
void PrintNode(bNode * pnode) {
	printf("�ڵ���Ϣ��id��%d data��%d\n",pnode->id,pnode->data);
}

//�������
void PreTraverse(bTree root, void (*ptrFunc)(bNode* pnode)) {
	if (!root) { ; }
	else {
		ptrFunc(root);
		PreTraverse(root->lchild,ptrFunc);
		PreTraverse(root->rchild,ptrFunc);
	}
}

//�������
void InTraverse(bTree root, void (*ptrFunc)(bNode* pnode)) {
	if (!root) { ; }
	else {
		InTraverse(root->lchild, ptrFunc);
		ptrFunc(root);
		InTraverse(root->rchild, ptrFunc);
	}
}

//�������
void PostTraverse(bTree root, void (*ptrFunc)(bNode* pnode)) {
	if (!root) { ; }
	else {
		PostTraverse(root->lchild, ptrFunc);
		PostTraverse(root->rchild, ptrFunc);
		ptrFunc(root);
	}
}

//�����������ú������
void DestroybTree(bTree root) {
	if (!root) { ; }
	else {
		DestroybTree(root->lchild);
		DestroybTree(root->rchild);
		free(root);
	}
}