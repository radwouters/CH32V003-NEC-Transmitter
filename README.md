# CH32V003-NEC-Transmitter
A library for transmitting NEC IR signals on the CH32V003. See [the article](https://blog.rickwouters.me/using-the-ch32v003-as-an-ir-transmitter/) for how it was made.

# How to use:
## Installation
Copy or `git clone` this repo into the `libraries` directory of your Arduino folder.

## Example
```arduino
#include "NECTransmitter.h";
#define LED_PIN PD4

NECTransmitter transmitter(LED_PIN);

void setup(){
    transmitter.begin();
}

void loop(){
    transmitter.transmitMessage(0x00FFAA55);
    delay(500);
}

```

# TODO
- [ ] Allow different data lengths
- [ ] Helper methods to go from address and command to a data object
- [ ] Multiple protocol
- [ ] An implementation that isn't delay-based