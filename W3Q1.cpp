#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};

struct Set
{
	struct Node *element;
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
//Determines if a value exist inside a Set
//Recieves a Set and a value, returns accordingly
bool findInSet(Set* _set, int val){
	
    Node* travelingNode = _set->element;
	while(travelingNode != NULL){
		if(travelingNode->data == val){
			return true;
		}
		travelingNode = travelingNode->next;
	}
	return false;
}

//Add element to given Set
//It will make sure the given value is unique
//Recives a Set and a value
int addElement(struct Set *set, int e)
{
    Node* travelingNode = set->element;
    if(travelingNode == NULL){
        set->element = makeNewNode(e);
        return e;
    }
    while (travelingNode->next != NULL)
    {
        if(travelingNode->data == e){//If found the input  ber on the List then stop the process.
            return -1;
        }
		else if(travelingNode->data >= e){
			break;
		}
        travelingNode = travelingNode->next;//Else move the following one.
    }

	if(travelingNode->data == e){//Since the loop can't catch if the last value
								 //is the same as the inputted one, we check manually
		return -1;
	}

    Node* temp = makeNewNode(e);
    temp->next = travelingNode->next;
    travelingNode->next = temp;
    return e;
    
}
//Prints given Set
//Outputs endline afterwards
void printSet(Set* _set){
	Node* travelingNode = _set->element;
	while(travelingNode != NULL){
		cout<<travelingNode->data<<" ";
		travelingNode = travelingNode->next;
	}
	cout<<endl;
}

//Return a new Set with the Union of two Sets
//The union of two sets A and B is the set of elements which are in A, in B, or in both A and B.
//Recives two Sets
Set *unions(Set *a, Set *b)
{
	if(a == NULL){
		return b;
	}

	Set* temp = new Set();
	Node* travelingNodeA = a->element;
	while(travelingNodeA != NULL){
		addElement(temp,travelingNodeA->data);
		travelingNodeA = travelingNodeA->next;
	}

	Node* travelingNodeB = b->element;
	while(travelingNodeB != NULL){
		if(!findInSet(temp,travelingNodeB->data)){
			addElement(temp,travelingNodeB->data);
		}
		travelingNodeB = travelingNodeB->next;
	}

	return temp;

}


//Return new Set with the Intersection of two Sets
//The intersection of two sets A and B, denoted by is the set of all objects that are members of both the sets A and B.
//Recives two Sets
Set *intersetcions(Set *a, Set *b)
{
	Set* newSet = new Set();
	Node* tempA = a->element;
	Node* tempB = b->element;

	while(tempA != NULL){
		if(!findInSet(b, tempA->data)) addElement(newSet,tempA->data);
		tempA = tempA->next;
	}
	while(tempB != NULL){
		if(!findInSet(a, tempB->data)) addElement(newSet,tempB->data);
		tempB = tempB->next;
	}

	return newSet;
	
}

//Determines if two Sets are Equivalent
//Two sets are equivalent to each other if the number of elements in both the sets is equal
//Recives two Sets
int equivalent(Set *a, Set *b)
{
	Node* travelingNodeA = a->element;
	Node* travelingNodeB = b->element;
	int aSize = 0;
	int bSize = 0;
	while(travelingNodeA != NULL){
		aSize++;
		travelingNodeA = travelingNodeA->next;
	}
	while(travelingNodeB != NULL){
		bSize++;
		travelingNodeB = travelingNodeB->next;
	}
	if(aSize == bSize){
		return true;
	}
	return false;
}

int main()
{
	struct Set *a = (struct Set *)malloc(sizeof(struct Set));
	struct Set *b = (struct Set *)malloc(sizeof(struct Set));
	struct Set *c;
	struct Node *cur;
	
	addElement(a, 1);
	addElement(a, 2);
	addElement(a, 3);
	addElement(b, 3);
	addElement(b, 4);
	addElement(b, 5);
	addElement(b, 5);
	
	c = unions(a, b);
	cur = c->element;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	
	c = intersetcions(a, b);
	cur = c->element;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	
	if(equivalent(a, b) == 0)
		printf("Not equivalent.\n");
	else
		printf("Equivalent!\n");
}
