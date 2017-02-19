/**
 * v65.c - Moto Guzzi instrumentbord
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#define WINDOW_WIDTH (128)
#define WINDOW_HEIGHT (160)


int main(void)
{
	SDL_Surface *surface1, *surface2, *surface3, *surface4, *surface5;
	SDL_Texture *tex1, *tex2, *tex3, *tex4, *tex5;
	
	int up1 = 0;
	int up2 = 0;
	int up3 = 0;
	int up4 = 0;
	int up5 = 0;
	int up6 = 0;
	int up7 = 0;
	int  ON = 1;
	int OFF = 0;
    // attempt to initialize graphics and timer system
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello, CS50!",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_BORDERLESS);
    if (!win)
    {
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
	    return 1;
    }

    // create a renderer, which sets up the graphics hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend)
    {
        printf("error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // load the image into memory using SDL_image library function
    
    surface1 = SDL_LoadBMP ("/home/pi/v65/sortlys3.bmp");
    
   
     //surface2 = SDL_LoadBMP ("/home/pi/projects/v65/sortlys3.bmp");
    if (!surface1)
    {
        printf("error creating surface\n");
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // load the image data into the graphics hardware's memory
     tex1 = SDL_CreateTextureFromSurface(rend, surface1);
     //tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface1);
    //SDL_FreeSurface(surface2);
    if (!tex1)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // struct to hold the position and size of the sprite
    SDL_Rect dest1, dest2, dest3, dest4, dest5;

    // get and scale the dimensions of texture
    SDL_QueryTexture(tex1, NULL, NULL, &dest1.w, &dest1.h);  //
    SDL_QueryTexture(tex2, NULL, NULL, &dest2.w, &dest2.h);  //
    SDL_QueryTexture(tex3, NULL, NULL, &dest3.w, &dest3.h);  //
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);  //
    SDL_QueryTexture(tex5, NULL, NULL, &dest5.w, &dest5.h);  //
    dest1.w = 64;                                           //   størelse på rectangel
    dest1.h = 53;                                          //
    dest2.w = 64;                                           //   størelse på rectangel
    dest2.h = 53;  
    dest3.w = 64;                                           //   størelse på rectangel
    dest3.h = 53;  
    dest4.w = 64;
    dest4.h = 53;
    dest5.w = 128;
    dest5.h = 54;                                         //

    

    // set to 1 when window close button is pressed
    int close_requested = 0;
    
    // animation loop
    while (!close_requested)
    {
        // process events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                close_requested = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_L:
                
                    up1 = 1;
                    up2 = 0;
                    break;
                case SDL_SCANCODE_K:
                
                    up2 = 1;
                    up1 = 0;
                    break;
                case SDL_SCANCODE_B:
               
                    up3 = 1;
                    break;    
                  case SDL_SCANCODE_O:
               
                    up4 = 1;
                    break;
                  case SDL_SCANCODE_N:
               
                    up5 = 1;
                    break;        
                         
                     case SDL_SCANCODE_V:
                
                    up6 = 1;
                    up7 = 0;
                    break;
                case SDL_SCANCODE_H:
                
                    up7 = 1;
                    up6 = 0;
                    break;
              
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_K:
                
                    up1 = 0;
                    up2 = 0;
                    break;  
                case SDL_SCANCODE_L:
               
                    up2 = 0;
                    up1 = 0;
           
                    break;
                case SDL_SCANCODE_B:
               
                    up3 = 0;
                    break;
                case SDL_SCANCODE_O:
               
                    up4 = 0;
                    break; 
                case SDL_SCANCODE_N:
               
                    up5 = 0;
                    break;    
                case SDL_SCANCODE_V:
                
                    up6 = 0;
                    up7 = 0;
                    break;
                case SDL_SCANCODE_H:
                
                    up7 = 0;
                    up6 = 0;
                    break; 
                }
                break;
            }
   
        }

        // determine velocity
    

        // set the positions in the struct            //
                 if (up2 == ON && up1 == OFF)
    {
		surface1 = SDL_LoadBMP ("/home/pi/v65/kortlys3.bmp");
		 tex1 = SDL_CreateTextureFromSurface(rend, surface1);
         SDL_FreeSurface(surface1);
         
	}
	             if (up1 == ON && up2 == OFF)
    {
		surface1 = SDL_LoadBMP ("/home/pi/v65/langlys3.bmp");
		 tex1 = SDL_CreateTextureFromSurface(rend, surface1);
         SDL_FreeSurface(surface1);
         				
	}
	               if (up2 == OFF && up1 == OFF)
    {
		surface1 = SDL_LoadBMP ("/home/pi/v65/sortlys3.bmp");
		 tex1 = SDL_CreateTextureFromSurface(rend, surface1);
         SDL_FreeSurface(surface1);
         
         
      
	}
	
	              if (up3 == ON)
    {
		surface2 = SDL_LoadBMP ("/home/pi/v65/battei3.bmp");
		 tex2 = SDL_CreateTextureFromSurface(rend, surface2);
         SDL_FreeSurface(surface2);
        
	 }
	               if (up3 == OFF)
    {
		surface2 = SDL_LoadBMP ("/home/pi/v65/sortlys3.bmp");
		 tex2 = SDL_CreateTextureFromSurface(rend, surface2);
         SDL_FreeSurface(surface2);
         
	 }
	                   if (up4 == ON)
    {
		surface3 = SDL_LoadBMP ("/home/pi/v65/olie.bmp");
		 tex3 = SDL_CreateTextureFromSurface(rend, surface3);
         SDL_FreeSurface(surface3);
         
	 }
	               if (up4 == OFF)
    {
		surface3 = SDL_LoadBMP ("/home/pi/v65/sortlys3.bmp");
		 tex3 = SDL_CreateTextureFromSurface(rend, surface3);
         SDL_FreeSurface(surface3);   
    }            
	                if (up5 == ON)
    {
		surface4 = SDL_LoadBMP ("/home/pi/v65/neutrallys3.bmp");
		 tex4 = SDL_CreateTextureFromSurface(rend, surface4);
         SDL_FreeSurface(surface4);
        
    }
	               if (up5 == OFF)
    {
		surface4 = SDL_LoadBMP ("/home/pi/v65/sortlys3.bmp");
		 tex4 = SDL_CreateTextureFromSurface(rend, surface4);
         SDL_FreeSurface(surface4);   
         
    }            
	                if (up6 == ON && up7 == OFF)
    {
		surface5 = SDL_LoadBMP ("/home/pi/v65/venstre.bmp");
		 tex5 = SDL_CreateTextureFromSurface(rend, surface5);
         SDL_FreeSurface(surface5);
         
	}
	             if (up7 == ON && up6 == OFF)
    {
		surface5 = SDL_LoadBMP ("/home/pi/v65/højre.bmp");
		 tex5 = SDL_CreateTextureFromSurface(rend, surface1);
         SDL_FreeSurface(surface5);
         
	}
	               if (up6 == OFF && up7 == OFF)
    {
		surface5 = SDL_LoadBMP ("/home/pi/v65/sortlys3.bmp");
		 tex5 = SDL_CreateTextureFromSurface(rend, surface5);
         SDL_FreeSurface(surface1);
        
      
	}
	
		 
        dest1.y = 0;//(int) y_pos;                     //
        dest1.x = 0;//(int) x_pos;                    //
        dest2.y = 0;//(int) y_pos;                     //
        dest2.x = 65;//(int) x_pos;                    //
        dest3.y = 54;//(int) y_pos;                     //
        dest3.x = 0;//(int) x_pos;                    //
        dest4.y = 54;//(int) y_pos;                     //
        dest4.x = 65;//(int) x_pos;                    //
        dest5.y = 107;
        dest5.x = 0;
                                                      //
        // clear the window                           // 
        SDL_RenderClear(rend);                        //  Position på skærmen
                                                      //
        // draw the image to the window               // 
        SDL_RenderCopy(rend, tex1, NULL, &dest1);      // 
        SDL_RenderCopy(rend, tex2, NULL, &dest2);      // 
        SDL_RenderCopy(rend, tex3, NULL, &dest3);      // 
        SDL_RenderCopy(rend, tex4, NULL, &dest4);      // 
        SDL_RenderCopy(rend, tex5, NULL, &dest5);      // 
        SDL_RenderPresent(rend);                      //
                                                  
        // wait 1/60th of a second
        SDL_Delay(1000/60);
    }
    
    // clean up resources before exiting
    SDL_DestroyTexture(tex1);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
