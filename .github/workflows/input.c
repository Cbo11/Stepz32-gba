#include "input.h"

static u16 keys_held;

void input_init(void) {
    // Nothing needed for now
}

void input_update(void) {
    keys_held = REG_KEYINPUT ^ 0x3FF;
}

int input_held(u16 key) {
    return keys_held & key;
}