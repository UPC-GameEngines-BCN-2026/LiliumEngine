#include <Console.h>

Console& Console::GetInstance()
{
	static Console instance;
	return instance;
}

void Console::Log(const char file[], int line, const char* format, ...)
{
	// Temporary memory space for the final text
	static char buffer[4096];
	// List that holds extra arguments passed to the function
	static va_list args;

	// Any extra arguments of type "format" can be passed into the function
	va_start(args, format);
	// Writes the finished text into buffer
	vsnprintf(buffer, sizeof(buffer), format, args);
	// Ends the list and cleans things up
	va_end(args);
	
	// Constructs the final message
	std::string logMessage = std::string("\n") + file + "(" + std::to_string(line) + ") : " + buffer;

	// Pushes the finished buffer into the entries vector
	entries.push_back(logMessage);

	std::cout << logMessage << std::endl;
}

void Console::Clear() 
{
	entries.clear();
}

void Console::Draw()
{
	if (!Open) return;

	if (ImGui::Begin("Console", &Open)) 
	{
		if (ImGui::BeginPopup("Options"))
		{
			ImGui::Checkbox("Auto-scroll", &AutoScroll);
			ImGui::EndPopup();
		}

		if (ImGui::Button("Options")) 
		{
			ImGui::OpenPopup("Options");
		}

		ImGui::SameLine();

		if (ImGui::Button("Clear")) 
		{
			Clear();
		}

		ImGui::SameLine();

		if (ImGui::Button("Copy")) 
		{
			ImGui::LogToClipboard();
		}

		ImGui::BeginChild("Scroll", ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);

		for (const auto& e : entries) 
		{
			ImGui::TextUnformatted(e.c_str());
		}

		if (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
		{
			ImGui::SetScrollHereY(1.0f);
		}
		ImGui::EndChild();
	}
	ImGui::End();
}
