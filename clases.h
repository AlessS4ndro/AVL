#ifndef __AVL_CLASE__
#define __AVL_CLASE__

template<class T>
struct Node
{
  T data;
  Node<T> *child[2];
  int factor;
  Node(T d,int f):data(d),child[0](NULL),child[1](NULL),factor(f){}
};

template <class T>
class AVL
{
  Node<T> *raiz;

  Node<T> * father(T);
  Node<T> * brother(T);
  Node<T> * uncle(T);
  void rotacion_dd(Node<T> *&);
  void rotacion_ii(Node<T> *&);
  void rotacion_di(Node<T> *&);
  void rotacion_id(Node<T> *&);
public:
  AVL():raiz(NULL){}
  bool find(T,Node<T> **&);
  void add(T);
};







#endif
