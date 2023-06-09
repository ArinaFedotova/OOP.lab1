#ifndef SET_H
#define SET_H

#include <initializer_list>
#include <iostream>
#include <iterator.h>
#include "set_exeption.h"

template <typename Type>
class set
{
private:
    Type *st;
    int len = 0;
public:
    set();                                          //конструктор по умолчанию
    set(const set<Type>&s);                         //конструктор копирования
    set (set<Type> &&s);                            //конструктор перемещения
    explicit set(std::initializer_list<Type> lst);  //конструктор со списком инициализации
    ~set();                                         //деструктор
    set<Type>& operator = (const set<Type>& lst);   //перегрузка оператора присваивания
    int get_length() const;                         //получить текущий размер
    bool contains(const Type& elem);                //проверить наличие в множестве элемента
    void add(const Type& elem);                     //добавить элемент в множество
    void remove(const Type& elem);                  //удалить элемент в множество
    Type* to_array();                               //создать новый массив, в который необходимо записать все элементы множества
    set<Type>& unionn(const set<Type>& s);           //результат – объединение this с s
    set<Type>& intersection(const set<Type>& s);    //результат – пересечение this с s
    set<Type>& subtract(const set<Type>& s);        //результат – разность this и s
    template<typename _T>                           //перегрузка оператора <<
    friend std::ostream& operator <<(std::ostream& os, const set<_T>& lst);
    set<Type>& operator +=(const set<Type>& s);     //перегрузка оператора += результат – объединение множеств this и s
    set<Type>& operator *=(const set<Type>& s);     //перегрузка оператора *=, результат – пересечение множеств this и s
    set<Type>& operator /=(const set<Type>& s);     //перегрузка оператора /=, разность множеств this и s
    template<typename _T>                           //перегрузка оператора + результат – объединение множеств v1 и v2
    friend set<_T> operator +(const set<_T>& s1, const set<_T>& s2);
    template<typename _T>                           //перегрузка оператора * результат – пересечение множеств v1 и v2
    friend set<_T> operator *(const set<_T>& s1, const set<_T>& s2);
    template<typename _T>                           //перегрузка оператора / результат – разность множеств v1 и v2
    friend set<_T> operator /(const set<_T>& s1, const set<_T>& s2);
    Iterator<Type> iterator_begin();                //метод получения итератора на начало множества (первый элемент)
    Iterator<Type> iterator_end();                  //метод получения итератора на конец множества (фиктивный элемент, следующий за последним в множестве)
    void clear();                                   //очистить множество
    bool comp(const Type &r1, const Type &r2);
    void sort(int (*comp)(const Type &r1, const Type &r2));
    void resize(int amount);
    Type &operator[](int index);

};

template<typename Type>
int comp(const Type &r1, const Type &r2)
{
    return (r1 > r2) ? (1) : (0);
}

template<typename Type>
void set<Type>::sort(int (*comp)(const Type &r1, const Type &r2)){
    int tmp;
    for (int i = 0; i < len - 1; i++)
        for (int j = i+1; j < len; j++)
            if (comp(st[i], st[j])){
                tmp = st[i];
                st[i] = st[j];
                st[j] = tmp;
            }
}


template<typename Type>
void set<Type>::resize(int len){
    st = (Type*)realloc(st, sizeof(Type) * len);
    if (st == nullptr){
        len = 0;
        throw set_exeption("Bad alloc!");
    }
}

template<typename Type>
Type &set<Type>::operator[](int index)
{
    if(index < 0 || len <= index)
        throw set_exeption("Wrong index of set");
    return *(st + index);
}

template <typename Type>
set<Type>::set()    //конструктор по умолчанию
{
    st = nullptr;
    len = 0;
}

template <typename Type>
set<Type>::set(const set<Type>&s)   //конструктор копирования
{
    try {
        len = s.len;
        st = new Type[len];
        for(int i = 0; i < len; i++)
            st[i] = s.st[i];
    } catch (std::bad_alloc const&){
        throw set_exeption("Bad alloc!");
    }
}

template <typename Type>
set<Type>::set (set<Type> &&s)  //конструктор перемещения
{
    st = s.st;
    len = s.len;
    s.len = 0;
    s.st = nullptr;
}

template <typename Type>
set<Type>::set(std::initializer_list<Type> lst)   //конструктор со списком инициализации
{
    try {
        if(len < 0)
            throw set_exeption("Bad length of set");
        st = new Type[lst.size()]{};
        for(Type item : lst)
            (*this).add(item);
    } catch (std::bad_alloc const&) {
        st = nullptr;
        throw set_exeption("Bad alloc");
    }
}

template <typename Type>
set<Type>::~set()   //деструктор
{
    delete[] st;
}

template<typename Type>
set<Type>& set<Type>::operator=(const set<Type>& lst)   //перегрузка оператора присваивания
{
    try {
        st = new Type[lst.len]{};
        len = lst.len;
        for(int i = 0; i < lst.len; i++)
            st[i] = lst.st[i];

        return *this;
    } catch (std::bad_alloc const&){
        throw set_exeption("bad alloc");
    }
}

template<typename Type>
int set<Type>::get_length() const  //получить текущий размер
{
    return len;
}

template<typename Type>
bool set<Type>::contains(const Type& elem)  //проверить наличие в множестве элемента
{
    bool ans = false;
    if(len == 0)
        return false;
    for(int i = 0; i < len; i++){
        int k = (*this).st[i];
        if (k == elem){
            ans = true;
            break;
        }
    }
    return ans;
}

template<typename Type>
void set<Type>::add(const Type& elem)   //добавить элемент в множество
{
    if (!contains(elem))
    {
        resize(len+1);
        st[len] = elem;
        len++;
    }
}

template<typename Type>
void set<Type>::remove(const Type& elem)   //удалить элемент в множествe
{
    if(len <= 0)
        throw set_exeption("Bad length for set");
    if (contains(elem)){
        len--;
        bool find_el = false;
        for(int i = 0; i < len; i++){
            if (elem == st[i] || find_el){
                find_el = true;
                st[i] = st[i+1];
            }
        }
        if (find_el)
            st[len-1] = st[len];
        else
            st[len] = 0;
        resize(len);
    }
}

template<typename Type>
Type* set<Type>::to_array()    //создать новый массив, в который необходимо записать все элементы множества
{
    Type *array = new Type[len];
    Iterator<Type> iter(*this);
    for (int i = 0; i < len; i++) {
        array[i] = iter.value();
        ++iter;
    }
    return array;
}

template<typename _T>
std::ostream& operator <<(std::ostream& os, const set<_T>& lst)  //перегрузка оператора <<
{
    std::string container = "set {len: " + std::to_string(lst.len) + ", set: [";
    for(int i = 0; i < lst.len; i++)
        container += std::to_string(lst.st[i]) + ", ";
    if(lst.len > 0)
        container = container.substr(0, container.size()-2); // Удалить два лишних ", "
    container += "]}";
    return os << container;
}

template<typename _T>
set<_T> operator +(const set<_T>& s1, const set<_T>& s2)  //перегрузка оператора + результат – объединение множеств s1 и s2
{
    set<_T> s_new;
    for (int i = 0; i < s1.len; i++)
        s_new.add(s1.st[i]);
    for (int i = 0; i < s2.len; i++)
        s_new.add(s2.st[i]);
    return s_new;
}

template<typename _T>
set<_T> operator *(const set<_T>& s1, const set<_T>& s2)    //перегрузка оператора * результат – пересечение множеств s1 и s2
{
    set<_T> s_new;
    for(int i = 0; i < s1.len; i++){
        for (int j = 0; j < s2.len; j++)
            if (s2.st[j] == s1.st[i]){
                s_new.add(s1.st[i]);
                break;
            }
    }
    return s_new;
}

template<typename _T>
set<_T> operator /(const set<_T>& s1, const set<_T>& s2)    //перегрузка оператора / результат – разность множеств s1 и s2
{
    set<_T> s_new;
    for(int i = 0; i < s1.len; i++){
        s_new.add(s1.st[i]);
    }
    for(int i = 0; i < s2.len; i++){
        if (s_new.contains(s2.st[i]))
            s_new.remove(s2.st[i]);
        else
            s_new.add(s2.st[i]);
    }

    return s_new;
}

template<typename Type>
set<Type>& set<Type>::unionn(const set<Type>& s)    //результат – объединение this с s
{
    *this = *this + s;
    return *this;
}

template<typename Type>
set<Type>& set<Type>::intersection(const set<Type>& s)    //результат – пересечение this с s
{
    *this = *this * s;
    return *this;
}

template<typename Type>
set<Type>& set<Type>::subtract(const set<Type>& s)  //результат – разность this и s
{
    *this = *this / s;
    return *this;
}

template<typename Type>
set<Type>& set<Type>::operator +=(const set<Type>& s)   //перегрузка оператора += результат – объединение множеств this и s
{
    *this = *this + s;
    return *this;
}

template<typename Type>
set<Type>& set<Type>::operator *=(const set<Type>& s)   //перегрузка оператора += результат – пересечение множеств this и s
{
    *this = *this * s;
    return *this;
}

template<typename Type>
set<Type>& set<Type>::operator /=(const set<Type>& s)   //перегрузка оператора += результат – разность множеств this и s
{
    *this = *this / s;
    return *this;
}

template<typename Type>
Iterator<Type> set<Type>::iterator_begin()
{
    return Iterator<Type>(*this);
}

template<typename Type>
Iterator<Type> set<Type>::iterator_end()
{
    Iterator<Type> it = Iterator<Type>(*this);
    while(!it.is_end())
        it.next();
    return it;
}

template<typename Type>
void set<Type>::clear()    //очистить множество
{
    for (int i = 0; i<len; i++)
        st[i] = 0;
    len = 0;
    delete []st;
    st = nullptr;

}


#endif // SET_H
