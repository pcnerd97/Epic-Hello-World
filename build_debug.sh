#!/bin/bash

echo "Starting Build!"
echo "Compiling...."
g++ -g -c src/main.cpp 
g++ -g -c src/PCN/Game.cpp
g++ -g -c src/PCN/Window.cpp

echo "Linking...."
g++ -g -o main_debug main.o Game.o Window.o -ltgui -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window

echo "Clean Up...."
rm ./Game.o
rm ./Window.o
rm ./main.o

echo "Build Done! Launching."

mkdir -p ./bin
mv ./main_debug ./bin/main_debug

konsole -e gdb -ex run ./bin/main_debug