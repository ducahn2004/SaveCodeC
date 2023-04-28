#include <bits/stdc++.h>
#include <SDL.h>
#include <string>

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_1,
	KEY_PRESS_SURFACE_2,
	KEY_PRESS_SURFACE_3,
	KEY_PRESS_SURFACE_4,
	KEY_PRESS_SURFACE_TOTAL,
    WIDTH = 0,
    HEIGHT = 1
};
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;
//Loads individual image
SDL_Surface* loadSurface( std::string path );

// SOURCE PIXEL IMAGE 


// CREAT WINDOW
bool init(int SCREEN_WIDTH, int SCREEN_HEIGHT,const char *strHeader);
bool loadMedia();
void close();
std::vector<std::vector<int>> source_size_image();
int main(int argc , char* args[]){
    
	std::vector<std::vector<int>>source = source_size_image();
	int SCREEN_WIDTH  = source[ KEY_PRESS_SURFACE_DEFAULT ][ WIDTH ];
    int SCREEN_HEIGHT = source[ KEY_PRESS_SURFACE_DEFAULT ][ HEIGHT ];
	if(!init(SCREEN_WIDTH,SCREEN_HEIGHT,"IMAGE")){
		printf("Fail to create a window surface \n");
	}
	else{
		//load media
		if( !loadMedia() ){
			printf("Failed to load media\n");
		}
		else{

			//Main loop 
			bool quit = false;
			SDL_Event e;
			gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

			//while application is running
			while( !quit ){
				//Handle events on queue
				while(SDL_PollEvent( &e) != 0){
					// user requests quit
					if(e.type == SDL_QUIT){
						quit == true;
					}
					else if(e.type == SDL_KEYDOWN){
						switch (e.key.keysym.sym)
						{
						case SDLK_1:
							SCREEN_WIDTH = source[KEY_PRESS_SURFACE_1][WIDTH];
							SCREEN_HEIGHT = source[KEY_PRESS_SURFACE_1][HEIGHT];
							SDL_SetWindowSize(gWindow,SCREEN_WIDTH,SCREEN_HEIGHT);
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_1 ];
							break;
						

						case SDLK_2:
							SCREEN_WIDTH = source[KEY_PRESS_SURFACE_2][WIDTH];
							SCREEN_HEIGHT = source[KEY_PRESS_SURFACE_2][HEIGHT];
							SDL_SetWindowSize(gWindow,SCREEN_WIDTH,SCREEN_HEIGHT);
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_2 ];
							break;
						
						case SDLK_3:
							SCREEN_WIDTH = source[KEY_PRESS_SURFACE_3][WIDTH];
							SCREEN_HEIGHT = source[KEY_PRESS_SURFACE_3][HEIGHT];
							SDL_SetWindowSize(gWindow,SCREEN_WIDTH,SCREEN_HEIGHT);
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_3 ];
							break;
						

						case SDLK_4:
							SCREEN_WIDTH = source[KEY_PRESS_SURFACE_4][WIDTH];
							SCREEN_HEIGHT = source[KEY_PRESS_SURFACE_4][HEIGHT];
							SDL_SetWindowSize(gWindow,SCREEN_WIDTH,SCREEN_HEIGHT);
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_4 ];
							break;
					
							
						default:
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
							break;
						}
					}
				}
				// Apply the current image 
				SDL_BlitSurface(gCurrentSurface, NULL , gScreenSurface , NULL);

				//Update the surface 
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	//Free resources and close SDL
	close();
	return 0;

}

SDL_Surface* loadSurface( std::string path )
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}

	return loadedSurface;
}

bool init(int SCREEN_WIDTH, int SCREEN_HEIGHT ,const char *strHeader ){
    //initialization flag 
    bool success = true; // auto run 

    // initialize SDl
    if(SDL_Init(SDL_INIT_VIDEO < 0)){
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false; 
    }
    else{

        //Create window
        gWindow = SDL_CreateWindow(strHeader,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH ,SCREEN_HEIGHT ,SDL_WINDOWEVENT_SHOWN);
		if(gWindow == NULL){
			printf("Window could not be created! SDL ERROR : %s\n",SDL_GetError);
			success = false;
		}
		else{
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
    }

	return success;
}
bool loadMedia(){
	
	//Loading success flag 
	bool success = true;

	// load defaut surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT] = loadSurface("image\\0.bmp");
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT] == NULL){
		printf("Failed to load defaut image\n" );
		success = false;
	}

	// Load 1 image 
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_1] = loadSurface("image\\1.bmp");
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_1] == NULL){
		printf("Failed to load image 1\n" );
		success = false;
	}

	//load 2 image
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_2] = loadSurface("image\\2.bmp");
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_2] == NULL){
		printf("Failed to load image 2\n" );
		success = false;
	}

	//load 3 image 
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_3] = loadSurface("image\\3.bmp");
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_3] == NULL){
		printf("Failed to load image 3\n" );
		success = false;
	}

	//load 4 image
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_4] = loadSurface("image\\4.bmp");
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_4] == NULL){
		printf("Failed to load image 4\n" );
		success = false;
	}
	
	return success;

}
//source pixel image 
std::vector<std::vector<int>> source_size_image(){
    std::vector<std::vector<int>>source;
    // [][0] = WIDTH [][1] = HEIGHT
    //image 0
    source[KEY_PRESS_SURFACE_DEFAULT][WIDTH] = 2048;
    source[KEY_PRESS_SURFACE_DEFAULT][HEIGHT] = 2048;

    //image 1
    source[KEY_PRESS_SURFACE_1][WIDTH] = 512;
    source[KEY_PRESS_SURFACE_1][HEIGHT] = 512;

    //image 2
    source[KEY_PRESS_SURFACE_2][WIDTH] = 550;
    source[KEY_PRESS_SURFACE_2][HEIGHT] = 309;

    //image 3
    source[KEY_PRESS_SURFACE_3][WIDTH] = 2048;
    source[KEY_PRESS_SURFACE_3][HEIGHT] = 2048;

    //image 4
    source[KEY_PRESS_SURFACE_4][WIDTH] = 720;
    source[KEY_PRESS_SURFACE_4][HEIGHT] = 405;
 
    return source;
}

void close()
{
	//Deallocate surfaces
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
	{
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
