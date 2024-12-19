#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include <string>
using namespace std;

template<typename T>
struct Coll
{
   string s;
   char sep;
   int curr;
};

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c = {"", sep, 0};
   return c;
}

template<typename T>
Coll<T> coll()
{
   Coll<T> c = {"", '|', 0};
   return c;
}

template<typename T>
int collSize(Coll<T> c)
{
   return tokenCount((string)c.s, c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c = {"", '|', 0};
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s, c.sep, p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s, c.sep, tToString(t));
   return collSize<T>(c);
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.s, c.sep, tToString(t), p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t = tFromString(getTokenAt(c.s, c.sep, p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   for(int i=0; i<collSize(c); i++)
   {
      if(cmpTK(tFromString(getTokenAt(c.s, c.sep, i)),k)==0)return i;
   }
   return -1;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
      T a, b, aux;
      bool ordenado = false;

      while(!ordenado){
         ordenado = true;

         for(int i=0; i<collSize<T>(c)-1; i++){
            a = collGetAt<T>(c, i, tFromString);
            b = collGetAt<T>(c, i+1, tFromString);

            if(cmpTT(a, b) > 0){
               aux = a;
               a = b;
               b = aux;
               collSetAt<T>(c, a, i, tToString);
               collSetAt<T>(c, b, i+1, tToString);
               ordenado = false;
            }
         }
      }
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   if(c.curr == collSize(c)){return false;}
   else{return true;}
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t = tFromString(getTokenAt(c.s, c.sep, c.curr));
   c.curr++;
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t = tFromString(getTokenAt(c.s, c.sep, c.curr));
   c.curr++;
   c.curr==collSize(c)? endOfColl=false : endOfColl=true;
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.curr=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}



#endif
