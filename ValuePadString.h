/** @file ValuePadString.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _VALUE_PAD_STRING_H
  #define _VALUE_PAD_STRING_H

#include <Arduino.h>
#include <Value.h>

/**
  *  ValuePadString class temmplate. 
  *  Has the value of a fixed number of pad charcaters
  */
class ValuePadString : public ValueBase {
  protected:
    byte _num;      /**< protected variable _num. The number of pad characters to generate */ 
    char _padChar;  /**< protected variable _padChar. The the character to use as the pad char */ 
  
  public:    
   /**
    * constructor
    * @param num the number of pad characters to generate
    * @param padChar the character to use as the pad char (defaults to space)
   */  
    ValuePadString(byte num, char padChar=' ') : _num(num), _padChar(padChar), ValueBase() { }

   /**
    * generates a stream of 'padChar' characters, 'num' long
    * @param buf the char buffer
    * @return nothing
    */  
    virtual void getValueString(char * buf) {
      buf[0] = 0;  //null terminate empty string
      
      byte i;
      for (i=0; i<_num; i++) {
        buf[i] = _padChar;
        buf[i+1] = 0;
      }
    }

};

#endif // _VALUE_PAD_STRING_H