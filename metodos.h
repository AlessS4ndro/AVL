#ifndef _AVL_METHOD_
#define _AVL_METHOD_

template<class T>
Node<T> * BST<T>::father(T data)
{
  Node<T> *walking=raiz;
  Node<T> **p;

  if(find(data,p)){
    while(walking){
      if(data<walking->data){       /////   consultamos y
        if(data==walking->left->data)   ////  recorremos hacia
          return walking;             ///// la izquierda
        walking=walking->left;
      }
      else{
        if(data==walking->right->data)    ///// consultamos
          return walking;                   /// y recorremos
        walking=walking->right;       //////  hacia la derecha
      }
    }
  }
  return NULL;
}

template<class T>
Node<T>* BST<T>::brother(T data)
{
  Node<T> *padre=father(data);
  if(data<padre->data)              ///// si el hijo es menor que el padre
    return padre->right;            ////  retorna el hijo derecho
  else
    return padre->left;             ///// y viceversa
}

template<class T>
Node<T>* BST<T>::uncle(T data)
{
  Node<T> *padre=father(data);
  if(padre)
    return brother(padre->data);
  return NULL;
}

template<class T>
bool AVL<T>::find(T d,Node<T> **&p)
{
  p=&(raiz);
  while(*p){
    if(*p->data==d)return true;
    p=&(*p->child[*p->data>d]);
  }
  return false;
}

template<class T>
void AVL<T>::add(T d)
{
  if(!p){p=new Node<T>(d,0);return;}
  if(p->data==d)return;
  add(d,p->child[p->data<d]);
  if(p->data<d)p->factor++;
  else p->factor--;
  switch(p->factor){
    case 0;return;
    case 1:if(p->child[1]->factor==1)rotacion_simple(p,1); else rotacion_doble(p,1);break;
    case -1:if(p->child[0]->factor==-1)rotacion_simple(p,0);else rotacion_doble(p,0);break;
  }

}

template<class T>
void AVL<T>::rotacion_simple(Node<T> *&p,bool v) // verdadero para uno
{
  Node<T> *q=p->child[v]; ////// donde sea v equivalente a 1
  p->child[v]=q->child[!v];     /// 1 para  rotacion derecha y viceversa
  q->child[!v]=p;
  p->factor=0;
  q->factor=0;
  p=q;
}

template<class T>
void AVL<T>::rotacion_doble(Node<T> *&,bool v)
{
  Node<T> *q=p->child[v];       /// 1 para derecha izquierda y viceversa
  Node<T> *r=q->child[!v];
  p->child[v]=r->child[!v];
  q->child[0]=r->child[!v];
  r->child[v]=p;
  r->child[!v]=q;
  switch(r->factor){
    case 0:p->factor=q->factor=0;break;
    case 1:p->factor=0;q->factor=-1;break;
    case -1:p->factor=1;q->factor=0;break;
  }
  p=r;
}


#endif
