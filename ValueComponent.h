/** @file ValueComponent.h 
  *  Copyright (c) 2017 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _VALUE_REFERENCE_COMPONENT_H
  #define _VALUE_REFERENCE_COMPONENT_H

#include <Arduino.h>
#include <Value.h>

/**
  *  ValueComponent class template. 
  *  Has the value of a referenced variable
  */
template <class T, class RT>
class ValueComponent : public Value<T> {
  protected:
    RT _valueRef;  /**< protected variable _valueRef. Reference to a variable */ 
  
  public:    
  /**
    * constructor
    * @param valueRef Reference to a variable.
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */  
    ValueComponent(RT valueRef, byte displayLength=0, byte displayDecimals=0, unsigned int divideBy=1) : _valueRef(valueRef), Value<T>(displayLength, displayDecimals, divideBy) { }
    
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
    
   /**
    * return the value in its native type
    * @return the current value
    */  
    virtual T getComponentValue()=0;
    
   /**
    * set the value
    * @param value the new value
    * @return nothing
    */  
    virtual void setComponentValue(T value)=0;
    
   /**
    * persist the value
    * @return nothing
    */  
    virtual void persistValue() {
      _valueRef->persistValue();
    }
    
    
   /**
    * set _updateEnabled
    * @param enabled   is update allowed?
    * @return nothing
    */  
    virtual void setUpdateEnabled(bool enabled) {
      //Serial.print("ValueComponent::setUpdateEnabled() ");
      //Serial.println(enabled);
      
      Value<T>::setUpdateEnabled(enabled);
      _valueRef->setUpdateEnabled(enabled);
    }
    
    
};

template <class T, class RT>
T ValueComponent<T,RT>::getValue() { 
  return getComponentValue(); 
}

template <class T, class RT>
void ValueComponent<T,RT>::setValue(T value) { 
  setComponentValue(value);
}
#endif // _VALUE_REFERENCE_COMPONENT_H