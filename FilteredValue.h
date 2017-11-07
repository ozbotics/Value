/** @file FilteredValue.h 
  *  Copyright (c) 2017 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _FILTERED_VALUE_H
  #define _FILTERED_VALUE_H

#include <stdlib.h>     /* qsort */
#include <Value.h>

#define FILTERED_VALUE_BUF_SIZE 4

//#define DEBUG_FILTERED_VALUE


/**
  *  FilteredValue class template. 
  *  Value that is able to initialize a Sensor
*/
template <class T>
class FilteredValue : public Value<T> {
  protected:
    T _valueBuf[FILTERED_VALUE_BUF_SIZE];
    uint8_t _bufIndex=0; 
    
  public:
  /**
    * constructor
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */  
    FilteredValue(byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : Value<T>(displayLength, displayDecimals, divideBy) { 
      for (byte i=0; i<FILTERED_VALUE_BUF_SIZE; i++) {
        _valueBuf[i] = T();
      }
    }
    
  /**
    * set the latest value 
    * @param val The latest value.
    */  
    virtual void setValue(T val);
    
  /**
    * get the filtered value 
    * @return The filtered value.
    */  
    virtual T getFilteredValue();

    
   /**
    * get the value (using overridable getFilteredValue() )
    * @return The value.
    */  
    virtual T getValue();

};


template <class T>
void FilteredValue<T>::setValue(T val) {
  Value<T>::setValue(val);
}

template <class T>
T FilteredValue<T>::getFilteredValue() {
  return Value<T>::getValue();
}

template <class T>
T FilteredValue<T>::getValue() {
  return getFilteredValue();
}

#endif // _FILTERED_VALUE_H
