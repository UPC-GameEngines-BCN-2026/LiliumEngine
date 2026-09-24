#include "ConfigurationWindow.h"

ConfigurationWindow::ConfigurationWindow():ImGuiWindow("Configuration"){}


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
			ImGui::PlotHistogram(
				"FPS",
				fpsData.data(),
				static_cast<float>(fpsData.size()),
				0,
				nullptr,
				100.0f,
				static_cast<float>(maxFPS),
				ImVec2(310, 100),
				2
			);
		}

		char title[25];
		sprintf_s(title, 25, "Framerate %.1f", fpsData[fpsData.size() - 1]);
		ImGui::PlotHistogram("##framerate", &fpsData[0], fpsData.size(), 0, title, 0.0f, 100.0f, ImVec2(310, 100));
		//sprintf_s(title, 25, "Milliseconds %.1f", ms_log[ms_log.size() - 1]);
		//ImGui::PlotHistogram("##milliseconds", &ms_log[0], ms_log.size(), 0, title, 0.0f, 40.0f, ImVec2(310, 100));


		ImGui::SeparatorText("General Info");

		if (ImGui::TreeNode("Testing"))
		{



			ImGui::TreePop();
		}

	}

	if (ImGui::CollapsingHeader("Window"))
	{
		ImGui::Text("Window options");
	}

	if (ImGui::CollapsingHeader("Hardware Info"))
	{
		ImGui::Text("Hardware information");
	}
}
