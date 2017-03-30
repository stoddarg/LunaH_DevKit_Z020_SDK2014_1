#pragma once

#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>					//for marshalling
#include <msclr/marshal_cppstd.h>	//for marshalling
#include "captureWaveformsPopup.h"
#include "changeAxesPopUp.h"
#include "setEnergyCutsPopUp.h"

struct EventData
{
	double s_time;
	long long s_totalEvents;
	int s_eventCount;
	double s_baseline;
	double s_shortInt;
	double s_longInt;
	double s_fullInt;
	double s_baselineAvg;
	double s_PSDvalue;
	double s_energy;
};

namespace lunaHMaptestbed {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			findPorts();
			psdCap_run = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:













	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  comboBox1;












	private: System::Windows::Forms::Label^  label6;


	private: bool psdCap_run;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  restartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  diagnosticsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  captureWaveformsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  option1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  option2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cOMPortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeCOMToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  restartCOMToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  ch_PSD;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  ch_Spectrum;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  ch_FOM;
	private: System::Windows::Forms::Button^  b_SetIntegrationTimes;

	private: System::Windows::Forms::TextBox^  tb_baseline;
	private: System::Windows::Forms::TextBox^  tb_short;
	private: System::Windows::Forms::TextBox^  tb_long;
	private: System::Windows::Forms::TextBox^  tb_full;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tb_trigger;
	private: System::Windows::Forms::Button^  b_SetThreshold;
	private: System::Windows::Forms::TextBox^  tb_updates;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  b_capturePSD;
	private: System::Windows::Forms::Button^  b_saveFile;
	private: System::Windows::Forms::CheckBox^  chk_stf;
	private: System::Windows::Forms::CheckBox^  chk_atf;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::TextBox^  tb_savefilename;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ToolStripMenuItem^  pSDOptionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  changeAxesPSDToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^  clearChartPSDToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  spectrumOptionsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  changeAxesSpectrumToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^  clearChartSpectrumToolStripMenuItem1;


	private: System::Windows::Forms::ToolStripMenuItem^  changeBinWidthToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fOMOptionsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  changeAxesFOMToolStripMenuItem2;
private: System::Windows::Forms::ToolStripMenuItem^  clearChartFOMToolStripMenuItem2;
private: System::Windows::Forms::ToolStripMenuItem^  addEnergyCutsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  addFOMCutsToolStripMenuItem;







	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diagnosticsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->captureWaveformsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cOMPortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeCOMToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restartCOMToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pSDOptionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeAxesPSDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearChartPSDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->spectrumOptionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeAxesSpectrumToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearChartSpectrumToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeBinWidthToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addEnergyCutsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fOMOptionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeAxesFOMToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearChartFOMToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addFOMCutsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ch_PSD = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ch_Spectrum = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ch_FOM = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->b_SetIntegrationTimes = (gcnew System::Windows::Forms::Button());
			this->tb_baseline = (gcnew System::Windows::Forms::TextBox());
			this->tb_short = (gcnew System::Windows::Forms::TextBox());
			this->tb_long = (gcnew System::Windows::Forms::TextBox());
			this->tb_full = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tb_trigger = (gcnew System::Windows::Forms::TextBox());
			this->b_SetThreshold = (gcnew System::Windows::Forms::Button());
			this->tb_updates = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->b_capturePSD = (gcnew System::Windows::Forms::Button());
			this->b_saveFile = (gcnew System::Windows::Forms::Button());
			this->chk_stf = (gcnew System::Windows::Forms::CheckBox());
			this->chk_atf = (gcnew System::Windows::Forms::CheckBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tb_savefilename = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ch_PSD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ch_Spectrum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ch_FOM))->BeginInit();
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 115200;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(1075, 394);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(139, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1016, 397);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 13);
			this->label6->TabIndex = 27;
			this->label6->Text = L"COM Port";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->fileToolStripMenuItem,
					this->diagnosticsToolStripMenuItem, this->cOMPortToolStripMenuItem, this->pSDOptionsToolStripMenuItem, this->spectrumOptionsToolStripMenuItem,
					this->fOMOptionsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1223, 24);
			this->menuStrip1->TabIndex = 28;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->restartToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// restartToolStripMenuItem
			// 
			this->restartToolStripMenuItem->Name = L"restartToolStripMenuItem";
			this->restartToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->restartToolStripMenuItem->Text = L"Restart";
			this->restartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::restartToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// diagnosticsToolStripMenuItem
			// 
			this->diagnosticsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->captureWaveformsToolStripMenuItem });
			this->diagnosticsToolStripMenuItem->Name = L"diagnosticsToolStripMenuItem";
			this->diagnosticsToolStripMenuItem->Size = System::Drawing::Size(80, 20);
			this->diagnosticsToolStripMenuItem->Text = L"Diagnostics";
			// 
			// captureWaveformsToolStripMenuItem
			// 
			this->captureWaveformsToolStripMenuItem->Name = L"captureWaveformsToolStripMenuItem";
			this->captureWaveformsToolStripMenuItem->Size = System::Drawing::Size(179, 22);
			this->captureWaveformsToolStripMenuItem->Text = L"Capture Waveforms";
			this->captureWaveformsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::captureWaveformsToolStripMenuItem_Click);
			// 
			// cOMPortToolStripMenuItem
			// 
			this->cOMPortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->closeCOMToolStripMenuItem,
					this->restartCOMToolStripMenuItem
			});
			this->cOMPortToolStripMenuItem->Name = L"cOMPortToolStripMenuItem";
			this->cOMPortToolStripMenuItem->Size = System::Drawing::Size(72, 20);
			this->cOMPortToolStripMenuItem->Text = L"COM Port";
			// 
			// closeCOMToolStripMenuItem
			// 
			this->closeCOMToolStripMenuItem->Name = L"closeCOMToolStripMenuItem";
			this->closeCOMToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->closeCOMToolStripMenuItem->Text = L"Close COM";
			this->closeCOMToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closeCOMToolStripMenuItem_Click);
			// 
			// restartCOMToolStripMenuItem
			// 
			this->restartCOMToolStripMenuItem->Name = L"restartCOMToolStripMenuItem";
			this->restartCOMToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->restartCOMToolStripMenuItem->Text = L"Restart COM";
			this->restartCOMToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::restartCOMToolStripMenuItem_Click);
			// 
			// pSDOptionsToolStripMenuItem
			// 
			this->pSDOptionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->changeAxesPSDToolStripMenuItem,
					this->clearChartPSDToolStripMenuItem
			});
			this->pSDOptionsToolStripMenuItem->Name = L"pSDOptionsToolStripMenuItem";
			this->pSDOptionsToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->pSDOptionsToolStripMenuItem->Text = L"PSD Options";
			// 
			// changeAxesPSDToolStripMenuItem
			// 
			this->changeAxesPSDToolStripMenuItem->Name = L"changeAxesPSDToolStripMenuItem";
			this->changeAxesPSDToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->changeAxesPSDToolStripMenuItem->Text = L"Change Axes";
			this->changeAxesPSDToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::changeAxesPSDToolStripMenuItem_Click);
			// 
			// clearChartPSDToolStripMenuItem
			// 
			this->clearChartPSDToolStripMenuItem->Name = L"clearChartPSDToolStripMenuItem";
			this->clearChartPSDToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->clearChartPSDToolStripMenuItem->Text = L"Clear Chart";
			this->clearChartPSDToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearChartPSDToolStripMenuItem_Click);
			// 
			// spectrumOptionsToolStripMenuItem
			// 
			this->spectrumOptionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->changeAxesSpectrumToolStripMenuItem1,
					this->clearChartSpectrumToolStripMenuItem1, this->changeBinWidthToolStripMenuItem, this->addEnergyCutsToolStripMenuItem
			});
			this->spectrumOptionsToolStripMenuItem->Name = L"spectrumOptionsToolStripMenuItem";
			this->spectrumOptionsToolStripMenuItem->Size = System::Drawing::Size(115, 20);
			this->spectrumOptionsToolStripMenuItem->Text = L"Spectrum Options";
			//this->spectrumOptionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::spectrumOptionsToolStripMenuItem_Click);
			// 
			// changeAxesSpectrumToolStripMenuItem1
			// 
			this->changeAxesSpectrumToolStripMenuItem1->Name = L"changeAxesSpectrumToolStripMenuItem1";
			this->changeAxesSpectrumToolStripMenuItem1->Size = System::Drawing::Size(173, 22);
			this->changeAxesSpectrumToolStripMenuItem1->Text = L"Change Axes";
			this->changeAxesSpectrumToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::changeAxesSpectrumToolStripMenuItem1_Click);
			// 
			// clearChartSpectrumToolStripMenuItem1
			// 
			this->clearChartSpectrumToolStripMenuItem1->Name = L"clearChartSpectrumToolStripMenuItem1";
			this->clearChartSpectrumToolStripMenuItem1->Size = System::Drawing::Size(173, 22);
			this->clearChartSpectrumToolStripMenuItem1->Text = L"Clear Chart";
			this->clearChartSpectrumToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::clearChartSpectrumToolStripMenuItem1_Click);
			// 
			// changeBinWidthToolStripMenuItem
			// 
			this->changeBinWidthToolStripMenuItem->Name = L"changeBinWidthToolStripMenuItem";
			this->changeBinWidthToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->changeBinWidthToolStripMenuItem->Text = L"Change Bin Width";
			// 
			// addEnergyCutsToolStripMenuItem
			// 
			this->addEnergyCutsToolStripMenuItem->Name = L"addEnergyCutsToolStripMenuItem";
			this->addEnergyCutsToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->addEnergyCutsToolStripMenuItem->Text = L"Add Cuts on PSD...";
			this->addEnergyCutsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addEnergyCutsToolStripMenuItem_Click);
			// 
			// fOMOptionsToolStripMenuItem
			// 
			this->fOMOptionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->changeAxesFOMToolStripMenuItem2,
					this->clearChartFOMToolStripMenuItem2, this->addFOMCutsToolStripMenuItem
			});
			this->fOMOptionsToolStripMenuItem->Name = L"fOMOptionsToolStripMenuItem";
			this->fOMOptionsToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->fOMOptionsToolStripMenuItem->Text = L"FOM Options";
			// 
			// changeAxesFOMToolStripMenuItem2
			// 
			this->changeAxesFOMToolStripMenuItem2->Name = L"changeAxesFOMToolStripMenuItem2";
			this->changeAxesFOMToolStripMenuItem2->Size = System::Drawing::Size(188, 22);
			this->changeAxesFOMToolStripMenuItem2->Text = L"Change Axes";
			this->changeAxesFOMToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::changeAxesFOMToolStripMenuItem2_Click);
			// 
			// clearChartFOMToolStripMenuItem2
			// 
			this->clearChartFOMToolStripMenuItem2->Name = L"clearChartFOMToolStripMenuItem2";
			this->clearChartFOMToolStripMenuItem2->Size = System::Drawing::Size(188, 22);
			this->clearChartFOMToolStripMenuItem2->Text = L"Clear Chart";
			this->clearChartFOMToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::clearChartFOMToolStripMenuItem2_Click);
			// 
			// addFOMCutsToolStripMenuItem
			// 
			this->addFOMCutsToolStripMenuItem->Name = L"addFOMCutsToolStripMenuItem";
			this->addFOMCutsToolStripMenuItem->Size = System::Drawing::Size(188, 22);
			this->addFOMCutsToolStripMenuItem->Text = L"Add Cuts on Energy...";
			this->addFOMCutsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addFOMCutsToolStripMenuItem_Click);
			// 
			// ch_PSD
			// 
			this->ch_PSD->AntiAliasing = System::Windows::Forms::DataVisualization::Charting::AntiAliasingStyles::None;
			chartArea4->AxisX->IsStartedFromZero = false;
			chartArea4->AxisX->Maximum = 200000;
			chartArea4->AxisX->Minimum = 0;
			chartArea4->AxisY->Maximum = 2;
			chartArea4->AxisY->Minimum = 0;
			chartArea4->Name = L"ChartArea1";
			this->ch_PSD->ChartAreas->Add(chartArea4);
			this->ch_PSD->Location = System::Drawing::Point(13, 28);
			this->ch_PSD->Name = L"ch_PSD";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series8->MarkerSize = 2;
			series8->Name = L"Series1";
			series9->BorderWidth = 4;
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series9->Color = System::Drawing::Color::Blue;
			series9->Name = L"series_ECutLower";
			series10->BorderWidth = 4;
			series10->ChartArea = L"ChartArea1";
			series10->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series10->Color = System::Drawing::Color::Blue;
			series10->Name = L"series_ECutUpper";
			series11->BorderWidth = 4;
			series11->ChartArea = L"ChartArea1";
			series11->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series11->Name = L"series_FOMCutLeft";
			series11->YValuesPerPoint = 2;
			series12->BorderWidth = 4;
			series12->ChartArea = L"ChartArea1";
			series12->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series12->MarkerSize = 100;
			series12->Name = L"series_FOMCutRight";
			series12->YValuesPerPoint = 2;
			this->ch_PSD->Series->Add(series8);
			this->ch_PSD->Series->Add(series9);
			this->ch_PSD->Series->Add(series10);
			this->ch_PSD->Series->Add(series11);
			this->ch_PSD->Series->Add(series12);
			this->ch_PSD->Size = System::Drawing::Size(706, 343);
			this->ch_PSD->TabIndex = 29;
			this->ch_PSD->Text = L"chart1";
			this->ch_PSD->TextAntiAliasingQuality = System::Windows::Forms::DataVisualization::Charting::TextAntiAliasingQuality::Normal;
			// 
			// ch_Spectrum
			// 
			this->ch_Spectrum->AntiAliasing = System::Windows::Forms::DataVisualization::Charting::AntiAliasingStyles::None;
			chartArea5->AxisX->IsStartedFromZero = false;
			chartArea5->AxisX->Maximum = 200000;
			chartArea5->AxisX->Minimum = 0;
			chartArea5->AxisY->Maximum = 500;
			chartArea5->AxisY->Minimum = 0;
			chartArea5->Name = L"ChartArea1";
			this->ch_Spectrum->ChartAreas->Add(chartArea5);
			this->ch_Spectrum->IsSoftShadows = false;
			this->ch_Spectrum->Location = System::Drawing::Point(13, 377);
			this->ch_Spectrum->Name = L"ch_Spectrum";
			series13->ChartArea = L"ChartArea1";
			series13->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series13->MarkerSize = 2;
			series13->Name = L"Series1";
			this->ch_Spectrum->Series->Add(series13);
			this->ch_Spectrum->Size = System::Drawing::Size(706, 286);
			this->ch_Spectrum->TabIndex = 30;
			this->ch_Spectrum->Text = L"chart1";
			this->ch_Spectrum->TextAntiAliasingQuality = System::Windows::Forms::DataVisualization::Charting::TextAntiAliasingQuality::Normal;
			// 
			// ch_FOM
			// 
			chartArea6->AxisX->Maximum = 2;
			chartArea6->AxisX->Minimum = 0;
			chartArea6->AxisY->IsStartedFromZero = false;
			chartArea6->AxisY->Maximum = 500;
			chartArea6->AxisY->Minimum = 0;
			chartArea6->Name = L"ChartArea1";
			this->ch_FOM->ChartAreas->Add(chartArea6);
			this->ch_FOM->Location = System::Drawing::Point(726, 28);
			this->ch_FOM->Name = L"ch_FOM";
			series14->ChartArea = L"ChartArea1";
			series14->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
			series14->CustomProperties = L"PointWidth=0.01";
			series14->Name = L"Series1";
			this->ch_FOM->Series->Add(series14);
			this->ch_FOM->Size = System::Drawing::Size(488, 343);
			this->ch_FOM->TabIndex = 31;
			this->ch_FOM->Text = L"chart1";
			// 
			// b_SetIntegrationTimes
			// 
			this->b_SetIntegrationTimes->Location = System::Drawing::Point(761, 488);
			this->b_SetIntegrationTimes->Name = L"b_SetIntegrationTimes";
			this->b_SetIntegrationTimes->Size = System::Drawing::Size(140, 41);
			this->b_SetIntegrationTimes->TabIndex = 32;
			this->b_SetIntegrationTimes->Text = L"Set Integration Times";
			this->b_SetIntegrationTimes->UseVisualStyleBackColor = true;
			this->b_SetIntegrationTimes->Click += gcnew System::EventHandler(this, &MyForm::b_SetIntegrationTimes_Click);
			// 
			// tb_baseline
			// 
			this->tb_baseline->Location = System::Drawing::Point(791, 381);
			this->tb_baseline->Name = L"tb_baseline";
			this->tb_baseline->Size = System::Drawing::Size(140, 20);
			this->tb_baseline->TabIndex = 33;
			// 
			// tb_short
			// 
			this->tb_short->Location = System::Drawing::Point(791, 408);
			this->tb_short->Name = L"tb_short";
			this->tb_short->Size = System::Drawing::Size(140, 20);
			this->tb_short->TabIndex = 34;
			// 
			// tb_long
			// 
			this->tb_long->Location = System::Drawing::Point(791, 435);
			this->tb_long->Name = L"tb_long";
			this->tb_long->Size = System::Drawing::Size(140, 20);
			this->tb_long->TabIndex = 35;
			// 
			// tb_full
			// 
			this->tb_full->Location = System::Drawing::Point(791, 462);
			this->tb_full->Name = L"tb_full";
			this->tb_full->Size = System::Drawing::Size(140, 20);
			this->tb_full->TabIndex = 36;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(730, 387);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 37;
			this->label1->Text = L"Baseline";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(730, 411);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 38;
			this->label2->Text = L"Short Int";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(730, 438);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 13);
			this->label3->TabIndex = 39;
			this->label3->Text = L"Long Int";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(730, 465);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 40;
			this->label4->Text = L"Full Int";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(729, 539);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 31);
			this->label5->TabIndex = 41;
			this->label5->Text = L"Trigger Threshold";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tb_trigger
			// 
			this->tb_trigger->Location = System::Drawing::Point(791, 545);
			this->tb_trigger->Name = L"tb_trigger";
			this->tb_trigger->Size = System::Drawing::Size(140, 20);
			this->tb_trigger->TabIndex = 42;
			// 
			// b_SetThreshold
			// 
			this->b_SetThreshold->Location = System::Drawing::Point(761, 573);
			this->b_SetThreshold->Name = L"b_SetThreshold";
			this->b_SetThreshold->Size = System::Drawing::Size(140, 41);
			this->b_SetThreshold->TabIndex = 43;
			this->b_SetThreshold->Text = L"Set Trigger Threshold";
			this->b_SetThreshold->UseVisualStyleBackColor = true;
			this->b_SetThreshold->Click += gcnew System::EventHandler(this, &MyForm::b_SetThreshold_Click);
			// 
			// tb_updates
			// 
			this->tb_updates->Location = System::Drawing::Point(1016, 447);
			this->tb_updates->Name = L"tb_updates";
			this->tb_updates->ReadOnly = true;
			this->tb_updates->Size = System::Drawing::Size(198, 20);
			this->tb_updates->TabIndex = 44;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(960, 450);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 13);
			this->label7->TabIndex = 45;
			this->label7->Text = L"Updates:";
			// 
			// b_capturePSD
			// 
			this->b_capturePSD->Location = System::Drawing::Point(1019, 473);
			this->b_capturePSD->Name = L"b_capturePSD";
			this->b_capturePSD->Size = System::Drawing::Size(140, 41);
			this->b_capturePSD->TabIndex = 46;
			this->b_capturePSD->Text = L"Capture PSD";
			this->b_capturePSD->UseVisualStyleBackColor = true;
			this->b_capturePSD->Click += gcnew System::EventHandler(this, &MyForm::b_capturePSD_Click);
			// 
			// b_saveFile
			// 
			this->b_saveFile->Location = System::Drawing::Point(974, 589);
			this->b_saveFile->Name = L"b_saveFile";
			this->b_saveFile->Size = System::Drawing::Size(107, 41);
			this->b_saveFile->TabIndex = 47;
			this->b_saveFile->Text = L"Choose Save File...";
			this->b_saveFile->UseVisualStyleBackColor = true;
			this->b_saveFile->Click += gcnew System::EventHandler(this, &MyForm::b_saveFile_Click);
			// 
			// chk_stf
			// 
			this->chk_stf->AutoSize = true;
			this->chk_stf->Location = System::Drawing::Point(1087, 591);
			this->chk_stf->Name = L"chk_stf";
			this->chk_stf->Size = System::Drawing::Size(107, 17);
			this->chk_stf->TabIndex = 48;
			this->chk_stf->Text = L"Save to New File";
			this->chk_stf->UseVisualStyleBackColor = true;
			// 
			// chk_atf
			// 
			this->chk_atf->AutoSize = true;
			this->chk_atf->Location = System::Drawing::Point(1087, 613);
			this->chk_atf->Name = L"chk_atf";
			this->chk_atf->Size = System::Drawing::Size(94, 17);
			this->chk_atf->TabIndex = 49;
			this->chk_atf->Text = L"Append to File";
			this->chk_atf->UseVisualStyleBackColor = true;
			// 
			// tb_savefilename
			// 
			this->tb_savefilename->Location = System::Drawing::Point(725, 642);
			this->tb_savefilename->Name = L"tb_savefilename";
			this->tb_savefilename->ReadOnly = true;
			this->tb_savefilename->Size = System::Drawing::Size(489, 20);
			this->tb_savefilename->TabIndex = 50;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(726, 624);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 13);
			this->label8->TabIndex = 51;
			this->label8->Text = L"Save File Location:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 673);
			this->Controls->Add(this->chk_atf);
			this->Controls->Add(this->chk_stf);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tb_savefilename);
			this->Controls->Add(this->b_saveFile);
			this->Controls->Add(this->b_capturePSD);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tb_updates);
			this->Controls->Add(this->b_SetThreshold);
			this->Controls->Add(this->tb_trigger);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb_full);
			this->Controls->Add(this->tb_long);
			this->Controls->Add(this->tb_short);
			this->Controls->Add(this->tb_baseline);
			this->Controls->Add(this->b_SetIntegrationTimes);
			this->Controls->Add(this->ch_FOM);
			this->Controls->Add(this->ch_Spectrum);
			this->Controls->Add(this->ch_PSD);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Luna H Map GUI";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ch_PSD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ch_Spectrum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ch_FOM))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
private:	//declare class-wide variables here
	double m_energyLowerCut{ 0.0 };
	double m_energyUpperCut{ 0.0 };
	double m_fomLeftCut{ 0.0 };
	double m_fomRightCut{ 0.0 };
		
private: void findPorts(void)
{
	array<Object^>^ objectArray = SerialPort::GetPortNames();
	this->comboBox1->Items->AddRange(objectArray);		
}

private: System::Void captureWaveformsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	/* When moving between screens, need to close open ports*/
	if (this->serialPort1->IsOpen)
	{
		this->serialPort1->Close();
	}
	
	/*show the capture waveforms pop up */
	captureWaveformsPopup ^ captureWFs = gcnew captureWaveformsPopup();
	captureWFs->Show();
}//eocapturewaveformsshow

private: System::Void b_SetIntegrationTimes_Click(System::Object^  sender, System::EventArgs^  e) {
	int baselineInt = 0;
	int shortInt = 0;
	int longInt = 0;
	int fullInt = 0;
	String^ retMessage = "";
	String^ baselineMessage = this->tb_baseline->Text;
	String^ shortMessage = this->tb_short->Text;
	String^ longMessage = this->tb_long->Text;
	String^ fullMessage = this->tb_full->Text;

	/* Open the serial port */
	if (this->comboBox1->Text == String::Empty) {
		this->tb_updates->Text = "Select a port above.";
		return;
	}
	else
	{
		if (!this->serialPort1->IsOpen) {
			this->serialPort1->PortName = this->comboBox1->Text;
			this->serialPort1->Open();
			this->b_SetIntegrationTimes->Enabled = false;
		}
		else {
			this->tb_updates->Text = (this->comboBox1->Text) + " is still open.";
			this->b_SetIntegrationTimes->Enabled = false;
			Application::DoEvents();
		}
	}

	this->serialPort1->WriteLine("12");	//change integrals at the main menu
	Sleep(500);						//retMessage = this->serialPort1->ReadLine();	//"enter each integral..."
										//Sleep(200);	//test sleep to see if we just need to give more time

	this->serialPort1->WriteLine(baselineMessage);
	Sleep(500);
	this->serialPort1->WriteLine(shortMessage);
	Sleep(500);
	this->serialPort1->WriteLine(longMessage);
	Sleep(500);
	this->serialPort1->WriteLine(fullMessage);
	Sleep(500);

	this->serialPort1->DiscardInBuffer();

	this->tb_updates->Text = "Integral times have been set.";
	this->b_SetIntegrationTimes->Enabled = true;
}//eoSetIntegrationTimes

private: System::Void b_SetThreshold_Click(System::Object^  sender, System::EventArgs^  e) {
	/* This button click will allow the user to change the trigger threshold of the system over the serial port */
	String^ retMessage = "";	//allows for testing
	String^ thresholdMessage = this->tb_trigger->Text;

	/* Open the serial port */
	if (this->comboBox1->Text == String::Empty) {
		this->tb_updates->Text = "Select a port above.";
		return;
	}
	else
	{
		if (!this->serialPort1->IsOpen) {
			this->serialPort1->PortName = this->comboBox1->Text;
			this->serialPort1->Open();
			this->b_SetThreshold->Enabled = false;
		}
		else {
			this->tb_updates->Text = (this->comboBox1->Text) + " is already open.";
			this->b_SetThreshold->Enabled = false;
			Application::DoEvents();
		}
	}
	
	/* Send commands to the uZ over the serial connection */
	this->serialPort1->WriteLine("11");				//choose change threshold from main menu
	retMessage = this->serialPort1->ReadLine();		//read the line that ask for the new threshold
	this->serialPort1->WriteLine(thresholdMessage);	//write the threshold specified by the user
	Sleep(1200);

	this->serialPort1->DiscardInBuffer();

	/* Clean up */
	this->tb_updates->Text = "Trigger threshold has been set.";
	this->b_SetThreshold->Enabled = true;
}//eoSetThreshold

private: System::Void b_capturePSD_Click(System::Object^  sender, System::EventArgs^  e) {
	/* This button will send commands to open a serial connection and get processed data */
	String^ retMessage = "";
	psdCap_run = !psdCap_run;		//init'd as false
	if (psdCap_run)
	{
		this->b_capturePSD->Text = "Stop Capture";
	}
	if (!psdCap_run)	//stop capturing data
	{
		this->b_capturePSD->Text = "Capture PSD";
		this->tb_updates->Text = "Stop button pressed.";
		//Application::DoEvents();
		return;	//returns out of this function call to the still running call of this function
	}

	/* create an output file stream object */
	std::ofstream outputFile;

	if (psdCap_run && (chk_atf->Checked || chk_stf->Checked))	//if we are running and one of the check buttons is checked, open the save file
	{
		if (this->tb_savefilename->Text == String::Empty)
		{
			this->tb_updates->Text = "Please choose a file save or append location.";
			this->b_capturePSD->Text = "Capture PSD";
			psdCap_run = !psdCap_run;
			return;
		}

		/* Get the filename */
		std::string str_fileName;
		String^ s_fileName = this->saveFileDialog1->FileName;
		str_fileName = msclr::interop::marshal_as<std::string>(s_fileName);

		/* open the file */
		outputFile.open(str_fileName, std::ios::app);

		if (!outputFile)	//if we can't open the file
		{
			this->tb_updates->Text = "Could not access the specified file.";
			this->b_capturePSD->Text = "Capture PSD";
			psdCap_run = !psdCap_run;
			return;
		}
	}

	/* Declare variables */
	int iBaselineValue{ 0 };
	int iShortIntValue{ 0 };
	int iLongIntValue{ 0 };
	int iFullIntValue{ 0 };
	int num_bl_samples{ 0 };
	int num_si_samples{ 0 };
	int num_li_samples{ 0 };
	int num_fi_samples{ 0 };
	double bl1{ 0 };
	double bl2{ 0 };
	double bl3{ 0 };
	double bl4{ 0 };
	int ID{ 0 };
	double bl_avg{ 0.0 };
	double baseline_int{ 0.0 };
	double short_int{ 0.0 };
	double long_int{ 0.0 };
	double full_int{ 0.0 };
	double psd{ 0.0 };
	double energy{ 0.0 };
	EventData eventStruct{};

	double dPSDXmin{ 0 };
	double dPSDXmax{ 0 };
	int iSpectrumArray[1000]{};
	double dSpectrumDomain{ 0.0 };
	double dBinSize{ 0.0 };
	int iSpectrumArrayIndex{ 0 };
	double dSpectrumBin{ 0.0 };
	int missedEvents{ 0 };

	double dPSDYmin{ 0.0 };
	double dPSDYmax{ 0.0 };
	double dFOMRange{ 0.0 };
	double dFOMBinSize{ 0.0 };
	double dFOMBinNumber{ 0.0 };
	int iFOMBins{ 100 };
	int * iFOMArray = new int[iFOMBins]{};	//need to work on how to be able to change this (probably should use std::vector)
	int iFOMArrayIndex{ 0 };

	/* Determine the domain and set axes for the spectrum graph */
	dPSDXmin = this->ch_PSD->ChartAreas[0]->AxisX->Minimum;
	dPSDXmax = this->ch_PSD->ChartAreas[0]->AxisX->Maximum;
	this->ch_Spectrum->ChartAreas[0]->AxisX->Minimum = dPSDXmin;
	this->ch_Spectrum->ChartAreas[0]->AxisX->Maximum = dPSDXmax;
	dSpectrumDomain = dPSDXmax - dPSDXmin;
	dBinSize = dSpectrumDomain / 1000.0;

	/* Determine the range, set axes, and calculate the bin size for the FOM graph */
	dPSDYmin = this->ch_PSD->ChartAreas[0]->AxisY->Minimum;
	dPSDYmax = this->ch_PSD->ChartAreas[0]->AxisY->Maximum;
	this->ch_FOM->ChartAreas[0]->AxisX->Minimum = dPSDYmin;
	this->ch_FOM->ChartAreas[0]->AxisX->Maximum = dPSDYmax;
	dFOMRange = dPSDYmax - dPSDYmin;
	dFOMBinSize = dFOMRange / iFOMBins;

	/* Open the serial port */
	if (this->comboBox1->Text == String::Empty) {
		this->tb_updates->Text = "Select a port above.";
		this->b_capturePSD->Text = "Capture PSD";
		psdCap_run = !psdCap_run;
		return;
	}
	else {
		if (!this->serialPort1->IsOpen) {	//if the port isn't open, open it 
			this->serialPort1->PortName = this->comboBox1->Text;
			this->serialPort1->Open();			
		}
		else {	//if the port is open, just post that and continue using it
			this->tb_updates->Text = "Already connected to the port.";
		}
	}

	/* get the number of samples based on what is in the textboxes, or the default */
	/* if nothing is entered in the integration times textboxes, put the default values there */
	if (this->tb_baseline->Text == String::Empty)
	{
		num_bl_samples = ((200 - 8) / 4) + 1;		// default is -8, gives 49 samples
		num_si_samples = ((200 + 232) / 4) + 1;		// default is 232, gives 109
		num_li_samples = ((200 + 616) / 4) + 1;		// default is 616, gives 205
		num_fi_samples = ((200 + 8008) / 4) + 1;	// default is 8008, gives 2053

		this->tb_baseline->Text = (num_bl_samples * 4) - 52 + " ";
		this->tb_short->Text = (num_si_samples * 4) - 52 + " ";
		this->tb_long->Text = (num_li_samples * 4) - 52 + " ";
		this->tb_full->Text = (num_fi_samples * 4) - 52 + " ";
	}
	else	// if the user entered their own values, find the number of samples for those values
	{
		Int32::TryParse(this->tb_baseline->Text, iBaselineValue);
		Int32::TryParse(this->tb_short->Text, iShortIntValue);
		Int32::TryParse(this->tb_long->Text, iLongIntValue);
		Int32::TryParse(this->tb_full->Text, iFullIntValue);
		num_bl_samples = ((200 + iBaselineValue) / 4) + 1;
		num_si_samples = ((200 + iShortIntValue) / 4) + 1;
		num_li_samples = ((200 + iLongIntValue) / 4) + 1;
		num_fi_samples = ((200 + iFullIntValue) / 4) + 1;
	}

	/* Now we may send commands over the serial port */
	if (this->serialPort1->IsOpen)
	{
		this->serialPort1->WriteLine("13");
		this->tb_updates->Text = "Collecting...";
		Sleep(2000);
	}
	else
	{
		this->tb_updates->Text = "Port is not open.";
		this->b_capturePSD->Text = "Capture PSD";
		psdCap_run = !psdCap_run;
		//Application::DoEvents();
		return;
	}
	
	/* Capture incoming data; process and plot it */
	int index{ 0 };
	int buffsize{ 0 };
	int numBuffers{ 0 };

/*	Int32::TryParse(this->serialPort1->ReadLine(), buffsize); */	//get the buffer size 
	while (psdCap_run)
	{
		//retVal = this->serialPort1->ReadLine();
		Int32::TryParse(this->serialPort1->ReadLine(), ID);
		if (ID == 111111)
		{
			this->serialPort1->ReadLine();	//time
			this->serialPort1->ReadLine();	//total events
			this->serialPort1->ReadLine();	//event number
			this->serialPort1->ReadLine();	//bl
			this->serialPort1->ReadLine();	//si
			this->serialPort1->ReadLine();	//li
			this->serialPort1->ReadLine();	//fi
		}
		else
			continue;

		/* process and plot loop */
		while (index < 509)
		{
			/* Try and read in the data from the serial port */
			try
			{
				Int32::TryParse(this->serialPort1->ReadLine(), ID);	//Identifier
				Double::TryParse(this->serialPort1->ReadLine(), eventStruct.s_time);	//time
				Int64::TryParse(this->serialPort1->ReadLine(), eventStruct.s_totalEvents);	//total events
				Int32::TryParse(this->serialPort1->ReadLine(), eventStruct.s_eventCount);	//event number
				Double::TryParse(this->serialPort1->ReadLine(), eventStruct.s_baseline);
				Double::TryParse(this->serialPort1->ReadLine(), eventStruct.s_shortInt);
				Double::TryParse(this->serialPort1->ReadLine(), eventStruct.s_longInt);
				Double::TryParse(this->serialPort1->ReadLine(), eventStruct.s_fullInt);
			}
			/* If it times out, catch that and close the connection */
			catch (const TimeoutException^)
			{
				this->serialPort1->Close();
				this->tb_updates->Text = "Connection closed due to timeout.";
				//this->b_capturePSD->Enabled = true;
				return;
			}

			/* Process data */
			bl4 = bl3;
			bl3 = bl2;
			bl2 = bl1;
			bl1 = (eventStruct.s_baseline / (16 * num_bl_samples));
			if( bl4 == 0 )
				eventStruct.s_baselineAvg = (eventStruct.s_baseline / (16 * num_bl_samples));
			else
				eventStruct.s_baselineAvg = (bl4 + bl3 + bl2 + bl1) / 4.0;

			eventStruct.s_shortInt = (eventStruct.s_shortInt / 16) - (eventStruct.s_baselineAvg * num_si_samples);
			eventStruct.s_longInt = (eventStruct.s_longInt / 16) - (eventStruct.s_baselineAvg * num_li_samples);
			eventStruct.s_fullInt = (eventStruct.s_fullInt / 16) - (eventStruct.s_baselineAvg * num_fi_samples);

			eventStruct.s_PSDvalue = eventStruct.s_shortInt / (eventStruct.s_longInt - eventStruct.s_shortInt);
			eventStruct.s_energy = 1.0 * eventStruct.s_longInt + 0.0;

			/* If we have data, plot it on the chart */
			if ((eventStruct.s_PSDvalue < 2 && eventStruct.s_PSDvalue > 0) && (eventStruct.s_energy < dPSDXmax && eventStruct.s_energy > dPSDXmin))	//guarantee that if we have a runaway value, we don't plot
			{
				this->ch_PSD->Series["Series1"]->Points->AddXY(eventStruct.s_energy, eventStruct.s_PSDvalue);
			}

			/* Write to file, line-by-line */
			outputFile << std::setw(11) << eventStruct.s_time
				<< std::setw(11) << eventStruct.s_totalEvents
				<< std::setw(11) << eventStruct.s_eventCount << " "
				<< std::setw(11) << eventStruct.s_baseline
				<< std::setw(11) << eventStruct.s_shortInt
				<< std::setw(11) << eventStruct.s_longInt
				<< std::setw(11) << eventStruct.s_fullInt
				<< std::setw(11) << eventStruct.s_baselineAvg
				<< std::setw(11) << eventStruct.s_PSDvalue
				<< std::setw(11) << eventStruct.s_energy << std::endl;
			++index;

			/* Here is where the sorting for cuts will be done; if not cuts are requested, skip these statements */
			/* Sort energy into spectrum bins */
			iSpectrumArrayIndex = static_cast<int>(eventStruct.s_energy / dBinSize);	//cast this as int to tell compiler we want to lose the decimal info
			if (iSpectrumArrayIndex > 999 || iSpectrumArrayIndex < 0)
			{
				++missedEvents;
				continue;
			}
			if ((m_energyLowerCut >= 0) && (m_energyUpperCut > 0))	//if the user made cuts on PSD
			{
				if ((eventStruct.s_PSDvalue >= m_energyLowerCut) && (eventStruct.s_PSDvalue <= m_energyUpperCut))
				{
					++iSpectrumArray[iSpectrumArrayIndex];
				}
			}
			else	//if the user did not make cuts
			{
				++iSpectrumArray[iSpectrumArrayIndex];
			}

			/* sort PSD into FOM bins */
			iFOMArrayIndex = static_cast<int>(eventStruct.s_PSDvalue / dFOMBinSize);
			if (iFOMArrayIndex > 99 || iFOMArrayIndex < 0)
			{
				++missedEvents;
				continue;
			}
			if ((m_fomLeftCut > 0) && (m_fomRightCut > 0))	//if the user made cuts on energy
			{
				if ((eventStruct.s_energy >= m_fomLeftCut) && (eventStruct.s_energy <= m_fomRightCut))
				{
					++iFOMArray[iFOMArrayIndex];
				}
			}
			else	//if the user did not make cuts
			{
				++iFOMArray[iFOMArrayIndex];
			}
		}	

		/* plot the x-y energy spectrum data */
		this->ch_Spectrum->Series["Series1"]->Points->Clear();
		for (int i = 0; i < 999; i++)	//go through every point in the array	//there are 1000 elements in the array, 0 - 999
		{			
			dSpectrumBin = dBinSize * (i + 0.5);	//(dBinSize * i) + (dBinSize / 2);
			this->ch_Spectrum->Series["Series1"]->Points->AddXY(dSpectrumBin, iSpectrumArray[i]);
		}

		/* plot the FOM data */
		this->ch_FOM->Series["Series1"]->Points->Clear();
		for (int j = 0; j < (iFOMBins - 1); j++)
		{
			dFOMBinNumber = dFOMBinSize * (j + 0.5);
			this->ch_FOM->Series["Series1"]->Points->AddXY(dFOMBinNumber, iFOMArray[j]);
		}

		index = 0;
		Application::DoEvents();
		++numBuffers;
		this->tb_updates->Text = numBuffers + " buffers plotted.";
		
		if (this->serialPort1->IsOpen)
		{
			this->serialPort1->ReadLine();	//read once more to move past final ID in the buffer
		}		
	}

	/* When we want to stop catpure */
	this->serialPort1->WriteLine("q");	//quit the data stream
	Sleep(1000);
	
	this->serialPort1->DiscardInBuffer();
	if (outputFile.is_open())
	{
		outputFile.close();
	}
	outputFile.close();
	delete[] iFOMArray;

	this->tb_updates->Text = "Capture finished. Chart not erased.";
	return;
}//eoCapturePSDclick

private: System::Void b_saveFile_Click(System::Object^  sender, System::EventArgs^  e) {
	/* create instance of a save file dialog */
	saveFileDialog1->ShowDialog();
	tb_savefilename->Text = saveFileDialog1->FileName;
}//eosavefileclick

private: System::Void changeAxesPSDToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	/* Open small pop-up which takes in values for axes and passes them back here */
	double xMin;
	double xMax;
	double yMin;
	double yMax;

	xMin = this->ch_PSD->ChartAreas[0]->AxisX->Minimum;
	xMax = this->ch_PSD->ChartAreas[0]->AxisX->Maximum;
	yMin = this->ch_PSD->ChartAreas[0]->AxisY->Minimum;
	yMax = this->ch_PSD->ChartAreas[0]->AxisY->Maximum;
	
	/* Show the change axes pop up */
	changeAxesPopUp ^ changePSDAxes = gcnew changeAxesPopUp( xMin, xMax, yMin, yMax);
	//Application::Run(changePSDAxes);
	changePSDAxes->ShowDialog();

	this->ch_PSD->ChartAreas[0]->AxisX->Minimum = changePSDAxes->getxMin();
	this->ch_PSD->ChartAreas[0]->AxisX->Maximum = changePSDAxes->getxMax();
	this->ch_PSD->ChartAreas[0]->AxisY->Minimum = changePSDAxes->getyMin();
	this->ch_PSD->ChartAreas[0]->AxisY->Maximum = changePSDAxes->getyMax();

	/* also change the spectrum chart because we need the two to be linked */
	this->ch_Spectrum->ChartAreas[0]->AxisX->Minimum = changePSDAxes->getxMin();
	this->ch_Spectrum->ChartAreas[0]->AxisX->Maximum = changePSDAxes->getxMax();
	this->ch_FOM->ChartAreas[0]->AxisY->Minimum = changePSDAxes->getyMin();
	this->ch_FOM->ChartAreas[0]->AxisY->Maximum = changePSDAxes->getyMax();

}//eochangepsdaxes

private: System::Void changeAxesSpectrumToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	double xMin;
	double xMax;
	double yMin;
	double yMax;

	xMin = this->ch_Spectrum->ChartAreas[0]->AxisX->Minimum;
	xMax = this->ch_Spectrum->ChartAreas[0]->AxisX->Maximum;
	yMin = this->ch_Spectrum->ChartAreas[0]->AxisY->Minimum;
	yMax = this->ch_Spectrum->ChartAreas[0]->AxisY->Maximum;

	/* Show the change axes pop up */
	changeAxesPopUp ^ changeSpectrumAxes = gcnew changeAxesPopUp(xMin, xMax, yMin, yMax);
	//Application::Run(changePSDAxes);
	changeSpectrumAxes->ShowDialog();

	this->ch_Spectrum->ChartAreas[0]->AxisX->Minimum = changeSpectrumAxes->getxMin();
	this->ch_Spectrum->ChartAreas[0]->AxisX->Maximum = changeSpectrumAxes->getxMax();
	this->ch_Spectrum->ChartAreas[0]->AxisY->Minimum = changeSpectrumAxes->getyMin();
	this->ch_Spectrum->ChartAreas[0]->AxisY->Maximum = changeSpectrumAxes->getyMax();
}//eochangespectrumaxes

private: System::Void changeAxesFOMToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	double xMin;
	double xMax;
	double yMin;
	double yMax;

	xMin = this->ch_FOM->ChartAreas[0]->AxisX->Minimum;
	xMax = this->ch_FOM->ChartAreas[0]->AxisX->Maximum;
	yMin = this->ch_FOM->ChartAreas[0]->AxisY->Minimum;
	yMax = this->ch_FOM->ChartAreas[0]->AxisY->Maximum;

	/* Show the change axes pop up */
	changeAxesPopUp ^ changeFOMAxes = gcnew changeAxesPopUp(xMin, xMax, yMin, yMax);
	//Application::Run(changePSDAxes);
	changeFOMAxes->ShowDialog();

	this->ch_FOM->ChartAreas[0]->AxisX->Minimum = changeFOMAxes->getxMin();
	this->ch_FOM->ChartAreas[0]->AxisX->Maximum = changeFOMAxes->getxMax();
	this->ch_FOM->ChartAreas[0]->AxisY->Minimum = changeFOMAxes->getyMin();
	this->ch_FOM->ChartAreas[0]->AxisY->Maximum = changeFOMAxes->getyMax();
}//eochangefomaxes

private: System::Void clearChartPSDToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ch_PSD->Series["Series1"]->Points->Clear();
	this->tb_updates->Text = "PSD Chart cleared.";
	Application::DoEvents();
}

private: System::Void clearChartSpectrumToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ch_Spectrum->Series["Series1"]->Points->Clear();
	this->tb_updates->Text = "Energy spectrum chart cleared.";
	Application::DoEvents();
}

private: System::Void clearChartFOMToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ch_FOM->Series["Series1"]->Points->Clear();
	this->tb_updates->Text = "FOM chart cleared.";
	Application::DoEvents();
}

private: System::Void closeCOMToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (!this->serialPort1->IsOpen)
	{
		this->tb_updates->Text = (this->comboBox1->Text) + " is already closed.";
		return;
	}
		
	this->serialPort1->Close();
	this->tb_updates->Text = (this->comboBox1->Text) + " has been closed.";
	return;
}

private: System::Void restartCOMToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	/* scan for com ports again, fill the combobox */
	this->tb_updates->Text = "Closing any open ports...";
	if (this->serialPort1->IsOpen)
	{
		this->serialPort1->Close();
		this->tb_updates->Text = "Port closed.";
	}

	this->comboBox1->Items->Clear();
	findPorts();
	
	this->tb_updates->Text = "Please re-select a port.";
	return;
}
private: System::Void restartToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->serialPort1->IsOpen)
	{
		this->serialPort1->Close();
	}

	/* shut down this instance of the application and start a new one */
	Application::Restart();
}//eorestart

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->serialPort1->IsOpen)
	{
		this->serialPort1->Close();
	}

	/* exit the application */
	Application::Exit();
}//eoexit

private: System::Void addEnergyCutsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	/* This function plots lines horizontally across the PSD chart to indicate an Energy cut */
	/* This further allows the user to specify what energy range to look at and plot on the energy spectrum chart */
	double psdXmin{ 0.0 };
	double psdXmax{ 0.0 };
	double psdYmin{ 0.0 };
	double psdYmax{ 0.0 };

	psdXmin = this->ch_PSD->ChartAreas[0]->AxisX->Minimum;
	psdXmax = this->ch_PSD->ChartAreas[0]->AxisX->Maximum;
	psdYmin = this->ch_PSD->ChartAreas[0]->AxisY->Minimum;
	psdYmax = this->ch_PSD->ChartAreas[0]->AxisY->Maximum;

	/* Show the set E cuts pop up */
	 setCutsPopUp ^ setECuts = gcnew setCutsPopUp(psdYmin, psdYmax);
	setECuts->ShowDialog();

	/* Retrieve the cuts the user entered and add them to the chart */
	m_energyLowerCut = setECuts->getCutLower();
	m_energyUpperCut = setECuts->getCutUpper();

	this->ch_PSD->Series["series_ECutLower"]->Points->Clear();
	this->ch_PSD->Series["series_ECutUpper"]->Points->Clear();

	if (m_energyLowerCut == 0 && m_energyUpperCut == 0)	//no cuts
	{
		m_energyLowerCut = 0.0;
		m_energyUpperCut = 0.0;
		this->tb_updates->Text = "No cuts chosen.";
		return;
	}

	if (m_energyLowerCut > 0 && m_energyUpperCut > 0)	//both cuts were chosen
	{
		this->ch_PSD->Series["series_ECutLower"]->Points->AddXY(psdXmin, m_energyLowerCut);
		this->ch_PSD->Series["series_ECutLower"]->Points->AddXY(psdXmax, m_energyLowerCut);
		this->ch_PSD->Series["series_ECutUpper"]->Points->AddXY(psdXmin, m_energyUpperCut);
		this->ch_PSD->Series["series_ECutUpper"]->Points->AddXY(psdXmax, m_energyUpperCut);
	}	

	if (m_energyLowerCut == 0 && m_energyUpperCut > 0)	//Just an upper cut
	{
		this->ch_PSD->Series["series_ECutUpper"]->Points->AddXY(psdXmin, m_energyUpperCut);
		this->ch_PSD->Series["series_ECutUpper"]->Points->AddXY(psdXmax, m_energyUpperCut);
	}
		
	if (m_energyLowerCut > 0 && m_energyUpperCut == 0)	//Just a lower cut
	{
		this->ch_PSD->Series["series_ECutLower"]->Points->AddXY(psdXmin, m_energyLowerCut);
		this->ch_PSD->Series["series_ECutLower"]->Points->AddXY(psdXmax, m_energyLowerCut);
	}
}

private: System::Void addFOMCutsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	/* allows user to plot two vertical lines on ch_PSD, indicating cuts which are plotted by FOM chart */
	double psdXmin{ 0.0 };
	double psdXmax{ 0.0 };
	double psdYmin{ 0.0 };
	double psdYmax{ 0.0 };

	psdXmin = this->ch_PSD->ChartAreas[0]->AxisX->Minimum;
	psdXmax = this->ch_PSD->ChartAreas[0]->AxisX->Maximum;
	psdYmin = this->ch_PSD->ChartAreas[0]->AxisY->Minimum;
	psdYmax = this->ch_PSD->ChartAreas[0]->AxisY->Maximum;

	/* Show the set E cuts pop up */
	setCutsPopUp ^ setFOMCuts = gcnew setCutsPopUp(psdXmin, psdXmax);
	setFOMCuts->ShowDialog();

	/* Retrieve the cuts the user entered and add them to the chart */
	m_fomLeftCut = setFOMCuts->getCutLower();
	m_fomRightCut = setFOMCuts->getCutUpper();

	this->ch_PSD->Series["series_FOMCutLeft"]->Points->Clear();	
	this->ch_PSD->Series["series_FOMCutRight"]->Points->Clear();

	if (m_fomLeftCut == 0 && m_fomRightCut == 0)	//no cuts
	{
		m_fomLeftCut = 0.0;
		m_fomRightCut = 0.0;

		this->tb_updates->Text = "No cuts chosen.";
		return;
	}

	if (m_fomLeftCut > 0 && m_fomRightCut > 0)	//both cuts were chosen
	{
		this->ch_PSD->Series["series_FOMCutLeft"]->Points->AddXY(m_fomLeftCut, psdYmin);
		this->ch_PSD->Series["series_FOMCutLeft"]->Points->AddXY(m_fomLeftCut, psdYmax);
		this->ch_PSD->Series["series_FOMCutRight"]->Points->AddXY(m_fomRightCut, psdYmin);
		this->ch_PSD->Series["series_FOMCutRight"]->Points->AddXY(m_fomRightCut, psdYmax);
	}

	if (m_fomLeftCut == 0 && m_fomRightCut > 0)	//Just an upper cut
	{
		this->ch_PSD->Series["series_FOMCutRight"]->Points->AddXY(m_fomRightCut, psdYmin);
		this->ch_PSD->Series["series_FOMCutRight"]->Points->AddXY(m_fomRightCut, psdYmax);
	}

	if (m_fomLeftCut > 0 && m_fomRightCut == 0)	//Just a lower cut
	{
		this->ch_PSD->Series["series_FOMCutLeft"]->Points->AddXY(m_fomLeftCut, psdYmin);
		this->ch_PSD->Series["series_FOMCutLeft"]->Points->AddXY(m_fomLeftCut, psdYmax);
	}
}

};
}
