#pragma once

#include "ImGuiWindow.h"
#include <vector>


class ConfigurationWindow : public ImGuiWindow
{
public:
	ConfigurationWindow();
	void Update(float dt);

protected:
	void DrawContent() override;

private:
	std::vector<float> fpsData;
	int maxFPS = 120;
};