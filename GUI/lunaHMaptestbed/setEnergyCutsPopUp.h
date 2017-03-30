#pragma once

namespace lunaHMaptestbed {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for setCutsPopUp
	/// </summary>
	public ref class setCutsPopUp : public System::Windows::Forms::Form
	{
	public:
		setCutsPopUp(double yMin, double yMax)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->tb_psdYMin->Text = yMin + " ";
			this->tb_psdYMax->Text = yMax + " ";
			this->tb_lowerCut->Text = "0";
			this->tb_upperCut->Text = "0";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~setCutsPopUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tb_lowerCut;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tb_upperCut;
	private: System::Windows::Forms::TextBox^  tb_psdYMin;
	private: System::Windows::Forms::TextBox^  tb_psdYMax;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  b_setCuts;



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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_lowerCut = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_upperCut = (gcnew System::Windows::Forms::TextBox());
			this->tb_psdYMin = (gcnew System::Windows::Forms::TextBox());
			this->tb_psdYMax = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->b_setCuts = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(189, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Current display range for PSD chart is: ";
			// 
			// tb_lowerCut
			// 
			this->tb_lowerCut->Location = System::Drawing::Point(142, 42);
			this->tb_lowerCut->Name = L"tb_lowerCut";
			this->tb_lowerCut->Size = System::Drawing::Size(100, 20);
			this->tb_lowerCut->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(65, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Lower Cut:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(65, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Upper Cut:";
			// 
			// tb_upperCut
			// 
			this->tb_upperCut->Location = System::Drawing::Point(142, 73);
			this->tb_upperCut->Name = L"tb_upperCut";
			this->tb_upperCut->Size = System::Drawing::Size(100, 20);
			this->tb_upperCut->TabIndex = 9;
			// 
			// tb_psdYMin
			// 
			this->tb_psdYMin->Location = System::Drawing::Point(207, 6);
			this->tb_psdYMin->Name = L"tb_psdYMin";
			this->tb_psdYMin->ReadOnly = true;
			this->tb_psdYMin->Size = System::Drawing::Size(72, 20);
			this->tb_psdYMin->TabIndex = 13;
			// 
			// tb_psdYMax
			// 
			this->tb_psdYMax->Location = System::Drawing::Point(305, 6);
			this->tb_psdYMax->Name = L"tb_psdYMax";
			this->tb_psdYMax->ReadOnly = true;
			this->tb_psdYMax->Size = System::Drawing::Size(72, 20);
			this->tb_psdYMax->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(285, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"-->";
			// 
			// b_setCuts
			// 
			this->b_setCuts->Location = System::Drawing::Point(269, 42);
			this->b_setCuts->Name = L"b_setCuts";
			this->b_setCuts->Size = System::Drawing::Size(75, 51);
			this->b_setCuts->TabIndex = 16;
			this->b_setCuts->Text = L"Set Cuts";
			this->b_setCuts->UseVisualStyleBackColor = true;
			this->b_setCuts->Click += gcnew System::EventHandler(this, &setCutsPopUp::b_setCuts_Click);
			// 
			// setCutsPopUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 113);
			this->Controls->Add(this->b_setCuts);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tb_psdYMax);
			this->Controls->Add(this->tb_psdYMin);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_lowerCut);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb_upperCut);
			this->Name = L"setCutsPopUp";
			this->Text = L"Set Chart Cuts";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion		
private:
	double m_CutLower{ 0.0 };
	double m_CutUpper{ 0.0 };
			
private: System::Void b_setCuts_Click(System::Object^  sender, System::EventArgs^  e) {
	/* Take in the values the user has entered and assign them to our member variables; we can access them later through the getter functions */
	Double::TryParse(this->tb_lowerCut->Text, m_CutLower);
	Double::TryParse(this->tb_upperCut->Text, m_CutUpper);

	if ((m_CutLower > m_CutUpper) && m_CutUpper > 0)
	{
		MessageBox::Show("Ensure upper > lower cuts.", "Warning", MessageBoxButtons::OK);
		return;
	}

	this->Hide();
	}
		 
public: Double getCutLower() {
	return m_CutLower;	 
}

public: Double getCutUpper() {
	return m_CutUpper;
}

};
}
