#include <iostream>
#include "Game.h"
#include "SpriteLoader.h"



using namespace std;

int main(int argc, char** argv)
{
    SpriteLoader spriteLoader;
    Game activeGame(spriteLoader);
    int playerCount = 0;
  
    
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    /** Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        cerr << "Unable to init SDL: " << SDL_GetError() << endl;
        return 1;
    }
    
    // Close SDL at program end
    atexit(SDL_Quit);

    /** Create Window for Project */
    window = SDL_CreateWindow("Crazy Eights", 100, 100, 1200, 800, SDL_WINDOW_SHOWN);

    if (!window)
    {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return 1;
    }

    /** Create Renderer to draw to */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        return 1;
    }

    //default is set to create a game of 5 players. If playing the game with variable names and players, comment this section and uncomment the next one.
    activeGame.addPlayer("Alice");
    activeGame.addPlayer("Bruno");
    activeGame.addPlayer("Charlie");
    activeGame.addPlayer("David");
    activeGame.addPlayer("Ethan");


    /*while (playerCount == 0)
    {
        cout << "Please enter a number of players between 2 and 6" << endl;
        cin >> playerCount;
        if (playerCount < 2 || playerCount > 6)
        {
            cout << "Sorry, that's not the correct number of players, please try again" << endl;
            playerCount = 0;
        }
        else
        {
            cout << "What are the player's names?" << endl;
            for (int i = 0; i < playerCount; i++)
            {
                string playerName;
                cout << "please enter the name of player " << i + 1 << endl;
                cin >> playerName;
                activeGame.addPlayer(playerName);
            }
        }
    }
    */

    activeGame.playGame();
    
    /** Free SDL resources */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}
