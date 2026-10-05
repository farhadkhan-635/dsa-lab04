// Name    : Farhad Khan
// Reg No  : 549034
// Section : BSCS-15E
// Lab 04, Task 5: Deleting a node by value

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

    // removes only the first node that holds delData
    void DeleteNode(int delData)
    {
        // case 1: nothing to delete from
        if (head == nullptr)
        {
            cout << "List is empty, cannot delete " << delData << endl;
            return;
        }

        // case 2: the first node is the one to delete (this also covers
        // a list with only one node, head just becomes nullptr)
        // head has no node before it, so it needs its own handling
        if (head->data == delData)
        {
            node* temp = head;
            head = head->next;   // reconnect first, so the rest of the list is not lost
            delete temp;
            cout << delData << " deleted" << endl;
            return;
        }

        // case 3: middle or last node
        // prev stays one step behind, we need it to skip over the deleted node
        node* prev = head;
        while (prev->next != nullptr && prev->next->data != delData)
        {
            prev = prev->next;
        }

        // prev reached the last node without a match, value is not in the list
        if (prev->next == nullptr)
        {
            cout << delData << " not found, nothing deleted" << endl;
            return;
        }

        node* temp = prev->next;   // the node we want to remove
        prev->next = temp->next;   // link around it first (works for the last node too,
                                   // since temp->next is nullptr then)
        delete temp;               // safe to release now, nothing points to it anymore
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
    // test 1: empty list
    cout << "Test 1: delete from an empty list" << endl;
    List a;
    a.DeleteNode(10);
    a.PrintList();
    a.ClearList();

    // test 2: duplicates, only the first 20 should go
    cout << endl << "Test 2: list 10 20 20 30, delete 20 once" << endl;
    List b;
    b.AddNode(10);
    b.AddNode(20);
    b.AddNode(20);
    b.AddNode(30);
    b.PrintList();
    b.DeleteNode(20);
    b.PrintList();   // expected 10 20 30

    // test 3: first node
    cout << endl << "Test 3: delete the first node (10)" << endl;
    b.DeleteNode(10);
    b.PrintList();   // expected 20 30

    // test 4: last node
    cout << endl << "Test 4: delete the last node (30)" << endl;
    b.DeleteNode(30);
    b.PrintList();   // expected 20

    // test 5: missing value
    cout << endl << "Test 5: delete a missing value (99)" << endl;
    b.DeleteNode(99);
    b.PrintList();   // list should stay the same

    // test 6: only node left
    cout << endl << "Test 6: delete the only node (20)" << endl;
    b.DeleteNode(20);
    b.PrintList();   // expected empty
    b.ClearList();

    // test 7: middle node on a fresh list
    cout << endl << "Test 7: list 5 6 7, delete the middle node (6)" << endl;
    List c;
    c.AddNode(5);
    c.AddNode(6);
    c.AddNode(7);
    c.DeleteNode(6);
    c.PrintList();   // expected 5 7
    c.ClearList();

    return 0;
}