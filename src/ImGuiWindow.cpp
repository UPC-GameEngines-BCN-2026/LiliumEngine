#include "ImGuiWindow.h"

ImGuiWindow::ImGuiWindow(const char* name)
{
	this->name = name;
}

ImGuiWindow::~ImGuiWindow() {}

void ImGuiWindow::Draw()
{
	if (ImGui::Begin(name))
	{
		DrawContent();
	}

	ImGui::End();
}
