// Name    : Farhad Khan
// Reg No  : 549034
// Section : BSCS-15E
// Lab 04, Task 6: Linked list application (menu driven)

#include <iostream>
using namespace std;

class List
{
private:
    struct node
    {
        int data;
        node* next;   // address of the next node, nullptr for the last one
    };
    node* head;       // first node of the list, nullptr means empty

public:
    List()
    {
        head = nullptr;
    }

    // adds a new node at the end of the list
    void AddNode(int addData)
    {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        node* curr = head;
        while (curr->next != nullptr)   // stop on the last node
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // adds a new node before the current first node
    void InsertAtBeginning(int addData)
    {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;   // connect to the old list first
        head = newNode;         // then move head
    }

    int CountNodes()
    {
        int count = 0;
        node* curr = head;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // there is no direct jump to a position in a linked list, so the
    // only way to find a value is to walk node by node, which is O(n)
    void SearchNode(int searchData)
    {
        node* curr = head;
        int position = 1;   // first node counts as position 1

        while (curr != nullptr)
        {
            if (curr->data == searchData)
            {
                cout << searchData << " found at position " << position << endl;
                return;
            }
            curr = curr->next;
            position++;
        }
        cout << "Value not found" << endl;
    }

    void PrintSecondNode()
    {
        // check head first, head->next is not safe on a null head
        if (head == nullptr || head->next == nullptr)
        {
            cout << "Second node does not exist, the list has fewer than two nodes." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
    }

    // removes only the first node that holds delData
    void DeleteNode(int delData)
    {
        if (head == nullptr)
        {
            cout << "List is empty, cannot delete " << delData << endl;
            return;
        }

        // first node has no node before it, so it is handled separately
        // (this also covers a list with only one node)
        if (head->data == delData)
        {
            node* temp = head;
            head = head->next;   // reconnect first, so the rest of the list is not lost
            delete temp;
            cout << delData << " deleted" << endl;
            return;
        }

        // prev stays one step behind the node we are checking
        node* prev = head;
        while (prev->next != nullptr && prev->next->data != delData)
        {
            prev = prev->next;
        }

        if (prev->next == nullptr)
        {
            cout << delData << " not found, nothing deleted" << endl;
            return;
        }

        node* temp = prev->next;
        prev->next = temp->next;   // link around it before releasing it
        delete temp;
        cout << delData << " deleted" << endl;
    }

    void PrintList()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        node* curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearList()
    {
        node* curr = head;
        while (curr != nullptr)
        {
            node* nextNode = curr->next;   // save it first, we cannot read next after delete
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
    }
};

int main()
{
    List myList;   // starts empty
    int choice = 0;
    int value;

    do
    {
        cout << endl;
        cout << "----- Linked List Menu -----" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Search by value" << endl;
        cout << "4. Delete by value" << endl;
        cout << "5. Display all nodes" << endl;
        cout << "6. Count nodes" << endl;
        cout << "7. Display second node" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // if something that is not a number was typed, cin goes into a fail
        // state and would loop forever, so reset it and throw the input away
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            myList.InsertAtBeginning(value);
            cout << value << " inserted at the beginning" << endl;
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            myList.AddNode(value);
            cout << value << " inserted at the end" << endl;
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            myList.SearchNode(value);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            myList.DeleteNode(value);
            break;
        case 5:
            myList.PrintList();
            break;
        case 6:
            cout << "Total nodes: " << myList.CountNodes() << endl;
            break;
        case 7:
            myList.PrintSecondNode();
            break;
        case 8:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, please enter a number from 1 to 8." << endl;
        }
    } while (choice != 8);

    // the user may exit while nodes are still in the list, so free them here
    myList.ClearList();
    return 0;
}