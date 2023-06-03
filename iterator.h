#ifndef ITERATOR_H
#define ITERATOR_H

#include <initializer_list>
#include <iostream>


template <typename Type>
class set;

template <typename Type>
class Iterator
{
private:
    set<Type> itr_set;
    int itr_set_index = -1;
public:
    Iterator(set<Type> container_obj);  //конструктор, принимающий объект контейнерного класса, который необходимо обойти с помощью данного итератора
    Iterator next();                    //перейти к следующему объекту в контейнере
    Type value();                       //получить значение текущего объекта в контейнере
    bool is_end();                      //указывает ли итератор на конечный фиктивный элемент контейнера
    Iterator &operator ++ ();           //префиксный инкремент, эквивалентен next()
    Type &operator * ();                //оператор разыменования, эквивалентен value()
    bool operator == (Iterator &b);     //оператор сравнения
    bool operator != (Iterator &b);     //оператор сравнения
};

template <typename Type>
Iterator<Type>::Iterator(set<Type> container_obj) : itr_set(container_obj), itr_set_index(0)
{
    while (! (*this).is_end())
        (*this).next();
    itr_set_index = 0;
}

template <typename Type>
Iterator<Type> Iterator<Type>::next()
{
    if(!this->is_end())
        itr_set_index += 1;
    return *this;
}

template <typename Type>
Type Iterator<Type>::value()
{
    return itr_set[itr_set_index];
}

template <typename Type>
bool Iterator<Type>::is_end()
{
    return (itr_set_index == itr_set.get_length()-1 || itr_set.get_length() == 0);
}


template <typename Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    Iterator::next();
    return *this;
}

template <typename Type>
Type &Iterator<Type>::operator*()
{
    return (*this).value();
}


template <typename Type>
bool Iterator<Type>::operator == (Iterator &b)
{
    return (&itr_set + itr_set_index) == (&(b.itr_set) + b.itr_set_index);
}


template <typename Type>
bool Iterator<Type>::operator != (Iterator &b)
{
    return !(*this == b);
}

#endif // ITERATOR_H
