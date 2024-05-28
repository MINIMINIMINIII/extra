#include <stdio.h>
#include <Windows.h>

enum Scene
{
	LOGO,
	MENU,
	STAGE,
	OPTION
};
Scene id;
struct Obj
{
	int x;
	int y;
	const char* shape;
};
Obj* arrowtext = nullptr;
Obj* starttext = nullptr;
Obj* optiontext = nullptr;
Obj* exittext = nullptr;

#pragma region LOGO
void LogoInitialize();
void LogoProgress();
void LogoRender();
#pragma endregion
#pragma region MENU
void MenuInitialize();
void MenuProgress();
void MenuRender();
void MenuRelease();
#pragma endregion
#pragma region STAGE

void StageInitialize();
void StageProgress();
void StageRender();
#pragma endregion
void OptionInitialize();
#pragma region WinAPI
void MoveCursorPosition(int x, int y);
#pragma endregion
int index = 0;
const char* stageimg[10];
int main()
{
	id = LOGO;
	LogoInitialize();
	
	while (true)
	{
		system("cls");
		switch (id)
		{
		case LOGO:
			LogoProgress();
			LogoRender();
			break;
		case MENU:
			MenuProgress();
			MenuRender();
			break;
		case STAGE:
			StageProgress();
			StageRender();
			break;
		default:
			break;
		}

		Sleep(50);
	}

	return 0;
}

void LogoInitialize()
{
	printf("이세계 음악인이 어쩌다가 코딩의 노예가 되었다??\n");
}
void LogoProgress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		id = MENU;
		MenuInitialize();
	}
}
void LogoRender()
{
	MoveCursorPosition(7, 7);
	printf("이세계 노예가 된 썰 푸는 게임\n");
	MoveCursorPosition(7, 8);
	printf("시작하시려면 Enter를 눌러주세요");
}
void MenuInitialize()
{
	printf("대충 MENU 창인데 상태창! 하고 외치면 이창이 뜸 ㅋㅋ\n");
	
	arrowtext = (Obj*)malloc(sizeof(Obj));
	arrowtext->x = 10;
	arrowtext->y = 20;
	arrowtext->shape = "▶";
	
	starttext = (Obj*)malloc(sizeof(Obj));
	starttext->x = 14;
	starttext->y = 22;
	starttext->shape = "START";
	
	optiontext = (Obj*)malloc(sizeof(Obj));
	optiontext->x = 14;
	optiontext->y = 24;
	optiontext->shape = "OPTION";
	
	exittext = (Obj*)malloc(sizeof(Obj));
	exittext->x = 14;
	exittext->y = 26;
	exittext->shape = "EXIT";

}
void MenuProgress()
{
	
	if (GetAsyncKeyState(VK_UP))
	{
		if (arrowtext->y >starttext->y)
		{
			arrowtext->y -= 2;
			
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if(arrowtext->y<exittext->y)
		arrowtext->y += 2;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (arrowtext->y == starttext->y)
		{
			id = STAGE;
			StageInitialize();
		}
		if (arrowtext->y == optiontext->y)
		{
			id = OPTION;
			OptionInitialize();
		}
		if (arrowtext->y == exittext->y)
		{
			exit(0);
		}
	}
	
}
void MenuRender()
{
	MoveCursorPosition(10, 10);
	printf("대충 MENU 창 ㅋㅋ\n");
	MoveCursorPosition(arrowtext->x	,arrowtext->y);
	printf(arrowtext->shape);
	MoveCursorPosition(starttext->x, starttext->y);
	printf(starttext->shape);
	MoveCursorPosition(optiontext->x, optiontext->y);
	printf(optiontext->shape);
	MoveCursorPosition(exittext->x, exittext->y);
	printf(exittext->shape);
}
void MenuRelease()
{
	if (arrowtext != nullptr)
	{
		free(arrowtext);
		arrowtext = nullptr;
	}

	if (starttext != nullptr)
	{
		free(starttext);
		starttext = nullptr;
	}

	if (optiontext != nullptr)
	{
		free(optiontext);
		optiontext = nullptr;
	}

	if (exittext != nullptr)
	{
		free(exittext);
		exittext = nullptr;
	}

}
void StageInitialize()
{
	MenuRelease();
	stageimg[0] = "■■■■■■■■■■■"  ;
	stageimg[1] = "■□□□□□□□□□■"  ;
	stageimg[2] = "■□□□□□□□□□■"  ;
	stageimg[3] = "■□□□□□□□□□■"  ;
	stageimg[4] = "■□□□□□□□□□■"  ;
	stageimg[5] = "■□□□□□□□□□■"  ;
	stageimg[6] = "■□□□□□□□□□■"  ;
	stageimg[7] = "■□□□□□□□□□■"  ;
	stageimg[8] = "■□□□□□□□□□■"  ;
	stageimg[9] = "■■■■■■■■■■■"  ;
		

}
void StageProgress()
{

}
void StageRender()
{
	for (int i = 0; i < 10; i++)
	{
		MoveCursorPosition(10, 10);
		printf(stageimg[i]);
	}
}
void MoveCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void OptionInitialize()
{
	printf("Option Initialize\n");
}