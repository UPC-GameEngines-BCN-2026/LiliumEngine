#pragma once

#include "ImGuiWindow.h"
#include "SDL3/SDL.h"
#include <vector>


class ConfigurationWindow : public ImGuiWindow
{
public:
	ConfigurationWindow(SDL_Window* window);
	void Update(float dt);

protected:
	void DrawContent() override;

private:
	SDL_Window* window;

	std::vector<float> fpsData;
	std::vector<float> msData;

	int maxFPS = 120;

	bool active = true;
	float brightness = 1.0f;
	int screenWidth = 1920;
	int screenHeight = 1080;
	int refreshRate = 60;
	bool fullscreen = false;
	bool resizable = true;
	bool borderless = false;
};

