#pragma once

#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"

#include "ImGuizmo.h"

#include <SDL3/SDL.h>

class ImGuiWindow
{
public:
	ImGuiWindow(const char* name);
	virtual ~ImGuiWindow();

	void Draw();

protected:
	virtual void DrawContent() = 0;

private:
	const char* name;
};

