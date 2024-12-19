#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   if(s=="")
      return 0;
   return charCount(s, sep)+1;
}

void addToken(string& s,char sep,string t)
{
   if(s==""){
      s=t;
   }
   else{
      s += charToString(sep) + t;
   }
}

string getTokenAt(string s,char sep, int i)
{
   if(i==0)
   {
      return substring(s, 0, indexOfN(s, sep, 1));
   }
   if(i==charCount(s, sep))
   {
      return substring(s, indexOfN(s, sep, i)+1);
   }
   return substring(s, indexOfN(s, sep, i)+1, indexOfN(s, sep, i+1));
}

void removeTokenAt(string& s,char sep, int i)
{
   if(i==0)
   {
      s = substring(s, length(getTokenAt(s, sep, i))+1);
   }
   else if(i==charCount(s, sep))
   {
      s = substring(s, 0, indexOf(s, getTokenAt(s, sep, i))-1);
   }
   else if(i!=0)
   {
      s = substring(s, 0, indexOf(s, getTokenAt(s, sep, i))) + substring(s, indexOf(s, getTokenAt(s, sep, i))+length(getTokenAt(s, sep, i))+1);
   }
}

void setTokenAt(string& s,char sep, string t,int i)
{
   if(i==0)
   {
      s = t + substring(s, length(getTokenAt(s, sep, i)));
   }
   if(i==charCount(s, sep))
   {
      s = substring(s, 0, indexOf(s, getTokenAt(s, sep, i))) + t;
   }
   else
   {
      s = substring(s, 0, indexOf(s, getTokenAt(s, sep, i))) + t + substring(s, indexOf(s, getTokenAt(s, sep, i))+length(getTokenAt(s, sep, i)));
   }
}

int findToken(string s,char sep, string t)
{
   for(int i=0; i<=tokenCount(s, sep); i++)
   {
      if(t==getTokenAt(s, sep, i))
      {
         return i;
      }
   }
   return -1;
}

#endif
