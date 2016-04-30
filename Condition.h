/** @file Condition.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _CONDITION_H
  #define _CONDITION_H
  
#include <Arduino.h>
#include <Value.h>

/**
  *  Condition class. 
  *  The base class of all Condition classes
  */
class Condition : public Value<bool>{
  public:
  /**
    * constructor
    */  
    Condition() : Value<bool>() { }
};

/**
  *  ConditionComparison class template. 
  *  The base class of all ConditionComparison classes
  */
template <typename T>
class ConditionComparison : public Condition {
  protected:
    Value<T>* _a;  /**< protected variable _a. Pointer to the left-hand sub-expression */ 
    Value<T>* _b;  /**< protected variable _b. Pointer to the right-hand sub-expression */ 

  public:
  /**
    * constructor
    * @param a Pointer to the left-hand sub-expression
    * @param b Pointer to the right-hand sub-expression
    */  
    ConditionComparison<T>(Value<T>* a, Value<T>* b) : _a(a), _b(b), Condition() { }
};

/**
  *  ConditionEQ class template. 
  *  Has the value of True if the left-hand sub-expression is equal to the right hand sub-expression
  */
template <typename T>
class ConditionEQ : public ConditionComparison<T> {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand sub-expression
    * @param b Pointer to the right-hand sub-expression
    */  
    ConditionEQ<T>(Value<T>* a, Value<T>* b) : ConditionComparison<T>(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (*this->_a == *this->_b);
    }
};

/**
  *  ConditionNEQ class template. 
  *  Has the value of True if the left-hand sub-expression is not equal to the right hand sub-expression
  */
template <typename T>
class ConditionNEQ : public ConditionComparison<T> {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand sub-expression
    * @param b Pointer to the right-hand sub-expression
    */  
    ConditionNEQ<T>(Value<T>* a, Value<T>* b) : ConditionComparison<T>(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (*this->_a != *this->_b);
    }
};

/**
  *  ConditionLT class template. 
  *  Has the value of True if the left-hand sub-expression is less than the right hand sub-expression
  */
template <typename T>
class ConditionLT : public ConditionComparison<T> {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand sub-expression
    * @param b Pointer to the right-hand sub-expression
    */  
    ConditionLT<T>(Value<T>* a, Value<T>* b) : ConditionComparison<T>(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (*this->_a < *this->_b);
    }
};

/**
  *  ConditionLTEQ class template. 
  *  Has the value of True if the left-hand sub-expression is less than or equal to the right hand sub-expression
  */
template <typename T>
class ConditionLTEQ : public ConditionComparison<T> {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand sub-expression
    * @param b Pointer to the right-hand sub-expression
    */  
    ConditionLTEQ<T>(Value<T>* a, Value<T>* b) : ConditionComparison<T>(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (*this->_a <= *this->_b);
    }
};

/**
  *  ConditionGT class template. 
  *  Has the value of True if the left-hand sub-expression is greater than the right hand sub-expression
  */
template <typename T>
class ConditionGT : public ConditionComparison<T> {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand sub-expression
    * @param b Pointer to the right-hand sub-expression
    */  
    ConditionGT<T>(Value<T>* a, Value<T>* b) : ConditionComparison<T>(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (*this->_a > *this->_b);
    }
};
  
/**
  *  ConditionGTEQ class template. 
  *  Has the value of True if the left-hand sub-expression is greater than or equal to the right hand sub-expression
  */
template <typename T>
class ConditionGTEQ : public ConditionComparison<T> {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand sub-expression
    * @param b Pointer to the right-hand sub-expression
    */  
    ConditionGTEQ<T>(Value<T>* a, Value<T>* b) : ConditionComparison<T>(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (*this->_a >= *this->_b);
    }
};

/**
  *  ConditionComparison class. 
  *  The base class of all ConditionBoolean classes
  */
class ConditionBoolean : public Condition {
  protected:
    Condition* _a;  /**< protected variable _a. Pointer to the left-hand condition sub-expression */ 
    Condition* _b;  /**< protected variable _b. Pointer to the right-hand condition sub-expression */ 

  /**
    * constructor
    * @param a Pointer to the left-hand condition sub-expression
    * @param b Pointer to the right-hand condition sub-expression
    */  
    ConditionBoolean(Condition* a, Condition* b) : _a(a), _b(b), Condition() {}
};

/**
  *  ConditionAND class. 
  *  Has the value of True if both the left-hand sub-expression and the right hand sub-expression are True
  */
class ConditionAND : public ConditionBoolean {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand condition sub-expression
    * @param b Pointer to the right-hand condition sub-expression
    */  
    ConditionAND(Condition* a, Condition* b) : ConditionBoolean(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (this->_a->getValue() && this->_b->getValue());
    }
};

/**
  *  ConditionAND class. 
  *  Has the value of True if either the left-hand sub-expression or the right hand sub-expression is True
  */
class ConditionOR : public ConditionBoolean {
  public:
  /**
    * constructor
    * @param a Pointer to the left-hand condition sub-expression
    * @param b Pointer to the right-hand condition sub-expression
    */ 
    ConditionOR(Condition* a, Condition* b) : ConditionBoolean(a, b) {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (this->_a->getValue() || this->_b->getValue());
    }
};

/**
  *  ConditionTRUE class. 
  *  Always has the value of True 
  */
class ConditionTRUE : public Condition {
  public:
  /**
    * constructor
    */ 
    ConditionTRUE() : Condition() {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return true;
    }
};

/**
  *  ConditionFALSE class. 
  *  Never has the value of True 
  */
class ConditionFALSE : public Condition {
  public:
  /**
    * constructor
    */ 
    ConditionFALSE() : Condition() {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return false;
    }
};

/**
  *  ConditionNOT class template. 
  *   Has the value of True if the sub-expreesion is nor True
  */
class ConditionNOT : public Condition {
  protected:
    Condition* _a;  /**< protected variable _a. Pointer to the sub-expression */

  public:
  /**
    * constructor
    * @param a Pointer to the condition sub-expression
    */ 
    ConditionNOT(Condition* a) : _a(a), Condition() {}
    
  /**
    * return the value of this expression
    * @return the current value
    */  
    virtual bool getValue() {
      return (!this->_a->getValue());
    }
};


#endif //_CONDITION_H
