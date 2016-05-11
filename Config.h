/** @file Actuator.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _CONFIG_H
  #define _CONFIG_H
  
 /**
  * Config
  *
  * The base of all Config classes
  * 
  * Requires subclasses to provide initFromEeprom() and factoryReset()
  */
class Config {
  protected:
   /**
    * initialise the Config object by reading from the Eeprom
    */
    virtual void initFromEeprom() = 0;

   /**
    * initialise the Config object by populating it with Factory Default values
    */
    virtual void factoryReset() = 0;
};


#endif //_CONFIG_H
