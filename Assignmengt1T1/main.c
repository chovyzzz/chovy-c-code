#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Delete.h"

typedef struct node{
    double data;
    struct node* next;
} Node;

bool IsEmpty(Node* head) {
    // If the head node is NULL then the linked list is empty.
    return head == NULL;
}

Node* InsertNode(Node** phead, int index, double x) {
    if (index < 0) return NULL;

    // Try to locate the node at position index.
    // If it does not exist, return NULL.
    int currIndex = 1;
    Node* currNode = *phead;
    while (currNode != NULL && index > currIndex) {
        currNode = currNode->next;
        currIndex++;
    }
    if (index > 0 && currNode == NULL) return NULL;

    // Create a new Node.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    if (index == 0) {
        // Insert as the new head:
        newNode->next = *phead;
        *phead = newNode;
    }
    else {
        // Insert after currNode:
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return newNode;
}

int FindNode(Node* head, double x) {
    Node* current = head;
    // Position counting starts from 1.
    int pos = 1;
    while (current != NULL) {
        if (current->data == x) {
            return pos;
        }
        pos++;
        current = current->next;
    }
    // We have reached the end of the list so the list does not contain x.
    return 0;
}


void DisplayList(Node* head){
    Node* current = head;
    while (current != NULL) {
        printf("%f ", current->data);
        current = current->next;
    }
    printf("\n");
}

void DestroyList(Node* head){
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int DeleteNode(Node** phead, double x){

    Node* p1 = NULL;
    Node* p2 = NULL;
    p1 = *phead;
    int a = 0;//记录有多少个要找的值
    if (p1 == NULL){//p1指向原链表的头节点，若为空则说明原linklist为空
        return 0;//返回删除的位置
    }
    p2 = p1->next;//把p1传入p2
    if (*phead != NULL && (*phead)->data == x)//判断头节点是否为要寻找的值
    {
        p2 = *phead;
        *phead = p2->next;
        free(p2);
        a++;
    }

    while (p2 != NULL)//当要删除的值不是头节点时,历尽后面的所有来删除链表中所有对应的值
    {
        if (p2->data == x){
            p1->next = p2->next;
            free(p2);
            p2 = p1->next;
            a++;
        }else{
            p1 = p1->next;
            p2 = p2->next;//往后读取
        }
    }
    return a;

}


    int main(){
        Node* head = NULL;
        // Output: true
        printf("%s\n", IsEmpty(head) ? "true" : "false");

        // Must output an empty line:
        DisplayList(head);

        // Must output "insert failed":
        Node* result = InsertNode(&head, 20, 7);
        printf("%s\n", result == NULL ? "insert failed" : "insert succeeded");

        // Output: 0.000000 1.000000 2.000000 3.000000 4.000000
        for (int i = 0; i < 5; i++) {
            InsertNode(&head, i, i);
        }
        DisplayList(head);

        // Output: false
        printf("%s\n", IsEmpty(head) ? "true" : "false");

        // Output: inserted 3.000000
        // 0.000000 1.000000 2.000000 3.000000 3.000000 4.000000
        Node* in = InsertNode(&head, 3, 3);
        printf("inserted %f\n", in->data);
        DisplayList(head);
        printf("\n");
        int k = DeleteNode(&head,4);
        printf("%d Node(s) has been deleted\n",k);
	 DisplayList(head);
        DestroyList(head);

        return 0;
    }
