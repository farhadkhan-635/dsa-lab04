// Name    : Farhad Khan
// Reg No  : 549034
// Section : BSCS-15E
// Lab 04, Task 4: Inserting at the beginning

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

        // order matters here: first connect the new node to the old
        // first node, and only then move head. If we moved head first,
        // we would lose the address of the old list.
        newNode->next = head;
        head = newNode;

        // no special case for an empty list, head is nullptr then,
        // so the new node correctly points to nullptr as the last node
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
    List myList;

    cout << "Starting with an empty list:" << endl;
    myList.PrintList();

    cout << endl << "Insert 20 at the beginning:" << endl;
    myList.InsertAtBeginning(20);
    myList.PrintList();

    cout << endl << "Insert 10 at the beginning:" << endl;
    myList.InsertAtBeginning(10);
    myList.PrintList();

    cout << endl << "Append 30 at the end:" << endl;
    myList.AddNode(30);
    myList.PrintList();   // final order should be 10 20 30

    myList.ClearList();
    return 0;
}