// solitario_0_3.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace solitario_0_3;

[STAThreadAttribute]
int main(cli::array<System::String ^> ^arg)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
