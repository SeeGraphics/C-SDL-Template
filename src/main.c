#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdbool.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

#define CHECK(expr, msg)                      \
    do                                        \
    {                                         \
        if (!(expr))                          \
        {                                     \
            fprintf(stderr,                   \
                    "CHECK failed: %s\n%s\n", \
                    #expr, msg);              \
            exit(EXIT_FAILURE);               \
        }                                     \
    } while (0)

#define CHECK_CLEANUP(expr, msg, ...)         \
    do                                        \
    {                                         \
        if (!(expr))                          \
        {                                     \
            fprintf(stderr,                   \
                    "CHECK failed: %s\n%s\n", \
                    #expr, msg);              \
            do                                \
            {                                 \
                __VA_ARGS__;                  \
            } while (0);                      \
            exit(EXIT_FAILURE);               \
        }                                     \
    } while (0)

int main(void)
{
    CHECK(SDL_Init(SDL_INIT_VIDEO) == 0, "Failed to initialize SDL.");
    SDL_Window *window = SDL_CreateWindow(
        "A: Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_RESIZABLE);

    CHECK_CLEANUP(window != NULL, "Failed to create window.", SDL_Quit());

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    CHECK_CLEANUP(renderer != NULL,
                  "Failed to create renderer.",
                  SDL_DestroyWindow(window);
                  SDL_Quit());

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

    
    CHECK_CLEANUP(texture != NULL, "Failed to create texture.", SDL_DestroyRenderer; SDL_DestroyWindow(window); SDL_Quit());

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
