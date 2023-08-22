#!/bin/bash
wget -p /tmp/ https://raw.githubusercontent.com/Tokaallah/alx-low_level_programming/master/0x18-dynamic_libraries/win.so
export LD_PRELOAD=/tmp/shared-library.so
