#include <iostream>

using namespace std;

// Define a node structure
struct Node {
    int data;
    Node* next;
};

// Define a SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList myList;

    // Insert nodes
    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtBeginning(5);

    // Display the list
    cout << "Linked list elements: ";
    myList.display();

    // Delete a node
    myList.deleteNode(20);

    // Display the list after deletion
    cout << "Linked list elements after deletion: ";
    myList.display();

    return 0;
}
