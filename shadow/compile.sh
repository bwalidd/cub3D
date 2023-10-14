#!/bin/bash

make re

if [ $? -eq 0 ]; then
    ./cub3D maps/map01.cub
else
    echo "Compilation failed."
fi