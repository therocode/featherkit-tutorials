#include <fea/structure.hpp>
#include <fea/userinterface.hpp>
#include <fea/render2d.hpp>

class IntroState : public fea::GameState
{
    public:
        IntroState(fea::InputHandler& iH, fea::Renderer2D& r);
        void setup() override;
        std::string run() override;
    private:
        fea::InputHandler& input;
        fea::Renderer2D& renderer;

        fea::Texture splashScreenTexture;
        fea::Quad splashScreen;
};
