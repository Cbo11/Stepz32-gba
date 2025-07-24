#ifndef INPUT_H
#define INPUT_H

#include <gba.h>

void input_init(void);
void input_update(void);
int input_held(u16 key);

#endif