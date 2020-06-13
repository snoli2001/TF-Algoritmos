#pragma once

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Numero
	/// </summary>
	public ref class Numero : public System::Windows::Forms::Form
	{
	public:
		Numero(void)
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
		~Numero()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ MAyor;
	private: System::Windows::Forms::CheckBox^ Menor;
	protected:

	private: System::Windows::Forms::CheckBox^ Igual;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:

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
			this->MAyor = (gcnew System::Windows::Forms::CheckBox());
			this->Menor = (gcnew System::Windows::Forms::CheckBox());
			this->Igual = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// MAyor
			// 
			this->MAyor->AutoSize = true;
			this->MAyor->Location = System::Drawing::Point(25, 63);
			this->MAyor->Name = L"MAyor";
			this->MAyor->Size = System::Drawing::Size(76, 17);
			this->MAyor->TabIndex = 0;
			this->MAyor->Text = L"Mayor que";
			this->MAyor->UseVisualStyleBackColor = true;
			// 
			// Menor
			// 
			this->Menor->AutoSize = true;
			this->Menor->Location = System::Drawing::Point(120, 63);
			this->Menor->Name = L"Menor";
			this->Menor->Size = System::Drawing::Size(77, 17);
			this->Menor->TabIndex = 1;
			this->Menor->Text = L"Menor que";
			this->Menor->UseVisualStyleBackColor = true;
			this->Menor->CheckedChanged += gcnew System::EventHandler(this, &Numero::checkBox2_CheckedChanged);
			// 
			// Igual
			// 
			this->Igual->AutoSize = true;
			this->Igual->Location = System::Drawing::Point(74, 86);
			this->Igual->Name = L"Igual";
			this->Igual->Size = System::Drawing::Size(70, 17);
			this->Igual->TabIndex = 2;
			this->Igual->Text = L"Igual que";
			this->Igual->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(74, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Numero::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Ingrese un numero";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(110, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			// 
			// Numero
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(235, 147);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Igual);
			this->Controls->Add(this->Menor);
			this->Controls->Add(this->MAyor);
			this->Name = L"Numero";
			this->Text = L"Numero";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
		   /*public: String^ get_dato() {

		   }*/

	};
}
