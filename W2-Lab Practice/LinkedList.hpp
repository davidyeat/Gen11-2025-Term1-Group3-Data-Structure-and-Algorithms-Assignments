#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};
class LinkedList{
    private:
        Node *head, *cur;
        int n = 0;
    public:
        LinkedList(){
            head = nullptr;
            cur = nullptr;
        }

        // Challenge1 - Insert at the Front
        void insertFront(int value){
            Node* newNode = new Node{value, nullptr};
            newNode->next = head;
            head = newNode;
            n++;
        }

        // Challenge2 - Insert at the End
        void insertEnd(int value){
            if(head == nullptr){
                insertFront(value);
                return;
            }
            cur = head;
            while (cur->next != nullptr){
                cur = cur->next;
            }
            Node* newNode = new Node{value, nullptr};
            cur->next = newNode;
            n++;
        }

        // Challenge3 - Insert in the Middle
        void insertAt(int value, int pos){
            if(pos <= 0 || pos > n + 1){
                cout << "Cannot insert: Position outside the valid range!" << endl;
                return;
            }
            if(pos == 1){
                insertFront(value);
                return;
            }
            if(pos == n + 1){
                insertEnd(value);
                return;
            }
            cur = head;
            for(int i = 1; i < pos - 1; i++){
                if(cur->next != nullptr){
                    cur = cur->next;
                }
            }
            Node* newNode = new Node{value, nullptr};
            newNode->next = cur->next;
            cur->next = newNode;
            n++;
        }

        // Challenge4 - Delete from the Front
        void deleteFront(){
            if(head == nullptr){
                cout << "Cannot delete from Front: the list is already empty!" << endl;
                return;
            }
            Node* tmp = head;
            head = head->next;
            delete tmp;
            n--;
        }

        // Challenge5 - Delete from the End
        void deleteEnd(){
            if(head == nullptr){
                cout << "Cannot delete from End: the list is already empty!" << endl;
                return;
            }
            if(n == 1){
                delete head;
                head = nullptr;
                n--;
                return;
            }

            cur = head;
            while(cur->next->next != nullptr){
                cur = cur->next;
            }
            cur->next = nullptr;
            n--;
        }

        // Challenge6 - Delete from the Middle
        void deleteAt(int pos){
            if(pos <= 0 || pos > n){
                cout << "Cannot delete: Position outside the valid range!" << endl;
                return;
            }
            if(pos == 1){
                deleteFront();
                return;
            }
            if(pos == n){
                deleteEnd();
                return;
            }
            cur = head;
            for(int i = 1; i < pos - 2; i++){
                if(cur->next != nullptr){
                    cur = cur->next;
                }
            }
            cur->next = cur->next->next;
            n--;
        }

        // Challenge7 - Traverse the List
        void printList(){
            cur = head;
            if(cur == nullptr){
                cout << "List is empty!" << endl;
                return;
            }
            while (cur != nullptr){
                cout << cur->value;
                if(cur->next != nullptr){
                    cout << " -> ";
                }
                cur = cur->next;
            }
            cout << endl;
            cout <<"Size: "<< n << endl;
            cout <<"Head value: "<< head->value << endl;
        }

        // Challenge8 - Swap Two Nodes
        void swapNodes(int posA, int posB){
            if(posA == posB) return;
            if(posA < 1 || posA > n || posB < 1 || posB > n){
                cout << "Cannot swap: One or both position are outside the valid range!" << endl;
                return;
            }

            Node *prevA = nullptr, *currA = head;
            Node *prevB = nullptr, *currB = head;

            // Fisrt Loop to find prevA and currA
            for(int i = 1; i < posA; i++){
                prevA = currA;
                currA = currA->next;
            }
            
            // Second Loop to find prevB and currB
            for(int i = 1; i < posB; i++){
                prevB = currB;
                currB = currB->next;
            }

            // Check if currA is head 
            if(prevA != nullptr){
                prevA->next = currB;
            }else{
                head = currB;
            }

            // Check if currB is head
            if(prevB != nullptr){
                prevB->next = currA;
            }else{
                head = currA;
            }

            // Swap next pointer
            Node* tmp = currB->next;
            currB->next = currA->next;
            currA->next = tmp;
        }         

        // Challenge9 - Search in Linked List
        bool searchTarget(int target){
            cur = head;
            while (cur != nullptr){
                if(cur->value == target) return true;
                cur = cur->next;
            }
            return false;
        }
};