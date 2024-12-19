#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* list;
   int curr;
};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.list = NULL;
   lst.curr = 0;
   return lst;
}

template<typename T>
T* listAdd(List<T>& lst, T e)
{
   return &add<T>(lst.list, e)->info;
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
   return &addFirst<T>(lst.list, e)->info;
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   return remove<T>(lst.list, k, cmpTK);
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{
   return removeFirst<T>(lst.list);
}

template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   return &find<T>(lst.list, k, cmpTK)->info;
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty<T>(lst.list);
}

template<typename T>
int listSize(List<T> lst)
{
   Node<T>* aux = lst.list;
   int cont = 0;

   while(aux!=NULL)
   {
      aux = aux->next;
      cont++;
   }

   return cont;
}

template<typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.list);
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   return &orderedInsert<T>(lst.list, t, cmpTT)->info;
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.list, cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.curr = 0;
}

template<typename T>
bool listHasNext(List<T> lst)
{
   return lst.curr==listSize<T>(lst)?false:true;
}

template<typename T>
T* listNext(List<T>& lst)
{
   Node<T>* t = lst.list;

   for(int i=0; i<lst.curr; i++)
      t = t->next;

   lst.curr++;

   return &t->info;
}

template<typename T>
T* listNext(List<T>& lst,bool& endOfList)
{
   Node<T>* t = lst.list;

   for(int i=0; i<lst.curr; i++)
      t = t->next;

   lst.curr++;
   endOfList = lst.curr==listSize<T>(lst)?true:false;


   return &t->info;
}

#endif
