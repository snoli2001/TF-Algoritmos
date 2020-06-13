#pragma once

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Edad
	/// </summary>
	public ref class Edad : public System::Windows::Forms::Form
	{
	public:
		Edad(void)
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
		~Edad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ May;
	private: System::Windows::Forms::CheckBox^ Menor;
	protected:

	private: System::Windows::Forms::CheckBox^ Igual;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ Contiene;
	private: System::Windows::Forms::CheckBox^ NoContiene;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->May = (gcnew System::Windows::Forms::CheckBox());
			this->Menor = (gcnew System::Windows::Forms::CheckBox());
			this->Igual = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Contiene = (gcnew System::Windows::Forms::CheckBox());
			this->NoContiene = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// May
			// 
			this->May->AutoSize = true;
			this->May->Location = System::Drawing::Point(119, 68);
			this->May->Name = L"May";
			this->May->Size = System::Drawing::Size(76, 17);
			this->May->TabIndex = 0;
			this->May->Text = L"Mayor que";
			this->May->UseVisualStyleBackColor = true;
			// 
			// Menor
			// 
			this->Menor->AutoSize = true;
			this->Menor->Location = System::Drawing::Point(33, 68);
			this->Menor->Name = L"Menor";
			this->Menor->Size = System::Drawing::Size(77, 17);
			this->Menor->TabIndex = 1;
			this->Menor->Text = L"Menor que";
			this->Menor->UseVisualStyleBackColor = true;
			// 
			// Igual
			// 
			this->Igual->AutoSize = true;
			this->Igual->Location = System::Drawing::Point(201, 68);
			this->Igual->Name = L"Igual";
			this->Igual->Size = System::Drawing::Size(70, 17);
			this->Igual->TabIndex = 2;
			this->Igual->Text = L"Igual que";
			this->Igual->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(102, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Edad::button1_Click);
			// 
			// Contiene
			// 
			this->Contiene->AutoSize = true;
			this->Contiene->Location = System::Drawing::Point(33, 91);
			this->Contiene->Name = L"Contiene";
			this->Contiene->Size = System::Drawing::Size(68, 17);
			this->Contiene->TabIndex = 4;
			this->Contiene->Text = L"Contiene";
			this->Contiene->UseVisualStyleBackColor = true;
			// 
			// NoContiene
			// 
			this->NoContiene->AutoSize = true;
			this->NoContiene->Location = System::Drawing::Point(119, 91);
			this->NoContiene->Name = L"NoContiene";
			this->NoContiene->Size = System::Drawing::Size(84, 17);
			this->NoContiene->TabIndex = 5;
			this->NoContiene->Text = L"No contiene";
			this->NoContiene->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Ingrese el dato";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(113, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 7;
			// 
			// Edad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(295, 166);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NoContiene);
			this->Controls->Add(this->Contiene);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Igual);
			this->Controls->Add(this->Menor);
			this->Controls->Add(this->May);
			this->Name = L"Edad";
			this->Text = L"Edad";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
