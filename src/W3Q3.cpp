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

struct Queue
{
	struct Node *top, *bot;
};

int enqueue(struct Queue *queue, int data)
{
    if(queue->top == NULL){
        queue->top = makeNewNode(data);
        queue->bot = queue->top;
        return 1;
    }
    Node *temp = makeNewNode(data);
    temp->next = queue->bot->next;
    queue->bot->next = temp;
    queue->bot = temp;
    return 1;
}

int *dequeue(struct Queue *queue)
{
    if(queue->top == NULL ||queue->bot == NULL){
        return NULL;
    }
    
    if(queue->top == queue->bot){
        int *found_data = &queue->top->data;
        queue->bot = NULL;
        return found_data;
    }
    Node* travelingNode = queue->top;
	while(travelingNode->next != queue->bot){
		travelingNode = travelingNode->next;
	}
    
    int *found_data = &queue->bot->data;
    queue->bot = travelingNode;
    return found_data;


}

int main()
{
	int data, *temp;
	char command[50];
	Queue queue;
	queue.top = NULL;
	queue.bot = NULL;
	while(1)
	{
		scanf("%s", command);
		if(strcmp(command, "exit") == 0)
		{
			break;
		}
		else if(strcmp(command, "enqueue") == 0)
		{
			printf("Please input a integer data:");
			scanf("%d", &data);
			if(enqueue(&queue, data) == 1)
			{
				printf("Successfully enqueue data %d into queue.\n",data);
			}
			else
			{
				printf("Failed to enqueue data into queue.\n");
			}
		}
		else if(strcmp(command, "dequeue") == 0) 
		{
			temp = dequeue(&queue);
			if(temp == NULL)
			{
				printf("Failed to dequeue a data from queue.\n");
			}
			else
			{
				printf("Dequeue data %d from queue.\n", *temp);
			}
		}
	}
}
