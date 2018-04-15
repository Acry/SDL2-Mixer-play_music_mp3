//BEGIN PROGRAM HEAD
//BEGIN DESCRIPTION
/* SDL2-Mixer-play_music_mp3:
 * Plays mp3-music
 * left mouse button or space switches play and pause
 * right mouse button or backspace stops music (rewind to start)
 * 
 * The.madpix.project_-_Wish_You_Were_Here.mp3
 * check mp3-info for details
 */
//END   DESCRIPTION

//BEGIN INCLUDES
//local headers
#include "helper.h"
//END   INCLUDES

//BEGIN CPP DEFINITIONS
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
Mix_Music *Music 	= NULL;
//END   GLOBALS

//BEGIN FUNCTION PROTOTYPES
//END	FUNCTION PROTOTYPES

/* DEFINED PROGRESS GOALS
 * 
 * todo todo todo
 *
 */
//END 	PROGRAM HEAD

//BEGIN MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

//BEGIN INIT
init();
Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
Music=Mix_LoadMUS("./The.madpix.project_-_Wish_You_Were_Here.mp3");
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,540,540);
SDL_SetWindowTitle(Window, "SDL 2 - Play music");
SDL_ShowWindow(Window);
SDL_Event event;
int running = 1;
//END   INIT

//BEGIN Event Loop
while(running){
//BEGIN EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				if(!Mix_PlayingMusic()){
					Mix_PlayMusic(Music, -1);
				}
				else{
					if(Mix_PausedMusic()){
						Mix_ResumeMusic();
					}
					else{
						Mix_PauseMusic();
					}
				}
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				Mix_HaltMusic();
			}
		}
		if(event.type == SDL_KEYDOWN )
		{
			switch(event.key.keysym.sym ){
				case SDLK_ESCAPE:
					running = 0;
					break;
					
				case SDLK_BACKSPACE:
					Mix_HaltMusic();
					break;
					
				case SDLK_SPACE:
					if(!Mix_PlayingMusic()){
						Mix_PlayMusic(Music, -1);
					}
					else{
						if(Mix_PausedMusic()){
							Mix_ResumeMusic();
						}
						else{
							Mix_PauseMusic();
						}
					}
					break;
					
				default:
					break;
			}
		}
	}
//END   EVENT LOOP

//BEGIN RENDERING
SDL_Delay(66);//~15fps
SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 255);
SDL_RenderClear(Renderer);
SDL_RenderPresent(Renderer);
//END   RENDERING

}
//END   Event Loop
Mix_FreeMusic(Music);
Mix_CloseAudio();
exit_();
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
//END   FUNCTIONS
