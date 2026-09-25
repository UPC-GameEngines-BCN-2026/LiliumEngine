#include "ConfigurationWindow.h"

ConfigurationWindow::ConfigurationWindow(SDL_Window* window) : ImGuiWindow("Configuration") {
	this->window = window;
}

void ConfigurationWindow::Update(float dt)
{
	if (dt > 0.0f)
	{
		float fps = 1.0f / dt;
		float ms = dt * 1000.0f;

		fpsData.push_back(fps);
		msData.push_back(ms);

		if (maxFPS > 0)
		{
			float targetMS = 1000.0f / maxFPS;

			if (ms < targetMS)
			{
				SDL_Delay(static_cast<Uint32>(targetMS - ms));
			}
		}

		if (fpsData.size() > 100)
		{
			fpsData.erase(fpsData.begin());
		}

		if (msData.size() > 100)
		{
			msData.erase(msData.begin());
		}
	}
}


void ConfigurationWindow::DrawContent()
{
	ImGui::Text("Options");

	if (ImGui::CollapsingHeader("Application"))
	{
		ImGui::Text("LiliumEngine");
		ImGui::Text("UPC CITM");

		ImGui::SliderInt("Max FPS", &maxFPS, 0, 120);
		if (!fpsData.empty())
		{
			char title[25];
			sprintf_s(title, 25, "Framerate %.1f", fpsData[fpsData.size() - 1]);
			ImGui::PlotHistogram("##framerate", &fpsData[0], fpsData.size(), 0, title, 0.0f, 100.0f, ImVec2(310, 100));
		}
		if (!msData.empty())
		{
			char title[25];
			sprintf_s(title, 25, "Milliseconds %.1f", msData[msData.size() - 1]);
			ImGui::PlotHistogram("##milliseconds", &msData[0], msData.size(), 0, title, 0.0f, 40.0f, ImVec2(310, 100));
		}


		ImGui::SeparatorText("General Info");

		if (ImGui::TreeNode("Testing"))
		{



			ImGui::TreePop();
		}

	}

	if (ImGui::CollapsingHeader("Window"))
	{
		ImGui::Text("Window options");
		ImGui::SliderInt("Width", &screenWidth, 720, 1920);
		ImGui::SliderInt("Height", &screenHeight, 720, 1080);

		SDL_SetWindowSize(window, screenWidth, screenHeight);

		ImGui::SliderFloat("Brightness", &brightness, 0, 1);

		ImGui::Checkbox("Fullscreen", &fullscreen);
		SDL_SetWindowFullscreen(window, fullscreen);

		ImGui::Checkbox("Resizable", &resizable);
		SDL_SetWindowResizable(window, resizable);

		ImGui::Checkbox("Borderless", &borderless);
		SDL_SetWindowBordered(window, borderless);
	}

	if (ImGui::CollapsingHeader("Hardware Info"))
	{
		ImGui::Text("Hardware information");
	}
}