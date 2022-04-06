#include <iostream>
using namespace std;

struct Stack {
    int stack[1000];
    int top = -1;

    void push(int no) {
        top++;
        stack[top] = no;
    }

    int pop() {
        if (top >= 0) {
            int no = stack[top];
            top--;
            return no;
        }
        return 0;
    }

    int getTop() { return stack[top]; }

    void display() {
        cout << "[";
        for (int i = top; i >= 0; i--) {
            cout << stack[i];
            if (i != 0) cout << ", ";
        }
        cout << "]";
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