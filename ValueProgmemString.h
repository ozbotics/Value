/** @file ValueProgmemString.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _VALUE_PROGMEM_STRING_H
  #define _VALUE_PROGMEM_STRING_H

#include <Arduino.h>
#include <Value.h>

/**
  *  ValueProgmemString class template. 
  *  Has the value of a character string that is stored in PROGMEM
  */
class ValueProgmemString : public ValueBase {
  protected:
    const char* _progmemString;  /**< protected variable _progmemString. Pointer to a string of characters in PROGMEM */ 

  public:
   /**
    * constructor
    * @param progmemString Pointer to a string of characters in PROGMEM
    */  
    ValueProgmemString(const char* progmemString) : _progmemString(progmemString), ValueBase() {}

   /**
    * copies of the char string from PROGMEM
    * @param buf the char buffer
    * @return nothing
    */  
    virtual void getValueString(char * buf);
  
};

#endif // _VALUE_PROGMEM_STRING_H