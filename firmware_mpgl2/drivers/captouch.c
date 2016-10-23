/***********************************************************************************************************************
File: captouch.c

Description:
Driver for Capacitive Touch sensors. This code supports the horizontal slider on the MPG2 board
and any future buttons/sliders that may be added.

Restarted by Alex Mildenberger
October 23, 2016

#include "configuration.h"
#include "libqtouch.h"


#define GET_SENSOR_STATE(SENSOR_NUMBER) (qt_measure_data.qt_touch_status.sensor_states[(SENSOR_NUMBER/8)] & (1 << (SENSOR_NUMBER % 8)))
#define GET_ROTOR_SLIDER_POSITION(ROTOR_SLIDER_NUMBER) qt_measure_data.qt_touch_status.rotor_slider_values[ROTOR_SLIDER_NUMBER]
