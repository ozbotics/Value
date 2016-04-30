#include <EEPROMex.h>

#include <Value.h>
#include <ValueEeprom.h>

ValueEeprom<bool> configured;
ValueEeprom<float> floatVal1(5,2);

void setup() {
  Serial.begin(9600);

  // use this as a buffer for all getValueString calls
  char outBuf[80];



  configured.initValueFromEeprom();
  
  Serial.print(F("Persisted configured.value: "));
  configured.getValueString(outBuf);
  Serial.println(outBuf);
  

  if (configured.getValue()) {
    Serial.println(F("Eeprom is already configured"));
    
    floatVal1.initValueFromEeprom();
    Serial.print(F("Persisted floatVal1.value: "));
    Serial.println(floatVal1.getValue());
  }
  else {
    Serial.println(F("Eeprom is not yet configured"));

    floatVal1.initValue(10.5);
    configured.initValue(true);

    Serial.print(F("Initialised floatVal1.value to: "));
    floatVal1.getValueString(outBuf);
    Serial.println(outBuf);
    Serial.println();
    
    Serial.print(F("Initialised configured.value to: "));
    configured.getValueString(outBuf);
    Serial.println(outBuf);
    Serial.println();
  }

  Serial.print(F("configured eepromAddress: "));
  Serial.println(configured.getEepromAddress());
  
  Serial.print(F("floatVal1 eepromAddress: "));
  Serial.println(floatVal1.getEepromAddress());




  floatVal1.setValue(2.01);

  Serial.print(F("Updated floatVal1.value: "));
  Serial.print(floatVal1.getValue());
  Serial.print(F(", floatVal1.getValueString: "));
  floatVal1.getValueString(outBuf);
  Serial.println(outBuf);

  floatVal1.revertValue();

  Serial.print(F("Reverted floatVal1.value: "));
  Serial.print(floatVal1.getValue());
  Serial.print(F(", floatVal1.getValueString: "));
  floatVal1.getValueString(outBuf);
  Serial.println(outBuf);

  floatVal1.setValue(2.02);
  floatVal1.persistValue();

  Serial.print(F("Persited floatVal1.value: "));
  Serial.print(floatVal1.getValue());
  Serial.print(F(", floatVal1.getValueString: "));
  floatVal1.getValueString(outBuf);
  Serial.println(outBuf);

  floatVal1.revertValue();

  Serial.print(F("Reverted floatVal1.value after persist: "));
  Serial.print(floatVal1.getValue());
  Serial.print(F(", floatVal1.getValueString: "));
  floatVal1.getValueString(outBuf);
  Serial.println(outBuf);

  
}

void loop() {
}
