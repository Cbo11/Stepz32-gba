#include "ui.h"
#include <gba.h>
#include <stdio.h>

void ui_init(void) {
    // Clear screen
    for (int i = 0; i < 240*160; i++) {
        ((u16*)VRAM)[i] = RGB5(0,0,0);
    }
}

void ui_draw(int step, int bpm) {
    char buf[32];
    snprintf(buf, sizeof(buf), "Step: %d BPM: %d", step + 1, bpm);
    // Simple text draw at top-left (use Mode3 pixel draw for simplicity)
    // Draw background bar
    for (int i=0; i<240*8; i++) {
        ((u16*)VRAM)[i] = RGB5(10,10,10);
    }
    // Draw characters manually or integrate a font here (simplified)
    // For now, skipping full text rendering due to complexity
}