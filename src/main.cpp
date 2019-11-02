// Use the functions implemented in question 1 to create a linked list of integers from a given array of integers of size N.
// Includes
#include <iostream>
#include <stdlib.h>
#include "IntegerList.h"

using namespace std;

int main() {

   int sequencia;
   int N = 100;
   int arr[N];
   int i = 0;

   // Lembrar que o limite de 100 não é testado aqui. Toy example.
   while ((cin >> sequencia) && (sequencia != 0)) {
      arr[i] = sequencia;
      i++;
   }

   int sizearr = i;

   IntegerList* head = NULL;
     
   /* initialize random seed: */
   srand (time(NULL));
   int middle = rand() % sizearr + 1;

   i = 0;
   while (i < sizearr) {
        insertElement(&head, arr[i]);
        i++;
   }

   printList(head);
   cout << size(head) << endl;
   // cout << isEmpty(head) << endl;

   if (sizearr > 2) {
     cout << "Removed middle element: " << removeElement(&head,middle) << endl;
     printList(head);
   }

   cout << "Removed first element: " << removeElement(&head,1) << endl;
   printList(head);

   cout << "Removed last element: " << removeElement(&head,size(head)) << endl;
   printList(head);

   int busca = search(head, 5);
   busca? cout << "Yes, found " << 5 << ", index: " << busca <<endl : cout << "No" <<endl;

}
