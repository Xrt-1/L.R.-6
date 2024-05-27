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
			Initialize_BChecker();
			MultySeletct = Borders = CtrlFunctional = false;
		}

	public:

















	private: System::Windows::Forms::ToolStripStatusLabel^ tStripLbl_Sh1ape;
	private: System::Windows::Forms::ToolStripSplitButton^ toolStripSplitButton1;
	private: System::Windows::Forms::ToolStripMenuItem^ squareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ triangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ circleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^ tStripLbl_Color;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::Label^ lblShape;

	private: System::Windows::Forms::ToolStripStatusLabel^ tStripLbl_Borders;
	private: System::Windows::Forms::ToolStripStatusLabel^ tStripLbl_MultuSel;
	private: System::Windows::Forms::ToolStripStatusLabel^ tStripLbl_CtrlFunctional;
	private: bool MultySeletct, Borders, CtrlFunctional;



























	public:
	private: System::Drawing::Size pBoxDeltaSize = System::Drawing::Size(0, 0);
	private: System::Void Container_update(System::Object^ sender, System::EventArgs^ e) {
		this->Refresh();
		cont->DrawAll(g);
	}


	private: System::String^ type = "Circle";
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


	protected: 	ShapeContainer^ cont = nullptr;

	protected:

	private: Graphics^ g;

	private: System::Windows::Forms::ColorDialog^ clrDialog;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pBox = (gcnew System::Windows::Forms::PictureBox());
			this->clrDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->tStripLbl_Sh1ape = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripSplitButton1 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->squareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->triangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tStripLbl_Color = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->tStripLbl_Borders = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tStripLbl_MultuSel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tStripLbl_CtrlFunctional = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lblShape = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBox))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pBox
			// 
			this->pBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pBox->Location = System::Drawing::Point(15, 23);
			this->pBox->Name = L"pBox";
			this->pBox->Size = System::Drawing::Size(644, 328);
			this->pBox->TabIndex = 0;
			this->pBox->TabStop = false;
			this->pBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pBox_MouseClick);
			// 
			// tStripLbl_Sh1ape
			// 
			this->tStripLbl_Sh1ape->Name = L"tStripLbl_Sh1ape";
			this->tStripLbl_Sh1ape->Size = System::Drawing::Size(92, 20);
			this->tStripLbl_Sh1ape->Text = L"Select shape";
			// 
			// toolStripSplitButton1
			// 
			this->toolStripSplitButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripSplitButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->squareToolStripMenuItem,
					this->triangleToolStripMenuItem, this->circleToolStripMenuItem
			});
			this->toolStripSplitButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSplitButton1.Image")));
			this->toolStripSplitButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton1->Name = L"toolStripSplitButton1";
			this->toolStripSplitButton1->Size = System::Drawing::Size(39, 24);
			this->toolStripSplitButton1->Text = L"toolStripSplitButton1";
			// 
			// squareToolStripMenuItem
			// 
			this->squareToolStripMenuItem->Name = L"squareToolStripMenuItem";
			this->squareToolStripMenuItem->Size = System::Drawing::Size(145, 26);
			this->squareToolStripMenuItem->Text = L"Square";
			this->squareToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::squareToolStripMenuItem_Click);
			// 
			// triangleToolStripMenuItem
			// 
			this->triangleToolStripMenuItem->Name = L"triangleToolStripMenuItem";
			this->triangleToolStripMenuItem->Size = System::Drawing::Size(145, 26);
			this->triangleToolStripMenuItem->Text = L"Triangle";
			this->triangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::triangleToolStripMenuItem_Click);
			// 
			// circleToolStripMenuItem
			// 
			this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
			this->circleToolStripMenuItem->Size = System::Drawing::Size(145, 26);
			this->circleToolStripMenuItem->Text = L"Circle";
			this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// tStripLbl_Color
			// 
			this->tStripLbl_Color->Name = L"tStripLbl_Color";
			this->tStripLbl_Color->Size = System::Drawing::Size(87, 20);
			this->tStripLbl_Color->Text = L"Select color";
			this->tStripLbl_Color->Click += gcnew System::EventHandler(this, &MyForm::btnColor_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->tStripLbl_Sh1ape,
					this->toolStripSplitButton1, this->tStripLbl_Color, this->tStripLbl_Borders, this->tStripLbl_MultuSel, this->tStripLbl_CtrlFunctional
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 363);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(680, 26);
			this->statusStrip1->TabIndex = 8;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// tStripLbl_Borders
			// 
			this->tStripLbl_Borders->Name = L"tStripLbl_Borders";
			this->tStripLbl_Borders->Size = System::Drawing::Size(60, 20);
			this->tStripLbl_Borders->Text = L"Borders";
			this->tStripLbl_Borders->Click += gcnew System::EventHandler(this, &MyForm::tStripLbl_Borders_Click);
			// 
			// tStripLbl_MultuSel
			// 
			this->tStripLbl_MultuSel->Name = L"tStripLbl_MultuSel";
			this->tStripLbl_MultuSel->Size = System::Drawing::Size(86, 20);
			this->tStripLbl_MultuSel->Text = L"MultySelect";
			this->tStripLbl_MultuSel->Click += gcnew System::EventHandler(this, &MyForm::tStripLbl_MultuSel_Click);
			// 
			// tStripLbl_CtrlFunctional
			// 
			this->tStripLbl_CtrlFunctional->Name = L"tStripLbl_CtrlFunctional";
			this->tStripLbl_CtrlFunctional->Size = System::Drawing::Size(98, 20);
			this->tStripLbl_CtrlFunctional->Text = L"ctrlFunctional";
			this->tStripLbl_CtrlFunctional->Click += gcnew System::EventHandler(this, &MyForm::tStripLbl_CtrlFunctional_Click);
			// 
			// lblShape
			// 
			this->lblShape->AutoSize = true;
			this->lblShape->Font = (gcnew System::Drawing::Font(L"Montserrat", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblShape->Location = System::Drawing::Point(12, 2);
			this->lblShape->Name = L"lblShape";
			this->lblShape->Size = System::Drawing::Size(48, 18);
			this->lblShape->TabIndex = 9;
			this->lblShape->Text = L"Circle";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(680, 389);
			this->Controls->Add(this->lblShape);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->pBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(698, 436);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"L.R. 6";
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_SizeChanged);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBox))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
	private: void Initialize_BChecker() {
		if (cont != nullptr) {
			cont->Initialize_BChecker((pBox->Size));
			this->KeyPreview = true;
		}
		
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey && CtrlFunctional) {
			fCtrl = 1;
		}
		else if (e->KeyCode == Keys::Delete) {
			cont->delSlctd();
		}
		else if (e->KeyCode == Keys::Add) cont->sizeChange("+", Borders);
		else if (e->KeyCode == Keys::Subtract) cont->sizeChange("-", Borders);
		else if (e->KeyCode == Keys::Up) cont->MoveSlctd("up", Borders);
		else if (e->KeyCode == Keys::Down) cont->MoveSlctd("down", Borders);
		else if (e->KeyCode == Keys::Right) cont->MoveSlctd("right", Borders);
		else if (e->KeyCode == Keys::Left) cont->MoveSlctd("left", Borders);
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey && CtrlFunctional) {
			fCtrl = 0;
		}
	}
private: System::Void pBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int x = e->X;
	int y = e->Y;
	cont->addOrSelect(x, y, MultySeletct, fCtrl, type);
}
private: System::Void cBoxCtrl_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!(CtrlFunctional)) fCtrl = 0;
}
private: System::Void btnColor_Click(System::Object^ sender, System::EventArgs^ e) {
	if (clrDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		cont->setSlctdColor(clrDialog->Color);
	}
}
private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	cont->DrawAll(g);
}


private: System::Void MyForm_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	delete g;
	g = this->pBox->CreateGraphics();
	Initialize_BChecker();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBoxBorders_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void squareToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	(lblShape->Text) = "Square";
	type = "Square";
}
private: System::Void triangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	lblShape->Text = "Triangle";
	type = "Triangle";
}
private: System::Void circleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	lblShape->Text = "Circle";
	type = "Circle";
}

private: System::Void tStripLbl_Borders_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Borders) {
		Borders = false;
		MessageBox::Show("Borders ---- OFF");
		System::Media::SystemSounds::Beep->Play();
	}
	else {
		Borders = true;
		MessageBox::Show("Borders ---- ON");
	}
}
private: System::Void tStripLbl_MultuSel_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MultySeletct) {
		MultySeletct = false;
		MessageBox::Show("Multy select ---- OFF");
	}
	else {
		MultySeletct = true;
		MessageBox::Show("Multy select ---- ON");
	}

}
private: System::Void tStripLbl_CtrlFunctional_Click(System::Object^ sender, System::EventArgs^ e) {
	if (CtrlFunctional) {
		CtrlFunctional = false;
		MessageBox::Show("Ctrl fuctional ---- OFF");
	}
	else {
		CtrlFunctional = true;
		MessageBox::Show("Ctrl fuctional ---- ON");
	}
}
};
}
