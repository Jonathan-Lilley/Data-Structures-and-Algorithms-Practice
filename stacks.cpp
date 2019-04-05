#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

/**
 * Stack class
 * Private variable:
 *      top index of stack
 * Public:
 *      int a[MAX]: the stack itself of size MAX
 *      Default constructor: sets top equal to -1
 *      push pushes a new value onto the stack
 *      pop pulls a value off the top of the stack
 *      isEmpty returns whether the stack is empty
 */
class Stack{
    private:
        int top;
    public:
        int a[MAX];
        
        Stack() { top = -1; }
        bool push(int);
        int pop();
        bool isEmpty() { return (top<0); }
};

/**
 * push
 * If the stack is at tis maximum, print out "Stack overflow" and return false
 * Else, increment the top of the stack, then set that value to x
 */
bool Stack::push(int x){
    if(top >= (MAX-1)){
        cout << "stack overflow" << endl;
        return false;
    }
    else{
        a[++top] = x;
        return true;
    }
}

/**
 * If the stack is at its minimum, print out "stack underflow"
 * Else, return the top value and decrement top
 */
int Stack::pop(){
    if(top < 0){
        cout << "stack underflow" << endl;
            return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

//tests
int main(){
    Stack stack;
    cout << "True " << true << endl;
    cout << "isEmpty (true): " << stack.isEmpty() << endl;
    cout << "push 5: " << stack.push(5) << endl;
    cout << "push 10: " << stack.push(10) << endl;
    cout << "pop (10): " << stack.pop() << endl;
    cout << "pop (5): " << stack.pop() << endl;
    return 0;
}