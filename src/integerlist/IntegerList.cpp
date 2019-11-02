// Includes
#include <iostream>
#include <stdlib.h>
#include "IntegerList.h"

using namespace std;

void insertElement(IntegerList** l, int element) {

  IntegerList *new_node;
  new_node = createElement(element);

  IntegerList *prev = (IntegerList *) NULL;
  IntegerList *ptr = * l;

  while (ptr) {
    prev = ptr;
    ptr = ptr->next;
  }

  if (prev) 
    prev->next = new_node;
  else
    (*l) = new_node;
}


// to test or not to test empty list

int removeElement(IntegerList** l, int index) {

  // Assume 1 <= index <= size(l)

  // locate
  IntegerList *prev = (IntegerList *) NULL;
  IntegerList *ptr = *l;

  if (isEmpty(*l)) {
    return 0;         // empty list
  }

  if (index == 1) {
    // element = ptr->data;
    (*l) = ptr->next;
  }
  else {
     for (int i=1; i < index; i++) {
       prev = ptr;
       ptr = ptr->next;
     }

  // remove
     // element = ptr->data;
     prev->next = ptr->next;
  }
  return 1; // removed element
}



/*  Checks whether the value x is present in linked list 
 *  and returns index if found, or 0 
 */

int search(IntegerList* head, int x) {  

    IntegerList* current = head; // Initialize current  
    int index = 0;
    while (current != NULL)  
    {  
        index++;
        if (current->data == x)  
            return index;  
        current = current->next;  
    }  
    return 0;  
} 

