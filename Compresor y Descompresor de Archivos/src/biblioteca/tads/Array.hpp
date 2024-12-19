#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* arr;
   int len;
};

template<typename T>
Array<T> array()
{
   Array<T> ret;
   ret.arr = new T[1000];
   ret.len = 0;
   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   return add<T>(a.arr, a.len, t);
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   return &a.arr[p];
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   a.arr[p] = t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   insert<T>(a.arr, a.len, t, p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T t = a.arr[p];
   remove<T>(a.arr, a.len, p);
   return t;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   int i=0;
   while(arraySize<T>(a)!=0)
   {
      remove<T>(a.arr, a.len, i);
      i++;
   }
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T>(a.arr, a.len, k, cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr, a.len, cmpTT);
}

#endif
