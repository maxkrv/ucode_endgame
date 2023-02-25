#include "header.h"

void handle_click(SDL_Event event, SDL_Rect rect, void (*callback)())
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        int x = event.button.x;
        int y = event.button.y;
        if (x >= rect.x && x < rect.x + rect.w && y >= rect.y && y < rect.y + rect.h)
        {
            // Call the callback function
            callback();
        }
    }
}


