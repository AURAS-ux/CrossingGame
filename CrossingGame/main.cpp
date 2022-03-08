#include"Game.h"

int main()
{
    Game* game=new Game();
	while (game->isRunning())
	{
		game->update();
	}
    return 0;
}