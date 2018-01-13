


# include<iostream>
#include "HW4-Todo-QueueLinkedList.hpp"
using namespace std;

TodoQueueLinkedList:: TodoQueueLinkedList(){
	queueFront = queueEnd = NULL;

}

TodoQueueLinkedList:: ~TodoQueueLinkedList(){
	while(queueFront != NULL){
		TodoItem *temp = queueFront;
		queueFront = queueFront -> next;
		delete temp;
	}
	queueEnd = NULL;
}

void TodoQueueLinkedList:: enqueue(std::string todoItem){
	TodoItem *temp = new TodoItem;
	
	temp -> todo = todoItem;
	temp -> next = nullptr;
	if(queueFront == nullptr){
		queueFront = temp;
		queueEnd = temp;
	}
	else{
		queueEnd -> next = temp;
		queueEnd = temp;
	}
}

void TodoQueueLinkedList:: dequeue(){

	TodoItem* temp = new TodoItem;
	string node = temp -> todo;
	if(queueFront != NULL){
		queueFront = queueFront -> next;
		delete temp;
	} 
	else{
		cout<<"Queue empty, cannot dequeue an item."<<endl;
	}
	return ;
}

bool TodoQueueLinkedList:: isEmpty(){
	return (queueFront == NULL);
}

TodoItem* TodoQueueLinkedList:: peek(){

	if(queueFront != NULL){
		return queueFront ;
	}
	else{
		return NULL;
	}
}