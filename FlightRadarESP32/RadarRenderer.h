#pragma once
#include <Arduino.h>

void initDisplay();
void releaseDisplaySpriteForNetwork(const char *message);
void restoreDisplaySpriteAfterNetwork();
void drawStartupScreen(const char *message);
void updateDisplay();
void drawDisplayFrame();
