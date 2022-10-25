#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "T1remove.h"



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


void RemoveDuplicates(Node** phead){
        if ((*phead) == NULL || (*phead)->next == NULL)//when the linklist is empty or only have one element
        {
            return;
        }
        Node* p1 = *phead;
        Node* p2 = p1;
        Node* p3 = *phead;
        while (p3 != NULL) {//????????§³?size?????????
            while (p3->next != NULL && p3->data == (p3->next)->data) {//??????????????????
                p3 = p3->next;
            }
            if (p2->next == p3) {//????¦Ë????????????????
                p2 = p2->next;
            }
            else {//????linklist????????????p2??????????????-1????????
                p2->next = p3->next;
                p3 = p3->next;
            }
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
        // Output: inserted 3.000000
        //0.000000 1.000000 2.000000 3.000000 3.000000 4.000000
        Node* in = InsertNode(&head, 3, 3);
        printf("inserted %f\n", in->data);
        DisplayList(head);
        printf("\n");
        RemoveDuplicates(&head);
        DisplayList(head);
        DestroyList(head);

        return 0;
    }
