#include <stdio.h>
#include <stdlib.h>

struct linkedListElement{

	struct linkedListElement *next;
	struct linkedListElement *prev;
	int value;
};

void printList(struct LinkedList* llist) {
    struct Node* tnode = llist->head;
    while (tnode != NULL) {
        printf("%d ", tnode->data);
        tnode = tnode->next;
    }
}


void listAdd(struct linkedListElement *newListElement){
	if (listHead == NULL){
	
		listHead = newListElement;

	} else if (listHead->value >= newListElement->value){
		newListElement->next = listHead;
		listHead->prev = newListElement;
		listHead = newListElement;
	} else {
	
		struct linkedListElement *iterator = listHead;
		while(iterator->next != NULL && iterator->next->value < newListElement->value){
		
			iterator = iterator->next;
		}
		newListElement->next = iterator->next;
		iterator->next = newListElement;
	}

}

void listRemove(struct linkedListElement *element){

	if (element == listHead){
	
		listHead = element->next;
		if(listHead == NULL){
			element->prev = NULL;
		}
	} else if (element->next != NULL){
		struct linkedListElement *test = listHead;
		while (test->next != element){
		
			test = test->next;
		}
		test->next = element->next;
	} else if (element->next == NULL){
		struct linkedListElement *new = listHead;
		while (new->next != element){
		
			new = new->next;
		}

		new->next = NULL;

			
	}
	free(element);

}

struct linkedListElement *listHead = NULL;
int main(){
	struct linkedListElement *newElement = malloc(sizeof(struct linkedListElement));

	newElement->value = 7;
	newElement->next = NULL;
	
	listAdd(newElement);

	struct linkedListElement *newElement2 = malloc(sizeof(struct linkedListElement));

	newElement2->value = 1;
	newElement2->next = NULL;
	listAdd(newElement2);

	struct linkedListElement *newElement3 = malloc(sizeof(struct linkedListElement));
	newElement3->value = 3;
	newElement3->next = NULL;

	struct linkedListElement *newElement4 = malloc(sizeof(struct linkedListElement));
	newElement3->value = 2;
	newElement3->next = NULL;

	printf("Created Linked List : \n");
	printList(linkedListElement);
	
}

