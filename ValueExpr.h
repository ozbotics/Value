/** @file ValueExpr.h */ 
#ifndef _VALUE_EXPR_H
  #define _VALUE_EXPR_H

#include <Arduino.h>

/**
  *  ValueExpr class template. 
  *  The Base of all ValueEXPR classes
  *
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
template <class T>
class ValueExpr : public Value<T> {
  protected:
    Value<T>* _a;  /**< protected variable _a. Pointer to the left hand side sub-expressions. */ 
    Value<T>* _b;  /**< protected variable _b. Pointer to the right hand side sub-expressions. */

    /**
      * constructor
      * @param a Pointer to the left hand side sub-expressions.
      * @param b Pointer to the right hand side sub-expressions.
    */  
    ValueExpr(Value<T>* a, Value<T>* b) : _a(a), _b(b), Value<T>() {}
};

/**
  *  ValueADD class template. 
  *  Has the v  alue of the left hand sub-expression added to the right-hand sub-expression
*/
template <class T>
class ValueADD : public ValueExpr<T> {
  public:
    /**
      * constructor
      * @param a Pointer to the left hand side sub-expressions.
      * @param b Pointer to the right hand side sub-expressions.
    */  
    ValueADD(Value<T>* a, Value<T>* b) : ValueExpr<T>(a, b) {}
    
   /**
    * get the value of this expression
    * @return the value of the left hand sub-expression added to the right-hand sub-expression
    */  
    virtual T getValue() {
      return (this->_a->getValue() + this->_b->getValue());
    }
};

/**
  *  ValueSUBTRACT class template. 
  *  Has the value of the right-hand sub-expression subtracted from the left hand sub-expression
*/
template <class T>
class ValueSUBTRACT : public ValueExpr<T> {
  public:
    /**
      * constructor
      * @param a Pointer to the left hand side sub-expressions.
      * @param b Pointer to the right hand side sub-expressions.
    */  
    ValueSUBTRACT(Value<T>* a, Value<T>* b) : ValueExpr<T>(a, b) {}
    
   /**
    * get the value of this expression
    * @return the value of the right-hand sub-expression subtracted from the left hand sub-expression
    */  
    virtual T getValue() {
      return (this->_a->getValue() - this->_b->getValue());
    }
};

/**
  *  ValueMULTIPLY class template. 
  *  Has the value of the left hand sub-expression multiplied by the right-hand sub-expression
*/
template <class T>
class ValueMULTIPLY : public ValueExpr<T> {
  public:
    /**
      * constructor
      * @param a Pointer to the left hand side sub-expressions.
      * @param b Pointer to the right hand side sub-expressions.
    */  
    ValueMULTIPLY(Value<T>* a, Value<T>* b) : ValueExpr<T>(a, b) {}
    
   /**
    * get the value of this expression
    * @return the value of the left hand sub-expression multiplied by the right-hand sub-expression
    */  
    virtual T getValue() {
      return (this->_a->getValue() * this->_b->getValue());
    }
};

/**
  *  ValueDIVIDE class template. 
  *  Has the value of the left hand sub-expression divided by the right-hand sub-expression
*/
template <class T>
class ValueDIVIDE : public ValueExpr<T> {
  public:
    /**
      * constructor
      * @param a Pointer to the left hand side sub-expressions.
      * @param b Pointer to the right hand side sub-expressions.
    */  
    ValueDIVIDE(Value<T>* a, Value<T>* b) : ValueExpr<T>(a, b) {}
    
   /**
    * get the value of this expression
    * @return the value of the left hand sub-expression divided by the right-hand sub-expression
    */  
    virtual T getValue() {
      return (this->_a->getValue() / this->_b->getValue());
    }
};

#endif // _VALUE_EXPR_H
