// Copyright 2022 @geigeigeist
// SPDX-License-Identifier: GPL-2.0+
// here you find only RP2040 specific configurations

#pragma once

// ┌─────────────────────────────────────────────────┐
// │ a u d i o                                       │
// └─────────────────────────────────────────────────┘

#define AUDIO_PWM_DRIVER PWMD4
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#define AUDIO_STATE_TIMER GPTD4
