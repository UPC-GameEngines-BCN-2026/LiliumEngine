#pragma once

#include "ImGuiWindow.h"

#include <vector>

class FPSWindow : public ImGuiWindow
{
public:
	FPSWindow();

	void Update(float dt);

	std::vector<float> fpsData;
	int maxFPS = 120;

protected:
	void DrawContent() override;
};