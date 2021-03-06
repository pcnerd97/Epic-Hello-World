#include "Game.h"

namespace PCN {

    Game::Game()
    {
		Window win(SCRWIDTH, SCRHEIGHT, "Epic Hello World!");
		gameWindow = win.getWindow();
		Start();

		gameWindow->setFramerateLimit(60);

		while(gameWindow->isOpen()){
            Update();
        }
    }

    void Game::Start(void){
    
		
		if (!font.loadFromFile("data/fonts/OpenSans-Regular.ttf"))
		{
			printf("Could not load font!\n");
		}

		
		if (!texture.loadFromFile("data/textures/texture.jpeg"))
		{
			printf("Could not load texture!\n");
		}

		camera.reset(sf::FloatRect(0.f, 0.f, SCRWIDTH, SCRHEIGHT));
		gameWindow->setView(camera);
		
		gui.setTarget(*gameWindow);

		button = tgui::Button::create();
		button->setText("Mute Audio");
		button->setTextSize(32);

		button->onPress([&]{ 
			if(music.getVolume() == 0.0f){
				music.setVolume(100.0f);
				button->setText("Mute Audio");
			} else{
				music.setVolume(0.0f);
				button->setText("Unmute Audio");
			}
		});

		sprite.setTexture(texture);
		sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		sprite.setPosition(SCRWIDTH / 2, SCRHEIGHT / 2);
		
		text.setFont(font);
		text.setString("Hello world");
		text.setCharacterSize(50); 
		text.setFillColor(sf::Color::Red);
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(10);

		fpsText.setFont(font);
		fpsText.setString("Hello world");
		fpsText.setCharacterSize(50); 
		fpsText.setFillColor(sf::Color::Red);
		fpsText.setOutlineColor(sf::Color::Black);
		fpsText.setOutlineThickness(10);
		fpsText.setPosition(sf::Vector2f(10.f, 10.f));

		PlaySound();
	
	}

	void Game::OnButtonPress(void){
		gameWindow->close();
	}

    void Game::Update(void){
        sf::Event event;
        while (gameWindow->pollEvent(event))
        {

			gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                gameWindow->close();
        }

		if(color_change == i){
			color_change += 10;
			
			switch(current_color){

				case 0:
					text.setFillColor(sf::Color::Green);
					current_color = 1;
					//camera.zoom(0.5f);
					break;
				
				case 1:
					text.setFillColor(sf::Color::Blue);
					current_color = 2;
					//camera.zoom(0);
					break;

				case 2:
					text.setFillColor(sf::Color::Red);
					current_color = 3;
					//camera.zoom(0.5f);
					break;

				case 3:
					text.setFillColor(sf::Color::Magenta);
					current_color = 0;
					//camera.zoom(0);
					break;

			}

		}
		
		text.setString("You have looped: " + std::to_string(i) + " Times!");
		i++;

		//center text
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width/2.0f,
               		   textRect.top  + textRect.height/2.0f);
		text.setPosition(sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f));
		//text.setPosition(sf::Vector2f(gameWindow->getSize().x /2.0f, gameWindow->getSize().y /2.0f));

		sprite.rotate(2.0f);
		camera.rotate(-1.0f);

		gameWindow->setView(camera);
		gameWindow->clear(text.getFillColor());
		gameWindow->draw(sprite);
        gameWindow->draw(text);
		//gameWindow->draw(fpsText);

		gui.add(button);
		gui.draw();

        gameWindow->display();

		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / currentTime;
		lastTime = currentTime;

		gameWindow->setTitle("FPS: " + std::to_string(fps));

    }
    
	void Game::PlaySound(void){
		if (!music.openFromFile("data/audio/music.ogg")){
			printf("Could not load audio file!");
		}
		music.play();
	}
	
}

