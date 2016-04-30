#include <Value.h>


void setup() {
  Serial.begin(9600);

  // use this as a buffer for all getValueString calls
  char outBuf[80];

  
  Serial.println(F("float Value, default format, 1 digit long, with no decimal places"));
  Value<float> floatVal1;
  
  Serial.print(F("Initial floatVal1.value: "));
  Serial.print(floatVal1.getValue());
  Serial.print(F(", floatVal1.getValueString: "));
  floatVal1.getValueString(outBuf);
  Serial.println(outBuf);

  floatVal1.setValue(2.01);

  Serial.print(F("Updated floatVal1.value: "));
  Serial.print(floatVal1.getValue());
  Serial.print(F(", floatVal1.getValueString: "));
  floatVal1.getValueString(outBuf);
  Serial.println(outBuf);
  Serial.println();

  
  Serial.println(F("float Value, 5 digital long, with 2 decimal places"));
  Value<float> floatVal2(5,2);
  
  Serial.print(F("Initial floatVal2.value: "));
  Serial.print(floatVal2.getValue());
  Serial.print(F(", floatVal2.getValueString: "));
  floatVal2.getValueString(outBuf);
  Serial.println(outBuf);

  floatVal2.setValue(2.01);

  Serial.print(F("Updated floatVal2.value: "));
  Serial.print(floatVal2.getValue());
  Serial.print(F(", floatVal2.getValueString: "));
  floatVal2.getValueString(outBuf);
  Serial.println(outBuf);
  Serial.println();

  
  Serial.println(F("float Value, 8 digital long (padded), with 2 decimal places"));
  Value<float> floatVal3(8,2);

  Serial.print(F("Initial floatVal3.value: "));
  Serial.print(floatVal3.getValue());
  Serial.print(F(", floatVal3.getValueString: "));
  floatVal3.getValueString(outBuf);
  Serial.println(outBuf);

  floatVal3.setValue(2.01);

  Serial.print(F("Updated floatVal3.value: "));
  Serial.print(floatVal3.getValue());
  Serial.print(F(", floatVal3.getValueString: "));
  floatVal3.getValueString(outBuf);
  Serial.println(outBuf);
  Serial.println();

  
  Serial.println(F("integer Value with default formating"));
  Value<int> intVal1;

  Serial.print(F("Initial intVal1.value: "));
  Serial.print(intVal1.getValue());
  Serial.print(F(", intVal1.getValueString: "));
  intVal1.getValueString(outBuf);
  Serial.println(outBuf);

  intVal1.setValue(1000);

  Serial.print(F("Updated intVal1.value: "));
  Serial.print(intVal1.getValue());
  Serial.print(F(", intVal1.getValueString: "));
  intVal1.getValueString(outBuf);
  Serial.println(outBuf);
  Serial.println();

  
  Serial.println(F("fixed point Value, 5 digits long, with 2 decimal places"));
  Value<int> intVal2(5,2);

  Serial.print(F("Initial intVal2.value: "));
  Serial.print(intVal2.getValue());
  Serial.print(F(", intVal2.getValueString: "));
  intVal2.getValueString(outBuf);
  Serial.println(outBuf);

  intVal2.setValue(1000);

  Serial.print(F("Updated intVal2.value: "));
  Serial.print(intVal2.getValue());
  Serial.print(F(", intVal2.getValueString: "));
  intVal2.getValueString(outBuf);
  Serial.println(outBuf);
  Serial.println();


  Serial.println(F("fixed point Value, 5 digits long, with 0 decimal places, divided by 1000 (eg; millisceonds to seconds)"));
  Value<int> intVal3(5,0,1000);

  Serial.print(F("Initial intVal3.value: "));
  Serial.print(intVal3.getValue());
  Serial.print(F(", intVal3.getValueString: "));
  intVal3.getValueString(outBuf);
  Serial.println(outBuf);

  intVal3.setValue(10000);

  Serial.print(F("Updated intVal3.value: "));
  Serial.print(intVal3.getValue());
  Serial.print(F(", intVal3.getValueString: "));
  intVal3.getValueString(outBuf);
  Serial.println(outBuf);
  Serial.println();
  
  
  // boolean Value
  Serial.println(F("boolean Value"));
  Value<bool> boolVal1;
  
  Serial.print(F("Initial boolVal1.value: "));
  Serial.print(boolVal1.getValue());
  Serial.print(F(", boolVal1.getValueString: "));
  boolVal1.getValueString(outBuf);
  Serial.println(outBuf);

  boolVal1.setValue(true);

  Serial.print(F("Updated boolVal1.value: "));
  Serial.print(boolVal1.getValue());
  Serial.print(F(", boolVal1.getValueString: "));
  boolVal1.getValueString(outBuf);
  Serial.println(outBuf);
  Serial.println();
  
}

void loop() {
}