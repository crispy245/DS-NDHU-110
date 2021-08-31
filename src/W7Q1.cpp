#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stack>
#include <iostream>

struct Node
{
	int data, level;
	struct Node *left, *right;	
};

void insert(struct Node **root, struct Node *node)
{
	if(*root == NULL)
		*root = node;
	else if(node->data > (*root)->data)
		insert(&((*root)->right), node);
	else
		insert(&((*root)->left), node);
}

void inorder(struct Node *root)
{
    if(root == NULL) return;
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if(root == NULL) return;
    std::cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if(root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    std::cout<<root->data<<" ";
}

void levelorder(struct Node *root)
{
}

int main()
{
	struct Node *tree = NULL, *node;
	int j;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = (struct Node *)malloc(sizeof(struct Node));
		node->data = rand()%10;
		node->left = NULL;
		node->right = NULL;
		insert(&tree, node);
	}
	inorder(tree);
	printf("\n");
	preorder(tree);
	printf("\n");
	postorder(tree);
	printf("\n");
	levelorder(tree);
	printf("\n");
}