#define Elemtype int

//������
typedef struct _bNode {
	int id;
	Elemtype data;
	struct _bNode* lchild, *rchild;
}bNode, *bTree;

//����˫�ױ�ʾ��
#define PTREE_SIZE 10
typedef struct _pNode {
	Elemtype data;
	int parent;//˫�׵���������
}pNode;

typedef struct _pTree {
	pNode nodes[PTREE_SIZE];
}pTree;


typedef enum {ERROR,OK} Status;

//����ԭ��
bTree buildbTreebydata(Elemtype* nodes, int num);
void buildbTreebydata_Pre(bTree root, int id, Elemtype data);
void PrintNode(bNode* pnode);
void PreTraverse(bTree root, void (*ptrFunc)(bNode* pnode));
void InTraverse(bTree root, void (*ptrFunc)(bNode* pnode));
void DestroybTree(bTree root);
