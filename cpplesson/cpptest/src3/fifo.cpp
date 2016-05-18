/* Fifo.cpp*/
#include "Fifo.h"

template <class T>
Fifo<T>::Fifo(int len)
{
  //_fifoptr = new FifoImpl_class((T)len);
  printf ("From the constructor\n");
  //thisbuffer = malloc(sizeof(T)*len);
}


template <class T>
Fifo<T>::~Fifo() { }

template <class T>
int Fifo<T>::AddTokens(T* buffer, int len)
{
  printf("Added tokens\n");
  return(1);
}


template <class T>
int Fifo<T>::RetrieveTokens(T* buffer, int len)
{
  printf("Removed tokens\n");
  return(2);
}
// end of Fifo.cpp

