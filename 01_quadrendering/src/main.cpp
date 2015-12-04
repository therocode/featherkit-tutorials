#include <fea/userinterface.hpp>
#include <fea/ui/sfmlwindowbackend.hpp>
#include <fea/ui/sfmlinputbackend.hpp>
#include <fea/render2d.hpp>
#include <SFML/Graphics/Image.hpp>

int main()
{
    sf::Window sfWindow;
    fea::Window window(new fea::SFMLWindowBackend(sfWindow), fea::VideoMode(800, 600, 32), "Window and user input");
    fea::InputHandler input(new fea::SFMLInputBackend(sfWindow));

    window.setFramerateLimit(60);

    fea::Renderer2D renderer(fea::Viewport({800, 600}, {0, 0}, fea::Camera({800.0f / 2.0f, 600.0f / 2.0f})));

    bool shutDown = false;

    sf::Image brickImage;
    brickImage.loadFromFile("./textures/brick.png");
    fea::Texture brickTexture;
    brickTexture.create({64, 64}, brickImage.getPixelsPtr());
    fea::Quad square({128.0f, 128.0f});
    square.setTexture(brickTexture);

    while(!shutDown)
    {
        fea::Event event;
        while(input.pollEvent(event))
        {
            if(event.type == fea::Event::CLOSED)
            {
                shutDown = true;
            }
            else if(event.type == fea::Event::KEYPRESSED)
            {
                if(event.key.code == fea::Keyboard::Q || event.key.code == fea::Keyboard::ESCAPE)
                {
                    shutDown = true;
                }
            }
        }

        renderer.clear();
        renderer.queue(square);
        renderer.render();
        window.swapBuffers();
    }
}
