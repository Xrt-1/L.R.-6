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
		}
	private: System::Windows::Forms::CheckBox^ cBoxCtrl;
	public:
	private: System::Windows::Forms::CheckBox^ cBoxMulty;


	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ tStripLbl_Sh1ape;






	private: System::Windows::Forms::ToolStripSplitButton^ toolStripSplitButton1;
	private: System::Windows::Forms::ToolStripMenuItem^ squareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ triangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ circleToolStripMenuItem;
	private: System::Windows::Forms::Label^ lblShape;






















	public:
	private: System::Drawing::Size pBoxDeltaSize = System::Drawing::Size(0, 0);
	private: System::Void Container_update(System::Object^ sender, System::EventArgs^ e) {
		this->Refresh();
		cont->DrawAll(g);
	}
	private: System::Windows::Forms::CheckBox^ checkBoxBorders;

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
	private: System::Windows::Forms::ComboBox^ cBoxShapes;
	private: System::Windows::Forms::ColorDialog^ clrDialog;

	private: System::Windows::Forms::Button^ btnColor;




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
			this->cBoxShapes = (gcnew System::Windows::Forms::ComboBox());
			this->clrDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->btnColor = (gcnew System::Windows::Forms::Button());
			this->checkBoxBorders = (gcnew System::Windows::Forms::CheckBox());
			this->cBoxCtrl = (gcnew System::Windows::Forms::CheckBox());
			this->cBoxMulty = (gcnew System::Windows::Forms::CheckBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->tStripLbl_Sh1ape = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripSplitButton1 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->squareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->triangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->pBox->Location = System::Drawing::Point(12, 22);
			this->pBox->Name = L"pBox";
			this->pBox->Size = System::Drawing::Size(752, 334);
			this->pBox->TabIndex = 0;
			this->pBox->TabStop = false;
			this->pBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pBox_MouseClick);
			// 
			// cBoxShapes
			// 
			this->cBoxShapes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cBoxShapes->FormattingEnabled = true;
			this->cBoxShapes->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Circle", L"Triangle", L"Square" });
			this->cBoxShapes->Location = System::Drawing::Point(782, 46);
			this->cBoxShapes->Name = L"cBoxShapes";
			this->cBoxShapes->Size = System::Drawing::Size(83, 24);
			this->cBoxShapes->TabIndex = 3;
			this->cBoxShapes->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cBoxShapes_SelectedIndexChanged);
			// 
			// btnColor
			// 
			this->btnColor->Location = System::Drawing::Point(782, 12);
			this->btnColor->Name = L"btnColor";
			this->btnColor->Size = System::Drawing::Size(163, 28);
			this->btnColor->TabIndex = 4;
			this->btnColor->Text = L"Select color";
			this->btnColor->UseVisualStyleBackColor = true;
			this->btnColor->Click += gcnew System::EventHandler(this, &MyForm::btnColor_Click);
			// 
			// checkBoxBorders
			// 
			this->checkBoxBorders->AutoSize = true;
			this->checkBoxBorders->Location = System::Drawing::Point(834, 115);
			this->checkBoxBorders->Name = L"checkBoxBorders";
			this->checkBoxBorders->Size = System::Drawing::Size(85, 20);
			this->checkBoxBorders->TabIndex = 5;
			this->checkBoxBorders->Text = L"√раницы";
			this->checkBoxBorders->UseVisualStyleBackColor = true;
			// 
			// cBoxCtrl
			// 
			this->cBoxCtrl->AutoSize = true;
			this->cBoxCtrl->Location = System::Drawing::Point(834, 167);
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
			this->cBoxMulty->Location = System::Drawing::Point(835, 141);
			this->cBoxMulty->Name = L"cBoxMulty";
			this->cBoxMulty->Size = System::Drawing::Size(98, 20);
			this->cBoxMulty->TabIndex = 2;
			this->cBoxMulty->Text = L"multySelect";
			this->cBoxMulty->UseVisualStyleBackColor = true;
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tStripLbl_Sh1ape,
					this->toolStripSplitButton1
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 376);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(945, 26);
			this->statusStrip1->TabIndex = 8;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// tStripLbl_Sh1ape
			// 
			this->tStripLbl_Sh1ape->Name = L"tStripLbl_Sh1ape";
			this->tStripLbl_Sh1ape->Size = System::Drawing::Size(94, 20);
			this->tStripLbl_Sh1ape->Text = L"Select_shape";
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
			// 
			// triangleToolStripMenuItem
			// 
			this->triangleToolStripMenuItem->Name = L"triangleToolStripMenuItem";
			this->triangleToolStripMenuItem->Size = System::Drawing::Size(145, 26);
			this->triangleToolStripMenuItem->Text = L"Triangle";
			// 
			// circleToolStripMenuItem
			// 
			this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
			this->circleToolStripMenuItem->Size = System::Drawing::Size(145, 26);
			this->circleToolStripMenuItem->Text = L"Circle";
			// 
			// lblShape
			// 
			this->lblShape->AutoSize = true;
			this->lblShape->Font = (gcnew System::Drawing::Font(L"Montserrat", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblShape->Location = System::Drawing::Point(12, 3);
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
			this->ClientSize = System::Drawing::Size(945, 402);
			this->Controls->Add(this->cBoxMulty);
			this->Controls->Add(this->lblShape);
			this->Controls->Add(this->cBoxCtrl);
			this->Controls->Add(this->btnColor);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->cBoxShapes);
			this->Controls->Add(this->checkBoxBorders);
			this->Controls->Add(this->pBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->KeyPreview = true;
			this->Name = L"MyForm";
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
		if (e->KeyCode == Keys::ControlKey && cBoxCtrl->Checked) {
			fCtrl = 1;
		}
		else if (e->KeyCode == Keys::Delete) {
			cont->delSlctd();
		}
		else if (e->KeyCode == Keys::Add) cont->sizeChange("+", checkBoxBorders->Checked);
		else if (e->KeyCode == Keys::Subtract) cont->sizeChange("-", checkBoxBorders->Checked);
		else if (e->KeyCode == Keys::Up) cont->MoveSlctd("up", checkBoxBorders->Checked);
		else if (e->KeyCode == Keys::Down) cont->MoveSlctd("down", checkBoxBorders->Checked);
		else if (e->KeyCode == Keys::Right) cont->MoveSlctd("right", checkBoxBorders->Checked);
		else if (e->KeyCode == Keys::Left) cont->MoveSlctd("left", checkBoxBorders->Checked);
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey && cBoxCtrl->Checked) {
			fCtrl = 0;
		}
	}
private: System::Void pBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int x = e->X;
	int y = e->Y;
	cont->addOrSelect(x, y, cBoxMulty->Checked, fCtrl, type);
}
private: System::Void cBoxCtrl_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!(cBoxCtrl->Checked)) fCtrl = 0;
}
private: System::Void btnColor_Click(System::Object^ sender, System::EventArgs^ e) {
	if (clrDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		cont->setSlctdColor(clrDialog->Color);
	}
}
private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	cont->DrawAll(g);
}
private: System::Void cBoxShapes_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (cBoxShapes->Text == "Circle") type = "Circle";
	else if (cBoxShapes->Text == "Square") type = "Square";
	else if (cBoxShapes->Text == "Triangle") type = "Triangle";
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
};
}
