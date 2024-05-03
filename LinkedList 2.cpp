#include <iostream>

using namespace std;

class Node {
public:
    char id;
    Node* next;

    Node() {
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = nullptr;
    }

    void insertToHead(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == nullptr) {
            head = tail = node;
        } else {
            Node* tmp = head;
            head = node;
            node->next = tmp;
        }
    }

    void insertToTail(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void traversal() {
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->id << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void insertAfterNode(Node* prevNode, char data) {
        if (prevNode == nullptr) {
            cout << "ERROR: Previous node cannot be null." << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->id = data;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        if (prevNode == tail) {
            tail = newNode;
        }
    }

    void deleteNode(char data) {
        Node* tmp = head;
        Node* prev = nullptr;

        // If head node holds the data to be deleted
        if (tmp != nullptr && tmp->id == data) {
            head = tmp->next;
            delete tmp;
            return;
        }

        // Search for the node to be deleted
        while (tmp != nullptr && tmp->id != data) {
            prev = tmp;
            tmp = tmp->next;
        }

        // If the node was not found
        if (tmp == nullptr) {
            cout << "ERROR: Node with id '" << data << "' not found" << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = tmp->next;
        // If the deleted node was the tail, update the tail pointer
        if (tmp == tail) {
            tail = prev;
        }
        delete tmp;
    }
};

int main(int argc, char** argv) {

    LinkedList* list1 = new LinkedList();

    list1->insertToHead('R');
    list1->insertToTail('A');

    cout << "Traversal after initial insertion: ";
    list1->traversal();

    Node* nodeX = new Node();
    nodeX->id = 'X';

    list1->insertAfterNode(list1->head, 'B');
    list1->insertAfterNode(list1->head->next, 'C');
    list1->insertAfterNode(nodeX, 'Y');

    cout << "Traversal after insertions: ";
    list1->traversal();

    list1->deleteNode('B');
    list1->deleteNode('X');
    list1->deleteNode('Z'); // Deleting a non-existent node

    cout << "Traversal after deletions: ";
    list1->traversal();

    return 0;
}

