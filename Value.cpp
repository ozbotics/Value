#include "Value.h"

template <>
void Value<bool>::getValueString(char * buf) {
  strcpy(buf, (_value) ? "On" : "Off");
}
