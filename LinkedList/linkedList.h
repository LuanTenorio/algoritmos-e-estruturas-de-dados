struct Node {
    int data;
    struct Node *nextNode;
};

typedef struct Node Node;

typedef struct {
    Node *head;
    int len;
} LinkedList;


LinkedList *createLinkedList();
// Node *createNode(int data);
// void setNextNode(Node *node, Node *next);
// Node *createNodeWithNextNode(int data, Node *next);
// void AddNodeAtBegin(LinkedList *list, int data);
void appendNode(LinkedList *list, int data);
Node *getNode(LinkedList *list, unsigned int index);
Node *getLastNode(LinkedList *list);
// void insertNode(LinkedList *list, int data, unsigned int index);
void addNode(LinkedList *list, int data, unsigned int index);
void showList(LinkedList *list);
// Node *selectNodeForDelete(LinkedList *list, unsigned int *index);
void deleteNode(LinkedList *list, unsigned int index);
void pop(LinkedList *list);
// void deleteAllNodes(LinkedList *list);
void deleteLinkedList(LinkedList *list);