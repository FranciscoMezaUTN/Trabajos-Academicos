#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len] = e;
   len++;
   return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   for(int i = len; i > p; i--)
   {
      arr[i] = arr[i-1];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret = arr[p];
   for(int i=p; i<len-1; i++)
      arr[i] = arr[i+1];
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int i=0;
   bool found = false;
   while(found==false && i<len)
   {
      if(cmpTK(arr[i], k)==0)
         found = true;
      i++;
   }
   if(found==true)
      return i-1;
   else
      return -1;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int i=0;
   while(i<len && cmpTT(arr[i], e)<=0)
      i++;
   insert<T>(arr, len, e, i);
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   for(int i=0; i<len; i++)
   {
      T aux;
      int pos=i;
      for(int j=i+1; j<len; j++)
      {
         if(cmpTT(arr[j], arr[pos])<=0)
            pos=j;
      }
      aux = arr[i];
      arr[i]=arr[pos];
      arr[pos]=aux;
   }
   return;
}



#endif
