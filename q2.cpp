// Name    : Farhad Khan
// Reg No  : 549034
// Section : BSCS-15E
// Lab 04, Task 2: Appending nodes using a loop

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
        newNode->next = nullptr;   // new node is the last one, so it points to nothing

        // empty list, the new node simply becomes the first node
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // otherwise walk until curr is sitting on the last node
        // (we stop at curr->next == nullptr, not at curr == nullptr,
        // because we need the last node itself to attach the new one)
        node* curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // counts nodes by traversing, returns 0 for an empty list
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
    int n;

    // n cannot be negative, so keep asking until we get a valid one
    do
    {
        cout << "Enter how many numbers you want to add (0 or more): ";
        cin >> n;
    } while (n < 0);

    for (int i = 1; i <= n; i++)
    {
        int value;
        cout << "Enter number " << i << ": ";
        cin >> value;
        myList.AddNode(value);
    }

    cout << "Final list:" << endl;
    myList.PrintList();
    cout << "Total nodes: " << myList.CountNodes() << endl;

    myList.ClearList();
    return 0;
}