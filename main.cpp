#include <iostream>
#include "set.h"
#include "iterator.h"
#define MESSAGE endl << "[set::" << __FUNCTION__ << "]" << endl

using namespace std;


void test_iterator();

void test_cout();
void test_init_list();
void test_constructor();
void test_transfer();
void test_copy();
void test_to_array();

void test_eq();
void test_multiple();
void test_devide();
void test_plus();

void test_add();
void test_contains();
void test_remove();


int main() {
    test_iterator();

    test_cout();
    test_init_list();
    test_constructor();
    test_transfer();
    test_copy();
    test_to_array();
    test_eq();

    test_add();
    test_contains();
    test_remove();

    test_multiple();
    test_devide();
    test_plus();

    return 0;
}

void test_iterator()
{
    try {
        set<int> a{4,5,6,3};
        cout << MESSAGE << "Set: " << endl;
        cout << a << "\n" << endl;

        Iterator<int> it = a.iterator_begin();
        cout << "Iterator begin: " << endl;
        cout << it.value() << endl;
        cout << *it << "\n" << endl;
        cout << "Next elem: " << endl;
        cout << (++it).value() << "\n" << endl;

        set<int> a2{4,5,6,3};
        Iterator<int> it2 = a2.iterator_end();
        cout << "Iterator end: " << endl;
        cout << it2.value() << "\n" << endl;

        cout << "==: " << (*it == *it2) << endl;
        cout << "!=: " << (*it != *it2) << endl;

        set<int> st{};
        set<int> move = std::move(st);
    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_cout()
{
    set<int> a{4, 5, 4, 5};
    cout << MESSAGE << a << "\n" << endl;
    cout << "_________________________________________________________________" << endl;
}

void test_init_list()
{
    try {
        set<int> a{0, 0, 0};
        cout << MESSAGE << a << endl;
        set<int> a0{};
        cout << a0 << endl;
    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_constructor()
{
    try {
        set<int> a;
        cout << MESSAGE << a << endl;
    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_transfer()
{
    try{
        set<int> a{2, 3, 4};
        set<int> a2 = std::move(a);
        cout << MESSAGE << a2 << endl;
    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_copy()
{
    try{
        set<int> a;
        a.add(2);
        a.add(3);
        set<int> a2 = a;
        cout << MESSAGE << a2 << endl;
    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_to_array()
{
    try {
        set<int> a{4,5,6,3};
        int *arr = a.to_array();
        cout << a.get_length() << endl;
        cout << a << endl;
        cout << "Array: " << endl;
        for(int i = 0; i < a.get_length(); i++)
            cout << "arr[" << i << "] = " << *(arr + i) << endl;
        delete[] arr;
    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_eq()
{
    try {
        set<int> a{4,5,6,3};
        set<int> a2;
        cout << MESSAGE << a << endl;
        cout << a2 << endl;
        set<int> a3 = a2;
        set<int> a4 = std::move(a);
        cout << "set = {} : \n" << a3 << endl;
        cout << "set = move({4,5,6,3}): \n" << a4 << endl;
        set<int> a5{};
        a2 = a5;
        cout << "{} = {} : \n" << a2 << endl;
    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_add()
{
    try {
        set<int> a;
        cout << MESSAGE << "add elements: " << endl;
        cout << a << endl;
        a.add(3);
        a.add(2);
        cout << a << endl;

        a.add(3);
        cout << "add repeated element: " << endl;
        cout << a << endl;

        set<int> a2{0, 0};
        cout << a2 << endl;

    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_contains()
{
    try {
        set<int> a{4, 5, 6};
        cout << MESSAGE << a << endl;
        if (a.contains(4) == true)
            cout << "Element 4 is in set!" << endl;

        if (a.contains(1) == false)
            cout << "Element 1 is not in set!" << endl;

    } catch (set_exeption& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}


void test_remove()
{
    set<int> a1;

    a1.add(1);
    a1.add(2);
    a1.add(3);
    a1.add(4);
    cout << MESSAGE << a1 << endl;

    a1.remove(4);
    cout << a1 << endl;

    a1.remove(1);
    cout << a1 << endl;

    a1.remove(1);
    cout << "Remove non-existent element: " << endl;
    cout << a1 << endl;
    cout << "_________________________________________________________________" << endl;
}


void test_devide()
{
    try {
        cout << MESSAGE << "Subtract: \n" << endl;
        set<int> a1{4, 5, 6, 3};
        set<int> a2{4, 6, 7};
        cout << a1 << " / " << a2 << endl;
        set<int> a3 = a2 / a1;
        cout << "Result: " << a3 << "\n" << endl;

        set<int> a4{4, 5, 6, 3};
        set<int> a5{};
        cout << a4 << " / " << a5 << endl;
        set<int> a6 = a4 / a5;
        cout << "Result: " << a6 << endl;

        set<int> a7{};
        cout << a5 << " / " << a7 << endl;
        set<int> a8 = a5 / a7;
        cout << "Result: " << a8 << endl;

    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_multiple()
{
    try {
        cout << MESSAGE << "Intersection: \n" << endl;
        set<int> a{4,5,6,3};
        set<int> a3{4,2,6};
        cout << a << " * " << a3 << endl;
        set<int> a4 = a * a3;
        cout << "Result: " << a4 << "\n" << endl;

        set<int> a2{};
        a4 = a2 * a;
        cout << a << " * " << a2 << endl;
        cout << "Result: " << a4 << endl;

        set<int> a5{};
        a4 = a2 * a5;
        cout << a2 << " * " << a5 << endl;
        cout << "Result: " << a4 << endl;

//        cout << a4 << " *= " << a3 << endl;
//        a4 *= a3;
//        cout << "Result: " << a4 << endl;

    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}

void test_plus()
{
    try {
        cout << MESSAGE << "Union: \n" << endl;
        set<int> a1{4,5,6,3};
        set<int> a2{4,5,6,3};
        cout << a1 << " + " << a2 << endl;
        set<int> a3 = a1 + a2;
        cout << "Result: " << a3 << "\n" << endl;

        set<int> a4{1,2,3};
        cout << a1 << " + " << a4 << endl;
        a3 = a1 + a4;
        cout << "Result: " << a3 << endl;

        cout << a3 << endl;
        set<int> a5{};
        cout << a4 << " + " << a5 << endl;
        set<int> a6 = a4 + a5;
        cout << "Result: " << a6 << endl;


    } catch(set_exeption &e) {
        cout << "Exception says: " << e.what() << endl;
    }
    cout << "_________________________________________________________________" << endl;
}
