#pragma once
#include "config_common.h"

// ┌─────────────────────────────────────────────────┐
// │ a u d i o                                       │
// └─────────────────────────────────────────────────┘

#define AUDIO_PWM_DRIVER PWMD4
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#define AUDIO_STATE_TIMER GPTD4
