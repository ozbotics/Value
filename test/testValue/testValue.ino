#line 2 "testValue.ino"
#include <ArduinoUnit.h>
#include <Value.h>

char outBuf[80];


test(float_default_is_0_0)
{
  Value<float> floatVal1;
  
  assertEqual(floatVal1.getValue(), 0.0);
  
  floatVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "0"), 0);
}

test(float_setValue_1_0_default_format)
{
  Value<float> floatVal1;
  floatVal1.setValue(1.0);
  
  assertEqual(floatVal1.getValue(), 1.0);
  
  floatVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1"), 0);
}

test(float_setValue_1_12_with_decimals)
{
  Value<float> floatVal1(1,2);
  floatVal1.setValue(1.12);
  
  assertEqual(floatVal1.getValue(), 1.12);
  
  floatVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.12"), 0);
}

test(float_setValue_1_with_padding)
{
  Value<float> floatVal1(4,0);
  floatVal1.setValue(1.12);
  
  assertEqual(floatVal1.getValue(), 1.12);
  
  floatVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "   1"), 0);
}


test(float_setValue_negative_1_12)
{
  Value<float> floatVal1(1,2);
  floatVal1.setValue(-1.12);
  
  assertEqual(floatVal1.getValue(), -1.12);
  
  floatVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "-1.12"), 0);
}

test(float_setValue_1_01_scaled)
{
  Value<float> floatVal1(1,2,10);
  floatVal1.setValue(10.10);
  
  assertEqual(floatVal1.getValue(), 10.10);
  
  floatVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.01"), 0);
}


test(int_default_is_0)
{
  Value<int> intVal1;
  
  assertEqual(intVal1.getValue(), 0);
  
  intVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "0"), 0);
  
}

test(int_setValue_1_default_format)
{
  Value<int> intVal1;
  intVal1.setValue(1);
  
  assertEqual(intVal1.getValue(), 1);
  
  intVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1"), 0);
}


test(int_setValue_1_01_fixed_point_2_decimals)
{
  Value<int> intVal1(1,2);
  intVal1.setValue(101);
  
  assertEqual(intVal1.getValue(), 101);
  
  intVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.01"), 0);
}

test(int_setValue_1_01_fixed_point_scaled_by_10)
{
  Value<int> intVal1(1,2,10);
  intVal1.setValue(1010);
  
  assertEqual(intVal1.getValue(), 1010);
  
  intVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.01"), 0);
}


test(int_setValue_negative_10_01)
{
  Value<int> intVal1(1,2);
  intVal1.setValue(-1001);
  
  assertEqual(intVal1.getValue(), -1001);
  
  intVal1.getValueString(outBuf);
  
  assertEqual(strcmp (outBuf, "-10.01"), 0);
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