#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
    LinkedList* this;
    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL) {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) {
    int len = -1;
    if (this!=NULL) {
        len = this->size;
    }
    return len;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex) {

    Node* pNode = NULL;

    if (this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this)) {
        pNode = this->pFirstNode;
        while(nodeIndex>0){
            pNode = pNode->pNextNode;
            nodeIndex--;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex) {
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
 static int addNode(LinkedList* this, int nodeIndex,void* pElement) {

    int returnAux = -1;
    Node *anterior = NULL;

    if (this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this) ) {

        Node *pNewNode = (Node*)malloc(sizeof(Node));

        if (pNewNode!=NULL) {
            pNewNode->pNextNode = NULL;
            pNewNode->pElement = pElement;

            pNewNode->pNextNode = getNode(this, nodeIndex);
            if (nodeIndex==0) {
                this->pFirstNode = pNewNode;
            } else {
                anterior = getNode(this, nodeIndex-1);
                anterior->pNextNode = pNewNode;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement) {
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) {
    Node *pNode = NULL;
    int returnAux = -1;
    short c = 0;

    if (this!=NULL) {
        pNode = this->pFirstNode;
        while (pNode!=NULL) {
            pNode = pNode->pNextNode;
            c++;
        }
        returnAux = addNode(this, c, pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) {

    void* element = NULL;
    Node* pNode = NULL;

    if (this!=NULL && index>=0 && index<ll_len(this) ) {
        pNode = getNode(this, index);
        if (pNode!=NULL) {
            element = pNode->pElement;
        }
    }
    return element;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement) {

    Node *pNode = NULL;
    int returnAux = -1;

    if (this!=NULL && index>=0 && index<ll_len(this)) {

        pNode = getNode(this, index);
        pNode->pElement = pElement;

        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) {

    int returnAux = -1;
    Node *pNode = NULL;
    Node *anterior = NULL;
    Node *siguiente = NULL;

    if (this!=NULL && index>=0 && index<ll_len(this)) {

        pNode = getNode(this, index);
        anterior = getNode(this, index-1);
        siguiente = getNode(this, index+1);
        if (anterior==NULL) {
            this->pFirstNode = siguiente;
        } else {
            anterior->pNextNode = siguiente;
        }
        this->size--;
        free(pNode);

        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this) {
    int returnAux = -1;
    int len;
    Node *pNode = NULL;

    if (this!=NULL) {
        len = ll_len(this)-1;
        while (len>=0) {
            pNode = getNode(this, len);
            free(pNode);
            len--;
        }
        this->size = 0;
        this->pFirstNode = NULL;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this) {
    int returnAux = -1;

    if (this!=NULL) {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement) {

    int index = -1;
    Node *pNode = NULL;
    int len;
    short f;

    if (this!=NULL) {
        len = ll_len(this);

        for (f=0 ; f<len ; f++) {
            pNode = getNode(this, f);
            if (pNode!=NULL && pElement==pNode->pElement) {
                index = f;
                break;
            }
        }
    }
    return index;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this) {

    int returnAux = -1;
    int size;

    if (this!=NULL) {
        size = ll_len(this);
        if (size==0) returnAux = 1;
        else returnAux = 0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) {

    int returnAux = -1;

    if (this!=NULL) {
        returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index) {

    void* returnAux = NULL;
    Node *pNode = NULL;
    Node *anterior = NULL;
    Node *siguiente = NULL;

    if (this!=NULL && index>=0 && index<ll_len(this)) {

        pNode = getNode(this, index);
        anterior = getNode(this, index-1);
        siguiente = getNode(this, index+1);
        if (anterior==NULL) {
            this->pFirstNode = siguiente;
        } else {
            anterior->pNextNode = siguiente;
        }
        this->size--;

        returnAux = pNode->pElement;
        free(pNode);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement) {

    int returnAux = -1;
    int index = 0;
    Node *pNode = NULL;

    if (this!=NULL) {
        returnAux = 0;
        pNode = getNode(this, index);

        while (pNode!=NULL) {
            if (pElement == pNode->pElement) {
                returnAux = 1;
                break;
            }
            index++;
            pNode = getNode(this, index);
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2) {

    int returnAux = -1;
    Node *pNodeList2 = NULL;
    void *pElementList2 = NULL;
    int index = 0;

    if (this!=NULL && this2!=NULL) {
        returnAux = 1;
        pNodeList2 = getNode(this2, index);

        while (pNodeList2!=NULL) {
            pElementList2 = pNodeList2->pElement;

            if ( !ll_contains(this, pElementList2) ) {
                returnAux = 0;
                break;
            }
            index++;
            pNodeList2 = getNode(this2, index);
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to) {

    LinkedList* cloneArray = NULL;
    Node *pNode = NULL;

    if (this!=NULL) {
        int len = ll_len(this);

        if (from>=0 && from<len &&
            to>from && to<=len) {

            cloneArray = ll_newLinkedList();

            if (cloneArray!=NULL) {

                for ( /*from*/ ; from<to ; from++) {
                    pNode = getNode(this, from);
                    if (pNode!=NULL) {
                        ll_add(cloneArray, pNode->pElement);
                    }
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) {
    LinkedList* cloneArray = NULL;

    if (this!=NULL) {
        int len = ll_len(this);
        cloneArray = ll_subList(this, 0, len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order) {
    int returnAux =-1;
    short f, i;
    Node *nodeF = NULL;
    Node *nodeI = NULL;
    int auxOrder;
    void *elementF = NULL;
    void *elementI = NULL;

    if (this!=NULL &&
        pFunc!=NULL &&
        (order==0 || order==1) ) {

        int len = ll_len(this);
        if (order==0) order = -1;

        for (f=0 ; f<len-1 ; f++) {

            for (i=f+1 ; i<len ; i++) {

                nodeF = getNode(this, f);
                elementF = nodeF->pElement;
                nodeI = getNode(this, i);
                elementI = nodeI->pElement;

                auxOrder = pFunc(elementF, elementI);

                if (auxOrder==order) {
                    ll_set(this, f, elementI);
                    ll_set(this, i, elementF);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}
