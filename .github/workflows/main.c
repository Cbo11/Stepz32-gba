---

### 2. `main.c`

```c
#include <gba.h>
#include "sound.h"
#include "input.h"
#include "ui.h"

#define STEPS 32
#define BPM_MIN 40
#define BPM_MAX 240

static int step = 0;
static int bpm = 120;

void init(void);
void update(void);
void draw(void);

int main(void) {
    irqInit();
    irqEnable(IRQ_VBLANK);

    init();

    while(1) {
        VBlankIntrWait();

        update();
        draw();
    }
    return 0;
}

void init(void) {
    REG_DISPCNT = MODE_3 | BG2_ON;

    sound_init();
    input_init();
    ui_init();

    bpm = 120;
    step = 0;
}

void update(void) {
    input_update();

    if (input_held(KEY_UP) && bpm < BPM_MAX) bpm++;
    if (input_held(KEY_DOWN) && bpm > BPM_MIN) bpm--;

    static int timer = 0;
    timer++;
    if (timer >= (60 * 59 / bpm)) {
        timer = 0;
        step = (step + 1) % STEPS;

        // Example sound trigger on step
        sound_play_step(step);
    }
}

void draw(void) {
    ui_draw(step, bpm);
}