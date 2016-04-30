/** @file Value.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _VALUE_H
  #define _VALUE_H

#include <Arduino.h>

 /**
  *  ValueBase class. 
  *  The Base of all Value<T> classes
  */
class ValueBase {
  public:
   /**
    * render the value as a character string
    * @param buf the char buffer
    * @return nothing
    */  
    virtual void getValueString(char * buf)=0;
};


 /**
  *  Value<T> class template. 
 */
template <class T>
class Value : public ValueBase {
  protected:
    T _value;                 /**< protected variable _value. The current value. */ 
    T _oldValue;              /**< protected variable _value. The previous value. */ 
    byte _displayLength;      /**< protected variable _displayLength. The total width of the output string. */ 
    byte _displayDecimals;    /**< protected variable _displayDecimals. The number of decimal places. */ 
    unsigned int _divideBy;   /**< protected variable _divideBy. Divide the value by this amount, eg; 60000 to convert milliseconds to minutes. */ 

  public:
  /**
    * constructor
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */  
    Value<T>(byte displayLength=0, byte displayDecimals=0, unsigned int divideBy=1) :  _displayLength(displayLength), _displayDecimals(displayDecimals), _divideBy(divideBy), _value( T() ), _oldValue( T() ), ValueBase() { }

   /**
    * render the value as a character string
    * @param buf the char buffer
    * @return nothing
    */  
    virtual void getValueString(char * buf);
    
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
    virtual void setValue(T value) { 
      _value = value; 
    }

   /**
    * set the displayLength
    * @param displayLength the new displayLength
    * @return nothing
    */  
    void setDisplayLength(byte displayLength) {
      _displayLength = displayLength;
    }
    
   /**
    * set the displayDecimals
    * @param displayDecimals the new displayDecimals
    * @return nothing
    */  
    void setDisplayDecimals(byte displayDecimals) {
      _displayDecimals = displayDecimals;
      }

   /**
    * set the divideBy
    * @param divideBy the new divideBy
    * @return nothing
    */  
    void setDivideBy(byte divideBy) {
      _divideBy = divideBy;
    }

   /**
    * equals operator
    * @param other the other Value object to be compared
    * @return true if this and other Value are equal
    */  
    bool operator==(Value<T>& other) {
      return (this->getValue() == other.getValue());
    }

   /**
    * not-equal operator
    * @param other the other Value object to be compared
    * @return true if this and other Value are not equal
    */  
    bool operator!=(Value<T>& other) {
      return (this->getValue() != other.getValue());
    }
    
   /**
    * less-than operator
    * @param other the other Value object to be compared
    * @return true if this is less than the other Value
    */  
    bool operator<(Value<T>& other) {
      return (this->getValue() < other.getValue());
    }

   /**
    * less-than-or-equal operator
    * @param other the other Value object to be compared
    * @return true if this is less than or equal to the other Value
    */  
    bool operator<=(Value<T>& other) {
      return (this->getValue() <= other.getValue());
    }

   /**
    * greater-than operator
    * @param other the other Value object to be compared
    * @return true if this is greater than the other Value
    */  
    bool operator>(Value<T>& other) {
      return (this->getValue() > other.getValue());
    }

   /**
    * greater-than-or-equal operator
    * @param other the other Value object to be compared
    * @return true if this is greater than or equal to the other Value
    */  
    bool operator>=(Value<T>& other) {
      return (this->getValue() >= other.getValue());
    }

   /**
    * add operator
    * @param other the other Value object to be compared
    * @return the value of this plus the other Value
    */  
    T operator+(Value<T>& other) {
      return (this->getValue() + other.getValue());
    }
    
   /**
    * subtract operator
    * @param other the other Value object to be compared
    * @return the value of this less the other Value
    */  
    T operator-(Value<T>& other) {
      return (this->getValue() - other.getValue());
    }
    
   /**
    * multiply operator
    * @param other the other Value object to be compared
    * @return the value of this multiplied by the other Value
    */  
    T operator*(Value<T>& other) {
      return (this->getValue() * other.getValue());
    }
    
   /**
    * divide operator
    * @param other the other Value object to be compared
    * @return the value of this divided by the other Value
    */  
    T operator/(Value<T>& other) {
      return (this->getValue() / other.getValue());
    }
    
   /**
    * has the value changed?
    * @return true if the value has been changed since it was last persisted
    */  
    inline bool hasChanged() {
      return (this->getValue() != _oldValue);
    }

   /**
    * persist the value
    * @return nothing
    */  
    virtual void persistValue() {
      _oldValue = this->getValue(); 
    }

   /**
    * revert the current value back to the persisted value
    * @return nothing
    */  
    inline void revertValue() {
      this->setValue(_oldValue);
    }
    
   /**
    * set the vlaue and immediately persist
    * @param value the new value
    * @return nothing
    */  
    void initValue(T value) { 
      this->setValue(value); 
      persistValue();
    }

};

template <class T>
void Value<T>::getValueString(char * buf) {
  float displayValue = (float) this->getValue() / _divideBy / pow(10, _displayDecimals);
  dtostrf(displayValue, _displayLength, _displayDecimals, buf);
}

template <class T>
T Value<T>::getValue() { 
  return _value; 
}

#endif // _VALUE_H
