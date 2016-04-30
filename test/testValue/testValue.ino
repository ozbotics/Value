#line 2 "testValue.ino"
#include <ArduinoUnit.h>
#include <Value.h>

char outBuf[80];

test(bool_default_is_false)
{
  Value<bool> boolVal1;
  
  assertEqual(boolVal1.getValue(), false);
  
  boolVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "Off"), 0);  
}

test(bool_setValue_true_default_format)
{
  Value<bool> boolVal1;
  boolVal1.setValue(true);
  
  assertEqual(boolVal1.getValue(), true);
  
  boolVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "On"), 0);
}

test(bool_comparisons)
{
  Value<bool> boolVal1;
  Value<bool> boolVal2;

  assertTrue(boolVal1 == boolVal2);

  boolVal1.setValue(true);
  assertTrue( boolVal1 != boolVal2);

  boolVal2.setValue(true);
  assertTrue(boolVal1 == boolVal2);
}


test(bool_has_changed)
{
  Value<bool> boolVal1;
  assertFalse(boolVal1.hasChanged());
  
  boolVal1.setValue(true);
  assertTrue(boolVal1.hasChanged());
}


test(bool_persist)
{
  Value<bool> boolVal1;
  assertFalse(boolVal1.hasChanged());
  
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

test(float_comparisons)
{
  Value<float> floatVal1;
  Value<float> floatVal2;

  assertTrue(floatVal1 == floatVal2);

  floatVal1.setValue(10.0);
  assertTrue( floatVal1 != floatVal2);
  assertTrue( floatVal1 > floatVal2);
  assertTrue( floatVal1 >= floatVal2);
  assertFalse( floatVal1 < floatVal2);
  assertFalse( floatVal1 <= floatVal2);
  
  floatVal2.setValue(10.0);
  assertTrue(floatVal1 == floatVal2);
  assertFalse( floatVal1 > floatVal2);
  assertTrue( floatVal1 >= floatVal2);
  assertFalse( floatVal1 < floatVal2);
  assertTrue( floatVal1 <= floatVal2);
  
}

test(float_math)
{
  Value<float> floatVal1;
  Value<float> floatVal2;
  Value<float> floatVal3;

  floatVal1.setValue(10.0);
  assertEqual(floatVal1.getValue(), 10.0);

  assertFalse(floatVal1 == floatVal2);

  floatVal3.setValue(10.0);
  assertTrue(floatVal1 == floatVal3);
  
  
  floatVal2 = floatVal1;
  assertTrue(floatVal1 == floatVal2);

  floatVal1.setValue(20.0);
  assertEqual(floatVal1.getValue(), 20.0);
  assertFalse(floatVal1 == floatVal2);

  assertEqual(floatVal1 + floatVal2, 30.0);

  assertEqual(floatVal1 - floatVal2, 10.0);
 
  assertEqual(floatVal1 * floatVal2, 200.0);
  
  assertEqual(floatVal1 / floatVal2, 2.0);
}

test(float_persist)
{
  Value<float> floatVal1;
  assertFalse(floatVal1.hasChanged());
  
  floatVal1.setValue(10.0);
  assertTrue(floatVal1.hasChanged());

  floatVal1.persistValue();
  assertFalse(floatVal1.hasChanged());

  floatVal1.setValue(0.0);
  assertTrue(floatVal1.hasChanged());

  floatVal1.revertValue();
  assertEqual(floatVal1.getValue(), 10.0);
  assertFalse(floatVal1.hasChanged());

  floatVal1.initValue(20.0);
  assertEqual(floatVal1.getValue(), 20.0);
  assertFalse(floatVal1.hasChanged());
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

test(int_comparisons)
{
  Value<int> intVal1;
  Value<int> intVal2;

  assertTrue(intVal1 == intVal2);

  intVal1.setValue(10);
  assertTrue( intVal1 != intVal2);
  assertTrue( intVal1 > intVal2);
  assertTrue( intVal1 >= intVal2);
  assertFalse( intVal1 < intVal2);
  assertFalse( intVal1 <= intVal2);
  
  intVal2.setValue(10);
  assertTrue(intVal1 == intVal2);
  assertFalse( intVal1 > intVal2);
  assertTrue( intVal1 >= intVal2);
  assertFalse( intVal1 < intVal2);
  assertTrue( intVal1 <= intVal2);
}

test(int_math)
{
  Value<int> intVal1;
  Value<int> intVal2;
  Value<int> intVal3;

  intVal1.setValue(10);
  assertEqual(intVal1.getValue(), 10);

  assertFalse(intVal1 == intVal2);

  intVal3.setValue(10);
  assertTrue(intVal1 == intVal3);
  
  
  intVal2 = intVal1;
  assertTrue(intVal1 == intVal2);

  intVal1.setValue(20);
  assertEqual(intVal1.getValue(), 20);
  assertFalse(intVal1 == intVal2);

  assertEqual(intVal1 + intVal2, 30);

  assertEqual(intVal1 - intVal2, 10);
 
  assertEqual(intVal1 * intVal2, 200);
  
  assertEqual(intVal1 / intVal2, 2);
}

test(int_persist)
{
  Value<int> intVal1;
  assertFalse(intVal1.hasChanged());
  
  intVal1.setValue(10);
  assertTrue(intVal1.hasChanged());

  intVal1.persistValue();
  assertFalse(intVal1.hasChanged());

  intVal1.setValue(0);
  assertTrue(intVal1.hasChanged());

  intVal1.revertValue();
  assertEqual(intVal1.getValue(), 10);
  assertFalse(intVal1.hasChanged());

  intVal1.initValue(20);
  assertEqual(intVal1.getValue(), 20);
  assertFalse(intVal1.hasChanged());
}

test(uint_default_is_0)
{
  Value<unsigned int> uintVal1;
  
  assertEqual(uintVal1.getValue(), 0);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "0"), 0);
  
}

test(uint_setValue_1_default_format)
{
  Value<unsigned int> uintVal1;
  uintVal1.setValue(1);
  
  assertEqual(uintVal1.getValue(), 1);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1"), 0);
}


test(uint_setValue_1_01_fixed_pouint_2_decimals)
{
  Value<unsigned int> uintVal1(1,2);
  uintVal1.setValue(101);
  
  assertEqual(uintVal1.getValue(), 101);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.01"), 0);
}

test(uint_setValue_1_01_fixed_pouint_scaled_by_10)
{
  Value<unsigned int> uintVal1(1,2,10);
  uintVal1.setValue(1010);
  
  assertEqual(uintVal1.getValue(), 1010);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.01"), 0);
}

test(ulong_default_is_0)
{
  Value<unsigned long> uintVal1;
  
  assertEqual(uintVal1.getValue(), 0);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "0"), 0);
  
}

test(ulong_setValue_1_default_format)
{
  Value<unsigned long> uintVal1;
  uintVal1.setValue(1);
  
  assertEqual(uintVal1.getValue(), 1);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1"), 0);
}


test(ulong_setValue_1_01_fixed_point_2_decimals)
{
  Value<unsigned long> uintVal1(1,2);
  uintVal1.setValue(101);
  
  assertEqual(uintVal1.getValue(), 101);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.01"), 0);
}

test(ulong_setValue_1_01_fixed_point_scaled_by_10)
{
  Value<unsigned long> uintVal1(1,2,10);
  uintVal1.setValue(1010);
  
  assertEqual(uintVal1.getValue(), 1010);
  
  uintVal1.getValueString(outBuf);
  assertEqual(strcmp (outBuf, "1.01"), 0);
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
