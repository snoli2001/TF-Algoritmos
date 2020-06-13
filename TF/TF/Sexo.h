#pragma once

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Sexo
	/// </summary>
	public ref class Sexo : public System::Windows::Forms::Form
	{
	public:
		Sexo(void)
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
		~Sexo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ Masculino;
	private: System::Windows::Forms::CheckBox^ Femenino;
	protected:


	private: System::Windows::Forms::Button^ button1;
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
			this->Masculino = (gcnew System::Windows::Forms::CheckBox());
			this->Femenino = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Masculino
			// 
			this->Masculino->AutoSize = true;
			this->Masculino->Location = System::Drawing::Point(31, 21);
			this->Masculino->Name = L"Masculino";
			this->Masculino->Size = System::Drawing::Size(74, 17);
			this->Masculino->TabIndex = 0;
			this->Masculino->Text = L"Masculino";
			this->Masculino->UseVisualStyleBackColor = true;
			this->Masculino->CheckedChanged += gcnew System::EventHandler(this, &Sexo::checkBox1_CheckedChanged);
			// 
			// Femenino
			// 
			this->Femenino->AutoSize = true;
			this->Femenino->Location = System::Drawing::Point(31, 44);
			this->Femenino->Name = L"Femenino";
			this->Femenino->Size = System::Drawing::Size(72, 17);
			this->Femenino->TabIndex = 1;
			this->Femenino->Text = L"Femenino";
			this->Femenino->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(28, 67);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Sexo::button1_Click);
			// 
			// Sexo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(174, 112);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Femenino);
			this->Controls->Add(this->Masculino);
			this->Name = L"Sexo";
			this->Text = L"Sexo";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	public: String^ getSex(int& cont) {
		if (Masculino->Checked == true) {
			cont++;
			return "M";
		}
		else if (Femenino->Checked == true)
		{
			cont++;
			return "F";
		}
	}
	};
}
