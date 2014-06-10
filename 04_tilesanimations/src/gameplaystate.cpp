#include "gameplaystate.h"
#include <SFML/Graphics/Image.hpp>

GameplayState::GameplayState(fea::InputHandler& iH, fea::Renderer2D& r) : input(iH), renderer(r), tiles(20, 20, 128, 128, 0.5f, 0.5f), slime({112.0f, 72.0f})
{
}

enum TileType { BACKGROUND, BRICK, LANTERN1, LANTERN2 };

void GameplayState::setup()
{
    sf::Image tilesImage;
    tilesImage.loadFromFile("./textures/tiles.png");
    tileTexture.create(128, 128, tilesImage.getPixelsPtr());
    tiles.setTexture(tileTexture);

    tiles.addTileDefinition(BACKGROUND, fea::TileDefinition(glm::uvec2(0, 0)));
    tiles.addTileDefinition(BRICK, fea::TileDefinition(glm::uvec2(1, 0)));
    tiles.addTileDefinition(LANTERN1, fea::TileDefinition(glm::uvec2(0, 1), LANTERN2, 20));
    tiles.addTileDefinition(LANTERN2, fea::TileDefinition(glm::uvec2(1, 1), LANTERN1, 20));

    tiles.fill(BACKGROUND);
    tiles.setTile({0, 3}, BRICK);
    tiles.setTile({1, 3}, BRICK);
    tiles.setTile({2, 3}, BRICK);
    tiles.setTile({3, 3}, BRICK);
    tiles.setTile({4, 3}, BRICK);
    tiles.setTile({5, 3}, BRICK);
    tiles.setTile({6, 3}, BRICK);
    tiles.setTile({0, 4}, BRICK);
    tiles.setTile({1, 4}, BRICK);
    tiles.setTile({2, 4}, BRICK);
    tiles.setTile({3, 4}, BRICK);
    tiles.setTile({4, 4}, BRICK);
    tiles.setTile({5, 4}, BRICK);
    tiles.setTile({6, 4}, BRICK);
    tiles.setTile({1, 2}, LANTERN1);
    tiles.setTile({4, 2}, LANTERN1);

    sf::Image slimeImage;
    slimeImage.loadFromFile("./textures/slime.png");
    slimeTexture.create(112, 18, slimeImage.getPixelsPtr());
    slime.setTexture(slimeTexture);

    slimeAnimation = fea::Animation(glm::vec2(0.0f, 0.0f), glm::vec2(28.0f / 112.0f, 18.0f / 18.0f), 4, 8);
    slime.setTexture(slimeTexture);
    slime.setAnimation(slimeAnimation);
    slime.setPosition({320.0f, 312.0f});
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

    for(auto& chunk : tiles.getTileChunks())
        renderer.queue(*chunk);

    renderer.queue(slime);

    renderer.render();

    tiles.tick();
    slime.tick();

    return "";
}
