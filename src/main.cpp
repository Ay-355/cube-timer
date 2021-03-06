#include <iostream>
#include "SDL.h" 



int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow(
        "Rubik's Cube Timer",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);


    // initial vars
    bool running = true;
    bool timerStarted = false;
    bool primed = false;

    SDL_Event evnt;

    while (running)
    {
        while (SDL_PollEvent(&evnt))
        {
            
            if (evnt.type == SDL_QUIT)
            {
                running = false;
                break;
            }
            else if (evnt.type == SDL_KEYDOWN)
            {
                switch (evnt.key.keysym.sym) // if key pressed down, then check what key it is
                {
                case SDLK_SPACE: // if its space then I have to see if I need to start the timer
                    if (primed == false && timerStarted == false && evnt.key.repeat == 0)
                    {
                        std::cout << "Timer primed" << std::endl;
                        //prime timer to start, which will make primed true
                        primed = true;
                        timerStarted = false;
                        break;
                    }
                    else if (timerStarted == true && primed == false && evnt.key.repeat == 0)
                    {
                        std::cout << "Timer ended" << std::endl;
                        //end timer because it has already been started
                        timerStarted = false;
                        primed = false;
                        break;
                    }
                    else if (primed == true)
                    {
                        // this is prob useless, will see later; just a safety measure, don't care if they press space while priming
                        break;
                    }

                default:
                    // if it wasn't a space key then another key has been pressed, check if timer is running or not
                    // I only care if the timer has been started because we want to end it, if the timer has not been started and it was NOT the space key that was pressed, I don't care
                    if (timerStarted == true && evnt.key.keysym.sym != SDLK_SPACE && primed == false && evnt.key.repeat == 0)
                    {
                        std::cout << "Timer ended" << std::endl;
                        timerStarted = false;
                        primed = false;
                        //end timer and show results
                        break;
                    }
                    else if (timerStarted == false || primed == false)
                    {
                        // don't care if the timer hasn't started, press whatever keys you want
                        //might change this later if I add more things/functionality
                        break;
                    }

                    else if (primed = true)
                    {
                        // this is prob useless, I might remove later; don't care if pressing other keys while space is down
                        break;
                    }
                }

            }
            else if (evnt.type == SDL_KEYUP)
            {
                if (evnt.key.repeat == 0 && evnt.key.keysym.sym != SDLK_SPACE)
                {
                    // idk if I need this, what works works so don't touch
                    break;
                }
                else if (evnt.key.repeat == 0 && timerStarted == false && primed == true && evnt.key.keysym.sym == SDLK_SPACE) // if the timer HASNT started yet and its been primed, then start it
                {
                    //start the timer if there is one running
                    std::cout << "Primed off, Timer started" << std::endl;
                    primed = false;
                    timerStarted = true;
                    break;
                }
            }
            
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
