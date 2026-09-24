#include "FPSWindow.h"

FPSWindow::FPSWindow() : ImGuiWindow("FPS"){}

void FPSWindow::Update(float dt)
{
	if (dt > 0.0f)
	{
		float fps = 1.0f / dt;

		fpsData.push_back(fps);

		if (fpsData.size() > 100)
		{
			fpsData.erase(fpsData.begin());
		}
	}
}

void FPSWindow::DrawContent()
{
	ImGui::Text("EnginishGL");
	ImGui::Text("UPC");

	ImGui::SliderInt("Max FPS", &maxFPS, 30, 240);

	if (!fpsData.empty())
	{
		ImGui::PlotHistogram(
			"FPS",
			fpsData.data(),
			static_cast<int>(fpsData.size()),
			0,
			nullptr,
			0.0f,
			static_cast<float>(maxFPS),
			ImVec2(310, 100)
		);

	}
}