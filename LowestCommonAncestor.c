#include <stdio.h>
#include <stdlib.h>

struct node{
	char c;
	struct node *left;
	struct node *right;
	struct node *parent;
	int children;
	int parents;
};


struct node* createNode(char c){
	struct node *result = malloc(sizeof(struct node));
	result->c = c;
	result->left = NULL;
	result->right = NULL;
	result->parent = NULL;
	result->children = 0;
	result->parents = 0;
	return result;
}

void addNode(struct node* newNode, struct node *head){
	if (newNode->c < head->c){
		if(head->left == NULL){
			head->left = newNode;
			head->parent = head;
			return;
		}
		else{
			addNode(newNode,head->left);
		}
	}
	else{
		if(head->right == NULL){
			head->right = newNode;
			newNode->left = head;
			return;
		}
		else{
			addNode(newNode,head->left);
		}
	}
	return;
}


int main(){
	struct node *head = createNode('c');
	printf("The head is %c\n", head->c);
	struct node *newNode = createNode('a');
	addNode(newNode, head);
	printf("Added node is %c\n", head->left->c);
	newNode = createNode('f');
	addNode(newNode, head);
	printf("Added node is %c\n", head->right->c);
}
