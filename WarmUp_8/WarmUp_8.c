#include <stdio.h>
#include <stdlib.h>

// Chatgpt4 was used to help understand malloc. This code was adapted from work
// on a previous assignment in comp 264.
struct Node {
  struct Node *next;
  int data;
};

struct Node *listHead = NULL;

void printList(struct Node *head) {
  struct Node *tnode = head;
  while (tnode != NULL) {
    printf("%d ", tnode->data);
    tnode = tnode->next;
  }
  printf("\n");
}

void push(struct Node *newListElement) {
  newListElement->next = NULL;

  if (listHead == NULL) {
    listHead = newListElement;
  } else {
    struct Node *iterator = listHead;
    while (iterator->next != NULL) {
      iterator = iterator->next;
    }
    iterator->next = newListElement;
  }
}

void delete (struct Node *element) {
  if (element == NULL)
    return;

  if (element == listHead) {
    listHead = element->next;
    free(element);
    return;
  }
  struct Node *prev = listHead;
  while (prev != NULL && prev->next != element) {
    prev = prev->next;
  }
  if (prev != NULL) {
    prev->next = element->next;
    free(element);
  }
}

int main() {
  struct Node *newElement = malloc(sizeof(struct Node));
  newElement->data = 2;
  newElement->next = NULL;
  push(newElement);

  struct Node *newElement2 = malloc(sizeof(struct Node));
  newElement2->data = 3;
  newElement2->next = NULL;
  push(newElement2);

  struct Node *newElement3 = malloc(sizeof(struct Node));
  newElement3->data = 1;
  newElement3->next = NULL;
  push(newElement3);

  struct Node *newElement4 = malloc(sizeof(struct Node));
  newElement4->data = 7;
  newElement4->next = NULL;
  push(newElement4);

  printf("Created Linked List: \n");
  printList(listHead);

  delete (newElement3);
  printf("Linked List after Deletion of 1: \n");
  printList(listHead);

  return 0;
}
