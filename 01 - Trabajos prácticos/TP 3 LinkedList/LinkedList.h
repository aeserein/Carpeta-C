/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
typedef struct {
    void* pElement;
    struct Node* pNextNode;
} Node;

typedef struct {
    Node* pFirstNode;
    int size;
} LinkedList;

//Publicas
LinkedList* ll_newLinkedList(void);    //Crear lista
int ll_len(LinkedList* this);    //Contar elementos en la lista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);    //Agregar elemento
void* ll_get(LinkedList* this, int index);    //Tomar elemento
int ll_set(LinkedList* this, int index, void* pElement);    ///????
int ll_remove(LinkedList* this,int index);    //Remover elemento
int ll_clear(LinkedList* this);    ///Limpiar todos los slots
int ll_deleteLinkedList(LinkedList* this);    ///Eliminar lista
int ll_indexOf(LinkedList* this, void* pElement);    /****************************** Sacar índice de un elemento */
int ll_isEmpty(LinkedList* this);    //Ver si lista está vacía
int ll_push(LinkedList* this, int index, void* pElement);    ///????
void* ll_pop(LinkedList* this,int index);    ///????
int ll_contains(LinkedList* this, void* pElement);    ///????
int ll_containsAll(LinkedList* this,LinkedList* this2);    ///????
LinkedList* ll_subList(LinkedList* this,int from,int to);    ///Retirar porción de la lista
LinkedList* ll_clone(LinkedList* this);    ///Copiar lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);    ///Ordenar

#endif
