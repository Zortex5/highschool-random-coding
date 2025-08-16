class Node:
    def __init__(self, body, next):
        if body:
            self.body = body
        else:
            self.body = 0
        if next:
            self.next = next
        else:
            self.next = None


def main():
    n2 = Node(8, 
         Node(8, 
         Node(19, 
    None)))

    n1 = Node(-4, 
         Node(2, 
         Node(8, 
    None)))

    printlist(n1)
    printlist(n2)
    start = synchronize(n1, n2)
    printlist(start)


def printlist(start):
    while start != None:
        print(start.body, end=" ")
        start = start.next
    print()


def synchronize(node1, node2):
    start = None
    s = None
    l1 = None
    l2 = None

    if node2.body > node1.body:
        start = node1
        s0 = node1
        s1 = node1.next
        l1 = node1.next
        l2 = node2
    else:
        start = node2
        s0 = node2
        s1 = node2.next
        l1 = node1
        l2 = node2.next

    while(l1 != None and l2 != None):
        if (l1.body > l2.body):
            s1 = l2
            s0.next = s1
            s0 = s0.next
            l2 = l2.next
        else:
            s1 = l1
            s0.next = s1
            s0 = s0.next
            l1 = l1.next
    
    while (l1 != None):
        s1 = l1
        s0.next = s1
        s0 = s0.next
        l1 = l1.next
    while (l2 != None):
        s1 = l2
        s0.next = s1
        s0 = s0.next
        l2 = l2.next

    return start


if __name__ == "__main__":
    main()