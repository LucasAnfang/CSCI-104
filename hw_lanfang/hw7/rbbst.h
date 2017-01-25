/*
 * rbbst.h
 *
 * Date        Author    Notes
 * =====================================================
 * 2014-04-14  Kempe     Initial version
 * 2015-04-06  Redekopp  Updated formatting and removed
 *                         KeyExistsException
 */
#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"
 using namespace std;

/* -----------------------------------------------------
 * Red-Black Nodes and Search Tree
 ------------------------------------------------------*/

enum Color {red, black};
template <class KeyType, class ValueType>
class RedBlackTree;

template <class KeyType, class ValueType>
class RedBlackNode : public Node<KeyType, ValueType>
{
public:
  RedBlackNode (KeyType k, ValueType v, RedBlackNode<KeyType, ValueType> *p)
    : Node<KeyType, ValueType> (k, v, p)
    { color = red; }
    //   this->_parent = RedBlackTree<KeyType, ValueType>::nil;
    //   this->_left = RedBlackTree<KeyType, ValueType>::nil;
    //   this->_right = RedBlackTree<KeyType, ValueType>::nil;
    // }
    // RedBlackNode(): Node<KeyType,ValueType>(NULL,NULL,NULL)
    // {
    //   color = black;
    //   this->_parent = NULL;
    //   this->_left = NULL;
    //   this->_right = NULL;
    // }
  
  virtual ~RedBlackNode () {}
  
  Color getColor () const
    { return color; }
  
  void setColor (Color c)
    { color = c; }
  
  virtual RedBlackNode<KeyType, ValueType> *getParent () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_parent; }
  
  virtual RedBlackNode<KeyType, ValueType> *getLeft () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_left; }
  
  virtual RedBlackNode<KeyType, ValueType> *getRight () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_right; }
  
 protected:
  Color color;
};

/* -----------------------------------------------------
 * Red-Black Search Tree
 ------------------------------------------------------*/
  //RedBlackNode<KeyType,ValueType>* nil = new RedBlackNode<KeyType,ValueType>();

template <class KeyType, class ValueType>
class RedBlackTree : public BinarySearchTree<KeyType, ValueType>
{
public:
  //static RedBlackNode<KeyType,ValueType>* nil;// = new RedBlackNode<KeyType,ValueType>();


  void insert (const std::pair<const KeyType, ValueType>& new_item)
  {
    RedBlackNode<KeyType,ValueType>* new_node = new RedBlackNode<KeyType,ValueType>(new_item.first, new_item.second,NULL);
    if((this->root) == NULL)
    {
      (this->root) = new_node;
    }
    else InsertInTree(static_cast<RedBlackNode<KeyType,ValueType>*>(this->root),new_node);
    this->print();
    fix(new_node);

  }

  void InsertInTree(RedBlackNode<KeyType,ValueType>* node,RedBlackNode<KeyType,ValueType>* new_node)
  {

   if(static_cast<RedBlackNode<KeyType,ValueType>*>(node)->getKey()>new_node->getKey())
    {
      if(static_cast<RedBlackNode<KeyType,ValueType>*>(node)->getLeft() == NULL)
      {
        static_cast<RedBlackNode<KeyType,ValueType>*>(node)->setLeft(new_node);
        new_node->setParent(static_cast<RedBlackNode<KeyType,ValueType>*>(node));
      }
      else 
        InsertInTree(static_cast<RedBlackNode<KeyType,ValueType>*>(node)->getLeft(),new_node);
    }
   else if(static_cast<RedBlackNode<KeyType,ValueType>*>(node)->getKey()<new_node->getKey())
    {
    
      if(static_cast<RedBlackNode<KeyType,ValueType>*>(node)->getRight() == NULL)
      {
        static_cast<RedBlackNode<KeyType,ValueType>*>(node)->setRight(new_node);
        new_node->setParent(static_cast<RedBlackNode<KeyType,ValueType>*>(node));
      }   
      else InsertInTree(static_cast<RedBlackNode<KeyType,ValueType>*>(node)->getRight(),new_node);
    }
    else if(static_cast<RedBlackNode<KeyType,ValueType>*>(node)->getKey()==new_node->getKey())
    {
      static_cast<RedBlackNode<KeyType,ValueType>*>(node)->setValue(new_node->getValue());
    }
  }
  void fix(RedBlackNode<KeyType,ValueType>*current_node)
  {
    //cout << "starting fix" << endl;
    while( current_node->getParent()!=NULL&&current_node->getParent()->getColor() == red )
    {
      //if P is a left or right child of G
      if(current_node->getParent()->getParent()!=NULL)
      {
        //cout << "grandparent exists" << current_node->getKey()<<endl;



      if( current_node->getParent() == current_node->getParent()->getParent()->getLeft())
      { //P is a left child of G
        //cout << "p is a left child" << endl;
        RedBlackNode<KeyType,ValueType>* uncle = current_node->getParent()->getParent()->getRight(); // Uncle
        if(uncle!= NULL && uncle->getColor() == red)
        {

          //Do a recolor 
          current_node->getParent()->setColor(black);
          if(uncle!= NULL)
          {
          uncle->setColor(black);
          }
          current_node->getParent()->getParent()->setColor(red);
          current_node=current_node->getParent()->getParent();
        }
        else
        {
          //case of rotations
          if(current_node == current_node->getParent()->getRight()) //Uncle is black c is a right child
          {
            current_node = current_node->getParent();
            rotateLeft(current_node);
          }
          current_node->getParent()->setColor(black);
          current_node->getParent()->getParent()->setColor(red);
          rotateRight(current_node->getParent()->getParent());
        }

      }
      else //if(current_node->getParent() == current_node->getParent()->getParent()->getRight())
      { //P is a right child of G
        //cout << "p is a right child" << endl;
        RedBlackNode<KeyType,ValueType>* uncle = current_node->getParent()->getParent()->getLeft();
        //cout << uncle << endl;
        if(uncle!=NULL && uncle->getColor() == red)
        {
         // cout <<1<<endl;
          //Do a recolor 
          current_node->getParent()->setColor(black);
          if(uncle!=NULL)
          {
            uncle->setColor(black);
          }
          current_node->getParent()->getParent()->setColor(red);
          current_node=current_node->getParent()->getParent();
        }
        else
        {
          //case of rotations
          if(current_node == current_node->getParent()->getLeft()) //Uncle is black c is a right child
          {
            //cout << "right rot time" << endl;
            current_node = current_node->getParent();
            rotateRight(current_node);
          }
          current_node->getParent()->setColor(black);
          current_node->getParent()->getParent()->setColor(red);
          rotateLeft(current_node->getParent()->getParent());

        }
      }
      }
    }
    static_cast<RedBlackNode<KeyType,ValueType>*>(this->root)->setColor(black);
  }
  void rotateLeft(RedBlackNode<KeyType,ValueType>* z)
  {
    RedBlackNode<KeyType,ValueType>* old_right = z->getRight();
    if(old_right == NULL)
    {
      return;
    } 
    if(old_right->getLeft()!=NULL)
    {
      old_right->getLeft()->setParent(z);
      z->setRight(old_right->getLeft());
    }

    old_right->setParent(z->getParent());
    if(z->getParent()==NULL)
    {
      this->root = old_right;
    }
    else if(z == z->getParent()->getRight())//z is right child
    {
      z->getParent()->setRight(old_right);
    }
    // else if(z == z->getParent()->getLeft()) // left child
    // {
    //   z->getParent()->setLeft(old_right);
    //       //new
    // //(old_right)->setParent(z->getParent());
    // //new
    // }
    // else
    // {
    //   z->getParent()->setRight(old_right);
    //       //new
    //   //(old_right)->setParent(z->getParent());
    //   //new
    // }
    else
    {
      z->getParent()->setLeft(old_right);
    }
    z->setRight(z->getLeft());
    old_right->setLeft(z);
    z->setParent(old_right);
        //old_right->setLeft(z);
    //new
    //z->setParent(old_right);
    
  }
  void rotateRight(RedBlackNode<KeyType,ValueType>* z)  
  {
    RedBlackNode<KeyType,ValueType>* old_left = z->getLeft();
    if(old_left == NULL)
    {
      return;
    } 
    if(old_left->getRight()!=NULL)
    {
      if(old_left->getRight()->getParent()!=NULL)
      {
      old_left->getRight()->setParent(z);
      z->setLeft(old_left->getRight());//set current nodes right to be the left child of its previous right child
      }
    }

    old_left->setParent(z->getParent());
    if(z->getParent()==NULL)
    {
      this->root = old_left;
    }    
    // else if(z == z->getParent()->getLeft()) // left child
    // {
    //   z->getParent()->setLeft(old_left);
    //   //new
    //  // old_left->setParent(z->getParent());
    // }
    // else
    // {
    //   z->getParent()->setRight(old_left);
    //   //new
    //  // old_left->setParent(z->getParent());
    // }
    else if(z == z->getParent()->getLeft())// left child
    {
      z->getParent()->setLeft(old_left);
    }
    else
    {
      z->getParent()->setRight(old_left);
    }
    z->setLeft(z->getRight());
    old_left->setRight(z);
    z->setParent(old_left);

    //old_left->setRight(z);
    //new
    //z->setParent(old_left);

  }




  /* This one is yours to implement.
     It should insert the (key, value) pair to the tree, 
     making sure that it remains a valid Red-Black Tree.
     If the key is already in the tree
     (with a possibly different associated value),
     then it should overwrite the value with the new one.
     We strongly recommend defining suitable (private) helper functions. */
};
//template <class KeyType, class ValueType> RedBlackNode<KeyType,ValueType>* RedBlackTree<KeyType, ValueType>::nil=new RedBlackNode<KeyType,ValueType>(); 



#endif
