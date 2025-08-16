#include <string>

class Node {
    public:
        int body;
        Node* next;

        Node(int nodeBody, Node* nextNode) {
            body = nodeBody;
            next = nextNode;
        }
};


/**Prints a linked list**/
std::string linkedlisttostr(Node* start) {
    std::string s = "";
    Node* cur = start;
    while (cur != nullptr) {
        s += cur->body + " ";
        cur = cur->next;
    }
    return s.substr(0, s.length() - 1);
}


/**Combines 2 sorted linked lists into 1 sorted linked list**/
Node* synchronize(Node node1, Node node2) {
    Node* start = nullptr;
    Node* s0 = nullptr;
    Node* s1 = nullptr;
    Node* l1 = nullptr;
    Node* l2 = nullptr;

    if (node2.body > node1.body) {
        start = &node1;
        s0 = &node1;
        s1 = node1.next;
        l1 = node1.next;
        l2 = &node2;
    }
    else {
        start = &node2;
        s0 = &node2;
        s1 = node2.next;
        l1 = &node1;
        l2 = node2.next;
    }

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->body > l2->body) {
            s1 = l2;
            s0->next = s1;
            s0 = s0->next;
            l2 = l2->next;
        }
        else {
            s1 = l1;
            s0->next = s1;
            s0 = s0->next;
            l1 = l1->next;
        }
    }
    while (l1 != nullptr) {
        s1 = l1;
        s0->next = s1;
        s0 = s0->next;
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        s1 = l2;
        s0->next = s1;
        s0 = s0->next;
        l2 = l2->next;
    }

    return start;
}