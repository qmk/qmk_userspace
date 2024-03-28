#pragma once

#include "quantum.h"

extern enum left_encoder_mode left_encoder_mode;
extern enum right_encoder_mode right_encoder_mode;

void left_encoder_click(void);

void left_encoder_hold(void);

void right_encoder_click(void);

void right_encoder_hold(void);

void left_encoder_oled(void);

void right_encoder_oled(void);
