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


struct node* createHead(char c){
	struct node *result = malloc(sizeof(struct node));
	result->c = c;
	result->left = NULL;
	result->right = NULL;
	result->parent = NULL;
	result->children = 0;
	result->parents = 0;
	return result;
}



int main(){
	struct node *head = createHead('a');
	printf("The head is %c\n", head->c);
}
