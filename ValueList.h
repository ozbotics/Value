/** @file ValueExpr.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _VALUE_LIST_H
  #define _VALUE_LIST_H

#include <Arduino.h>
#include <Value.h>

/**
  *  ValueList class template. 
  *  The concatenation of a collection of Values
*/
class ValueList : public ValueBase {
  protected:
    int _sz;                 /**< protected variable _sz. The size of the array */ 
    ValueBase* const* _data; /**< protected variable _data. The array of pointers to Values */ 
  
  public:
    /**
      * constructor
      * @param sz the size of the array
      * @param data the array of pointers to Values
    */  
    ValueList(int sz, ValueBase* const data[]) : _sz(sz), _data(data), ValueBase() { }

   /**
    * concatenate the value strings of all of the sub-expressions
    * @param buf the char buffer
    * @return nothing
    */  
    virtual void getValueString(char * buf) {
      buf[0] = 0;  //null terminate empty string
      
      for (int i=0; i<_sz; i++) {
        _data[i]->getValueString(buf + strlen(buf));
      }
    }

};

#endif // _VALUE_LIST_H