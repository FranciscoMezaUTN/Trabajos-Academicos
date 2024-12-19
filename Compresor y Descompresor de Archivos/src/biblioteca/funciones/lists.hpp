#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T>* next;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->next = NULL;

   if(p!=NULL)
   {
      Node<T>* aux = p;
      while(aux->next!=NULL)
         aux = aux->next;
      aux->next = nuevo;
   }
   else
      p = nuevo;

   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->next = p;
   p = nuevo;
   return nuevo;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
   T t;
   Node<T>* aux = p;
   Node<T>* ant = NULL;

   while(aux!=NULL && cmpTK(aux->info, k)!=0)
   {
      ant = aux;
      aux = aux->next;
   }

   if(ant==NULL)
   {
      t = p->info;
      p = aux->next;

   }
   else
   {
      t = ant->info;
      ant->next = aux->next;
   }

   delete aux;

   return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t = p->info;
   Node<T>* aux = p->next;
   delete p;
   p=aux;
   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   Node<T>* aux = p;

   while(aux!=NULL && cmpTK(aux->info, k)!=0)
      aux = aux->next;

   return aux;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   if(p==NULL)
      return add(p, e);

   if(cmpTT(p->info, e)>=0)
      return addFirst(p, e);

   Node<T>* aux = p->next;
   Node<T>* ant = p;


   while(aux!=NULL)
   {
      if(cmpTT(aux->info, e)>=0)
         return addFirst<T>(ant->next, e);

      aux = aux->next;
      ant = ant->next;
   }

   return add<T>(ant, e);
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   Node<T>* r = find<T,T>(p, e, cmpTT);

   if(r==NULL)
   {
      r = orderedInsert<T>(p, e, cmpTT);
      enc = false;
   }
   else
      enc = true;

   return r;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
   Node<T>* aux = p;
   Node<T>* sortList = NULL;

   while(aux!=NULL)
   {
      orderedInsert<T>(sortList, aux->info, cmpTT);
      aux = aux->next;
   }

   p = sortList;
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL?true:false;
}

template <typename T>
void free(Node<T>*& p)
{
   while(p!=NULL)
   {
      Node<T>* aux = p->next;
      delete p;
      p = aux;
   }
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return addFirst<T>(p, e);
}

template <typename T> T pop(Node<T>*& p)
{
   return removeFirst<T>(p);
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   return NULL;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   return NULL;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t;
   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   T t;
   return t;
}

#endif
