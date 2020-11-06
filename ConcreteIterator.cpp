
#include "ConcreteIterator.h"

template <class T>
ConcreteIterator<T>::ConcreteIterator(T ** arr)
{
  array = arr;
  currentPosition = 0;
}

template <class T>
ConcreteIterator<T>::~ConcreteIterator(){
  //Do Nothing
}

template <class T>
void ConcreteIterator<T>::first()
{
  currentPosition = 0;
}

template <class T>
void ConcreteIterator<T>::next()
{
  currentPosition++;
}

template <class T>
bool ConcreteIterator<T>::hasNext(){
  bool hNext = true;
  T* temp;
  try{
    temp = array[currentPosition + 1];
  }
  catch(char const *error){
    hNext = false;
  }
  return hNext;
}

template <class T>
int ConcreteIterator<T>::current(){
  return currentPosition;
}

template <class T>
T* ConcreteIterator<T>::getCurrent()
{
  return array[currentPosition];
}

template class ConcreteIterator<F1CarSpecification>;
template class ConcreteIterator<EngineeringDepartments>;
//template class ConcreteIterator<int>;
//template class ConcreteIterator<string>;