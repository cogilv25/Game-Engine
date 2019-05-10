#include "nppch.h"
#include "ImGuiWrapper.h"
#include "imgui.h"

namespace np
{
	namespace ImGuiWrapper
	{
		void Text(const char* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			ImGui::TextV(fmt, args);
			va_end(args);
		}

		bool Begin(const char * name, bool * p_open, ImGuiWindowFlags flags)
		{
			return ImGui::Begin(name, p_open, flags);
		}
		void End()
		{
			ImGui::End();
		}
	}
}