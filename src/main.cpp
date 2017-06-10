#include "header.h"
#include "CApplication.h"
#include "CRenderer.h"
#include "CMainScence.h"
#include "CPlayScence.h"
#include "CButton.h"


int SDL_main(int argc, char *argv[])
{
	CApplication app;

	app.init(1248, 655, "mtSiniChi");
	//app.init(1215, 650, "mtSiniChi");
	//app.init(1344, 717, "mtSiniChi");

	app.setStartScene(new CPlayScence());

	app. run(50);

	app.teminate();

	return 0;
}
