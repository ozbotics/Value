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

/**
  * PbStreamConfig
  *
  * Extends Config to provide ProtoBuf encoding/decoding to/from a Stream
  *
  * Requires subclasses to provide decodePb() & encodePb()
  */
class PbStreamConfig : public Config {
  protected:
    int _pBufSize;
    uint8_t* _pBuf;
    
  public:
    PbStreamConfig(int pBufSize) : _pBufSize(pBufSize), Config() {
      _pBuf = (uint8_t*) malloc(_pBufSize);
    }
    
    ~PbStreamConfig() {
      free(_pBuf);
    }
    
   /**
    * Encode the Config Tree to a ProtoBuf stored in _pBuf
    */
    virtual void encodePb(size_t& message_length) =0;
    
   /**
    * Decode the Config Tree from a ProtoBuf stored in _pBuf
    */
    virtual void decodePb(size_t& message_length) =0;

   /**
    * Encode the Config Tree to a ProtoBuf writen to the provided Stream
    *
    * @param stream The stream that the PB will be written to
    */
    void encodePbStream(Stream& stream) {
      size_t message_length;
      
      encodePb(message_length);
      
      stream.write((char *)_pBuf, message_length);
    }
    
   /**
    * Decode the Config Tree from a ProtoBuf read from the provided Stream
    *
    * @param stream The stream that the PB will be read from
    */
    void decodePbStream(Stream& stream) {
      int i = 0;
      while (stream.available()) {
        _pBuf[i++] = stream.read();
      }
      
      size_t message_length = (size_t) i;
      
      decodePb(message_length);
    }

};

#endif //_CONFIG_H
