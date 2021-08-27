
#include<stdio.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *next;
};

Node* makeNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* makeNewNode(){
    Node* newNode = new Node();
	newNode->next =	NULL;
    return newNode;
}

struct Stack
{
	struct Node *head, *top;
};

//Push element to the top of the stack
int push(struct Stack *stack, int data)
{
    if(stack->top == NULL){//if head is null then just generate a Node at head
        stack->head = makeNewNode(data);
        stack->top = stack->head;
        return 1;
    }
	//Else go to the top and add a Node infront of it, making sure to connect it
    Node* temp = makeNewNode(data);
    stack->top->next = temp;
    stack->top = temp;
    return 1;
}

//Pop the top element of stack
int *pop(struct Stack *stack)
{

    if(stack->top == NULL || stack->head == NULL){//If no elements in the stack then return NULL.
        return NULL;
    }
	if(stack->top == stack->head){//If there is only one element, make the top NULL but keep head reference
		int *found_data = &stack->head->data;
		stack->top = NULL;
		return found_data;
	}
    Node* travelingNode = stack->head;//Make a Node pointing to the head node of the given Stack

	while(travelingNode->next != stack->top){//Tranverse through the list until the node before the top
		travelingNode = travelingNode->next;
	}

	int* found_data = &stack->top->data;//Point to the data that top is CURRENTLY pointing at
	stack->top = travelingNode;//Move top a node back
	return found_data;

}

int main()
{
    int data, *temp;
	char command[50];
	struct Stack stack;
	stack.head = NULL;
	stack.top = NULL;
	while(1)
	{
		scanf("%s", command);
		if(strcmp(command, "exit") == 0)
		{
			break;
		}
		else if(strcmp(command, "push") == 0)
		{
			printf("Please input a integer data:");
			scanf("%d", &data);
			if(push(&stack, data) == 1)
			{
				printf("Successfully push data %d into stack.\n",data);
			}
			else
			{
				printf("Failed to push data into stack.\n");
			}
		}
		else if(strcmp(command, "pop") == 0) 
		{
			temp = pop(&stack);
			if(temp == NULL)
			{
				printf("Failed to pop a data from stack.\n");
			}
			else
			{
				printf("Pop data %d from stack.\n", *temp);
			}
		}
	}
}
