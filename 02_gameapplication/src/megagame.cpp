#include "megagame.h"
#include <SFML/Graphics/Image.hpp>

MegaGame::MegaGame() : window(new fea::SFMLWindowBackend(sfWindow), fea::VideoMode(800, 600, 32), "Window and user input"), 
                       input(new fea::SFMLInputBackend(sfWindow)), 
                       renderer(fea::Viewport({800, 600}, {0, 0}, fea::Camera({800.0f / 2.0f, 600.0f / 2.0f}))), 
                       square({128.0f, 128.0f})
{
}

void MegaGame::setup(const std::vector<std::string>& args)
{
    (void)args;
    window.setFramerateLimit(60);

    sf::Image brickImage;
    brickImage.loadFromFile("textures/brick.png");
    brickTexture.create({64, 64}, brickImage.getPixelsPtr());

    square.setTexture(brickTexture);
}

void MegaGame::loop()
{
    fea::Event event;
    while(input.pollEvent(event))
    {
        if(event.type == fea::Event::CLOSED)
        {
            quit();
        }
        else if(event.type == fea::Event::KEYPRESSED)
        {
            if(event.key.code == fea::Keyboard::Q || event.key.code == fea::Keyboard::ESCAPE)
            {
                quit();
            }
        }
    }

    renderer.clear();
    renderer.queue(square);
    renderer.render();
    window.swapBuffers();
}
