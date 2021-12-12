#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
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