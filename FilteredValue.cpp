#include "FilteredValue.h"

int compareValueUInt(const void * a, const void * b) {
  return ( *(unsigned int*)a - *(unsigned int*)b );
}  

template <>
void FilteredValue<unsigned int>::setValue(unsigned int val) {
  _valueBuf[_bufIndex] = val;
  _bufIndex++;
  
  if (_bufIndex > FILTERED_VALUE_BUF_SIZE) {
    _bufIndex = 0;  // rollover index
  }
}

template <>
unsigned int FilteredValue<unsigned int>::getFilteredValue() {
  unsigned int sortBuf[FILTERED_VALUE_BUF_SIZE];
  unsigned int cumulativeValue = 0;

#ifdef DEBUG_FILTERED_VALUE
  Serial.println("Entered FilteredValue::getFilteredValue");
#endif

  memcpy(sortBuf, _valueBuf, FILTERED_VALUE_BUF_SIZE*sizeof(unsigned int));
  qsort (sortBuf, FILTERED_VALUE_BUF_SIZE, sizeof(unsigned int), compareValueUInt);
  
#ifdef DEBUG_FILTERED_VALUE
  for (int i = 0; i < FILTERED_VALUE_BUF_SIZE; i++) {
    Serial.print(i);
    Serial.print(": ");
    Serial.println(sortBuf[i]);
  }  
#endif
  
  // exclude smallest & largest values
  for (int i = 1; i < (FILTERED_VALUE_BUF_SIZE - 1); i++) {
    cumulativeValue += sortBuf[i];
  }

#ifdef DEBUG_FILTERED_VALUE
  Serial.print("~ ");
  Serial.println(cumulativeValue / (FILTERED_VALUE_BUF_SIZE - 2));
#endif
  
  // return average of others
  return cumulativeValue / (FILTERED_VALUE_BUF_SIZE - 2);
}
