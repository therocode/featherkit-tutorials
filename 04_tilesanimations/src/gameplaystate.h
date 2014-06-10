#include <fea/structure.hpp>
#include <fea/userinterface.hpp>
#include <fea/render2d.hpp>

class GameplayState : public fea::GameState
{
    public:
        GameplayState(fea::InputHandler& iH, fea::Renderer2D& r);
        void setup() override;
        std::string run() override;
    private:
        fea::InputHandler& input;
        fea::Renderer2D& renderer;

        fea::Texture tileTexture;
        fea::TileMap tiles;

        fea::Texture slimeTexture;
        fea::Animation slimeAnimation;
        fea::AnimatedQuad slime;
};
