#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ReverseList.h"


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


void DisplayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%f ", current->data);
        current = current->next;
    }
    printf("\n");
}

void DestroyList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}


void ReverseList(Node** phead) {//通过两个指针，让第二个节点从链表中“脱离出来”，然后再将脱离出来的节点设置为phead，并一直反复进行，直到第一个节点和第一个结点的后一个节点为空就停止
        Node* p1 = NULL;
        Node* p2 = NULL;
        if (*phead == NULL || (*phead)->next == NULL) {
            return;
        }
        p1 = *phead;
        p2 = (*phead)->next;
        while (p2 != NULL) {
            p1->next = p2->next;//remove the p2 out of linklist
            p2->next = (*phead);//make p2 to the linklist head
            (*phead) = p2;
            p2 = p1->next;//Prepare to reverse the next node
        }
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
        // Output: inserted 10.000000
        //0.000000 1.000000 2.000000 3.000000 3.000000 4.000000
        Node* in = InsertNode(&head, 3, 3);
        printf("inserted %f\n", in->data);
        DisplayList(head);
        printf("\n");
        ReverseList(&head);
        DisplayList(head);
        DestroyList(head);

        return 0;
    }
