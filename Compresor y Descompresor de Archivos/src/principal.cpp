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
#include "biblioteca/tads/huffman/BitWriter(1).hpp"
#include "biblioteca/tads/huffman/BitReader(1).hpp"
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"

using namespace std;

struct Reg
{
   unsigned char byte;
   int length;
   string huffCode;
};

int cmpOcurr(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
   if(a.n!=b.n)
      return a.n-b.n;
   else
      return a.c-b.c;
}

void contarOcurrencias (FILE* f, HuffmanTable* tabla)
{
   seek<unsigned char>(f, 0);

   unsigned char byte = read<unsigned char>(f);

   while(!feof(f))
   {
      tabla[(int)byte].n++;
      byte = read<unsigned char>(f);
   }
}

void crearLista(List<HuffmanTreeInfo>& lista, HuffmanTable* tabla)
{
   for(int i=0; i<256; i++)
   {
      if(tabla[i].n!=0)
      {
         HuffmanTreeInfo ht = *(huffmanTreeInfo(i, tabla[i].n, NULL, NULL));
         listAdd<HuffmanTreeInfo>(lista, ht);
      }
   }
   listSort<HuffmanTreeInfo>(lista, cmpOcurr);
}

HuffmanTreeInfo* crearArbol(List<HuffmanTreeInfo> lista)
{
   HuffmanTreeInfo* root;

   int dadNumber = 0;

   while(listSize<HuffmanTreeInfo>(lista)!= 1)
   {
      HuffmanTreeInfo* rightSon = new HuffmanTreeInfo;
      HuffmanTreeInfo* leftSon = new HuffmanTreeInfo;

      *rightSon = listRemoveFirst<HuffmanTreeInfo>(lista);
      *leftSon = listRemoveFirst<HuffmanTreeInfo>(lista);

      dadNumber++;

      HuffmanTreeInfo* father;
      father = huffmanTreeInfo(255+dadNumber, rightSon->n+leftSon->n, leftSon, rightSon);

      root = listOrderedInsert<HuffmanTreeInfo>(lista, *father, cmpOcurr);
   }
   return root;
}

void cargarCodigoEnTabla(HuffmanTreeInfo* root, HuffmanTable* tabla)
{
   HuffmanTree ht = huffmanTree(root);
   HuffmanTreeInfo* hoja;
   string cod;

   while(huffmanTreeHasNext(ht))
   {
      hoja = huffmanTreeNext(ht, cod);
      tabla[hoja->c].code = cod;
   }
}

void grabarArchivoComprimido(FILE* f, HuffmanTable* tabla, string fName)
{
   //Asigno el .huf al nombre del archivo comprimido.
   string fNameHuff = fName + ".huf";
   FILE* fcomp = fopen(fNameHuff.c_str(), "w+b");

   int cantHojas = 0;
   BitWriter bw = bitWriter(fcomp);

   for(int k=0; k<256; k++)
   {
      if(tabla[k].n!=0)
         cantHojas++;
   }

   write<unsigned char>(fcomp, (unsigned char)cantHojas);

   for(int i=0; i<256; i++)
   {
      if(tabla[i].n!=0)
      {
         write<unsigned char>(fcomp, (unsigned char)i);
         write<unsigned char>(fcomp, (unsigned char)length(tabla[i].code));

         for(int j=0; j<length(tabla[i].code); j++)
         {
            if(tabla[i].code[j]=='0')
               bitWriterWrite(bw, 0);
            if(tabla[i].code[j]=='1')
               bitWriterWrite(bw, 1);
         }
         bitWriterFlush(bw);
       }
    }

   write<int>(fcomp, fileSize<unsigned char>(f));

   seek<unsigned char>(f, 0);

   unsigned char c = read<unsigned char>(f);

   while(!feof(f))
   {
      for(int i=0; i<length(tabla[(int)c].code); i++)
      {
         if(tabla[(int)c].code[i]=='0')
            bitWriterWrite(bw, 0);
         if(tabla[(int)c].code[i]=='1')
            bitWriterWrite(bw, 1);
      }
      c = read<unsigned char>(f);
   }
   bitWriterFlush(bw);

   fclose(fcomp);
}

void compress(FILE* f, string fName)
{
   HuffmanTable tabla[256] = {0, ""};

   contarOcurrencias(f, tabla);

   List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
   crearLista(lista, tabla);

   HuffmanTreeInfo* root = crearArbol(lista);

   cargarCodigoEnTabla(root, tabla);

   grabarArchivoComprimido(f, tabla, fName);
}

void leerArchivoComprimido(FILE* f, int cantHojas, Reg registro[], int &oriFileSize)
{
   int bit;
   BitReader br = bitReader(f);

   for(int i=0; i<cantHojas; i++)
   {
      registro[i].byte = read<unsigned char>(f);
      registro[i].length = (int)read<unsigned char>(f);

      for(int j=1; j<=16; j++)
      {
         if(registro[i].length<=8*j)
         {
            for(int k=0; k<8*j; k++)
            {
               bit = bitReaderRead(br);
               if(length(registro[i].huffCode)<registro[i].length)
                  registro[i].huffCode += intToString(bit);
            }
            j=17;
         }
      }
   }
   oriFileSize = read<int>(f);
}

HuffmanTreeInfo* recomponerArbol(FILE* f, Reg registro[], int cantHojas)
{
   HuffmanTreeInfo* root = huffmanTreeInfo(256, 0, NULL, NULL);
   int auxChar = 256;

   for(int i=0; i<cantHojas; i++)
   {
      HuffmanTreeInfo* aux = root;

      for(int j=0; j<registro[i].length; j++)
      {
         if(registro[i].huffCode[j]=='0')
         {
            if(aux->left==NULL)
               aux->left = huffmanTreeInfo(auxChar++, 0, NULL, NULL);

            aux = aux->left;
         }
         if(registro[i].huffCode[j]=='1')
         {
            if(aux->right==NULL)
               aux->right = huffmanTreeInfo(auxChar++, 0, NULL, NULL);

            aux = aux->right;
         }
      }
      aux->c = registro[i].byte;
      auxChar--;
   }
   return root;
}

void grabarArchivoDescomprimido(FILE* f, HuffmanTreeInfo* root, string fName, int oriFileSize)
{
   string fileName = substring(fName, 0, length(fName)-4);
   FILE* fdesc = fopen(fileName.c_str(), "w+b");

   HuffmanTreeInfo* aux = root;
   BitReader br = bitReader(f);
   int bit = bitReaderRead(br);

   while(!feof(f) && fileSize<unsigned char>(fdesc)!=oriFileSize)
   {
      if(bit==0)
         aux = aux->left;
      else
         aux = aux->right;

      if(aux->left==NULL && aux->right==NULL)
      {
         write<unsigned char>(fdesc, (unsigned char)aux->c);
         aux = root;
      }
      bit = bitReaderRead(br);
   }
   fclose(fdesc);
}

void decompress(FILE* f, string fName)
{
   int cantHojas = (int)read<unsigned char>(f), originalFileSize;
   Reg registro[cantHojas];

   leerArchivoComprimido(f, cantHojas, registro, originalFileSize);

   HuffmanTreeInfo* root = recomponerArbol(f, registro, cantHojas);

   grabarArchivoDescomprimido(f, root, fName, originalFileSize);
}

int main()
{
   FILE* f = fopen("example.bmp", "r+b");

   string fName = "example.bmp";

   compress(f, fName);
   //decompress(f, fName);

   fclose(f);

   return 0;
}

#endif
