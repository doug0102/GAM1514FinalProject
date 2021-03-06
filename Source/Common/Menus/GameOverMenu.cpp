#include "GameOverMenu.h"
#include "../Screen Manager/ScreenManager.h"
#include "../OpenGL/OpenGL.h"

GameOverMenu::GameOverMenu() : Menu(NULL, NULL)
{
	addButton(new UIButton("ButtonReset"));
	addButton(new UIButton("ButtonMainMenu"));	
	addButton(new UIButton("ButtonLoadLevel"));
	addButton(new UIButton("ButtonExit"));

	m_Background = new OpenGLTexture("LoseBG");
}

GameOverMenu::~GameOverMenu()
{
	// texture and buttons are deleted by Menu's deconstructor
}

const char* GameOverMenu::getName()
{
	return GAME_OVER_SCREEN_NAME;
}

void GameOverMenu::buttonAction(UIButton* button)
{
	switch(getIndexForButton(button))
	{
	case 0:
		// Reset the level
		ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME)->keyUpEvent(KEYCODE_ESCAPE);

		// Switch to the game screen
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
		break;
	case 1:
		// Go to main menu screen
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
		break;
	case 2:
		// Go to the load screen 
		ScreenManager::getInstance()->switchScreen(LOAD_MENU_SCREEN_NAME);
		break;
	case 3:
		// Exit the game
		exit(1);
		break;
	}
}