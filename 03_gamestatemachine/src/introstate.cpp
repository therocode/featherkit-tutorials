#include "introstate.h"
#include <SFML/Graphics/Image.hpp>

IntroState::IntroState(fea::InputHandler& iH, fea::Renderer2D& r) : input(iH), renderer(r), splashScreen({800.0f, 600.0f})
{
}

void IntroState::setup()
{
    sf::Image splashScreenImage;
    splashScreenImage.loadFromFile("./textures/intro.png");
    splashScreenTexture.create(800, 600, splashScreenImage.getPixelsPtr());
    splashScreen.setTexture(splashScreenTexture);
}

std::string IntroState::run()
{
    fea::Event event;
    while(input.pollEvent(event))
    {
        if(event.type == fea::Event::CLOSED)
        {
            return "NONE";
        }
        else if(event.type == fea::Event::KEYPRESSED)
        {
            if(event.key.code == fea::Keyboard::Q || event.key.code == fea::Keyboard::ESCAPE)
            {
                return "NONE";
            }
            if(event.key.code == fea::Keyboard::SPACE)
            {
                return "gameplay";
            }
        }
    }

    renderer.clear();
    renderer.queue(splashScreen);
    renderer.render();
    return "";
}
