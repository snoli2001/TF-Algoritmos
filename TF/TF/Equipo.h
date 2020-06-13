﻿#pragma once

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Equipo
	/// </summary>
	public ref class Equipo : public System::Windows::Forms::Form
	{
	public:
		Equipo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Equipo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ Inicia;
	private: System::Windows::Forms::CheckBox^ Finaliza;
	private: System::Windows::Forms::CheckBox^ Contiene;
	private: System::Windows::Forms::CheckBox^ Nocont;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	protected:
		int op;
	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Inicia = (gcnew System::Windows::Forms::CheckBox());
			this->Finaliza = (gcnew System::Windows::Forms::CheckBox());
			this->Contiene = (gcnew System::Windows::Forms::CheckBox());
			this->Nocont = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(83, 104);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Equipo::button1_Click);
			// 
			// Inicia
			// 
			this->Inicia->AutoSize = true;
			this->Inicia->Location = System::Drawing::Point(43, 58);
			this->Inicia->Name = L"Inicia";
			this->Inicia->Size = System::Drawing::Size(72, 17);
			this->Inicia->TabIndex = 1;
			this->Inicia->Text = L"Inicia con";
			this->Inicia->UseVisualStyleBackColor = true;
			this->Inicia->CheckedChanged += gcnew System::EventHandler(this, &Equipo::Inicia_CheckedChanged);
			// 
			// Finaliza
			// 
			this->Finaliza->AutoSize = true;
			this->Finaliza->Location = System::Drawing::Point(129, 58);
			this->Finaliza->Name = L"Finaliza";
			this->Finaliza->Size = System::Drawing::Size(82, 17);
			this->Finaliza->TabIndex = 2;
			this->Finaliza->Text = L"Finaliza con";
			this->Finaliza->UseVisualStyleBackColor = true;
			this->Finaliza->CheckedChanged += gcnew System::EventHandler(this, &Equipo::Finaliza_CheckedChanged);
			// 
			// Contiene
			// 
			this->Contiene->AutoSize = true;
			this->Contiene->Location = System::Drawing::Point(43, 81);
			this->Contiene->Name = L"Contiene";
			this->Contiene->Size = System::Drawing::Size(68, 17);
			this->Contiene->TabIndex = 3;
			this->Contiene->Text = L"Contiene";
			this->Contiene->UseVisualStyleBackColor = true;
			this->Contiene->CheckedChanged += gcnew System::EventHandler(this, &Equipo::Contiene_CheckedChanged);
			// 
			// Nocont
			// 
			this->Nocont->AutoSize = true;
			this->Nocont->Location = System::Drawing::Point(129, 81);
			this->Nocont->Name = L"Nocont";
			this->Nocont->Size = System::Drawing::Size(84, 17);
			this->Nocont->TabIndex = 4;
			this->Nocont->Text = L"No contiene";
			this->Nocont->UseVisualStyleBackColor = true;
			this->Nocont->CheckedChanged += gcnew System::EventHandler(this, &Equipo::Nocont_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(129, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Ingrese los datos";
			// 
			// Equipo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 154);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Nocont);
			this->Controls->Add(this->Contiene);
			this->Controls->Add(this->Finaliza);
			this->Controls->Add(this->Inicia);
			this->Controls->Add(this->button1);
			this->Name = L"Equipo";
			this->Text = L"Equipo";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Inicia_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Inicia->Checked) {
			Finaliza->Enabled = false;
			Contiene->Enabled = false;
			Nocont->Enabled = false;
			op = 1;
		}
		else
		{
			Finaliza->Enabled = true;
			Contiene->Enabled = true;
			Nocont->Enabled = true;
			op = 0;

		}
	}
	private: System::Void Finaliza_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Finaliza->Checked) {
			Inicia->Enabled = false;
			Contiene->Enabled = false;
			Nocont->Enabled = false;
			op = 2;
		}
		else
		{
			Inicia->Enabled = true;
			Contiene->Enabled = true;
			Nocont->Enabled = true;
			op = 0;
		}
	}
	private: System::Void Contiene_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Contiene->Checked) {
			Finaliza->Enabled = false;
			Inicia->Enabled = false;
			Nocont->Enabled = false;
			op = 3;
		}
		else
		{
			Finaliza->Enabled = true;
			Inicia->Enabled = true;
			Nocont->Enabled = true;
			op = 0;
		}
	}
	private: System::Void Nocont_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Nocont->Checked) {
			Finaliza->Enabled = false;
			Contiene->Enabled = false;
			Inicia->Enabled = false;
			op = 4;
		}
		else
		{
			Finaliza->Enabled = true;
			Contiene->Enabled = true;
			Inicia->Enabled = true;
			op = 0;
		}
	}
	public:
	String^ getText() {
	   return textBox1->Text;
	}
	int getFiltro() {
	   return op;
	}
};

}
