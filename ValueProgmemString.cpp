#include <Value.h>
#include <ValueProgmemString.h>

void ValueProgmemString::getValueString(char * buf) {
  strcpy_P(buf, (char*)_progmemString);
}
