#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *getNode(int n) {
    Node *newNode = new Node;
    newNode->data = n;
    return newNode;
}

struct DoublyLinkedList {
    Node *head = NULL;
    int length = 0;

    void print();

    void addAtFirst(int data);
    void addAtIndex(int data, int index);
    void addAtLast(int data);

    void removeFirst();
    void removeAtIndex(int index);
    void removeLast();

    void findAndReplace(int find, int replace) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data == find) temp->data = replace;

            temp = temp->next;
        }
    }
};

void DoublyLinkedList::print() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        if (temp != NULL) {
            cout << " <-> ";
        }
    }

    cout << endl;
}
void DoublyLinkedList::addAtFirst(int data) {
    Node *newNode = getNode(data);
    Node *temp = head;
    newNode->next = temp;
    if (temp != NULL) temp->prev = newNode;
    head = newNode;
    length++;
};
void DoublyLinkedList::addAtIndex(int data, int index) {
    if (index == 0) {
        addAtFirst(data);
        return;
    } else if (index > length) {
        cerr << "Index Out of Bounds" << endl;
        exit(-1);
    }

    int i = 0;
    Node *temp = head;

    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    Node *newNode = getNode(data);
    Node *next = temp->next;
    next->prev = newNode;
    newNode->next = next;
    newNode->prev = temp;
    temp->next = newNode;
    length++;
};

void DoublyLinkedList::addAtLast(int data) {
    Node *newNode = getNode(data);
    Node *temp = head;

    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    length++;
};

void DoublyLinkedList::removeFirst() {
    head = head->next;
    head->prev = NULL;
    length--;
}
void DoublyLinkedList::removeAtIndex(int index) {
    if (index == 0)
        removeFirst();
    else if (index >= length - 1) {
        cerr << "Index Out of Bounds " << endl;
        exit(-1);
        return;
    } else {
        int i = 0;
        Node *temp = head;
        while (temp != NULL && i < index - 1) {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
        length--;
    }
}

void DoublyLinkedList::removeLast() {
    if (head != NULL) {
        Node *temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        temp->next = NULL;
        length--;
    }
}

int mainMenu() {
    int menu;
    cout << "1. View List Items" << endl
         << "2. Add Item" << endl
         << "3. Remove Item" << endl
         << "4. Find and Replace" << endl
         << "0. Exit" << endl;
    cout << "Enter Menu No.: ";
    cin >> menu;

    if (menu == 1) {
        return menu;
    } else if (menu == 2) {
        cout << "======== ADD ITEM ========" << endl;
        cout << "1. Front " << endl
             << "2. End" << endl
             << "3. At Given Index" << endl;
        cout << "Select Position: ";
        cin >> menu;

        return menu + 3;
    } else if (menu == 3) {
        cout << "======== REMOVE ITEM ========" << endl;
        cout << "1. Front " << endl
             << "2. End" << endl
             << "3. At Given Index" << endl;
        cout << "Select Position: ";
        cin >> menu;

        return menu + 6;
    } else if (menu == 4) {
        return 10;
    } else {
        return menu;
    }
}

int main() {
    DoublyLinkedList dll;

    cout << "========================================" << endl
         << "          Doubly Linked List" << endl
         << "========================================" << endl;

    int menu;
    do {
        menu = mainMenu();
        switch (menu) {
            case 1:
                cout << endl
                     << "Elements in List" << endl
                     << "----------------" << endl;
                dll.print();
                break;

            case 4: {
                cout << endl
                     << "Add Front Element" << endl
                     << "----------------" << endl;
                int no;
                cout << "Enter Num: ";
                cin >> no;

                dll.addAtFirst(no);
                break;
            }
            case 5: {
                cout << endl
                     << "Add Last Element" << endl
                     << "----------------" << endl;
                int no;
                cout << "Enter Num: ";
                cin >> no;
                dll.addAtLast(no);
                break;
            }
            case 6: {
                cout << endl
                     << "Add Element at Index" << endl
                     << "--------------------" << endl;
                int no, index;
                cout << "Enter Num: ";
                cin >> no;
                do {
                    cout << "Enter Index: ";
                    cin >> index;

                    if (index >= dll.length)
                        cout << "Error: Index out of bounds" << endl;
                } while (index > dll.length);

                dll.addAtIndex(no, index);
                break;
            }
            case 7:
                dll.removeFirst();
                cout << "First Element Removed" << endl;
                break;
            case 8:
                dll.removeLast();
                cout << "Last Element Removed" << endl;
                break;
            case 9:
                cout << endl
                     << "Remove Element at Index" << endl
                     << "----------------------" << endl;
                int index;
                do {
                    cout << "Enter Index: ";
                    cin >> index;
                    if (index < 0) break;

                    if (index >= dll.length)
                        cout << "Error: Index out of bounds" << endl;

                } while (index >= dll.length);

                dll.removeAtIndex(index);
                cout << "Element at Index " << index << " Removed" << endl;
                break;

            case 10:
                cout << "Find and Replace an Element " << endl
                     << "-----------------------------" << endl;
                int find, replace;
                cout << "Enter no to find: ";
                cin >> find;
                cout << "Enter no to replace with: ";
                cin >> replace;
                dll.findAndReplace(find, replace);
                break;
            default:
                break;
        }

        char w;
        cout << "Continue..." << endl;
        cin.ignore();
        cin.get(w);

    } while (menu != 0);

    return 0;
}