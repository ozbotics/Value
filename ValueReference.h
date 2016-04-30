/** @file ValueProgmemString.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _VALUE_REFERENCE_H
  #define _VALUE_REFERENCE_H

#include <Arduino.h>
#include <Value.h>

/**
  *  ValueReference class template. 
  *  Has the value of a referenced variable
  */
template <class T>
class ValueReference : public Value<T> {
  protected:
    T& _valueRef;  /**< protected variable _valueRef. Reference to a vraiable */ 
  
  public:    
  /**
    * constructor
    * @param valueRef Reference to a variable.
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */  
    ValueReference(T& valueRef, byte displayLength=0, byte displayDecimals=0, unsigned int divideBy=1) : _valueRef(valueRef), Value<T>(displayLength, displayDecimals, divideBy) { }
    
   /**
    * return the value in its native type
    * @return the current value
    */  
    virtual T getValue();
    
    
   /**
    * set the value
    * @param value the new value
    * @return nothing
    */  
    virtual void setValue(T value);
};

template <class T>
T ValueReference<T>::getValue() { 
  return _valueRef; 
}

template <class T>
void ValueReference<T>::setValue(T value) { 
  _valueRef = value;
}

#endif // _VALUE_REFERENCE_H