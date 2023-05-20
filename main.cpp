#include <iostream>
#include "set.h"
#define MESSAGE endl << "[set::" << __FUNCTION__ << "]" << endl

using namespace std;

void test_base();
void test_base_extra();
void test_add();
void test_add_extra();
void test_elems();
void test_combine();
void test_sort();
int comp(int &r1, int &r2);
void test_index();
void test_array();
void test_iterators();
void test_inizalisation();
void test_remove();
template<typename Type>
bool comp(Type &r1, Type &r2);

int main()
{
    test_base();
//    test_base_extra();
//    test_inizalisation();
//    test_add();
//    test_add_extra();
//    test_elems();
//    test_remove();
//    test_combine();
//    test_sort();
//    test_index();
//    test_array();
//    test_iterators();
    return 0;
}

void test_base(){
  set<int> b;//конструктор по умолчанию
  cout << "1. a set by comporator is made" << endl;
  cout << "----------------------------" << endl;
  set<int> a{1, 5};
  a.add(1);
  a.add(3);
  a.add(3);
  a.add(2);
  cout << "2. a set 'a' is made" << endl;
  cout << "elements of set 'a': " << a << endl;
  cout << "len of 'a': " << a.get_length() << endl;
  cout << endl;
  cout << "----------------------------" << endl;
//  set<int> a2 = a;
//  cout << "3. a set 'a2' is copied by 'a'" << endl;
//  cout << "len of 'a2' - " << a2.get_length() << endl;
//  cout << "elements of set 'a2': " << endl;
//  for (int i = 0; i < a2.get_length(); i++)
//      cout << a2[i] << " ";
//  cout << endl;
//  cout << "----------------------------" << endl;
}
/*
void test_base_extra(){
    set<int> a(2);
    set<int> b;
    set<int> a2 =a;
    set<int> a3 = std::move(a2);//конструктор перемещения
    a2 = std::move(a);//конструктор перемещения
    set<int> b1 = std::move(b);
    cout << "len of 'b1' - " << b1.get_length() << endl;
    cout << "len of 'b' - " << b.get_length() << endl;
    cout << "4. a set 'a3' is moved from 'a2'" << endl;
    cout << "len of 'a3' - " << a3.get_length() << endl;
    cout << "elemets of set 'a3': " << endl;
    for (int i = 0; i < a3.get_length(); i++)
         cout << a3[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
}
void test_inizalisation(){
    set<int> a4{1,2,3,4,5};//список инициализации
    set<int> a100{};
    set<int> a228;
    set<int> a105;
    a105 = a4;
    a228 = a100;
    //a4 = a100;//+присваивание ицниалиазции ++ .. иниц + пустой
    cout << "len of 'a100' - " << a100.get_length() << endl;
    cout << "len of 'a228' - " << a228.get_length() << endl;
    cout << "5. a set 'a4' is initialized by numbers (1,2,3,4,5)" << endl;
    cout << "len of 'a4' - " << a4.get_length() << endl;
    cout << "elemets of set 'a4': " << endl;
    for (int i = 0; i < a4.get_length(); i++)
        cout << a4[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
    set<int> a5;
    a5 = a4;//перегрузка оператора присваивания
    cout << "6. a set 'a5' is assigned by 'a4'" << endl;
    cout << "len of 'a5' - " << a5.get_length() << endl;
    cout << "elemets of set 'a5': " << endl;
    for (int i = 0; i < a5.get_length(); i++)
        cout << a5[i] << " ";
    cout << endl;
}
void test_add(){
    cout << "----------------------------" << endl;
    set<int> a6{1,2,3,4};
    cout << "7. a set 'a6' is initialized with (1,2,3,4)" << endl;
    a6.add(123);
    a6.add(123);//2 раза добавим 123r
    cout << "123 is added to set 'a6'" << endl;
    cout << "elemets of set 'a6': " << endl;
    for (int i = 0; i < a6.get_length(); i++)
        cout << a6[i] << " ";
    cout << endl;
    set<int> a7{1,2,3};
    set<int> a8{4,5};
    set<int> a12{};
    cout << "----------------------------" << endl;
    cout << "8. a set 'a7' is initialized with (1,2,3) " << endl;
    cout << "a set 'a8' is initialized with (4,5) " << endl;
    a7.add_range(a8);
    a7.add_range(a12);//a7 add range пустой
    cout << "elemets of set 'a7' + 'a8': " << endl;
    for (int i = 0; i < a7.get_length(); i++)
        cout << a7[i] << " ";
    cout << endl;
}

void test_add_extra(){
    try {
        cout << "----------------------------" << endl;
        set<int> a9{1,2};
        cout << "9. a set 'a9' is initialized with (1,2) " << endl;
        cout << "an arr is with (-1,-2,-3,-4) " << endl;
        int arr[4]{-1,-2,-3,-4};
        a9.add_range(arr, 3);
        cout << "elements of set 'a9' + 'arr':" << endl;
        for (int i = 0; i < a9.get_length(); i++)
            cout << a9[i] << " ";
        cout << endl;
        a9.add_range(arr, -3);
    }catch(MyException& ex) {
        cout << ex.what() << endl;
    }
}

void test_elems(){
    try {
        cout << "----------------------------" << endl;
        set<int> a10{1,2,3,4};
        cout << "10. a set 'a10' is initialized with (1,2,3,4) " << endl;
        cout << "the first element is changed to '0'" << endl;
        a10.set_elem(0,0);
        cout << "elements of set 'a10':" << endl;
        for (int i = 0; i < a10.get_length(); i++)
            cout << a10[i] << " ";
        cout << endl;
        cout << "----------------------------" << endl;
        a10.set_elem(-1,-1);
    }catch (MyException& ex) {
        cout << ex.what() << endl;
    try{
        set<int> a11{1,2,3,4,5};
        cout << "11. a set 'a11' is initialized with (1,2,3,4,5) " << endl;
        cout << "the first element is - " << a11.get_elem(0) << endl;
        cout << "----------------------------" << endl;
        a11.get_elem(-900);
    } catch (MyException& ex){
        cout << ex.what() << endl;
        }
    }
}

void test_remove(){
    try {
        set<int> a12{1,2,3,4};
        cout << "12. a set 'a12' is initialized with (1,2,3,4) " << endl;
        cout << "the second element is removed" << endl;
        a12.remove_elem(1);
        cout << "elements of set 'a12':" << endl;
        for (int i = 0; i < a12.get_length(); i++)
            cout << a12[i] << " ";
        cout << endl;
        a12.remove_elem(-69);
    }catch (MyException& ex) {
        cout << ex.what() << endl;
    }
}

void test_combine(){
    cout << "----------------------------" << endl;
    set<int> a13 {1,2,3};
    set<int> a14 {4,5};
    set<int> a15{};
    cout << "13. a set 'a13' is initialized with (1,2,3) " << endl;
    cout << "a set 'a14' is initialized with (4,5) " << endl;
    a13.combine(a14);
    a14.combine(a15);//на всякий пожарный
    cout << "elements of set 'a13', which was combined with 'a14':" << endl;
    for (int i = 0; i < a13.get_length(); i++)
        cout << a13[i] << " ";
    cout << endl;
}

int comp(const int &r1, const int &r2)
{
    return r1 > r2;
}

void test_sort(){
    cout << "----------------------------" << endl;
    set<int> a15 {5,2,1,4,3};
    set<int> a229 {}; //sort для пустого
    cout << "14. a set 'a15' is initialized with (5,2,1,4,3) " << endl;
    cout << "a set 'a15' is sorted " << endl;
    a15.sort(comp);
    a229.sort(comp);
    cout << "elements of set 'a15':" << endl;
    for (int i = 0; i < a15.get_length(); i++)
        cout << a15[i] << " ";
    cout << endl;
    cout << "elements of set 'a15':" << endl;
    for (int i = 0; i < a229.get_length(); i++)
        cout << a229[i] << " ";
    cout << endl;
}

void test_index(){
    try {
        cout << "----------------------------" << endl;
        set<int> a16 {1,2,3,4,5};
        cout << "15. a set 'a16' is initialized with (1,2,3,4,5) " << endl;
        cout << "element '2' has index " << a16.get_index(2);
        cout << endl;
        cout << "element '2' has index " << a16.get_index(-200);//на дурака
        cout << endl;
    }catch(MyException& ex) {
        cout << ex.what() << endl;
    }
}

void test_array(){
    cout << "----------------------------" << endl;
    set<int> a17 {1,2,3,4,5};
    set<int> a18 {};
    cout << "16. a set 'a17' is initialized with (1,2,3,4,5) " << endl;
    int *array = a17.to_array();
    int *array2 = a18.to_array();//для пустого дурака (сделано)
    cout << "elements of set 'a17' are moved to array" << endl;
    cout << "elements of array:" << endl;
    for (int i = 0; i < a17.get_length(); i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "elements of set 'a18' are moved to array" << endl;
    cout << "elements of array:" << endl;
    for (int i = 0; i < a18.get_length(); i++)
        cout << array[i] << " ";
    free(array);
    free(array2);
    cout << endl;
}

void test_iterators(){
    try {
        cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" << endl;
        set<int> a18{10,20,30,40,50,60,70,80,90,100};
        set<int> a25{};
        cout << "17. a set 'a18' is initialized with (10,20,30,40,50,60,70,80,90,100) " << endl;
        Iterator<int> iterator(a18);
        //Iterator<int> pupa(a25);
        cout << "\nthe value of iterator is - " << iterator.value() << endl;
        cout << "\nthe value of iterator after next() is - " << iterator.next().value() << endl;
        cout << "\nis it end? - " << iterator.is_end() << endl;
        auto a19 = a18.begin();
        ++a19;
        cout << "\nthe set 'a19' is made and iterator is moved to second element" << endl;
        if (iterator == a19){
            cout << "the position of iterator and element is similar" << endl;
            cout << *iterator << " == " << a19.value() << endl;}
        else{
            cout << "the position of iterator and element is different" << endl;
            cout << *iterator << " != " << *a19 << endl;}
        auto a20 = a18.end();
        if (a19 != a20){
            cout << "\nthe end of set 'a18' is not similar as position of iterator" << endl;
            cout << *a19 << " != " << a20.value() << endl;}
        else{
            cout << "\nthe end of set 'a18' is similar as position of iterator" << endl;
            cout << *a19 << " == " << *a20 << endl;}
    } catch (MyException& ex){
        cout << ex.what() << endl;
    }
}

template<typename Type>
bool set<Type>::comp(Type &r1, Type &r2){
    return r1 < r2;
}
*/
