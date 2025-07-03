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
int getLength(Node* head)
{
   int count=0;
   Node* current=head;
   while (current!=NULL)
   {
      count++;
      current=current->next;
   }
   return count;
}
Node* deleteLast(Node* head)
{
   if (head->next==NULL)
   {
      free(head);
      return NULL;
   }
   Node* current=head;
   while (current->next->next!=NULL)
   {
      current=current->next;
   }
   free(current->next);
   current->next=NULL;
   return head;
}
void printList(Node* head)
{
   Node* current=head;
   while (current!=NULL)
   {
      printf("%d",current->data);
      if (current->next!=NULL)
      {
         printf("->");
      }
      current=current->next;
   }
   printf("->NULL\n");
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
   head=deleteLast(head);
   printList(head);
   return 0;
}