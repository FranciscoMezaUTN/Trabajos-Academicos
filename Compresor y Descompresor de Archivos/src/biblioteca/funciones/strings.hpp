#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i=0;
   while(s[i]!='\0')
   {
      i++;
   }
   return i;
}

int charCount(string s,char c)
{
   int i=0, contc=0;
   while(s[i]!='\0')
   {
      if(s[i]==c){
         contc++;
      }
      i++;

   }
   return contc;
}

string substring(string s,int d,int h)
{
   string r="";
   while(d<h)
   {
         string aux = "a";
         aux[0] = s[d];

         r=r+aux;
         d++;
      }

   return r;
}

string substring(string s,int d) // ok
{
   string r="";
   int i=d;
   while(s[i]!='\0'){
      string aux = "a";
      aux[0] = s[i];
      r=r+aux;
      i++;
   }

   return r;
}

int indexOf(string s,char c) // ok
{
   int posicion=0;
   for(int i=0; s[i]!='\0'; i++)
   {
      if(s[i]==c)
      {
         posicion=i;
         break;
      }
      else
      {
         posicion=-1;
      }
   }
   return posicion;
}

int indexOf(string s,char c,int offSet) // ok
{
   int posicion=0;
      for(int i=offSet; s[i]!='\0'; i++)
      {
         if(s[i]==c)
         {
            posicion=i;
            break;
         }
         else
         {
            posicion=-1;
         }
      }
      return posicion;
}

int indexOf(string s,string toSearch) // ok
{
   int primCar = indexOf(s, (char)toSearch[0]);

      string subs;
      while(primCar != -1 && primCar+length(toSearch) <= length(s)){
         subs = substring(s, primCar, primCar+length(toSearch));
         if(subs == toSearch)
               return primCar;
         primCar = indexOf(s, (char)toSearch[0], primCar+1);
      }

      return -1;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   string subs = substring(s, offset);
   int ocu = indexOf(subs, toSearch);
   if(ocu == -1)
   {
      return -1;
   }
   return -1;
}

int lastIndexOf(string s,char c)
{
   int i;
   for(i=length(s)-1; i>=0; i--)
   {
      if(s[i] == c)
      {
         return i;
      }
   }
   return -1;
}

int indexOfN(string s,char c,int n)
{
   if(n==0)
   {
      return -1;
   }
   int i;
   for(i=0; i<length(s); i++)
   {
      if(s[i]==c)
      {
         n--;
      }
      if(n==0)
      {
         return i;
      }
   }
   return length(s);
}

int charToInt(char c)
{
   int n=(int)c;
   if(n>=48 && n<=57){
      return n-48;
   }
   if(n>=65 && n<=90){
      return n-55;
   }
   if(n>=97 && n<=122){
      return n-87;
   }
   return 0;
}

char intToChar(int i)
{
   int n;
   if(i>=0 && i<=9){
      n=i+48;
   }
   if(i>=10 && i<=35){
      n=i+55;
   }
   return (char)n;
}

int getDigit(int n,int i)
{
   int r, pot=1;
   for(int j=0; j<i; j++){
      pot*=10;
   }
   r=n%(pot*10)/pot; // r= n%(10 elevado a (i+1))/ 10 elevado a i

   return r;
}

int digitCount(int n)
{
   int cont=0;
   if(n==0){
      return 1;
   }
   while(n!=0){
      n/=10;
      cont++;
   }
   return cont;
}

string intToString(int i)
{
   int digito;
   string r="", aux="a";
   for(int j=digitCount(i)-1; j>=0; j--)
   {
      digito=getDigit(i, j);
      aux[0]=intToChar(digito);
      r+=aux;
   }
   return r;
}

int stringToInt(string s,int b) // ok
{
   int aux, n=0;
   for(int i=0; i<length(s); i++)
   {
      aux=charToInt((char)s[i]);
      n=n*b+aux;

   }
   return n;
}

int stringToInt(string s) // ok
{
   return stringToInt(s, 10);
}

string charToString(char c)
{
   string s="a";
   s[0]=c;
   return s;
}

char stringToChar(string s)
{
   return (char)s[0];
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{
   int partEnt = (int)d, aux=0;
   double partDec = d-partEnt;
   string r = intToString(partEnt)+".";
   for(int i =0; i<10; i++){
      partDec= (partDec-aux)*10;
      aux=(int)partDec;
      r+=intToString(aux);
   }

   return r;
}

double stringToDouble(string s)
{
   int posComa=indexOf(s, '.');
   if(posComa==-1){
      return stringToInt(s);
   }
   string partEnt= substring(s, 0, posComa),
         partDec= substring(s, posComa+1);

   double r=stringToInt(partEnt),
         rdec=stringToInt(partDec);

   for(int i=0; i<length(partDec); i++)
   {
      rdec/=10;
   }
   r+=rdec;

   return r;
}

bool isEmpty(string s)
{
   return (s == "");
}

bool startsWith(string s,string x)
{
   for(int i=0; i<length(x); i++)
   {
      if(s[i]!=x[i])
      {
         return false;
      }
   }
   return true;
}

bool endsWith(string s,string x)
{
   char firstCharX = x[0];
   int j=0;

   if(indexOf(s, firstCharX)<0)
   {
      return false;
   }

   for(int i = indexOf(s, firstCharX); i<=length(s); i++)
   {
      if(s[i] != x[j])
      {
         return false;
      }
      j++;
   }

   return true;
}

bool contains(string s,char c)
{
   if(indexOf(s, c)<0)
   {
      return false;
   }
   return true;
}

string replace(string s,char oldChar,char newChar)
{
   for(int i=1; i<length(s); i++)
   {
         if(indexOfN(s, oldChar, 1)!=length(s))//esto no tiene sentido pero funciona ¡¡¿¿(:o)??!! (y si tiene sentido, no entendí jajaj)
         {
            s[indexOfN(s, oldChar, 1)]=newChar;
         }
   }
   return s;
}

string insertAt(string s,int pos,char c)
{
   s[pos]=c;
   return s;
}

string removeAt(string s, int pos)
{
   string restOfs = substring(s, pos);
   int j=1;

   for(int i=pos; i<length(s); i++)
   {
      s[i]=restOfs[j];
      j++;
   }

   return s;
}

string ltrim(string s)
{
  int cont=0, aux;
  string nuevoS="", aux2="a";

  for(int i=0; i<length(s); i++){
     if(s[i]==' ')
     {
          cont++;
     }
     else
     {
        break;
     }
  }

  aux=cont;

  for(int j=0; j<length(s)-aux; j++){
     aux2[0]=s[cont];
     nuevoS+=aux2;
     cont++;
  }

   return nuevoS;
}

string rtrim(string s)
{
   int i=length(s)-1;

   while(s[i] == ' ')
   {
      i--;
   }

   return substring(s, 0, i+1);
}

string trim(string s)
{
   string nuevoS= s;
   nuevoS=ltrim(nuevoS);
   nuevoS=rtrim(nuevoS);

   return nuevoS;
}

string replicate(char c,int n)
{
   string nuevoS="", aux="a";
   aux[0]=c;

   for(int i=0; i<n; i++)
   {
      nuevoS+=aux;
   }
   return nuevoS;
}

string spaces(int n)
{
   string espacios="";
   for(int i=0; i<n; i++){
      espacios+=' ';
   }

   return espacios;
}

string lpad(string s,int n,char c)
{
   string relleno = replicate(c,  n-length(s));

   return relleno+s;
}

string rpad(string s,int n,char c)
{
   string relleno = replicate(c,  n-length(s));
   return s+relleno;
}

string cpad(string s,int n,char c)
{
   int canCarR = n - length(s);
   string relleno = replicate(c, canCarR/2);
   string r = relleno + s + relleno;

   if(length(r) != n)
   {
      r = r + charToString(c);
   }

   return r;
   //return lpad(rpad(s, length(s)+(n/2)-2, c), n, c);
}

bool isDigit(char c)
{
   for(int i = 0; i<=9; i++)
   {
      if(charToInt(c)==i)
      {
         return true;
      }
   }
   return false;
}

bool isLetter(char c)
{
   if(isDigit(c)==0)
   {
      return true;
   }
   return false;
}

bool isUpperCase(char c)
{
   for(int i=65; i<=90; i++)
   {
      if((int)c == i)
      {
         return true;
      }
   }
   return false;
}

bool isLowerCase(char c)
{
   if(isUpperCase(c)==0)
   {
      return true;
   }
   return false;
}

char toUpperCase(char c)
{
   int upperCase=(int)c-32;

   return (char)upperCase;
}

char toLowerCase(char c)
{
   int lowerCase=(int)c+32;

   return (char)lowerCase;
}

string toUpperCase(string s)
{
   string upperCase;

   for(int i=0; i<length(s); i++)
   {
      upperCase += toUpperCase((char)s[i]);
   }

   return upperCase;
}

string toLowerCase(string s)
{
   string lowerCase;

      for(int i=0; i<length(s); i++)
      {
         lowerCase += toLowerCase((char)s[i]);
      }

   return lowerCase;
}

int cmpString(string a,string b)
{
   if(length(a)>length(b) || length(a)==length(b))
   {
      for(int i=0; i<=length(a); i++)
      {
         if(charToInt((char)a[i]) < charToInt((char)b[i]))
         {
            return -1;
         }
         if(charToInt((char)a[i]) > charToInt((char)b[i])){
            return 1;
         }
      }
   }

   if(length(a)<length(b) || length(a)==length(b))
      {
         for(int i=0; i<=length(b); i++)
         {
            if(charToInt((char)a[i]) < charToInt((char)b[i]))
            {
               return -1;
            }
            if(charToInt((char)a[i]) > charToInt((char)b[i])){
               return 1;
            }
         }
      }

   return 0;
}

int cmpDouble(double a,double b)
{
   if(a < b)
   {
      return -1;
   }
   if(a > b)
   {
      return 1;
   }
   return 0;
}

#endif
