#include <iostream>
#include "HW4-Todo-QueueArray.hpp"

using namespace std;

TodoQueueArray::TodoQueueArray(){
	queueFront = -1;
	queueEnd = -1;
	for(int i= 0; i< MAX_QUEUE_SIZE ; i++){
		queue[i] = new TodoItem;
		
	}
}


bool TodoQueueArray::isEmpty(){
	if(queueFront == -1 && queueEnd == -1){
		return true;
	}
	else {
		return false;
	}
}


bool TodoQueueArray::isFull(){
	return (queueEnd+1)%MAX_QUEUE_SIZE == queueFront ? true : false;
}

void TodoQueueArray::enqueue(std::string todoItem){
	if(isFull()){
	cout<<"Queue full, cannot add new todo item."<<endl;
	return;
}
 if(isEmpty()){
	queueFront = queueEnd = 0;
	queue[queueFront] -> todo = todoItem;
	return;
}
queueEnd++;
if( queueEnd > MAX_QUEUE_SIZE -1){
		
		queueEnd = 0;
}
queue[queueEnd] -> todo =todoItem;
return;

}
	


void TodoQueueArray::dequeue(){
	
		if(isEmpty())
		{
			cout<<"Queue empty, cannot dequeue an item."<<endl;
			
		}
		else if(queueFront == queueEnd ) 
		{
			queueEnd = queueFront = -1;
		}
		else
		{
			queueFront = (queueFront+1)%MAX_QUEUE_SIZE;
		}
}

TodoItem* TodoQueueArray:: peek(){

if(isEmpty()){
	cout<<"Queue empty, cannot peek."<<endl;
	return NULL;
}
else{
	return queue[queueFront];
}
	
}