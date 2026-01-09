#pragma once
#include <msclr/marshal_cppstd.h>
#include "MyLib.h"
#include "AboutForm.h"


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			this->button1->Text = L"Prideti";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);

			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());

			this->panel1->Visible = false;
			this->panel2->Visible = false;
			this->panel3->Visible = false;
		

			this->vectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::vectorToolStripMenuItem_Click);
			this->listToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::listToolStripMenuItem_Click);
			this->dequeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dequeToolStripMenuItem_Click);

			this->apieToolStripMenuItem->Click +=
				gcnew System::EventHandler(this, &Form1::apieToolStripMenuItem_Click);
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// UI Components
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ MenuIvesti;
		System::Windows::Forms::ToolStripMenuItem^ SugeneruotiAtsitiktinai;
		System::Windows::Forms::ToolStripMenuItem^ medianaToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ vidurkiToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ nuskaitytIsFailoMediana;
		System::Windows::Forms::ToolStripMenuItem^ MedianaFIle;
		System::Windows::Forms::ToolStripMenuItem^ VidurkiFile;
		System::Windows::Forms::ToolStripMenuItem^ generuotiFailusIrTestuotiStrategijasToolStripMenuItem;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Panel^ panelSugeneruotiAtsitiktinai;
		System::Windows::Forms::Button^ buttonGenerate;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::NumericUpDown^ numericUpDown2;
		System::Windows::Forms::NumericUpDown^ numericUpDown1;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::ListBox^ listBox1;
		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::Button^ button7;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::ToolStripMenuItem^ vectorToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ listToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ dequeToolStripMenuItem;
		System::Windows::Forms::Panel^ panel3;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::NumericUpDown^ numericUpDown4;
		System::Windows::Forms::NumericUpDown^ numericUpDown3;
		System::Windows::Forms::ComboBox^ comboBox1;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Button^ buttonRun;
		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::OpenFileDialog^ openFileDialog1;

		System::ComponentModel::Container^ components;

	private: System::Windows::Forms::ToolStripMenuItem^ apieToolStripMenuItem;


		// Переменная для хранения выбранного контейнера
		ContainerType currentContainer = ContainerType::Vector;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuIvesti = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SugeneruotiAtsitiktinai = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medianaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vidurkiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nuskaitytIsFailoMediana = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MedianaFIle = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->VidurkiFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generuotiFailusIrTestuotiStrategijasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dequeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->apieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelSugeneruotiAtsitiktinai = (gcnew System::Windows::Forms::Panel());
			this->buttonGenerate = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panelSugeneruotiAtsitiktinai->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(135, 297);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(197, 53);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Prideti";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(9, 228);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(344, 22);
			this->textBox4->TabIndex = 16;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(5, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(262, 20);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Iveskite egzamino bala (nebutinai)";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(9, 164);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(344, 22);
			this->textBox3->TabIndex = 14;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(5, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(342, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Iveskite namu darbu pazymius (pvz. 1 2 3 4 )";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(9, 100);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(344, 22);
			this->textBox2->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(5, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Iveskite pavarde:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(344, 22);
			this->textBox1->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(5, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Iveskite varda:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(12, 42);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(471, 396);
			this->panel1->TabIndex = 18;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(430, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(29, 30);
			this->button2->TabIndex = 18;
			this->button2->Text = L"X";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Silver;
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->listBox1);
			this->panel2->Location = System::Drawing::Point(12, 42);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(735, 603);
			this->panel2->TabIndex = 22;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(703, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(29, 30);
			this->button7->TabIndex = 24;
			this->button7->Text = L"X";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(569, 68);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(161, 40);
			this->button5->TabIndex = 23;
			this->button5->Text = L"ikelti";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(569, 131);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(161, 42);
			this->button4->TabIndex = 22;
			this->button4->Text = L"išvalyti";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(14, 16);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(549, 544);
			this->listBox1->TabIndex = 21;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->MenuIvesti, this->SugeneruotiAtsitiktinai,
					this->nuskaitytIsFailoMediana, this->generuotiFailusIrTestuotiStrategijasToolStripMenuItem, this->apieToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(973, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MenuIvesti
			// 
			this->MenuIvesti->Name = L"MenuIvesti";
			this->MenuIvesti->Size = System::Drawing::Size(155, 24);
			this->MenuIvesti->Text = L" Įvesti rankiniu būdu";
			this->MenuIvesti->Click += gcnew System::EventHandler(this, &Form1::MenuIvesti_Click);
			// 
			// SugeneruotiAtsitiktinai
			// 
			this->SugeneruotiAtsitiktinai->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->medianaToolStripMenuItem,
					this->vidurkiToolStripMenuItem
			});
			this->SugeneruotiAtsitiktinai->Name = L"SugeneruotiAtsitiktinai";
			this->SugeneruotiAtsitiktinai->Size = System::Drawing::Size(175, 24);
			this->SugeneruotiAtsitiktinai->Text = L"Sugeneruoti atsitiktinai";
			// 
			// medianaToolStripMenuItem
			// 
			this->medianaToolStripMenuItem->Name = L"medianaToolStripMenuItem";
			this->medianaToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->medianaToolStripMenuItem->Text = L"Medianą";
			this->medianaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::medianaToolStripMenuItem_Click);
			// 
			// vidurkiToolStripMenuItem
			// 
			this->vidurkiToolStripMenuItem->Name = L"vidurkiToolStripMenuItem";
			this->vidurkiToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->vidurkiToolStripMenuItem->Text = L"Vidurkį";
			this->vidurkiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::vidurkiToolStripMenuItem_Click);
			// 
			// nuskaitytIsFailoMediana
			// 
			this->nuskaitytIsFailoMediana->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->MedianaFIle,
					this->VidurkiFile
			});
			this->nuskaitytIsFailoMediana->Name = L"nuskaitytIsFailoMediana";
			this->nuskaitytIsFailoMediana->Size = System::Drawing::Size(140, 24);
			this->nuskaitytIsFailoMediana->Text = L" Nuskaityti iš failo";
			// 
			// MedianaFIle
			// 
			this->MedianaFIle->Name = L"MedianaFIle";
			this->MedianaFIle->Size = System::Drawing::Size(150, 26);
			this->MedianaFIle->Text = L"Medianą";
			this->MedianaFIle->Click += gcnew System::EventHandler(this, &Form1::MedianaFIle_Click);
			// 
			// VidurkiFile
			// 
			this->VidurkiFile->Name = L"VidurkiFile";
			this->VidurkiFile->Size = System::Drawing::Size(150, 26);
			this->VidurkiFile->Text = L"Vidurkį";
			this->VidurkiFile->Click += gcnew System::EventHandler(this, &Form1::VidurkiFile_Click);
			// 
			// generuotiFailusIrTestuotiStrategijasToolStripMenuItem
			// 
			this->generuotiFailusIrTestuotiStrategijasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->vectorToolStripMenuItem,
					this->listToolStripMenuItem, this->dequeToolStripMenuItem
			});
			this->generuotiFailusIrTestuotiStrategijasToolStripMenuItem->Name = L"generuotiFailusIrTestuotiStrategijasToolStripMenuItem";
			this->generuotiFailusIrTestuotiStrategijasToolStripMenuItem->Size = System::Drawing::Size(266, 24);
			this->generuotiFailusIrTestuotiStrategijasToolStripMenuItem->Text = L"Generuoti failus ir testuoti strategijas";
			// 
			// vectorToolStripMenuItem
			// 
			this->vectorToolStripMenuItem->Name = L"vectorToolStripMenuItem";
			this->vectorToolStripMenuItem->Size = System::Drawing::Size(136, 26);
			this->vectorToolStripMenuItem->Text = L"Vector";
			this->vectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::vectorToolStripMenuItem_Click_1);
			// 
			// listToolStripMenuItem
			// 
			this->listToolStripMenuItem->Name = L"listToolStripMenuItem";
			this->listToolStripMenuItem->Size = System::Drawing::Size(136, 26);
			this->listToolStripMenuItem->Text = L"List";
			this->listToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::listToolStripMenuItem_Click_1);
			// 
			// dequeToolStripMenuItem
			// 
			this->dequeToolStripMenuItem->Name = L"dequeToolStripMenuItem";
			this->dequeToolStripMenuItem->Size = System::Drawing::Size(136, 26);
			this->dequeToolStripMenuItem->Text = L"Deque";
			this->dequeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dequeToolStripMenuItem_Click_1);
			// 
			// apieToolStripMenuItem
			// 
			this->apieToolStripMenuItem->Name = L"apieToolStripMenuItem";
			this->apieToolStripMenuItem->Size = System::Drawing::Size(52, 24);
			this->apieToolStripMenuItem->Text = L"apie";
			// 
			// panelSugeneruotiAtsitiktinai
			// 
			this->panelSugeneruotiAtsitiktinai->BackColor = System::Drawing::Color::Gainsboro;
			this->panelSugeneruotiAtsitiktinai->Controls->Add(this->buttonGenerate);
			this->panelSugeneruotiAtsitiktinai->Controls->Add(this->button3);
			this->panelSugeneruotiAtsitiktinai->Controls->Add(this->numericUpDown2);
			this->panelSugeneruotiAtsitiktinai->Controls->Add(this->numericUpDown1);
			this->panelSugeneruotiAtsitiktinai->Controls->Add(this->label6);
			this->panelSugeneruotiAtsitiktinai->Controls->Add(this->label5);
			this->panelSugeneruotiAtsitiktinai->Location = System::Drawing::Point(166, 42);
			this->panelSugeneruotiAtsitiktinai->Name = L"panelSugeneruotiAtsitiktinai";
			this->panelSugeneruotiAtsitiktinai->Size = System::Drawing::Size(409, 221);
			this->panelSugeneruotiAtsitiktinai->TabIndex = 20;
			this->panelSugeneruotiAtsitiktinai->Visible = false;
			// 
			// buttonGenerate
			// 
			this->buttonGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonGenerate->Location = System::Drawing::Point(107, 163);
			this->buttonGenerate->Name = L"buttonGenerate";
			this->buttonGenerate->Size = System::Drawing::Size(196, 45);
			this->buttonGenerate->TabIndex = 11;
			this->buttonGenerate->Text = L"Prideti";
			this->buttonGenerate->UseVisualStyleBackColor = true;
			this->buttonGenerate->Click += gcnew System::EventHandler(this, &Form1::buttonGenerate_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(367, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(29, 30);
			this->button3->TabIndex = 10;
			this->button3->Text = L"X";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(23, 118);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000000, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(133, 22);
			this->numericUpDown2->TabIndex = 5;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(23, 56);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(133, 22);
			this->numericUpDown1->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(19, 94);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(272, 20);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Kiek namų darbų (ND) kiekvienam\?\r\n";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(19, 32);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(184, 20);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Kiek studentų generuoti";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::LightGray;
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->buttonRun);
			this->panel3->Controls->Add(this->comboBox1);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->numericUpDown4);
			this->panel3->Controls->Add(this->numericUpDown3);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Location = System::Drawing::Point(489, 42);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(457, 342);
			this->panel3->TabIndex = 23;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(425, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(29, 30);
			this->button6->TabIndex = 25;
			this->button6->Text = L"X";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// buttonRun
			// 
			this->buttonRun->Location = System::Drawing::Point(154, 265);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(117, 42);
			this->buttonRun->TabIndex = 6;
			this->buttonRun->Text = L"Start";
			this->buttonRun->UseVisualStyleBackColor = true;
			this->buttonRun->Click += gcnew System::EventHandler(this, &Form1::buttonRun_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
				L"1 - Strategija 1: Kopijuoti į 2 naujus failus (kietiakiai + vargšiukai)",
					L"2 - Strategija 2: Perkelti vargšiukus ir ištrinti iš pagrindinio"
			});
			this->comboBox1->Location = System::Drawing::Point(17, 219);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(407, 24);
			this->comboBox1->TabIndex = 5;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(18, 196);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(166, 20);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Pasirinkite strategiją:";
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(17, 117);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(183, 22);
			this->numericUpDown4->TabIndex = 3;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(17, 48);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000000, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(196, 22);
			this->numericUpDown3->TabIndex = 2;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(14, 98);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(167, 20);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Kiek ND kiekvienam\?";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(14, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(193, 20);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Kiek studentų generuoti\?";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(973, 664);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panelSugeneruotiAtsitiktinai);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panelSugeneruotiAtsitiktinai->ResumeLayout(false);
			this->panelSugeneruotiAtsitiktinai->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	 

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			 
			std::string vardas = msclr::interop::marshal_as<std::string>(textBox1->Text);
			std::string pavarde = msclr::interop::marshal_as<std::string>(textBox2->Text);
			std::string ndStr = msclr::interop::marshal_as<std::string>(textBox3->Text);
			std::string egzStr = msclr::interop::marshal_as<std::string>(textBox4->Text);

			 
			std::string error;
			if (!ValidateStudentInput(vardas, pavarde, error)) {
				MessageBox::Show(gcnew System::String(error.c_str()));
				return;
			}
 
			int egz = 0;
			if (!egzStr.empty()) {
				try {
					egz = System::Int32::Parse(textBox4->Text);
				}
				catch (...) {
					MessageBox::Show("Egzamino bala turi buti skaicius.");
					return;
				}
				if (!ValidateExamGrade(egz, error)) {
					MessageBox::Show(gcnew System::String(error.c_str()));
					return;
				}
			}

			 
			std::vector<int> paz;
			if (!ParseND(ndStr, paz, error)) {
				MessageBox::Show(gcnew System::String(error.c_str()));
				return;
			}

			 
			FinalGrades grades = CalculateFinalGrades(paz, egz);

			 
			std::string filePath = MakePathInResults("kursiokai.txt");
			WriteStudentToFile(filePath, pavarde, vardas, grades.vidurkis, grades.mediana);


			 
			textBox1->Clear();
			textBox2->Clear();
			textBox3->Clear();
			textBox4->Clear();

			MessageBox::Show("Irasas pridetas i kursiokai.txt");
		}
		catch (const std::exception& ex)
		{
			MessageBox::Show(gcnew System::String(ex.what()));
		}
	}

	private: System::Void buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			int N = (int)numericUpDown1->Value;
			int nd_kiek = (int)numericUpDown2->Value;

			if (N <= 0 || nd_kiek <= 0) {
				MessageBox::Show("N ir ND kiek turi buti > 0");
				return;
			}

			 
			std::string outPath = MakePathInResults("sugeneruoti.txt");
			GeneruotiSugeneruoti(outPath, N, nd_kiek);

			MessageBox::Show("Sugeneruota i sugeneruoti.txt");
		}
		catch (const std::exception& ex)
		{
			MessageBox::Show(gcnew System::String(ex.what()));
		}
	}

	private: System::Void buttonRun_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			int N = (int)numericUpDown3->Value;
			int nd = (int)numericUpDown4->Value;

			if (N <= 0 || nd <= 0) {
				MessageBox::Show("N ir ND kiek turi buti > 0");
				return;
			}

			int stratIndex = comboBox1->SelectedIndex;
			if (stratIndex != 0 && stratIndex != 1) {
				MessageBox::Show("Pasirinkite strategija (1 arba 2).");
				return;
			}

			double genTime = 0.0;
			double stratTime = 0.0;

			const std::string inputFile = MakePathInResults("students_generated.txt");
			RunStrategy(currentContainer, stratIndex, inputFile, genTime, stratTime, N, nd);


			 
			System::String^ msg =
				"Sugeneruota: " + N.ToString() + " studentu, ND: " + nd.ToString() + "\n"
				"Generavimo laikas: " + gcnew System::String(std::to_string(genTime).c_str()) + " s\n"
				"Strategijos laikas: " + gcnew System::String(std::to_string(stratTime).c_str()) + " s\n"
				"Ivesties failas: students_generated.txt\n"
				"Rezultatai:\n"
				" - students_generated_kietiakiai.txt\n"
				" - students_generated_vargsiukai.txt (strategija 1)\n"
				" - arba tik vargsiukai (strategija 2)";

			MessageBox::Show(msg);
		}
		catch (const std::exception& ex)
		{
			MessageBox::Show(gcnew System::String(ex.what()));
		}
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				listBox1->Items->Clear();
				StreamReader^ failas = gcnew StreamReader(openFileDialog1->FileName);
				try
				{
					String^ line;
					while ((line = failas->ReadLine()) != nullptr)
						listBox1->Items->Add(line);
				}
				finally
				{
					delete failas;
				}
			}
			catch (IOException^ ex)
			{
				MessageBox::Show("Nepavyko nuskaityti failo: " + ex->Message);
			}
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::DialogResult r =
			MessageBox::Show("Ar tikrai norite viska pasalinti?",
				"Patvirtinimas",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question);

		if (r == System::Windows::Forms::DialogResult::Yes)
			listBox1->Items->Clear();
	}

		   

	private: System::Void MenuIvesti_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panel1->Visible = true;
		panelSugeneruotiAtsitiktinai->Hide();
		panel2->Hide();
		panel3->Hide();
	}

	private: System::Void medianaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panelSugeneruotiAtsitiktinai->Visible = true;
		panel1->Hide();
		panel2->Hide();
		panel3->Hide();
	}

	private: System::Void vidurkiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panelSugeneruotiAtsitiktinai->Visible = true;
		panel1->Hide();
		panel2->Hide();
		panel3->Hide();
	}

	private: System::Void MedianaFIle_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panel2->Visible = true;
		panel1->Hide();
		panelSugeneruotiAtsitiktinai->Hide();
		panel3->Hide();
	}

	private: System::Void VidurkiFile_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panel2->Visible = true;
		panel1->Hide();
		panelSugeneruotiAtsitiktinai->Hide();
		panel3->Hide();
	}

	private: System::Void vectorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		currentContainer = ContainerType::Vector;
		vectorToolStripMenuItem->Checked = true;
		listToolStripMenuItem->Checked = false;
		dequeToolStripMenuItem->Checked = false;
	}

	private: System::Void listToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		currentContainer = ContainerType::List;
		vectorToolStripMenuItem->Checked = false;
		listToolStripMenuItem->Checked = true;
		dequeToolStripMenuItem->Checked = false;
	}

	private: System::Void dequeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		currentContainer = ContainerType::Deque;
		vectorToolStripMenuItem->Checked = false;
		listToolStripMenuItem->Checked = false;
		dequeToolStripMenuItem->Checked = true;
	}

	private: System::Void vectorToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		panel3->Visible = true;
		panelSugeneruotiAtsitiktinai->Hide();
		panel2->Hide();
		panel1->Hide();
	}

	private: System::Void listToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		panel3->Visible = true;
		panelSugeneruotiAtsitiktinai->Hide();
		panel2->Hide();
		panel1->Hide();
	}

	private: System::Void dequeToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		panel3->Visible = true;
		panelSugeneruotiAtsitiktinai->Hide();
		panel2->Hide();
		panel1->Hide();
	}

		    

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panel1->Hide();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panelSugeneruotiAtsitiktinai->Hide();
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panel3->Hide();
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		panel2->Hide();
	}



	 System::Void apieToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			 AboutForm^ about = gcnew AboutForm();
		     about->ShowDialog(); 
		}


};
}
