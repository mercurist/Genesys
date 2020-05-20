/*
LINKED LIST
    In this section, I assume that the lists with which we are working are unsorted and doubly linked.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class linkedListNode
{
public:
    int key;
    linkedListNode *next;
    linkedListNode *prev;

    linkedListNode(int value) : key(value), next(NULL), prev(NULL) {}
    linkedListNode() {}
};

// function to create a new node
linkedListNode *createNewNode(int value)
{
    linkedListNode *temp = new linkedListNode;
    temp->key = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

class linkedList
{
public:
    linkedListNode *head;
    linkedListNode *tail;

    linkedList() : head(NULL), tail(NULL) {}

    // Searching a Linked List by key
    linkedListNode *listSearch(int value)
    {
        linkedListNode *trav = head;
        while (trav != NULL && trav->key != value)
            trav = trav->next;
        return trav;
    }

    // given an element whose key attribute is already set, the listInsert procedure "splices value"
    // onto the front of the linked list
    void listInsertAtFront(int value)
    {
        linkedListNode *target = createNewNode(value);
        // target->next = head;
        // if (head != NULL)
        //     head->prev = target;
        // head = target;

        if (head == NULL)
        {
            head = target;
            tail = target;
            return;
        }

        target->next = head;
        head->prev = target;
        head = target;
    }

    void display()
    {
        linkedListNode *trav = head;
        cout << "head -> ";
        while (trav != NULL)
        {
            cout << trav->key << " -> ";
            trav = trav->next;
        }
        cout << "NULL";
        cout << '\n';
    }

    void deleteFirstNodeWithValue(int value)
    {
        linkedListNode *nodeToDelete = listSearch(value);
        // if the element is not found in the list
        if (nodeToDelete == NULL)
            return;

        // if the node to be deleted is NOT the first node in the list
        if (nodeToDelete->prev != NULL)
            nodeToDelete->prev->next = nodeToDelete->next;
        else
        {
            head = head->next;
        }

        // if the node to be deleted is NOT the last node in the list
        if (nodeToDelete->next != NULL)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        else
        {
            tail = tail->prev;
        }
    }
};

int main()
{
    int choice, x;
    linkedList mySweetNumbers;
    do
    {
        system("CLS");
        cout << "1. Insert at front of the list" << '\n';
        cout << "2. Display the numbers in list" << '\n';
        cout << "3. Search for your number" << '\n';
        cout << "4. Delete a particular number" << '\n';
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "1. Insert at front of the list" << '\n';
            cout << "\t\tEnter number ";
            cin >> x;
            mySweetNumbers.listInsertAtFront(x);
            break;

        case 2:
            system("CLS");
            cout << "2. Display the numbers in list" << '\n';
            cout << "\t\tHere are your numbers" << '\t';
            mySweetNumbers.display();
            system("pause");
            break;

        case 3:
        {
            system("CLS");
            cout << "3. Search for your number" << '\n';
            cin >> x;
            linkedListNode *temp = mySweetNumbers.listSearch(x);
            if (temp == NULL)
                cout << "Number does not exist" << '\n';
            else
            {
                cout << "The query returned with\t" << temp->key << " " << temp->next << " "
                     << temp->prev << '\n';
            }
            system("pause");
        }
        break;

        case 4:
        {
            system("CLS");
            cout << "4. Delete a particular number" << '\n';
            cin >> x;
            mySweetNumbers.deleteFirstNodeWithValue(x);
            break;
        }

        default:;
        }
    } while (choice != -1);

    return 0;
}