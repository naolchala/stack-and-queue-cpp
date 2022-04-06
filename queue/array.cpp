#include <iostream>
using namespace std;

struct Queue {
    int queue[1000];
    int front = 0;
    int rear = -1;

    void enqueue(int data) {
        rear++;
        queue[rear] = data;
    }

    int dequeue() {
        int data = queue[front];
        front++;
        return data;
    }

    void display() {
        cout << "[";
        for (int i = front; i <= rear; i++) {
            cout << queue[i];
            if (i != rear) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
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