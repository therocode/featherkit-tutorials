#include "gameplaystate.h"
#include <SFML/Graphics/Image.hpp>

GameplayState::GameplayState(fea::InputHandler& iH, fea::Renderer2D& r) : input(iH), renderer(r), square({128.0f, 128.0f})
{
}

void GameplayState::setup()
{
    sf::Image brickImage;
    brickImage.loadFromFile("./textures/brick.png");
    brickTexture.create(64, 64, brickImage.getPixelsPtr());
    square.setTexture(brickTexture);
}

std::string GameplayState::run()
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
        }
    }

    renderer.clear();
    renderer.queue(square);
    renderer.render();
    return "";
}
