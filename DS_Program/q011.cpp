#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    // Display queue
    q.display();

    // Dequeue elements
    q.dequeue();
    q.dequeue();

    // Display queue after dequeue
    q.display();

    // Get front element
    cout << "Front element: " << q.getFront() << endl;

    return 0;
}
