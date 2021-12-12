#include "Window.h"

namespace PCN{

    Window::Window(int width, int height, std::string title){
        window.create(sf::VideoMode(width, height), title);
    }

    sf::RenderWindow * Window::getWindow(){
        return &window;
    }
}