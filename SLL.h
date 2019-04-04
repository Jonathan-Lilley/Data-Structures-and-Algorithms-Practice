#include <iostream>
using namespace std;

/**
 * Base struct for singly linked list element
 * contains value and pointer to next element
 */
struct SLLE{
    int val;
    SLLE* next;
};

/**
 * Generates and returns pointer to new element of value v
 */
SLLE* newSLLE(int v){
    SLLE* lle = new SLLE;
    lle->val = v;
    lle->next = NULL;
    return lle;
}

/**
 * Links two elements -- current and next
 */
void linkSLLE(SLLE* cur, SLLE* n){
    cur->next = n;
}

/**
 * Like a stack, pushes value onto end of linked list
 * Does so by recursively checking for the tail of the linked list, then adding
 * the value v onto it
 */
void push(SLLE* head, int v){
    if(head->next != NULL){
        push(head->next, v);
    }
    else{
        linkSLLE(head, newSLLE(v));
    }
}

/**
 * Finds the tail of the linked list by recursively checking each pointer
 * to see if the next one is NULL. returns this pointer.
 */
SLLE* findTail(SLLE* head){
    if(head->next != NULL){
        return findTail(head->next);
    }
    return head;
}

/**
 * Prints the entire list recursively.
 * Prints current value, then recurses if the next pointer exists.
 */
void printSLL(SLLE* head){
    cout << head->val << " ";
    if(head->next != NULL){
        printSLL(head->next);
    }
}

/** WORK IN PROGRESS -- PROBLEM: Currently does not UNlink the former head
 *                              and new last element links to the penultimate element.
 *                              working on a fix.
 * Reverses the linked list
 * Checks if the next next element is NULL. If not, recurses on the next element
 * If so, continues to the next step, linking the next element to the current element
 */
void reverseSLL(SLLE* head){
    if(head->next->next != NULL){
        reverseSLL(head->next);
    }
    linkSLLE(head->next, head);
}

/** WORK IN PROGRESS -- PROBLEM: Currently does not properly link, not sure why
 * Iteratively reverses a linked list.
 * Creates three additional pointers -- one to keep track of the next element
 *      one to keep set the current element to the next element
 *      and one to keep track of the previous element
 * While the next element is not NULL,
 *      set the pointer keeping track of the next element to the next next element
 *      Link the current element and the previous element
 *      Set the current element to the next element and the next element to the
 *      next next element
 * Finally, link the last element to the pervious element.
 */
void reverseSLLiter(SLLE* head){
    SLLE* nextHead = head->next;
    SLLE* nextToSet = nextHead;
    SLLE* prev = NULL;
    while(nextHead != NULL){
        nextHead = nextHead->next;
        linkSLLE(head, prev);
        head = nextToSet;
        nextToSet = nextHead;
    }
    linkSLLE(head, prev);
}