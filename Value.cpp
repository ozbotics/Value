#include "Value.h"

template <>
void Value<bool>::getValueString(char * buf) {
  strcpy(buf, (_value) ? "On" : "Off");
}

template <>
void Value<float>::getValueString(char * buf) {
  float displayValue = this->getValue() / _divideBy;
  dtostrf(displayValue, _displayLength, _displayDecimals, buf);
}
