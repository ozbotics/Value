#line 2 "testValue.ino"
#include <ArduinoUnit.h>
#include <EEPROMex.h>

#include <Value.h>
#include <ValueEeprom.h>

ValueEeprom<bool> boolVal1;
ValueEeprom<int> intVal1;
ValueEeprom<float> floatVal1(5,2);

char outBuf[80];

test(bool_persist)
{
  boolVal1.initValue(false);
  assertFalse(boolVal1.getValue());

  boolVal1.setValue(true);
  assertTrue(boolVal1.hasChanged());

  boolVal1.persistValue();
  assertFalse(boolVal1.hasChanged());

  boolVal1.setValue(false);
  assertTrue(boolVal1.hasChanged());

  boolVal1.revertValue();
  assertTrue(boolVal1.getValue());
  assertFalse(boolVal1.hasChanged());

  boolVal1.initValue(false);
  assertFalse(boolVal1.getValue());
  assertFalse(boolVal1.hasChanged());
}

test(bool_eeprom_address)
{
  assertEqual(boolVal1.getEepromAddress(), 0);
}


test(int_persist)
{
  intVal1.initValue(0);
  assertFalse(intVal1.getValue());

  intVal1.setValue(10);
  assertTrue(intVal1.hasChanged());

  intVal1.persistValue();
  assertFalse(intVal1.hasChanged());

  intVal1.setValue(0);
  assertTrue(intVal1.hasChanged());

  intVal1.revertValue();
  assertTrue(intVal1.getValue());
  assertFalse(intVal1.hasChanged());

  intVal1.initValue(0);
  assertFalse(intVal1.getValue());
  assertFalse(intVal1.hasChanged());
}

test(int_eeprom_address)
{
  assertEqual(intVal1.getEepromAddress(), 1);
}


test(float_persist)
{
  floatVal1.initValue(0.0);
  assertFalse(floatVal1.getValue());

  floatVal1.setValue(10.0);
  assertTrue(floatVal1.hasChanged());

  floatVal1.persistValue();
  assertFalse(floatVal1.hasChanged());

  floatVal1.setValue(0.0);
  assertTrue(floatVal1.hasChanged());

  floatVal1.revertValue();
  assertTrue(floatVal1.getValue());
  assertFalse(floatVal1.hasChanged());

  floatVal1.initValue(0.0);
  assertFalse(floatVal1.getValue());
  assertFalse(floatVal1.hasChanged());
}

test(float_eeprom_address)
{
  assertEqual(floatVal1.getEepromAddress(), 3);
}


void setup()
{
  Serial.begin(9600);
  while(!Serial); // for the Arduino Leonardo/Micro only
}

void loop()
{
  Test::run();
}
