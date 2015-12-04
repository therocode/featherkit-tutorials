#include "megagame.h"
#include "gameplaystate.h"
#include "introstate.h"

MegaGame::MegaGame() : window(new fea::SFMLWindowBackend(sfWindow), fea::VideoMode(800, 600, 32), "Window and user input"), 
                       input(new fea::SFMLInputBackend(sfWindow)), 
                       renderer(fea::Viewport({800, 600}, {0, 0}, fea::Camera({800.0f / 2.0f, 600.0f / 2.0f})))
{
}

void MegaGame::setup(const std::vector<std::string>& args)
{
    (void)args;
    window.setFramerateLimit(60);

    stateMachine.addGameState("gameplay", std::unique_ptr<GameplayState>(new GameplayState(input, renderer)));

    stateMachine.addGameState("intro", std::unique_ptr<IntroState>(new IntroState(input, renderer)));
    stateMachine.setCurrentState("intro");
}

void MegaGame::loop()
{
    stateMachine.run();

    window.swapBuffers();

    if(stateMachine.isFinished())
        quit();
}
