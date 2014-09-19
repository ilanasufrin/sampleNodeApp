#include <stdio.h>
#include <stdlib.h>

struct l_node {
  int value;
  struct l_node *next;
};

typedef struct l_node node;

node* create_node(int value, node* next);
int dequeue(node* head);

int main(int argc, char* argv[])
{
  node *head = create_node(13, NULL);
  head = create_node(12, head);
  head = create_node(11, head);
  printf("%d\n", dequeue(head));
  printf("%d\n", dequeue(head));
  printf("%d\n", dequeue(head));
  return 0;
}

node* l_node_index(node* head, int index) {
  for(int i = 0;i < index;i++) {
    head = head->next;
  }
  return head;
}

int dequeue(node* head) {
  while(head->next->next != NULL) {
    head = head->next;
  }
  node* lastThing = head->next;
  head->next = NULL;
  int returnValue = lastThing->value;

  free(lastThing);

  return returnValue;
}

node* create_node(int value, node* next) {
  node* newNode = malloc(sizeof(node));
  newNode->value = value;
  newNode->next = next;
  return newNode;
}
