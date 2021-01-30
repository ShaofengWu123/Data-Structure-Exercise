#include <stdio.h>
#include <stdlib.h>
#include "bTree.h"

#define NODE_NUMS 7

//函数声明
int exe6_33(int first_node, int target_node, int* L, int* R, int n);
void exe6_33_ischild(int current_node, int target_node, int* L, int* R, int* flag);

int exe6_42_leafcount(bTree root);

void exe6_43_switchlrchild(bTree root);

int exe6_45_deletexchildtree(bTree root, Elemtype x);

int main() {
	//建立二叉树
	int nodes[NODE_NUMS] = { 4,2,66,4321,96,190,4 };
	bTree root = buildbTreebydata(nodes,NODE_NUMS);
	PreTraverse(root,PrintNode);


	//exe6.33
	int L[8] = { 0, 2, 0, 7, 5, 0, 0, 0};
	int R[8] = { 0, 3, 0, 4, 0, 6, 0, 0};
	if (exe6_33(2, 4, L, R, 7)) { 
		printf("Is child\n");
	}
	else { printf("Not child\n"); }

	//exe6.42
	printf("树总共有 %d 个叶子节点\n",exe6_42_leafcount(root));

	//exe6.43
	exe6_43_switchlrchild(root);
	PreTraverse(root, PrintNode);
	printf("\n");

	//exe6.45
	exe6_45_deletexchildtree(root,4321);
	PreTraverse(root, PrintNode);

	//exe6.47 （队列）

	return 0;


}

//练习6.33
void exe6_33_ischild(int current_node,int target_node,int *L,int *R,int * flag) {
	if ((!current_node)||*flag) { ; }
	else if (current_node == target_node) { *flag = 1; }
	else {
		exe6_33_ischild(L[current_node], target_node, L, R, flag);
		exe6_33_ischild(R[current_node], target_node, L, R, flag);
	}
}

int exe6_33(int first_node, int target_node, int * L, int* R, int n) {
	int flag_exe6_33 = 0;//用于最后返回结果
	if (first_node <= 0 || target_node <= 0 || first_node == target_node||first_node>n||target_node>n) { ; }
	else {
		exe6_33_ischild(first_node,target_node,L,R,&flag_exe6_33);
	}
	return flag_exe6_33;
}

//练习6.42
int exe6_42_leafcount(bTree root) {
	static int leaf_count = 0;
	if (!root) { ; }
	else if (!root->lchild && !root->rchild) { leaf_count++; }
	else {
		exe6_42_leafcount(root->lchild);
		exe6_42_leafcount(root->rchild);
	}
	return leaf_count;
}

//练习6.43
void exe6_43_switchlrchild(bTree root) {
	bNode* temp;
	if (!root) { ; }
	else {
		temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;
		exe6_43_switchlrchild(root->lchild);
		exe6_43_switchlrchild(root->rchild);
	}
}

//练习6.45
int exe6_45_deletexchildtree(bTree root, Elemtype x) {
	if (!root) { ; }
	else {
		if (root->data == x) { DestroybTree(root); return 1; }
		else {
			if (exe6_45_deletexchildtree(root->lchild, x)){ root->lchild = NULL; }
			if (exe6_45_deletexchildtree(root->rchild, x)){ root->rchild = NULL; }
		}
	}
	return 0;
}


