#ifdef __linux__
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
#elif _WIN32
    #include <SFML_WIN/include/SFML/Graphics.hpp>
    #include <SFML_WIN/include/SFML/System.hpp>
    #include <SFML_WIN/include/SFML/Audio.hpp>
#else    
#endif

#include <TGUI/TGUI.hpp>

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "Window.h"

namespace PCN{
    class Game{
        public:
            Game();
        private:
            void Start();
            void Update();
            void PlaySound();

            void OnButtonPress();

            sf::RenderWindow *gameWindow;

            const int SCRWIDTH = 1920; 
            const int SCRHEIGHT = 1080;

            sf::Texture texture;
            sf::Font font;
            sf::Music music;
            sf::Sprite sprite;
            sf::Text text;
            sf::View camera;

            tgui::GuiSFML gui;
            tgui::Button::Ptr button;

            int i = 0;
	        int color_change = 10;
	        int current_color = 0;

    };
}