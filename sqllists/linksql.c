#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 初始化带头结点的链表
Node* initList() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    head->data = 0;  // 头结点不存储有效数据
    head->next = NULL;
    return head;
}

// 头插法添加节点（插入到头结点之后）
void insertAtHead(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
}

// 尾插法添加节点
void insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 查找节点
Node* findNode(Node* head, int data) {
    Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// 删除节点
void deleteNode(Node* head, int data) {
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

// 遍历链表
void traverseList(Node* head) {
    Node* temp = head->next; // 从头结点的下一个节点开始
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 销毁链表
void destroyList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    Node* head = initList();

    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    traverseList(head); // 输出: 1 -> 2 -> 3 -> NULL

    insertAtTail(head, 4);
    insertAtTail(head, 5);

    traverseList(head); // 输出: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    deleteNode(head, 3);

    traverseList(head); // 输出: 1 -> 2 -> 4 -> 5 -> NULL

    destroyList(head);

    return 0;
}

