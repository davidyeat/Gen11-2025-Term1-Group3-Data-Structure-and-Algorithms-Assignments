#include <iostream>
#include "LinkedList.hpp"
using namespace std;
  
int main(){
    LinkedList list;

    list.insertFront(10);
    list.insertEnd(20);
    list.insertAt(30, 2);
    
    list.deleteFront();
    list.deleteEnd();
    list.deleteAt(1);
    
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);

    list.swapNodes(2, 4);   // Output: 1 -> 4 -> 3 -> 2 -> 5

    list.printList();

    return 0;
}