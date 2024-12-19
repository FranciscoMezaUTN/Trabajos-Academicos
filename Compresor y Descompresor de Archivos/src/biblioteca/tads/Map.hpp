
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int curr;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys = array<K>();
   m.values = array<V>();
   m.curr = 0;
   return m;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   for(int i=0; i<m.keys.len; i++)
   {
      if(m.keys.arr[i]==k)
         return arrayGet<V>(m.values, i);
   }
   return NULL;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   for(int i=0; i<m.keys.len; i++)
   {
      if(m.keys.arr[i]==k)
      {
         m.values.arr[i] = v;
         return mapGet<K, V>(m, k);
      }
   }

   arrayAdd<K>(m.keys, k);
   arrayAdd<V>(m.values, v);

   return mapGet<K, V>(m, k);
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   for(int i=0; i<m.keys.len; i++){
      if(m.keys.arr[i]==k){
         return true;
      }
   }
   return false;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   V v = *mapGet<K, V>(m, k);
   int pos;

   for(int i=0; i<m.keys.len; i++)
   {
      if(m.keys.arr[i]==k)
         pos=i;
   }

   arrayRemove<K>(m.keys, pos);
   arrayRemove<V>(m.values, pos);

   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return arraySize<V>(m.values);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   if(m.curr == mapSize<K, V>(m))
      return false;
   return true;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   K k = *arrayGet<K>(m.keys, m.curr);
   m.curr++;
   return k;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   m.curr++;
   return arrayGet<V>(m.values, m.curr-1);
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.curr = 0;
}

template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
      Array<K> auxKeys = array<K>();
      Array<V> auxValues = array<V>();

      for(int i=0; i<arraySize<K>(m.keys); i++)
         arrayAdd<K>(auxKeys, *arrayGet<K>(m.keys, i));

      arraySort<K>(auxKeys, cmpKK);

      for(int i=0; i<arraySize<K>(auxKeys); i++)
         arrayAdd<V>(auxValues, *mapGet<K,V>(m, *arrayGet<K>(auxKeys, i)));

      m.keys = auxKeys;
      m.values = auxValues;
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
   Array<K> auxKeys = array<K>();
   Array<V> auxValues = array<V>();

   for(int i=0; i<arraySize<V>(m.values); i++)
      arrayAdd<V>(auxValues, *arrayGet<V>(m.values, i));

   arraySort<V>(auxValues, cmpVV);

   for(int i=0; i<arraySize<V>(auxValues); i++)
   {
      int posK = arrayFind<V>(m.values, *arrayGet<V>(auxValues, i), cmpVV);
      arrayAdd<K>(auxKeys, *arrayGet(m.keys, posK));
   }

   m.keys = auxKeys;
   m.values = auxValues;
}

#endif
