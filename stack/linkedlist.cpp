#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next = NULL;
};

Node *getNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    return temp;
}

struct Stack {
    Node *head = NULL;

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

    void push(int data) {
        Node *newNode = getNode(data);

        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    int pop() {
        if (head != NULL) {
            int data = head->data;
            head = head->next;
            return data;
        }
        return 0;
    }
};

int main() {
    int menu;
    Stack st;

    do {
        cout << "----- STACK -----" << endl;
        cout << "1. Display Stack" << endl;
        cout << "2. Push to Stack" << endl;
        cout << "3. Pop from stack" << endl;
        cout << "0. Exit " << endl;
        cout << "Enter Operation No.: ";
        cin >> menu;

        switch (menu) {
            case 1: {
                cout << "---- Display ----" << endl;
                st.display();
                break;
            }
            case 2: {
                cout << "----- PUSH ----" << endl;
                int no;
                cout << "Enter No. to Push: ";
                cin >> no;
                st.push(no);
                break;
            }
            case 3: {
                int no = st.pop();
                cout << "Removed " << no << endl;
                break;
            }
            default:
                cout << "Wrong Choice" << endl;
                break;
        }
        char k;
        cout << endl << "Press any Key to Continue" << endl;
        cin.ignore();
        cin.get(k);

    } while (menu != 0);
    return 0;
}