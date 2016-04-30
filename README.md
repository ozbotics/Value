# Value

The Value library provides class templates for objects that hold a value and can render the value into a character string.

The Value abstraction provides a uniform interface so that eeprom settings, sensor values and calculated values can all be easily exposed in a text interface.

Values may specify the minimum width of the displayValue. If the width is more than the precision of the value, the value will be left padded so it is the minimum width.
(Does not at this point constrain the width to the minimum width. It may in the future)

Values may specify the number of decimal places. Value<int> becomes a fixed point number by specifying more than 0 decimal places.

Values may specify a scaleFactor. The displayValue is the actual value, divided by the scaler. This is usefull for converting milliseconds into seconds or minutes, etc.
(This is currently implemented as an unsigned integer. ie; value can only be divided, not multiplied. In the future it may be necessary to make this a float or fixed-point)

All Values may be read, updated, persisted and reverted, via getValue(), setValue(), persitValue() and revertValue(). A Value can indicate that it has changed, via hasChanged().

Value may be sub-classed to handle the representation of various information sources within a project. 

The Value library currently provides interfaces for EEPROM storage, Sensors, Actuators, Numerical Expressions and Boolean Expressions.

Any number of Values, Numerical Expressions and Boolean Expressions can be wired together to form Expression trees.
(Currently each expression tree is expected to be re-evaluated on a periodical basis, later versions of this library may include Observer callbacks)


## Installation

Clone the git repository into your Arduino/libraries directory


## BaseValue

All Value template classes inherit from BaseValue. BaseValue guarantees the ability to getValueString().

```
char buffer[BUFFER_SIZE];
myValue.getValueString(buffer);
```


## Value\<T>

Include the Value library
```
#include <Value.h>
```

Value is a class template. To create an instance, you must specify the type.
```
Value<int> intValue();
```
Note: The type will typically be a byte, int, unsigned int, long, unsigned long, float or bool.


Set the value
```
intValue.setValue(1000);
```

Get the value
```
int i = intValue.getValue();
```

At construction time you can specify the minimum width of the displayValue
```
Value<int> intValue(5);
```
If the width is more than the precision of the value, the value will be left padded so it is the minimum width.

It is possibly to change this a run-time by calling setDisplayLength()
```
intValue.setDisplayLength(5);
```

At construction time you can specify the number of decimal places.
```
Value<int> intValue(1,2);
```
In this case the int is being used as fixed point, where its last 2 digital are used as decimal places  (divided by 10^2)

In the case of a float the value is not divided, its precision is simply capped to the number of decimals.

It is possibly to change this a run-time by calling setDisplayDecimals()
```
intValue.setDisplayDecimals(2);
```

At construction time you can specify a divideBy scaler.
```
Value<int> intValue(1,0,1000);
```
The displayValue is the actual value divided by the divideBy value. This is usefull for converting milliseconds to seconds or minutes, etc.

It is possibly to change this at run-time by calling setDivideBy()
```
intValue.setDivideBy(60000);
```

Please note: regardless of the DisplayLength, DisplayDecimals or DivideBy, the internal represention does not change. In fact when getting the value by calling getValue(), the actual value is returned. 
This should be born in mind when comparing the values of Value<int> with different settings. A Value<int> intVal1(5,0,100) may display as '20', and  Value<int> intVal2(5,0,10) may be display as '30', 
but intVal1.getValue() is far greater than intVal2.getValue()


It is also possible to persist and revert a value. (This is usefull when manging a Setting in a User Interface.)
```
intValue.setValue(60000);
intValue.persistValue();
```

```
intValue.setValue(10000);
intValue.revertValue();  // value will return to last persisted value
```

It is possible to tell if a value has changed . (Is different from the persisted value)
```
if (intValue.hasChanged()) { ... }
```


## ValueEeprom\<T>

The Value Libary provides the ValueEeprom class template. Values may be held permanently in EEPROM memory. This is usefull for device configuaration.

The EEPROMEx Library is required (see https://github.com/thijse/Arduino-EEPROMEx)

```
#include <EEPROMex.h>

#include <Value.h>
#include <ValueEeprom.h>
```

Settings may be created simply by defining and instance of ValueEeprom\<T>
```
ValueEeprom<int> intValue(1,0,1000);
```

The Value needs to be initialized from EEPROM storage ...
```
intValue.initValueFromEeprom();
```

.. or in code
```
intValue.initValue(1000);
```

I recommend that the first ValueEeprom be a 'configured' flag or magic number, so that it is possible by initialising the first ValueEeprom from eeprom, 
then depending on its value, proceeding to initialize the remaining ValueEeprom(s) from eeprom, or initiallising them in code (First tiem setup / Factory Reset )

The 'Config' class is a good complement to ValueEeprom. It provides mechanisms for setting default values on factory reset and initiallising current values from the eeprom.
(See Config)


Any number of ValueEeprom(s) may be created (as long as there is EEPROM space available). 
Their values will faithfully link up with their EEPROM storage, so long as the ValueEeprom(s) are declared in the same order.


Values may be changed at will, but are not written to the EEPROM until they are persisted
```
intValue.setValue(1000);
intValue.persistValue();
```

For debugging purposes, it is possible to identify the actual EEPROM address used
```
unsigned int address = intValue.getEepromAddress();
```

