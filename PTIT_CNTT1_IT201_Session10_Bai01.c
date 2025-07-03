#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
   int data;
   struct Node *next;
}Node;
Node* createNode(int data)
{
   Node* node = (Node*)malloc(sizeof(Node));
   node -> data = data;
   node -> next = NULL;
   return node;
}
void printList(Node* head)
{
   Node* current=head;
   int index=1;
   current=head;
   while (current!=NULL)
   {
      printf("data %d: %d\n",index,current->data);
      index++;
      current=current->next;
   }
}
int main(){
   Node* head = createNode(10);
   Node* node2 = createNode(20);
   Node* node3 = createNode(30);
   Node* node4 = createNode(40);
   Node* node5 = createNode(50);
   head->next=node2;
   node2->next=node3;
   node3->next=node4;
   node4->next=node5;
   printList(head);
   return 0;
}