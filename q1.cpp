// Name    : Farhad Khan
// Reg No  : 549034
// Section : BSCS-15E
// Lab 04, Task 1: Creating and traversing a singly linked list

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

    // takes three numbers and links three nodes in the same order
    void CreateThreeNodes()
    {
        // only allowed on an empty list, otherwise old nodes would be lost
        if (head != nullptr)
        {
            cout << "List is not empty." << endl;
            return;
        }

        int a, b, c;
        cout << "Enter three integers: ";
        cin >> a >> b >> c;

        node* first = new node;
        node* second = new node;
        node* third = new node;

        first->data = a;
        second->data = b;
        third->data = c;

        first->next = second;
        second->next = third;
        third->next = nullptr;

        head = first;
    }

    void PrintList()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        // curr walks the list, head stays put so we never lose the start
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
        head = nullptr;   // otherwise head would keep pointing at freed memory
    }
};

int main()
{
    List myList;

    cout << "Before creation:" << endl;
    myList.PrintList();

    myList.CreateThreeNodes();

    cout << "After creation:" << endl;
    myList.PrintList();

    myList.ClearList();
    return 0;
}