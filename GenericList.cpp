#include "GenericList.h"
template <class T>
GenericList<T>::GenericList()
{
  array = NULL;
  numItems = 0;
}

template <class T>
GenericList<T>::~GenericList()
{
  for (int i = 0; i < numItems; i++)
  {
    if (array[i] != NULL)
      delete array[i];
  }

  if (array != NULL)
    delete[] array;
}

template <class T>
void GenericList<T>::addItem(T * newItem)
{
  T **newArr = new T *[numItems + 1];

  for (int i = 0; i < numItems; i++)
  {
    newArr[i] = array[i];
  }
  numItems++;
  newArr[numItems] = newItem;
  if(array != NULL){
    delete[] array;
  }
  array = newArr;
}

template <class T>
void GenericList<T>::removeItem(string name)
{
  for (int i = 0; i < numItems; i++)
  {
    if (name.compare(array[i]->getName()) == 0){
      removeItem(i);
      break;
    }
  }
}

template <class T>
void GenericList<T>::removeItem(int index)
{
  if(index < numItems && array[index] != NULL){
    delete array[index];

    T **newArr = new T *[numItems -1];

    for (int i = 0, count = 0; i < numItems; i++)
    {
      if(i != index)
        newArr[count++] = array[i];
    }
    numItems--;
    delete[] array;
    array = newArr;
  }
}

template <class T>
T *GenericList<T>::getItem(string name)
{
  for (int i = 0; i < numItems; i++)
  {
    if (name.compare(array[i]->getName()) == 0)
      return array[i];
  }
  return NULL;
}

template <class T>
T *GenericList<T>::getItem(int index)
{
  if (index >= numItems)
    return NULL;
  else
    return array[index];
}

template <class T>
Iterator *GenericList<T>::createIterator()
{
  return new ConcreteIterator<T>(array);
}

template <class T>
bool GenericList<T>::isEmpty()
{
  return (numItems==0);
}

template class GenericList<F1CarSpecification>;
template class GenericList<EngineeringDepartments>;