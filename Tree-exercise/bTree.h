#define Elemtype int

//二叉树
typedef struct _bNode {
	int id;
	Elemtype data;
	struct _bNode* lchild, *rchild;
}bNode, *bTree;

//树的双亲表示法
#define PTREE_SIZE 10
typedef struct _pNode {
	Elemtype data;
	int parent;//双亲的数组索引
}pNode;

typedef struct _pTree {
	pNode nodes[PTREE_SIZE];
}pTree;


typedef enum {ERROR,OK} Status;

//函数原型
bTree buildbTreebydata(Elemtype* nodes, int num);
void buildbTreebydata_Pre(bTree root, int id, Elemtype data);
void PrintNode(bNode* pnode);
void PreTraverse(bTree root, void (*ptrFunc)(bNode* pnode));
void InTraverse(bTree root, void (*ptrFunc)(bNode* pnode));
void DestroybTree(bTree root);
