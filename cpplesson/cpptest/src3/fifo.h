/* Fifo.h */
#ifndef FIFO_H_
#define FIFO_H_

#include <atomic>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

template <class T>
class Fifo
{
public:

   Fifo<T>(int len);
   ~Fifo<T>();

   int  AddTokens(T* buffer, int len);
   int  RetrieveTokens(T* buffer, int len);
   // custom constructor
   explicit Fifo(int size = maxlen) : fv(size) {
       front = rear = count = 0;
    }

   // Modifiers
   void write (const T &);    // wrtie data to Fifo
   <T> read();                // read data from Fifo

   // Selectors
   int nitems() const { return count; }
   int length() const { return fv.length(); }
   bool full()  const { return count == length(); }
   bool empty() const { return count == 0; }
   void push (const T);                        // add character to back of Q
   T pop();                                    // remove character from Q
   T front() const;                            // check character at front
   int size () const;                          // return no of elements
   void shrink();                              // resize Queue small
   void expand();                              // expand queue
   int capacity();                             // returns number elements
   void resize (int);                          // resize the queue by adding

private:
   Array <T> fv;          // container array object
   int front;             // read position
   int rear;              // write prosition
   int count;             // current number of items
   enum { maxlen = 80 };  // default length
   int capacity;
   //int size;
   T * data;
   static const int _EMPTY = -1;
   static const int _DEFAULT = 5;
};
#endif  // Fifo.h end


template <class T>Fifo<T>::Fifo(int len)
{
  _fifoptr = new FifoImpl_class((T)len);
   cout << "From the constructor" << endl;
      //thisbuffer = malloc(sizeof(T)*len);
}
  
  
template <class T>Fifo<T>::~Fifo() { }
  
template <class T>int Fifo<T>::AddTokens(T* buffer, int len)
{
      cout << "Added tokens" << endl;
      return(1);
}
  
template <class T>int Fifo<T>::RetrieveTokens(T* buffer, int len)
{
      cout << "Removed tokens" << endl;
      return(2);
}

template <class T>void Fifo<T>::write(const T  &c)   // write data to fifo
{
    if(full())
       throw FifoError("Fifo is full");
    else {
       count++;
       if(rear == length())       // reached to end?
            rear = 0;             // wrap around
       fv[rear++] = c;            // put data into array
    }
}

template <class T> <T>Fifo<T>::read()    // read data from Fifo
{
     if(empty())
       throw FifoError("Fifo is an Empty");
     else {
        count--;
         if(front == length())      // reached to an end
           front = 0;               // wrap around
     }
    return fv[front++];             // get data from Array
}

template <class T>Fifo<T>::capacity()
{
      if (capacity < 0)
          capacity = _DEFAULT;
      else {
             capacity = capacity;     // total size of array
             front = 0;
             rear  = 0;
             count = 0;
             data  = 0;
        }
}

template <class T>Fifo<T>::~Fifo()
{
       delete [] data;
}

template <class T>bool Fifo<T>::empty() 
{
          return count = 0;
}

template <class T> bool Fifo<T>::full() const
{
       return count = capacity;
}

class FifoError {
     private:
         char buf[80];
     public:
         FifoError (const char *msg) 
         { sprintf( buf, "Fifo: %s", msg); }
         void response() const 
         { cerr << buf << endl; }
};


