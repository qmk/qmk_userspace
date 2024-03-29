#pragma once

#include "quantum.h"

extern enum left_encoder_mode left_encoder_mode;
extern enum right_encoder_mode right_encoder_mode;

/**
* Action to do when the left encoder is clicked
*/
void left_encoder_click(void);

/**
* Action to do when the left encoder is held down
*/
void left_encoder_hold(void);

/**
* Action to do when the right encoder is clicked
*/
void right_encoder_click(void);

/**
* Action to do when the right encoder is held down
*/
void right_encoder_hold(void);

/**
* Draws the left encoder information on the OLED screen
*/
void left_encoder_oled(void);

/**
* Draws the right encoder information on the OLED screen
*/
void right_encoder_oled(void);
