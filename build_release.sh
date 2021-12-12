#!/bin/bash

echo "Starting Build!"
echo "Compiling...."
g++  -c main.cpp 
g++  -c PCN/Game.cpp
g++  -c PCN/Window.cpp

echo "Linking...."
g++ -o main main.o Game.o Window.o -ltgui -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window

echo "Build Done! Launching."

./main