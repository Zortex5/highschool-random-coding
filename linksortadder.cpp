#include <iostream>
using namespace std;

typedef struct {
    int body;
    Node next;
} Node;


int main() {

    Node n6; n6.body = 6; n6.next = nullptr;
    Node n4; n4.body = 4; n4.next = &n6;
    Node n2; n2.body = 2; n2.next = &n4;

    Node n5; n5.body = 5; n5.next = nullptr;
    Node n3; n3.body = 3; n3.next = &n5;
    Node n1; n1.body = 1; n1.next = &n3;

    Node* start = synchronize(n1, n2);
    printlist(start);

}


void printlist(Node* start) {

    while (start != nullptr) {
        cout << start -> body;
        start = start -> next;
    }

}

Node* synchronize(Node node1, Node node2) {

    Node* start = nullptr;
    Node* s = start;
    Node* l1 = &node1;
    Node* l2 = &node2;

    while (true) {
        if (l1 == nullptr) {
            if (l2 == nullptr) return start;
            while (l2 != nullptr) {
                s -> next = l2;
                s = s -> next;
                cout << s -> body;
                l2 = l2 -> next;
            }
            return start;
        }
        else if (l2 == nullptr) {
            while (l1 != nullptr) {
                s -> next = l1;
                s = s -> next;
                cout << s -> body;
                l1 = l1 -> next;
            }
            return start;
        }

        if (l1 -> body > l2 -> body) {
            s -> next = l1;
            s = s -> next;
            l1 = l1 -> next;
        }
        else if (l1 -> body < l2 -> body) {
            s -> next = l2;
            s = s -> next;
            l2 = l2 -> next;
        }
    }

}