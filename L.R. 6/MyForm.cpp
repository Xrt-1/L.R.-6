#include "MyForm.h"
#include <iostream>
#include "Container.h"
using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew LR6::MyForm());

	return 0;
}
