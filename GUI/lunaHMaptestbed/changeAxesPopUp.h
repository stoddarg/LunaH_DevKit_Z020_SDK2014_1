#pragma once

namespace lunaHMaptestbed {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for changeAxesPopUp
	/// </summary>
	public ref class changeAxesPopUp : public System::Windows::Forms::Form
	{
	public:
		changeAxesPopUp(double xMin, double xMax, double yMin, double yMax)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->tb_xMin->Text = xMin + " ";
			this->tb_xMax->Text = xMax + " ";
			this->tb_yMin->Text = yMin + " ";
			this->tb_yMax->Text = yMax + " ";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~changeAxesPopUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tb_xMin;
	private: System::Windows::Forms::TextBox^  tb_xMax;
	private: System::Windows::Forms::Button^  b_setAxes;

	protected:

	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb_yMin;
	private: System::Windows::Forms::TextBox^  tb_yMax;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb_xMin = (gcnew System::Windows::Forms::TextBox());
			this->tb_xMax = (gcnew System::Windows::Forms::TextBox());
			this->b_setAxes = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_yMin = (gcnew System::Windows::Forms::TextBox());
			this->tb_yMax = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tb_xMin
			// 
			this->tb_xMin->Location = System::Drawing::Point(89, 29);
			this->tb_xMin->Name = L"tb_xMin";
			this->tb_xMin->Size = System::Drawing::Size(100, 20);
			this->tb_xMin->TabIndex = 0;
			// 
			// tb_xMax
			// 
			this->tb_xMax->Location = System::Drawing::Point(196, 29);
			this->tb_xMax->Name = L"tb_xMax";
			this->tb_xMax->Size = System::Drawing::Size(100, 20);
			this->tb_xMax->TabIndex = 1;
			// 
			// b_setAxes
			// 
			this->b_setAxes->Location = System::Drawing::Point(302, 29);
			this->b_setAxes->Name = L"b_setAxes";
			this->b_setAxes->Size = System::Drawing::Size(100, 53);
			this->b_setAxes->TabIndex = 4;
			this->b_setAxes->Text = L"Set Axis Ranges";
			this->b_setAxes->UseVisualStyleBackColor = true;
			this->b_setAxes->Click += gcnew System::EventHandler(this, &changeAxesPopUp::b_setAxes_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X-Axis Range:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Y-Axis Range:";
			// 
			// tb_yMin
			// 
			this->tb_yMin->Location = System::Drawing::Point(89, 63);
			this->tb_yMin->Name = L"tb_yMin";
			this->tb_yMin->Size = System::Drawing::Size(100, 20);
			this->tb_yMin->TabIndex = 2;
			// 
			// tb_yMax
			// 
			this->tb_yMax->Location = System::Drawing::Point(196, 62);
			this->tb_yMax->Name = L"tb_yMax";
			this->tb_yMax->Size = System::Drawing::Size(100, 20);
			this->tb_yMax->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(86, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Minimum";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(193, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Maximum";
			// 
			// changeAxesPopUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(423, 103);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_yMax);
			this->Controls->Add(this->tb_yMin);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->b_setAxes);
			this->Controls->Add(this->tb_xMax);
			this->Controls->Add(this->tb_xMin);
			this->Name = L"changeAxesPopUp";
			this->Text = L"Change Chart Axes";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
private:
	double m_xmin{ 0 };
	double m_xmax{ 0 };
	double m_ymin{ 0 };
	double m_ymax{ 0 };
	
private: System::Void b_setAxes_Click(System::Object^  sender, System::EventArgs^  e) {
	/* take in the values from the text boxes and pass them back to the main form */

	Double::TryParse(this->tb_xMin->Text, m_xmin);	//set the variables the user entered 
	Double::TryParse(this->tb_xMax->Text, m_xmax);
	Double::TryParse(this->tb_yMin->Text, m_ymin);
	Double::TryParse(this->tb_yMax->Text, m_ymax);

	this->Hide();
}//eob_setaxesclick
			 
public: Double getxMin() {
	return m_xmin;
}

public: Double getxMax() {
	return m_xmax;
}
		
public: Double getyMin() {
	return m_ymin;		
}

public: Double getyMax() {
	return m_ymax;
}

};
}
