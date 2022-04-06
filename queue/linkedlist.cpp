#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *getNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    return temp;
}

struct Queue {
    Node *head = NULL;
    Node *tail = NULL;

    void enqueue(int data) {
        Node *newNode = getNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    int dequeue() {
        if (tail == NULL) return -0;
        if (tail->prev == NULL) {
            int data = head->data;
            head = NULL;
            tail = NULL;
            return data;
        }
        int data = tail->data;
        tail = tail->prev;
        tail->next = NULL;
        return data;
    }

    void display() {
        Node *temp = head;
        cout << "[";
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << "]";
    }
};

int main() {
    int menu;
    Queue qu;

    do {
        cout << "----- QUEUE -----" << endl;
        cout << "1. Display Queue" << endl;
        cout << "2. Push to Queue" << endl;
        cout << "3. Pop from Queue" << endl;
        cout << "0. Exit " << endl;
        cout << "Enter Operation No.: ";
        cin >> menu;

        switch (menu) {
            case 1: {
                cout << "---- Display ----" << endl;
                qu.display();
                break;
            }
            case 2: {
                cout << "----- PUSH ----" << endl;
                int no;
                cout << "Enter No. to Push: ";
                cin >> no;
                qu.enqueue(no);
                break;
            }
            case 3: {
                int no = qu.dequeue();
                cout << "Removed " << no << endl;
                break;
            }
            default:
                cout << "Wrong Choice" << endl;
                break;
        }
        char k;
        cout << endl << "Press any Key to Continue.." << endl;
        cin.ignore();
        cin.get(k);

    } while (menu != 0);

    return 0;
}