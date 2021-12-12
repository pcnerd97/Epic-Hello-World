#ifdef __linux__
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
#elif _WIN32
    #include "SFML_WIN/include/SFML/Graphics.hpp"
    #include "SFML_WIN/include/SFML/System.hpp"
#else 
#endif

#include <string>

namespace PCN{
    class Window{
        public:
            Window(int width, int height, std::string title);
            sf::RenderWindow *getWindow();
        private:
            sf::RenderWindow window;
    };
}