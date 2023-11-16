#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
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

    // Function to search for a value in the linked list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to update the value at any n point
    void updateAtN(int n, int value) {
        Node* temp = head;
        for (int i = 1; i < n && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            temp->data = value;
        }
    }

    // Function to delete from the beginning
    void deleteFromBeginning() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to delete from the end
    void deleteFromEnd() {
        if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
        }
    }

    // Function to delete from any n point
    void deleteFromN(int n) {
        if (head != nullptr && n > 0) {
            if (n == 1) {
                Node* temp = head;
                head = head->next;
                delete temp;
            } else {
                Node* temp = head;
                for (int i = 1; i < n - 1 && temp->next != nullptr; ++i) {
                    temp = temp->next;
                }
                if (temp->next != nullptr) {
                    Node* toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                }
            }
        }
    }

    // Function to search and update at any point
    void searchAndUpdate(int value, int newValue) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                temp->data = newValue;
                break;
            }
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    int choice, value, n, newValue;

    do {
        cout << "1. Search\n"
             << "2. Update at any n point\n"
             << "3. Insert at any n point\n"
             << "4. Delete from beginning\n"
             << "5. Delete from end\n"
             << "6. Delete from any n point\n"
             << "7. Search and update at any point\n"
             << "8. Display\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to search: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Value found in the list.\n";
                } else {
                    cout << "Value not found in the list.\n";
                }
                break;

            case 2:
                cout << "Enter the position (n) and new value: ";
                cin >> n >> newValue;
                list.updateAtN(n, newValue);
                break;

            case 3:
                cout << "Enter the value to insert and position (n): ";
                cin >> value >> n;
                // Assuming n is a valid position (1-based index)
                list.insert(value);
                break;

            case 4:
                list.deleteFromBeginning();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter the position (n) to delete: ";
                cin >> n;
                list.deleteFromN(n);
                break;

            case 7:
                cout << "Enter the value to search and the new value: ";
                cin >> value >> newValue;
                list.searchAndUpdate(value, newValue);
                break;

            case 8:
                cout << "Current list: ";
                list.display();
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
    