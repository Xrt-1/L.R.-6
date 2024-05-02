#pragma once
#include "Container.h"
namespace LR6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	static int fCtrl = 0;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			cont = gcnew ShapeContainer();
			cont->ContainerChanged += gcnew System::EventHandler(this, &MyForm::Container_update);
			g = this->pBox->CreateGraphics();
			this->Container_update(this, nullptr);
		}
	private: System::Void Container_update(System::Object^ sender, System::EventArgs^ e) {
		this->Refresh();
		this->Invalidate();
		cont->DrawAll(g);
	}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pBox;
	protected:


	protected: 	ShapeContainer^ cont;
	private: System::Windows::Forms::CheckBox^ cBoxCtrl;
	protected:
	private: System::Windows::Forms::CheckBox^ cBoxMulty;
	private: Graphics^ g;
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pBox = (gcnew System::Windows::Forms::PictureBox());
			this->cBoxCtrl = (gcnew System::Windows::Forms::CheckBox());
			this->cBoxMulty = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pBox
			// 
			this->pBox->Location = System::Drawing::Point(-2, -1);
			this->pBox->Name = L"pBox";
			this->pBox->Size = System::Drawing::Size(672, 370);
			this->pBox->TabIndex = 0;
			this->pBox->TabStop = false;
			this->pBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pBox_MouseClick);
			// 
			// cBoxCtrl
			// 
			this->cBoxCtrl->AutoSize = true;
			this->cBoxCtrl->Location = System::Drawing::Point(677, 307);
			this->cBoxCtrl->Name = L"cBoxCtrl";
			this->cBoxCtrl->Size = System::Drawing::Size(107, 20);
			this->cBoxCtrl->TabIndex = 1;
			this->cBoxCtrl->Text = L"ctrlFunctional";
			this->cBoxCtrl->UseVisualStyleBackColor = true;
			this->cBoxCtrl->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cBoxCtrl_CheckedChanged);
			// 
			// cBoxMulty
			// 
			this->cBoxMulty->AutoSize = true;
			this->cBoxMulty->Location = System::Drawing::Point(677, 334);
			this->cBoxMulty->Name = L"cBoxMulty";
			this->cBoxMulty->Size = System::Drawing::Size(98, 20);
			this->cBoxMulty->TabIndex = 2;
			this->cBoxMulty->Text = L"multySelect";
			this->cBoxMulty->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 371);
			this->Controls->Add(this->cBoxMulty);
			this->Controls->Add(this->cBoxCtrl);
			this->Controls->Add(this->pBox);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey && cBoxCtrl->Checked) {
			fCtrl = 1;
		}
		else if (e->KeyCode == Keys::Delete) {
			cont->delSlctd();
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey && cBoxCtrl->Checked) {
			fCtrl = 0;
		}
	}
private: System::Void pBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int x = e->X;
	int y = e->Y;
	cont->addOrSelect(x, y, cBoxMulty->Checked, fCtrl);
}
private: System::Void cBoxCtrl_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!(cBoxCtrl->Checked)) fCtrl = 0;
}
};
}
