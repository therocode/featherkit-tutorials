#include <fea/userinterface.hpp>
#include <fea/ui/sfmlwindowbackend.hpp>
#include <fea/ui/sfmlinputbackend.hpp>

int main()
{
    sf::Window sfWindow;
    fea::Window window(new fea::SFMLWindowBackend(sfWindow));
    fea::InputHandler input(new fea::SFMLInputBackend(sfWindow));

    window.create(fea::VideoMode(800, 600, 32), "Window and user input");
    bool shutDown = false;

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
    }
    window.close();
}
