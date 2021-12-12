#!/bin/bash

echo "Starting Build!"
echo "Compiling...."
g++ -g -c main.cpp 
g++ -g -c PCN/Game.cpp
g++ -g -c PCN/Window.cpp

echo "Linking...."
g++ -g -o main_debug main.o Game.o Window.o -ltgui -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window

echo "Build Done! Launching."

konsole -e gdb -ex run ./main_debug