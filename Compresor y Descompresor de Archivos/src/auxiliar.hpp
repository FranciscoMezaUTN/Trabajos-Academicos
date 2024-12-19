#ifndef _MAIN
#define _MAIN

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "principal.hpp"
using namespace std;

/* //ESTRUCTURAS

struct Persona
{
   string name;
   int dni;
   double pesoKg;
};

struct Player
{
   string name;
   double score;
};
//FUNCIONES AUX.

Persona persona(string name,int dni,double pesoKg)
{
   Persona a;
   a.name = name;
   a.dni = dni;
   a.pesoKg = pesoKg;
   return a;
}

string personaToString(Persona x)
{
   char sep = 1;
   string sName=x.name;
   string sDni=to_string(x.dni);
   string sPesoKg=to_string(x.pesoKg);
   return sName+sep+sDni+sep+sPesoKg;
}

Player player(string name,double score)
{
   Player a;
   a.name = name;
   a.score = score;
   return a;
}

string playerToString(Player x)
{
   char sep = 1;
   string sName=x.name;
   string sScore=to_string(x.score);
   return sName+sep+sScore;
}

int cmpIntInt(int a, int b)
{
   return a-b;
}

int cmpDoubleDouble(double a, double b)
{
   if(a == b){
      return 0;
   }
   else{
      return a-b;
   }
}

int cmpStringString(string a, string b)
{
   return cmpString(a, b);
}

int cmpCharChar(char a, char b)
{
   return cmpString(charToString(a), charToString(b));
}

int cmpPersonaPeso(Persona p, double w)
{
   if(p.pesoKg!=w)
      return -1;
   else
      return p.pesoKg-w;
}

int cmpPersonaPersona(Persona a, Persona b)
{
   return cmpString(personaToString(a), personaToString(b));
}

int cmpPlayerPlayer(Player a, Player b)
{
   return cmpString(playerToString(a), playerToString(b));

}

int cmpPlayerScore(Player p, double s)
{
   if(p.score!=s)
      return -1;
   else
      return p.score-s;
}

int cmpPlayerName(Player p, string n)
{
   return cmpString(p.name, n);
}

int cmpInt(int a,int b){return a-b;}

int cmpShort(short a, short b){return a-b;}

int main(){

   cout<<"hola"<<endl;
   int len=0, len2=0, len3=0;
   int vec[10];
   string vec2[10];
   Persona vec3[10];

   //Pruebo función add:
   add<int>(vec, len, 100);
   cout << "añado elemento en pos: " << add<int>(vec, len, 200) << endl;
   add<int>(vec, len, 300);

   cout << vec[0] << endl;
   cout << vec[1] << endl;
   cout << vec[2] << endl;

   cout << "________________________" << endl;

   add<string>(vec2, len2, "p");
   add<string>(vec2, len2, "e");
   add<string>(vec2, len2, "z");

   cout << vec2[0];
   cout << vec2[1];
   cout << vec2[2] << endl;

   cout << "________________________" << endl;

   add<Persona>(vec3, len3, {"juan", 1234, 80.9});
   add<Persona>(vec3, len3, {"maria", 4321, 72.3});
   add<Persona>(vec3, len3, {"pedro", 1234, 90.5});
   add<Persona>(vec3, len3, {"manuel", 2243, 60.1});

   cout << personaToString(vec3[0]) << endl;
   cout << personaToString(vec3[1]) << endl;
   cout << personaToString(vec3[2]) << endl;

   cout << "________________________" << endl;

   //Pruebo función insert:
   insert<int>(vec, len, 50, 0);
   insert<int>(vec, len, 200, 2);
   insert<string>(vec2, len2, "e", 2);
   insert<string>(vec2, len2, "r", 2);
   insert<Persona>(vec3, len3, persona("mario", 987, 100.1), 1);


   for(int i=0; i<len; i++)
   {
      cout << vec[i] << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<len2; i++)
   {
      cout << vec2[i];
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<len3; i++)
   {
      cout << personaToString(vec3[i]) << endl;
   }

   cout << "________________________" << endl;

   remove<int>(vec, len, 1);
   remove<int>(vec, len, 0);
   remove<Persona>(vec3, len3, 2);
   remove<string>(vec2, len2, len2-1);


   for(int i=0; i<len; i++)
   {
      cout << vec[i] << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<len3; i++)
   {
      cout << personaToString(vec3[i]) << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<len2; i++)
   {
      cout << vec2[i];
   }

   cout << "\n________________________" << endl;

   cout << "Numero 300 encontrado en posicion: " << find<int, int>(vec, len, 200, cmpIntInt) << endl;
   cout << "________________________" << endl;

   cout << "Letra r encontrada en posicion: " << find<string, string>(vec2, len2, "r", cmpStringString) << endl;
   cout << "________________________" << endl;

   cout << "Persona de 90,5 kg. encontrada en posicion: " << find<Persona, double>(vec3, len3, 90.5, cmpPersonaPeso) << endl;
   cout << "________________________" << endl;

   orderedInsert<int>(vec, len, 125, cmpIntInt);
   orderedInsert<string>(vec2, len2, "a", cmpStringString);
   orderedInsert<int>(vec, len, 400, cmpIntInt);
   orderedInsert<string>(vec2, len2, "t", cmpStringString);
   orderedInsert<Persona>(vec3, len3, persona("zara", 4433, 50), cmpPersonaPersona);
   orderedInsert<Persona>(vec3, len3, persona("lorenzo", 1142, 25.7), cmpPersonaPersona);


   for(int i=0; i<len; i++)
   {
      cout << vec[i] << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<len2; i++)
   {
      cout << vec2[i];
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<len3; i++)
   {
      cout << personaToString(vec3[i]) << endl;
   }

   cout << "________________________" << endl;

   sort<int>(vec, len, cmpIntInt);
   sort<string>(vec2, len2, cmpStringString);
   sort<Persona>(vec3, len3, cmpPersonaPersona);

   for(int i=0; i<len; i++)
   {
      cout << vec[i] << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<len2; i++)
   {
      cout << vec2[i];
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<len3; i++)
   {
      cout << personaToString(vec3[i]) << endl;
   }

   cout << "________________________" << endl;

   Array<double> arr = array<double>();
   Array<char> arr2 = array<char>();
   Array<Persona> arr3 = array<Persona>();

   arrayAdd<double>(arr, 4.5);
   arrayAdd<double>(arr, 8.5);
   arrayAdd<double>(arr, 12.5);

   arrayAdd<char>(arr2, 'a');
   arrayAdd<char>(arr2, 'r');
   arrayAdd<char>(arr2, 'b');
   arrayAdd<char>(arr2, 'o');
   arrayAdd<char>(arr2, 'l');

   arrayAdd<Persona>(arr3, persona("tomas", 5577, 60.7));
   arrayAdd<Persona>(arr3, persona("tamara", 9182, 50.9));
   arrayAdd<Persona>(arr3, persona("tobias", 6547, 71.2));


   for(int i=0; i<arraySize<double>(arr); i++)
   {
      cout << *arrayGet<double>(arr, i) << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<arraySize<char>(arr2); i++)
   {
      cout << *arrayGet<char>(arr2, i);
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<arraySize<Persona>(arr3); i++)
   {
      cout << personaToString(*arrayGet<Persona>(arr3, i)) << endl;
   }

   cout << "________________________" << endl;

   cout << "Primer Elemento de arr: " << *arrayGet<double>(arr, 0) << endl;

   cout << "________________________" << endl;

   cout << "Cuarto elemento de arr2: " << *arrayGet<char>(arr2, 3) << endl;

   cout << "________________________" << endl;

   cout << "Ultimo elemento de arr3: " << personaToString(*arrayGet<Persona>(arr3, 2)) << endl;

   cout << "________________________" << endl;

   arraySet<double>(arr, 2, 16.5);
   arraySet<char>(arr2, 0, 'A');
   arraySet<Persona>(arr3, 1, persona("thalia", 3002, 80));

   for(int i=0; i<arraySize<double>(arr); i++)
   {
      cout << *arrayGet<double>(arr, i) << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<arraySize<char>(arr2); i++)
   {
      cout << *arrayGet<char>(arr2, i);
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<arraySize<Persona>(arr3); i++)
   {
      cout << personaToString(*arrayGet<Persona>(arr3, i)) << endl;
   }

   cout << "________________________" << endl;

   arrayInsert<double>(arr, 20.5, 3);
   arrayInsert<char>(arr2, 'b', 2);
   arrayInsert<Persona>(arr3, persona("thiago", 1111, 96.3), 0);
   arrayInsert<Persona>(arr3, persona("theo", 2222, 95.4), 0);

   for(int i=0; i<arraySize<double>(arr); i++)
   {
      cout << *arrayGet<double>(arr, i) << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<arraySize<char>(arr2); i++)
   {
      cout << *arrayGet<char>(arr2, i);
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<arraySize<Persona>(arr3); i++)
   {
      cout << personaToString(*arrayGet<Persona>(arr3, i)) << endl;
   }

   cout << "________________________" << endl;

   cout<< "Elimino de arr el elemento: " << arrayRemove<double>(arr, 0) << endl;
   cout << "________________________" << endl;

   cout<< "Elimino de arr2 el elemento: " << arrayRemove<char>(arr2, 3) << endl;
   cout << "________________________" << endl;

   cout<< "Elimino de arr3 el elemento: " << personaToString(arrayRemove<Persona>(arr3, 4)) << endl;
   cout << "________________________" << endl;

   for(int i=0; i<arraySize<double>(arr); i++)
   {
      cout << *arrayGet<double>(arr, i) << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<arraySize<char>(arr2); i++)
   {
      cout << *arrayGet<char>(arr2, i);
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<arraySize<Persona>(arr3); i++)
   {
      cout << personaToString(*arrayGet<Persona>(arr3, i)) << endl;
   }

   cout << "________________________" << endl;

// arrayRemoveAll funciona pero comento para seguir trabajando
   arrayRemoveAll<double>(arr);
   arrayRemoveAll<char>(arr2);
   arrayRemoveAll<Persona>(arr3);

   cout << arraySize<double>(arr) << endl;
   cout << arraySize<char>(arr2) << endl;
   cout << arraySize<Persona>(arr3) << endl;*/

   /*cout << "Numero 16.5 encontrado en pos.: " << arrayFind<double>(arr, 16.5, cmpDoubleDouble) << endl;
   cout << "________________________" << endl;

   cout << "Letra A encontrada en pos.: " << arrayFind<char>(arr2, 'A', cmpCharChar) << endl;
   cout << "________________________" << endl;

   cout << "Letra w encontrada en pos.: " << arrayFind<char>(arr2, 'w', cmpCharChar) << endl;
   cout << "________________________" << endl;

   cout << "Persona de 80 kg. encontradaa en pos.: " << arrayFind<Persona>(arr3, 80.0, cmpPersonaPeso) << endl;
   cout << "________________________" << endl;

   cout << "Persona de 100 kg. encontradaa en pos.: " << arrayFind<Persona>(arr3, 100.0, cmpPersonaPeso) << endl;
   cout << "________________________" << endl;

   arraySort<double>(arr, cmpDoubleDouble);
   arraySort<char>(arr2, cmpCharChar);
   arraySort<Persona>(arr3, cmpPersonaPersona);

   for(int i=0; i<arraySize<double>(arr); i++)
   {
      cout << *arrayGet<double>(arr, i) << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<arraySize<char>(arr2); i++)
   {
      cout << *arrayGet<char>(arr2, i);
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<arraySize<Persona>(arr3); i++)
   {
      cout << personaToString(*arrayGet<Persona>(arr3, i)) << endl;
   }

   cout << "________________________" << endl;

   arrayOrderedInsert<double>(arr, 50.3, cmpDoubleDouble);
   arrayOrderedInsert<char>(arr2, 'z', cmpCharChar);
   arrayOrderedInsert<Persona>(arr3, persona("zarah", 9999, 35.9), cmpPersonaPersona);

   for(int i=0; i<arraySize<double>(arr); i++)
   {
      cout << *arrayGet<double>(arr, i) << endl;
   }

   cout << "________________________" << endl;

   for(int i=0; i<arraySize<char>(arr2); i++)
   {
      cout << *arrayGet<char>(arr2, i);
   }

   cout << "\n________________________" << endl;

   for(int i=0; i<arraySize<Persona>(arr3); i++)
   {
      cout << personaToString(*arrayGet<Persona>(arr3, i)) << endl;
   }

   cout << "________________________" << endl;

   //TAD MAP

   Map<string, int> map1 = map<string, int>();

   mapPut<string, int>(map1, "diez", 10);
   mapPut<string, int>(map1, "ocho", 8);
   mapPut<string, int>(map1, "seis", 6);
   mapPut<string, int>(map1, "cuatro", 4);

   Map<int, Player> map2 = map<int, Player>();

   mapPut<int, Player>(map2, 321, player("Ronaldo", 20.5));
   mapPut<int, Player>(map2, 312, player("Mbappe", 30.4));
   mapPut<int, Player>(map2, 123, player("Neymar", 7.9));
   mapPut<int, Player>(map2, 213, player("Messi", 25.1));

   cout << *mapGet<string, int>(map1, "ocho") << endl;
   cout << *mapGet<string, int>(map1, "diez") << endl;
   cout << *mapGet<string, int>(map1, "seis") << endl;
   cout << *mapGet<string, int>(map1, "cuatro") << endl;

   cout << "________________________" << endl;

   cout << playerToString(*mapGet<int, Player>(map2, 123)) << endl;
   cout << playerToString(*mapGet<int, Player>(map2, 213)) << endl;
   cout << playerToString(*mapGet<int, Player>(map2, 321)) << endl;

   cout << "________________________" << endl;

   if(mapContains<string, int>(map1, "uno"))
      cout << "Existe clave uno en map1" << endl;
   else
      cout << "NO existe clave uno en map1" << endl;

   if(mapContains<string, int>(map1, "cuatro"))
      cout << "Existe clave cuatro en map1" << endl;
   else
      cout << "NO existe clave cuatro en map1" << endl;

   cout << "________________________" << endl;

   if(mapContains<int, Player>(map2, 123))
      cout << "Existe jugador 123 en map2" << endl;
   else
      cout << "NO existe jugador 123 en map2" << endl;

   if(mapContains<int, Player>(map2, 321))
      cout << "Existe jugador 321 en map2" << endl;
   else
      cout << "NO existe jugador 321 en map2" << endl;

   cout << "________________________" << endl;

   cout << "Elimino " << mapRemove<string, int>(map1, "ocho") << " de map1" << endl;

   if(mapContains<string, int>(map1, "ocho"))
      cout << "Existe clave ocho en map1" << endl;
   else
      cout << "NO existe clave ocho en map1" << endl;

   cout << "________________________" << endl;

   cout << "Elimino " << playerToString(mapRemove<int, Player>(map2, 213)) << " de map2" << endl;

   if(mapContains<int, Player>(map2, 213))
      cout << "Existe jugador 213 en map2" << endl;
   else
      cout << "NO existe jugador 213 en map2" << endl;

   cout << "________________________" << endl;

   cout << "Tamanio map1 = " << mapSize(map1) << endl;
   cout << "________________________" << endl;

   cout << "Tamanio map2 = " << mapSize(map2) << endl;
   cout << "________________________" << endl;

   //COMENTO removeall PARA SEGUIR TRABAJANDO
   mapRemoveAll<string, int>(map1);
   mapRemoveAll<int, Player>(map2);

   cout << "Tamanio map1 = " << mapSize(map1) << endl;
   cout << "________________________" << endl;

   cout << "Tamanio map2 = " << mapSize(map2) << endl;
   cout << "________________________" << endl;*/

   /*mapReset<string, int>(map1);
   while(mapHasNext<string, int>(map1))
   {
      cout << *mapGet<string, int>(map1, mapNextKey<string, int>(map1)) << endl;
   }
   cout << "________________________" << endl;

   mapReset<string, int>(map1);
   while(mapHasNext<string, int>(map1))
   {
      cout << *mapNextValue<string, int>(map1) << endl;
   }
   cout << "________________________" << endl;

   mapReset<int, Player>(map2);
   while(mapHasNext<int, Player>(map2))
   {
      cout << playerToString(*mapGet<int, Player>(map2, mapNextKey<int, Player>(map2))) << endl;
   }
   cout << "________________________" << endl;

   mapReset<int, Player>(map2);
   while(mapHasNext<int, Player>(map2))
   {
      cout << playerToString(*mapNextValue<int, Player>(map2)) << endl;
   }
   cout << "________________________" << endl;

   mapSortByKeys<int, Player>(map2, cmpIntInt);

   mapReset<int, Player>(map2);
   while(mapHasNext<int, Player>(map2))
   {
      int i=0;
      cout << playerToString(*mapGet<int, Player>(map2, mapNextKey<int, Player>(map2))) <<endl;
      i++;
   }
   cout << "________________________" << endl;

   mapSortByValues<int, Player>(map2, cmpPlayerPlayer);

   mapReset<int, Player>(map2);
   while(mapHasNext<int, Player>(map2))
   {
      int i=0;
      cout << playerToString(*mapGet<int, Player>(map2, mapNextKey<int, Player>(map2))) << endl;
      i++;
   }
   cout << "________________________" << endl;

   // LISTAS (API)

   Node<int>* p1 = NULL;
   Node<int>* aux1;

   Node<Player>* p2 = NULL;
   Node<Player>* aux2;

   for(int i=5; i>0; i--)
   {
      add<int>(p1, i);
   }

   addFirst<Player>(p2, player("Walter", 40.5));
   addFirst<Player>(p2, player("Lukas", 50.3));
   add<Player>(p2, player("Tomas", 24.1));
   add<Player>(p2, player("Simon", 10.9));

   aux1 = p1;
   while(aux1!=NULL)
   {
      cout << aux1->info << endl;
      aux1 = aux1->next;
   }
   cout << "________________________" << endl;

   aux2 = p2;
   while(aux2!=NULL){
      cout<< playerToString(aux2->info) << endl;
      aux2 = aux2->next;
   }
   cout << "________________________" << endl;

   addFirst<int>(p1, 6);

   addFirst<Player>(p2, player("Rodrigo", 30.7));

   aux1 = p1;
   while(aux1!=NULL)
   {
      cout << aux1->info << endl;
      aux1 = aux1->next;
   }
   cout << "________________________" << endl;

   aux2 = p2;
   while(aux2!=NULL){
      cout<< playerToString(aux2->info) << endl;
      aux2 = aux2->next;
   }
   cout << "________________________" << endl;

   remove<int, int>(p1, 1, cmpInt);
   remove<int, int>(p1, 4, cmpInt);
   removeFirst<int>(p1);

   aux1 = p1;
   while(aux1!=NULL)
   {
      cout << aux1->info << endl;
      aux1 = aux1->next;
   }
   cout << "________________________" << endl;

   removeFirst<Player>(p2);
   remove<Player, string>(p2, "Tomas", cmpPlayerName);

   aux2 = p2;
   while(aux2!=NULL){
      cout<< playerToString(aux2->info) << endl;
      aux2 = aux2->next;
   }
   cout << "________________________" << endl;

   if(find<int, int>(p1, 5, cmpInt)==NULL)
   {
      cout << "No está el elemento en la lista." << endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout << find<int, int>(p1, 5, cmpInt)->info << endl;
      cout << "________________________" << endl;
   }

   if(find<Player, double>(p2, 50.4, cmpPlayerScore)==NULL)
   {
      cout << "No está el elemento en la lista." << endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout << playerToString(find<Player, double>(p2, 50.4, cmpPlayerScore)->info) << endl;
      cout << "________________________" << endl;
   }

   //free<int>(p1); Funciona pero comento para seguir probando las otras funciones.

   if(!isEmpty<int>(p1))
      cout << "La lista1 tiene elementos." << endl;
   else
      cout << "La lista1 NO tiene elementos." << endl;

   cout << "________________________" << endl;

   //free<Player>(p2); Funciona pero comento para seguir probando las otras funciones.

   if(!isEmpty<Player>(p2))
      cout << "La lista2 tiene elementos." << endl;
   else
      cout << "La lista2 NO tiene elementos." << endl;

   cout << "________________________" << endl;

   Node<int>* p3 = NULL;
   Node<int>* aux3;

   orderedInsert<int>(p3, 3, cmpInt);
   orderedInsert<int>(p3, 1, cmpInt);
   orderedInsert<int>(p3, 5, cmpInt);
   orderedInsert<int>(p3, 4, cmpInt);


   aux3 = p3;
   while(aux3!=NULL)
   {
      cout << aux3->info << endl;
      aux3 = aux3->next;
   }
   cout << "________________________" << endl;

   sort<int>(p1, cmpInt);
   sort<Player>(p2, cmpPlayerPlayer);

   aux1 = p1;
   while(aux1!=NULL)
   {
      cout << aux1->info << endl;
      aux1 = aux1->next;
   }
   cout << "________________________" << endl;

   aux2 = p2;
   while(aux2!=NULL){
      cout<< playerToString(aux2->info) << endl;
      aux2 = aux2->next;
   }
   cout << "________________________" << endl;

   bool enc;

   searchAndInsert<Player>(p2, player("Simon", 10.9), enc, cmpPlayerPlayer);
   cout<<enc<<endl;
   searchAndInsert<Player>(p2, player("Lorenzo", 33.1), enc, cmpPlayerPlayer);
   cout<<enc<<endl;

   cout << "________________________" << endl;

   aux2 = p2;
   while(aux2!=NULL)
   {
      cout<< playerToString(aux2->info) << endl;
      aux2 = aux2->next;
   }
   cout << "________________________" << endl;

   //TAD LIST

   List<short> lista1 = list<short>();
   List<Player> lista2 = list<Player>();


   listAdd<short>(lista1, 0);
   listAdd<short>(lista1, 25);
   listAdd<short>(lista1, 5);
   listAdd<short>(lista1, 10);
   listAddFirst<short>(lista1, 15);

   listAddFirst<Player>(lista2, player("Jose", 22.2));
   listAdd<Player>(lista2, player("Armando", 14.3));
   listAdd<Player>(lista2, player("Wanda", 35.9));
   listAddFirst<Player>(lista2, player("Camilo", 40.5));

   listRemove<short, short>(lista1, 0, cmpShort);
   listRemoveFirst<Player>(lista2);

   while(listHasNext<short>(lista1))
   {
      cout << *listNext<short>(lista1) << endl;
   }
   listReset<short>(lista1);

   cout << "________________________" << endl;

   while(listHasNext<Player>(lista2))
   {
      cout << playerToString(*listNext<Player>(lista2)) << endl;
   }
   listReset<Player>(lista2);

   cout << "________________________" << endl;

   if(listFind<short, short>(lista1, 26, cmpShort)==NULL)
   {
      cout<<"No se encuentra el elemento buscado"<<endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout << "Encontrado: " << *listFind<short, short>(lista1, 26, cmpShort) << endl;
      cout << "________________________" << endl;
   }

   if(listFind<Player, double>(lista2, 14.3, cmpPlayerScore)==NULL)
   {
      cout<<"No se encuentra el elemento buscado"<<endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout << "Encontrado: " << playerToString(*listFind<Player, double>(lista2, 14.3, cmpPlayerScore)) << endl;
      cout << "________________________" << endl;
   }

   List<char> lista3 = list<char>();

   //listFree<Player>(lista2); FUNCIONA, comento para seguir con el testing

   if(!listIsEmpty<short>(lista1))
   {
      cout<<"Lista 1 tiene elementos."<<endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout<<"Lista 1 NO tiene elementoos." << endl;
      cout << "________________________" << endl;
   }

   if(!listIsEmpty<Player>(lista2))
   {
      cout<<"Lista 2 tiene elementos."<<endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout<<"Lista 2 NO tiene elementoos." << endl;
      cout << "________________________" << endl;
   }

   if(!listIsEmpty<char>(lista3))
   {
      cout<<"Lista 3 tiene elementos."<<endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout<<"Lista 3 NO tiene elementoos." << endl;
      cout << "________________________" << endl;
   }

   cout << "Tamanio lista 1: " << listSize<short>(lista1) << endl;
   cout << "Tamanio lista 2: " << listSize<Player>(lista2) << endl;
   cout << "Tamanio lista 3: " << listSize<char>(lista3) << endl;

   cout << "________________________" << endl;

   listOrderedInsert<char>(lista3, 'z', cmpCharChar);
   listOrderedInsert<char>(lista3, 'y', cmpCharChar);
   listOrderedInsert<char>(lista3, 'x', cmpCharChar);
   listOrderedInsert<char>(lista3, 'c', cmpCharChar);
   listOrderedInsert<char>(lista3, 'b', cmpCharChar);
   listOrderedInsert<char>(lista3, 'a', cmpCharChar);

   while(listHasNext<char>(lista3))
   {
      cout << *listNext<char>(lista3) << endl;
   }
   listReset<char>(lista3);

   cout << "________________________" << endl;

   listSort<short>(lista1, cmpShort);
   listSort<Player>(lista2, cmpPlayerPlayer);

   while(listHasNext<short>(lista1))
   {
      cout << *listNext<short>(lista1) << endl;
   }
   listReset<short>(lista1);

   cout << "________________________" << endl;

   while(listHasNext<Player>(lista2))
   {
      cout << playerToString(*listNext<Player>(lista2)) << endl;
   }
   listReset<Player>(lista2);

   cout << "________________________" << endl;

   bool eol1=false, eol2=false;

   while(listHasNext<short>(lista1))
   {
      cout << *listNext<short>(lista1, eol1) << endl;
   }
   cout << eol1 << endl;
   listReset<short>(lista1);

   cout << "________________________" << endl;

   while(listHasNext<Player>(lista2))
   {
      cout << playerToString(*listNext<Player>(lista2, eol2)) << endl;
   }
   cout << eol2 << endl;
   listReset<Player>(lista2);

   cout << "________________________" << endl;

   //API & TAD STACKS

   Stack<char> pila = stack<char>();

   if(!stackIsEmpty<char>(pila))
   {
      cout << "La pila tiene elementos." << endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout << "La pila NO tiene elementos." << endl;
      cout << "________________________" << endl;
   }

   stackPush<char>(pila, 'o');
   stackPush<char>(pila, 'l');
   stackPush<char>(pila, 'l');
   stackPush<char>(pila, 'e');
   stackPush<char>(pila, 'h');

   cout << "Tamanio de la pila: " << stackSize<char>(pila) << endl;

   cout << "________________________" << endl;

   if(!stackIsEmpty<char>(pila))
   {
      cout << "La pila tiene elementos." << endl;
      cout << "________________________" << endl;
   }
   else
   {
      cout << "La pila NO tiene elementos." << endl;
      cout << "________________________" << endl;
   }

   while(!stackIsEmpty<char>(pila))
   {
      cout << stackPop<char>(pila) << "\n";
   }
   cout << "________________________" << endl;

   cout << "Tamanio de la pila: " << stackSize<char>(pila) << endl;

   cout << "________________________" << endl;

   //BITWRITER & BITREADER

   FILE* f = fopen("prueba.txt", "w+b");
   BitWriter bw = bitWriter(f);

   bitWriterWrite(bw, 1);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 1);
   bitWriterWrite(bw, 0);

   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 1);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 1);
   bitWriterWrite(bw, 0);

   bitWriterWrite(bw, 1);
   bitWriterWrite(bw, 1);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 0);
   bitWriterWrite(bw, 1);
   bitWriterFlush(bw);

   cout << "________________________" << endl;

   f = fopen("prueba.txt", "r+b");
   BitReader br = bitReader(f);

   int bit = bitReaderRead(br);
   while(!feof(f))
   {
      cout << bit << endl;
      bit = bitReaderRead(br);
   }

   fclose(f);

   cout << "________________________" << endl;*/

//EJERCICIO STREAMING DE AUDIO CUENTOS
/*
//ESTRUCTURAS

struct Reproduccion
{
int idUsuario;
int idCuento;
int fecha;
int minutos;
};

struct Cuento
{
int idCuento;
int idRelator;
int idAutor;
char titulo[50];
int duracion;
};

struct Streams
{
   int cont100;
   int cont75;
   int cont50;
   int cont25;
   int contLess25;
};

struct RCuento
{
   Cuento c;
   Streams streams;
};

struct Relator
{
int idRelator;
char nombre[50];
};

struct RRelator
{
   Relator r;
   int streams;
};

//INICIALIZADORES

Reproduccion reproduccion(int idUsuario,int idCuento,int fecha,int minutos)
{
   Reproduccion a;
   a.idUsuario = idUsuario;
   a.idCuento = idCuento;
   a.fecha = fecha;
   a.minutos = minutos;
   return a;
}

Cuento cuento(int idCuento,int idRelator,int idAutor,string titulo,int duracion)
{
   Cuento a;
   a.idCuento = idCuento;
   a.idRelator = idRelator;
   a.idAutor = idAutor;
   strcpy(a.titulo,titulo.c_str());
   a.duracion = duracion;
   return a;
}

Streams streams(int cont100,int cont75,int cont50,int cont25,int contLess25)
{
   Streams a;
   a.cont100 = cont100;
   a.cont75 = cont75;
   a.cont50 = cont50;
   a.cont25 = cont25;
   a.contLess25 = contLess25;
   return a;
}

RCuento rCuento(Cuento c,Streams streams)
{
   RCuento a;
   a.c = c;
   a.streams = streams;
   return a;
}

Relator relator(int idRelator,string nombre)
{
   Relator a;
   a.idRelator = idRelator;
   strcpy(a.nombre,nombre.c_str());
   return a;
}

RRelator rRelator(Relator r,int streams)
{
   RRelator a;
   a.r = r;
   a.streams = streams;
   return a;
}

//FUNCIONES

Map<int, RCuento> subirCuentos()
{
   Map<int, RCuento> c = map<int, RCuento>();

   FILE* f = fopen("CUENTOS.txt", "r+b");

   Cuento cuento = read<Cuento>(f);
   while(!feof(f)){
      RCuento cuento2 = rCuento(cuento, streams(0, 0, 0, 0, 0));
      mapPut<int, RCuento>(c, cuento.idCuento, cuento2);
      cuento = read<Cuento>(f);
   }
   fclose(f);

   return c;
}

Map<int, RRelator> subirRelatores()
{
   Map<int, RRelator> r = map<int, RRelator>();

   FILE* f = fopen("RELATORES.txt", "r+b");

   Relator relator = read<Relator>(f);
   while(!feof(f)){
      RRelator relator2 = rRelator(relator, 0);
      mapPut<int, RRelator>(r, relator.idRelator, relator2);
      relator = read<Relator>(f);
   }
   fclose(f);

   return r;
}

int cmpRelatores(RRelator a, RRelator b)
{
   return a.streams-b.streams;
}

void punto1(Map<int, RCuento>& cuentos, Reproduccion stream)
{
   RCuento* c = mapGet<int, RCuento>(cuentos, stream.idCuento);

   if(stream.minutos==c->c.duracion)
      c->streams.cont100++;
   if(stream.minutos>=(double)c->c.duracion*0.75 && stream.minutos<c->c.duracion)
      c->streams.cont75++;
   if(stream.minutos>=(double)c->c.duracion*0.50 && stream.minutos<(double)c->c.duracion*0.75)
      c->streams.cont50++;
   if(stream.minutos>=(double)c->c.duracion*0.25 && stream.minutos<(double)c->c.duracion*0.50)
      c->streams.cont25++;
   else
      c->streams.contLess25++;

   mapPut<int, RCuento>(cuentos, c->c.idCuento, *c);
}

void punto2a(Map<int, RRelator>& relatores, Map<int, RCuento> cuentos, Reproduccion stream)
{
   RCuento* c = mapGet<int, RCuento>(cuentos, stream.idCuento);
   RRelator* r = mapGet<int, RRelator>(relatores, c->c.idRelator);

   if(stream.minutos>=(double)c->c.duracion*0.75)
      r->streams++;

   mapPut<int, RRelator>(relatores, r->r.idRelator, *r);
}

void punto2b(Map<int, RRelator> r, Map<int, RRelator>& top10, int cmpR(RRelator, RRelator))
{
   mapSortByValues<int, RRelator>(r, cmpR);

   for(int i=0; i<10; i++)
      mapPut<int, RRelator>(top10, mapNextKey<int, RRelator>(r), *mapNextValue<int, RRelator>(r));
}

void showPunto1(Map<int, RCuento> listado)
{
   cout << "Listado de los cuentos con sus cantidades de reproducciones en porcentajes: " << endl;

   while(mapHasNext<int, RCuento>(listado))
   {
      RCuento print = *mapNextValue<int, RCuento>(listado);

      cout << print.c.titulo << endl;
      cout << print.streams.cont100 << "reproducciones completas." << endl;
      cout << print.streams.cont75 << "reproducciones entre el 75% y el 100% de la duracion." << endl;
      cout << print.streams.cont50 << "reproducciones entre el 50% y el 75% de la duracion." << endl;
      cout << print.streams.cont25 << "reproducciones entre el 25% y el 50% de la duracion." << endl;
      cout << print.streams.contLess25 << "reproducciones con menos del 25% de la duracion" << endl;
   }
}

void showPunto2(Map<int, RRelator> top10)
{
   cout << "Top 10 de los relatores con mayor cantidad de reproducciones entre el 75% y el 100% de la duración: " << endl;

   while(mapHasNext(top10))
   {
      RRelator print = *mapNextValue<int, RRelator>(top10);

      cout << print.r.nombre << endl;
   }
}

int main()
{
   Map<int, RCuento> ListadoCuentos = subirCuentos();
   Map<int, RRelator> relatores = subirRelatores();
   Map<int, RRelator> Top10Relatores = map<int, RRelator>();

   FILE* f = fopen("REPRODUCCIONES.txt", "r+b");

   Reproduccion stream = read<Reproduccion>(f);
   while(!feof(f))
   {
      punto1(ListadoCuentos, stream);
      punto2a(relatores, ListadoCuentos, stream);

      stream = read<Reproduccion>(f);
   }

   punto2b(relatores, Top10Relatores, cmpRelatores);

   showPunto1(ListadoCuentos);
   showPunto2(Top10Relatores);

   fclose(f);
   return 0;
  }

 */

#endif
