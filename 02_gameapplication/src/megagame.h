#include <fea/structure.hpp>
#include <fea/userinterface.hpp>
#include <fea/ui/sfmlwindowbackend.hpp>
#include <fea/ui/sfmlinputbackend.hpp>
#include <fea/render2d.hpp>

class MegaGame : public fea::Application
{
    public:
        MegaGame();
    protected:
        void setup(const std::vector<std::string>& args) override;
        void loop() override;
        void destroy() override;
    private:
        sf::Window sfWindow;

        fea::Window window;
        fea::InputHandler input;

        fea::Renderer2D renderer;
        fea::Texture brickTexture;

        fea::Quad square;
};
