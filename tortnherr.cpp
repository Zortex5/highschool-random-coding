#include <iostream>
using namespace std;

struct node { // DEFINE NODE
    int body;
    node* next;
};

bool tanh(node* start); //TANH PROTO

//initialize circular linked list of length 7, n0-n6
node n0, n1, n2, n3, n4, n5, n6;
/*node n0; n0.body = 0;
node n1; n1.body = 1; n0.next = &n1;
node n2; n2.body = 2; n1.next = &n2;
node n3; n3.body = 3; n2.next = &n3;
node n4; n4.body = 4; n3.next = &n4;
node n5; n5.body = 5; n4.next = &n5;
node n6; n6.body = 6; n5.next = &n6; n6.next = &n0;*/

int main() {
    n0.body = 0; n1.body = 1; n2.body = 2; n3.body = 3; n4.body = 4; n5.body = 5; n6.body = 6;
    n0.next = &n1; n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5; n5.next = &n6; n6.next = &n0;
    if (tanh(&n0)) { //tortoise and hare
        cout << "Circular Linked List\n";
    } else {
        cout << "Not Circular Linked List\n";
    }

    return 0;
}

bool tanh(node* start) { //tortoise and hare algorithm
    node* h = start; //initialize tortoise
    node* t = start; //initialize hare

    while (true) {
        if (h->next != NULL) { //move hare and tortoise if available
            h = h->next;
            t = t->next;
        } else {
            return false; //end reached, not circular
        }
        if (h->next != NULL) { //move hare second time cause its faster than tortoise
            h = h->next;
        }

        if (h == t) {
            return true; //hare caught up to tortoise, is circular
        }
    }
}