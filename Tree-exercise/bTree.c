#include <stdio.h>
#include <stdlib.h>
#include "bTree.h"

//建立二叉树
//按值建立二叉树：在左子树的节点值总是小于根，在右子树的节点总是大于等于根。传入的data存放在数组内，id为数组下标，默认数组第一个为根。
bTree buildbTreebydata(Elemtype *nodes, int num) {
	if (num <= 0) { return NULL; }
	//先分配根的空间
	bTree root = (bNode*)malloc(sizeof(bNode));
	root->id = 0; root->data = nodes[0]; root->lchild = root->rchild = NULL;
	for (int i = 1; i < num; i++) {
		buildbTreebydata_Pre(root,i,nodes[i]);
	}
	return root;
}
//用于按值建立二叉树，按照值的大小在已经建立好的二叉树上运动
void buildbTreebydata_Pre(bTree root,int id,Elemtype data) {
	if (data < root->data) {
		if (!root->lchild) {//左子树为空
			root->lchild = (bNode*)malloc(sizeof(bNode));
			root->lchild->id = id;
			root->lchild->data = data;
			root->lchild->lchild = root->lchild->rchild = NULL;
		}
		else {//左子树不为空，递归调用
			buildbTreebydata_Pre(root->lchild,id,data);
		}
	}
	else {
		if (!root->rchild) {//右子树为空
			root->rchild = (bNode*)malloc(sizeof(bNode));
			root->rchild->id = id;
			root->rchild->data = data;
			root->rchild->lchild = root->rchild->rchild = NULL;
		}
		else {//右子树不为空，递归调用
			buildbTreebydata_Pre(root->rchild, id, data);
		}
	}
}

//由双亲表示法建立二叉树
//bTree buildbTreefrompTree(pTree root) {
//}

//打印节点信息
void PrintNode(bNode * pnode) {
	printf("节点信息：id：%d data：%d\n",pnode->id,pnode->data);
}

//先序遍历
void PreTraverse(bTree root, void (*ptrFunc)(bNode* pnode)) {
	if (!root) { ; }
	else {
		ptrFunc(root);
		PreTraverse(root->lchild,ptrFunc);
		PreTraverse(root->rchild,ptrFunc);
	}
}

//中序遍历
void InTraverse(bTree root, void (*ptrFunc)(bNode* pnode)) {
	if (!root) { ; }
	else {
		InTraverse(root->lchild, ptrFunc);
		ptrFunc(root);
		InTraverse(root->rchild, ptrFunc);
	}
}

//后序遍历
void PostTraverse(bTree root, void (*ptrFunc)(bNode* pnode)) {
	if (!root) { ; }
	else {
		PostTraverse(root->lchild, ptrFunc);
		PostTraverse(root->rchild, ptrFunc);
		ptrFunc(root);
	}
}

//销毁树，采用后序遍历
void DestroybTree(bTree root) {
	if (!root) { ; }
	else {
		DestroybTree(root->lchild);
		DestroybTree(root->rchild);
		free(root);
	}
}