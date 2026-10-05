// Name    : Farhad Khan
// Reg No  : 549034
// Section : BSCS-15E
// Lab 04, Task 3: Searching and accessing the second node

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

    // prints the position of the first node holding searchData
    void SearchNode(int searchData)
    {
        node* curr = head;
        int position = 1;   // first node counts as position 1

        while (curr != nullptr)
        {
            if (curr->data == searchData)
            {
                cout << searchData << " found at position " << position << endl;
                return;   // first match only, so no need to look further
            }
            curr = curr->next;
            position++;
        }

        // reaching here means curr ran off the end without a match
        // (an empty list also lands here, the loop never runs)
        cout << "Value not found" << endl;
    }

    // prints only the second node, if there is one
    void PrintSecondNode()
    {
        // order matters: check head first, because head->next is
        // not safe to read when head itself is nullptr
        if (head == nullptr || head->next == nullptr)
        {
            cout << "Second node does not exist, the list has fewer than two nodes." << endl;
            return;
        }

        cout << "Second node: " << head->next->data << endl;
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
    cout << "Test 1: empty list" << endl;
    List a;
    a.PrintList();
    a.SearchNode(20);
    a.PrintSecondNode();
    a.ClearList();

    // test 2: one node only
    cout << endl << "Test 2: one node list" << endl;
    List b;
    b.AddNode(10);
    b.PrintList();
    b.SearchNode(10);
    b.PrintSecondNode();
    b.ClearList();

    // test 3: 10, 20, 30, 20 (20 appears twice, we want the first one)
    cout << endl << "Test 3: list 10 20 30 20" << endl;
    List c;
    c.AddNode(10);
    c.AddNode(20);
    c.AddNode(30);
    c.AddNode(20);
    c.PrintList();
    c.SearchNode(20);   // expected position 2
    c.SearchNode(99);   // expected not found
    c.PrintSecondNode();
    c.ClearList();

    return 0;
}