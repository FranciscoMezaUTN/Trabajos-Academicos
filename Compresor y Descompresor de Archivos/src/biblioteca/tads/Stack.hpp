#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   List<T> stack;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.stack = list<T>();
   return st;
}

template<typename T>
T* stackPush(Stack<T>& st,T e)
{
   return &push<T>(st.stack.list, e)->info;
}

template<typename T>
T stackPop(Stack<T>& st)
{
   return pop<T>(st.stack.list);
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return listIsEmpty<T>(st.stack);
}

template<typename T>
int stackSize(Stack<T> st)
{
   return listSize<T>(st.stack);
}

#endif
