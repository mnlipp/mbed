#include "mbed.h"

#if defined(TARGET_SAMR21G18A) || defined(TARGET_SAMD21J18A) || defined(TARGET_SAMD21G18A)
DigitalOut out(PB02);
#else
DigitalOut out(p5);
#endif

int main() {
    while (true) {
        out = 1;
        out = 0;
    }
}
