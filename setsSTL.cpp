#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    set <int, greater<int>> setOne;
    setOne.insert(60);
    setOne.insert(10);
    setOne.insert(40);
    setOne.insert(20);
    setOne.insert(60);              // only one 60 is added to the setOne
    setOne.insert(40);              // only one 40 is added to the setOne
    setOne.insert(30);
    setOne.insert(50);

    // displaying the set
    set <int, greater<int>> :: iterator itr;

    cout << "setOne :";
    for( itr = setOne.begin(); itr != setOne.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    // copying the elements in setOne to setTwo
    set <int> setTwo( setOne.begin(), setOne.end());
    cout << "\nsetTwo :";
    for( itr = setTwo.begin(); itr != setTwo.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    // The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.
    set <int> setThree = setTwo;
    cout << "\nsetThree :";
    for( itr = setThree.begin(); itr != setThree.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    // deleting elements in setTwo less than 30
    // the following function deletes all the element in the set starting from begin() to the element just before find(30)
    setTwo.erase( setTwo.begin(), setTwo.find(30));
    cout << "\nAfter deleting elements ( less than 30) in setTwo :\nsetTwo :";
    for( itr = setTwo.begin(); itr != setTwo.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    // deletes the element with the value 50 in the setTwo
    cout << "\n\nAfter deleting element ( of value 50) in setTwo :\nsetTwo :";
    setTwo.erase(50);
    for( itr = setTwo.begin(); itr != setTwo.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    // no changes are made to the original set as is evident in the following display
    cout << "\nsetOne :";
    for( itr = setOne.begin(); itr != setOne.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    cout << "\n\nafter deleting elements 50 and 60 in the setThree :";
    // setThree.erase(50);
    // setThree.erase(60);

    // another way of achieving this type of deletion in the given case is ~
    setThree.erase( setThree.find(50), setThree.end());

    cout << "\nsetThree :";
    for( itr = setThree.begin(); itr != setThree.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    // swap()– This function is used to exchange the contents of two sets but the sets must be of same type, although sizes may differ.
    setTwo.swap( setThree);
    cout << "\n\nafter swapping the contents of the setThree and setTwo :";
    cout << "\nsetTwo :";
    for( itr = setTwo.begin(); itr != setTwo.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    cout << "\nsetThree :";
    for( itr = setThree.begin(); itr != setThree.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    cout << "\n\n\nFinally the sets are as follows :";

    cout << "\nsetOne :";
    for( itr = setOne.begin(); itr != setOne.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    cout << "\nsetTwo :";
    for( itr = setTwo.begin(); itr != setTwo.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    cout << "\nsetThree :";
    for( itr = setThree.begin(); itr != setThree.end(); itr++)
    {
        cout << '\t' << *itr;
    }

    cout << "\n\nThe bounds are represented as follows :";

    cout << "\nsetOne.lower_bound(30)\t\t" << *setOne.lower_bound(30);
    cout << "\nsetOne.upper_bound(30)\t\t" << *setOne.upper_bound(30);
    cout << "\nsetTwo.lower_bound(30)\t\t" << *setTwo.lower_bound(30);
    cout << "\nsetTwo.upper_bound(30)\t\t" << *setTwo.upper_bound(30);
    cout << "\nsetThree.lower_bound(30)\t" << *setThree.lower_bound(30);
    cout << "\nsetThree.upper_bound(30)\t" << *setThree.upper_bound(30);

    return EXIT_SUCCESS;
}