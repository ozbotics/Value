/** @file Condition.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _EEPROM_VALUE_H
  #define _EEPROM_VALUE_H

#include <Value.h>
#include <EEPROMex.h>

/**
  *  ValueEeprom class template. 
  *  Value that is able to persist itself to EEPROM
*/
template <class T>
class ValueEeprom : public Value<T> {
  protected:
    int _eepromAddress;  /**< protected variable _eepromAddress. The address in EEPROM memory */ 

  public:
  /**
    * constructor
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */  
    ValueEeprom(byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : Value<T>(displayLength, displayDecimals, divideBy) {
      _eepromAddress = EEPROM.getAddress(sizeof(T));
      initValueFromEeprom();
    }

   /**
    * update current value from EEPROM
    * @return nothing
    */  
    void initValueFromEeprom() { 
      EEPROM.readBlock(_eepromAddress, this->_value); 
      this->_oldValue = this->_value; 
    }

   /**
    * persist the value to EEPROM
    * @return nothing
    */  
    virtual void persistValue() {
      Value<T>::persistValue();

      EEPROM.updateBlock(_eepromAddress, this->_value);
    }

   /**
    * return the EEPROM memory address
    * @return the address of this value in EEPROM memory
    */  
    int getEepromAddress() {
      return _eepromAddress;
    }
    
};
#endif // _EEPROM_VALUE_H
