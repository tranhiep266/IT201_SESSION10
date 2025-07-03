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
Node* deleteValue(Node* head,int value)
{
   Node* current=head;
   while (current->next!=NULL)
   {
      if (current->next->data==value)
      {
         current->next=current->next->next;
      }else
      {
         current=current->next;
      }
   }
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
   Node* node6 = createNode(50);
   head->next=node2;
   node2->next=node3;
   node3->next=node4;
   node4->next=node5;
   node5->next=node6;
   int value;
   printf("Nhap gia tri muon xoa: ");
   scanf("%d",&value);
   head=deleteValue(head,value);
   printList(head);
   return 0;
}