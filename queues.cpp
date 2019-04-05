#include <iostream>
using namespace std;

#define MAX 10

/**
 * Queue class
 * Private variables:
 *      tail and head; to keep track of where the tail and head of queue are
 * Public:
 *      int q[MAX]: array of integers of size MAX, the queue itself
 *      Constructor: Sets tail and head to 0
 *      isEmpty checks if the tail and head are the same index; if so, it's empty
 *      isFull checks if the queue is full
 *      enqueue adds an item to the tail of the queue
 *      dequeue takes an item off the head of the queue
 *      getTail returns tail index
 *      getHead returns head index
 */
class Queue{
    private:
        int tail;
        int head;
    public:
        int q[MAX];
        
        Queue() { tail = 0; head = 0; }
        bool isEmpty() { return (tail == head); };
        bool isFull();
        bool enqueue(int);
        int dequeue();
        int getTail() { return tail; }
        int getHead() { return head; }
};

/**
 * Returns if the queue is full
 * The queue is full if the tail is one less than the head or if the tail is 
 * one less than MAX and the head is 0
 */
bool Queue::isFull(){
    if(tail+1 == MAX){
        return (head == 0);
    }
    return (tail+1 == head);
}

/**
 * Adds an element to the tail of the queue
 * If the queue is full, outputs that the queue is full
 * Else, sets the tail value equal to x and increments x
 * if tail is now MAX, sets tail to 0
 */
bool Queue::enqueue(int x){
    if(isFull()){
        cout << "queue full" << endl;
        return false;
    }
    q[tail++] = x;
    if(tail == MAX){
        tail = 0;
    }
    return true;
}

/**
 * Takes an element off the head of the queue
 * If the queue is empty, output the queue is empty and return 0
 * Else, make the value to return equal to the head and increment the head
 * If the head is equal to MAX, set head equal to 0
 * return the value
 */
int Queue::dequeue(){
    if(isEmpty()){
        cout << "queue empty" << endl;
        return 0;
    }
    int x = q[head++];
    if(head == MAX){
        head = 0;
    }
    return x;
}

//tests
int main(){
    Queue queue;
    cout << "empty?: " << queue.isEmpty() << endl;
    for(int i=1; i<11; i++){
        cout << "enqueue " << i << ": " << queue.enqueue(i) << endl;
        cout << "head: " << queue.getHead() << ", tail: " << queue.getTail() << endl;
    }
    cout << "enqueue 10: " << queue.enqueue(10) << endl;
    cout << "full?: " << queue.isFull() << endl;
    for(int i=0; i<10; i++){
        cout << "dequeue element " << i << ": " << queue.dequeue() << endl;
    }
    return 0;
}