#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
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

//int DeleteNode(Node** phead, double x) {
//    Node* current = *phead;
//    Node* previous = NULL;
//    // Position counting starts from 1.
//    int pos = 1;
//    while (current != NULL) {
//        if (current->data == x) {
//            // current now points at the node we want to delete.
//            // First we remove that node from the list.
//            if (previous == NULL) {
//                // Removing the head node from the list:
//                *phead = current->next;
//            }
//            else {
//                // Removing a node in the middle or at the end of the list:
//                previous->next = current->next;
//            }
//            // Then we delete the node and return its position:
//            free(current);
//            return pos;
//        }
//        // The current node is not the one we are looking for so we keep searching:
//        pos++;
//        previous = current;
//        current = current->next;
//    }
//    // We have reached the end of the list so the list does not contain x.
//    return 0;
//}

void DisplayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
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

int DeleteNode(Node** phead, double x){

    Node* p1 = NULL;
    Node* p2 = NULL;
    p1 = *phead;
    int a = 0;//��¼�ж��ٸ�Ҫ�ҵ�ֵ
    if (p1 == NULL){//p1ָ��ԭ�����ͷ�ڵ㣬��Ϊ����˵��ԭlinklistΪ��
        return 0;//����ɾ����λ��
    }
    p2 = p1->next;//��p1����p2
    if (*phead != NULL && (*phead)->data == x)//�ж�ͷ�ڵ��Ƿ�ΪҪѰ�ҵ�ֵ
    {
        p2 = *phead;
        *phead = p2->next;
        free(p2);
        a++;
    }

    while (p2 != NULL)//��Ҫɾ����ֵ����ͷ�ڵ�ʱ,���������������ɾ�����������ж�Ӧ��ֵ
    {
        if (p2->data == x){
            p1->next = p2->next;
            free(p2);
            p2 = p1->next;
            a++;
        }else{
            p1 = p1->next;
            p2 = p2->next;//�����ȡ
        }
   }
    return a;

}
void RemoveDuplicates(Node** phead){
	/*Node* p1 = NULL;     
        p1=*phead;
       Node* p2 = p1->next;
        Node* p3 = p1;
        while(p1){
		while(p2) {       
	           if(p1->data == p2->data){
				(p3->next) = (p2->next);
				free(p2);
				p2 = p3->next;
				}else{
				p3 = p2;
				p2 = p2->next;
				}
		}
		p1 = p1->next;
	}
	*phead = p1;*/
		
		
		
		if((*phead)==NULL || (*phead)->next==NULL)
       {
           return ;
       }
       Node* p1 = *phead;
	Node* p2 = p1;
	Node* p3 = *phead;
	while(p3 != NULL) {
		//if(p3->next != NULL && p3->data == p3->next->data) {
			while(p3->next != NULL && p3->data == (p3->next)->data) {
				p3 = p3->next;
			}
		if(p2 ->next == p3){
			p2 = p2->next;
		}else{
			p2->next = p3->next;
			p3 = p3->next;
		}
	}
	//*phead = p1->next;
	/*Node* p;
	Node* q;
	Node* s;
	Node* r;
 	int count=0;
 	for(p=(*phead)->next;p!=NULL;p=p->next){ 
     		s=p;
		r=*phead;  
  		for(q=p->next;q!=NULL;q=q->next){
   			if(p->data == q->data){
       			s->next =q->next;
       			q->next=NULL;
       			q=s;//q��ǰ�ƶ�����ִ��q=q->pnext�����ָ��s����һ����� 
       			count++;
   			}else{
     s=s->next;
				}
  }
  if(count!=0){
   r->next=p->next;
   p->next=NULL;
   p=r;
   count=0;
  }
  else
    r=r->next;
 }*/
}
    /*Node* p1 = (* phead);
	Node* p2 = p1->next;
    while (p2 != NULL){
	p2 = p1->next;//��p1����p2
    if (*phead != NULL && (*phead)->data == p2->data)//�ж�ͷ�ڵ��Ƿ�ΪҪѰ�ҵ�ֵ
    {
        p2 = *phead;
        *phead = p2->next;
        free(p2);
    }
while (p2 != NULL)//��Ҫɾ����ֵ����ͷ�ڵ�ʱ,���������������ɾ�����������ж�Ӧ��ֵ
    {
        if (p2->data == p2->data){
            p1->next = p2->next;
            free(p2);
            p2 = p1->next;
        }else{
            p1 = p1->next;
            p2 = p2->next;//�����ȡ
        }
   }
		/*
        if ((*phead)->data == ((*phead)->next)->data){//����ҵ���ǰ�ڵ��������һ������ֵ��ͬ��ɾ������һ�����
   		while(p1->next->data = (*phead)->data){
			(*phead) = p1->next;
			p1=p1->next;
				}
	}else if(p2->next->data == p2->data){
		while(p2->next->data == p2->data){
				p1->next = p2->next;
            free(p2);
            p2 = p1->next;
				}
			}else{
            p1 = p1->next;
		p2 = p2->next;
           //���û���ҵ�����ǰ�ڵ����
        }*/
    //}
    //return phead;
//}
void ReverseList(Node** phead) {//ͨ������ָ�룬�õڶ���ָ��ָ���һ���ڵ㣬������ָ��ָ��ڶ����ڵ�����ת��һֱ���������ڵ�Ϊ�գ�
    if (*phead == NULL || (*phead)->next == NULL) {//����Ϊ�ջ���������ֻ��һ��ֵ
        return;
    }
    else {
        Node* p1 = NULL;
        Node* p2 = (*phead);//ָ��ͷ�ڵ�
        Node* p3 = (*phead)->next;//ָ��ͷ�ڵ��һ���ڵ�
        while (1) {//һֱ����
            p2->next = p3;//�޸�p2��ָ�ڵ��ָ��         
            if (p3 == NULL) {//��ʱ�ж�p3�Ƿ�Ϊ NULL������������˳�ѭ��
                break;
            }
            p1 = p2;
            p2 = p3;
            p3 = p3->next;//��������ƶ�
        }
        *phead = p2;//�޸�ͷָ���ָ��

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

        // Output: 4.000000 3.000000 2.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
       

        

        // Output: inserted 10.000000
        //         4.000000 3.000000 2.000000 10.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
        Node* in = InsertNode(&head, 3, 3);
        printf("inserted %f\n", in->data);
        DisplayList(head);
        printf("\n");
        //int k = DeleteNode(&head,4);
        //printf("%d",k);
        ReverseList(&head);
        DisplayList(head);
        DestroyList(head);

        return 0;
    }
