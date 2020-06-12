#pragma once
#include <msclr\marshal_cppstd.h>
#include <list>
#include<iterator>
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:

		//Arbol<Persona>* principal = new Arbol<Persona>();
		//Arbol<Persona>* columna1;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Insertar;
	protected:
	private: System::Windows::Forms::Button^ Eliminar;
	private: System::Windows::Forms::Button^ Filtros;



	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox7;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ Numero;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::ListView^ Table;
	private: System::Windows::Forms::ColumnHeader^ cNombre;
	private: System::Windows::Forms::ColumnHeader^ cEquipo;
	private: System::Windows::Forms::ColumnHeader^ cSexo;
	private: System::Windows::Forms::ColumnHeader^ cEdad;
	private: System::Windows::Forms::ColumnHeader^ cNumero;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Insertar = (gcnew System::Windows::Forms::Button());
			this->Eliminar = (gcnew System::Windows::Forms::Button());
			this->Filtros = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->Numero = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->Table = (gcnew System::Windows::Forms::ListView());
			this->cNombre = (gcnew System::Windows::Forms::ColumnHeader());
			this->cEquipo = (gcnew System::Windows::Forms::ColumnHeader());
			this->cSexo = (gcnew System::Windows::Forms::ColumnHeader());
			this->cEdad = (gcnew System::Windows::Forms::ColumnHeader());
			this->cNumero = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// Insertar
			// 
			this->Insertar->Location = System::Drawing::Point(66, 166);
			this->Insertar->Name = L"Insertar";
			this->Insertar->Size = System::Drawing::Size(75, 23);
			this->Insertar->TabIndex = 0;
			this->Insertar->Text = L"Insertar";
			this->Insertar->UseVisualStyleBackColor = true;
			this->Insertar->Click += gcnew System::EventHandler(this, &MyForm::Insertar_Click);
			this->Insertar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Insertar_MouseUp);
			// 
			// Eliminar
			// 
			this->Eliminar->Location = System::Drawing::Point(66, 250);
			this->Eliminar->Name = L"Eliminar";
			this->Eliminar->Size = System::Drawing::Size(75, 23);
			this->Eliminar->TabIndex = 1;
			this->Eliminar->Text = L"Eliminar";
			this->Eliminar->UseVisualStyleBackColor = true;
			// 
			// Filtros
			// 
			this->Filtros->Location = System::Drawing::Point(400, 114);
			this->Filtros->Name = L"Filtros";
			this->Filtros->Size = System::Drawing::Size(128, 23);
			this->Filtros->TabIndex = 2;
			this->Filtros->Text = L"Aplicar Filtros";
			this->Filtros->UseVisualStyleBackColor = true;
			this->Filtros->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(344, 33);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(58, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Igual a";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(344, 57);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(72, 17);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"Inicia con";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(344, 81);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(82, 17);
			this->checkBox3->TabIndex = 7;
			this->checkBox3->Text = L"Finaliza con";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(431, 32);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(112, 17);
			this->checkBox4->TabIndex = 8;
			this->checkBox4->Text = L"Esta contenido en";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(431, 57);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(128, 17);
			this->checkBox5->TabIndex = 9;
			this->checkBox5->Text = L"No esta contenido en";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(431, 81);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(55, 17);
			this->checkBox6->TabIndex = 10;
			this->checkBox6->Text = L"Mayor";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(549, 33);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(56, 17);
			this->checkBox7->TabIndex = 11;
			this->checkBox7->Text = L"Menor";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(77, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(136, 20);
			this->textBox1->TabIndex = 13;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(77, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(136, 20);
			this->textBox2->TabIndex = 14;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(77, 78);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(136, 20);
			this->textBox3->TabIndex = 15;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(77, 108);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(136, 20);
			this->textBox4->TabIndex = 16;
			// 
			// Numero
			// 
			this->Numero->AutoSize = true;
			this->Numero->Location = System::Drawing::Point(29, 29);
			this->Numero->Name = L"Numero";
			this->Numero->Size = System::Drawing::Size(44, 13);
			this->Numero->TabIndex = 17;
			this->Numero->Text = L"Nombre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Equipo";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Sexo";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Edad";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Numero";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(77, 140);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(136, 20);
			this->textBox5->TabIndex = 22;
			// 
			// Table
			// 
			this->Table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->cNombre, this->cEquipo,
					this->cSexo, this->cEdad, this->cNumero
			});
			this->Table->GridLines = true;
			this->Table->HideSelection = false;
			this->Table->Location = System::Drawing::Point(296, 218);
			this->Table->Name = L"Table";
			this->Table->Size = System::Drawing::Size(493, 253);
			this->Table->TabIndex = 23;
			this->Table->UseCompatibleStateImageBehavior = false;
			this->Table->View = System::Windows::Forms::View::Details;
			this->Table->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Table_SelectedIndexChanged);
			// 
			// cNombre
			// 
			this->cNombre->Text = L"Nombre";
			this->cNombre->Width = 260;
			// 
			// cEquipo
			// 
			this->cEquipo->Text = L"Equipo";
			this->cEquipo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->cEquipo->Width = 63;
			// 
			// cSexo
			// 
			this->cSexo->Text = L"Sexo";
			this->cSexo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->cSexo->Width = 54;
			// 
			// cEdad
			// 
			this->cEdad->Text = L"Edad";
			this->cEdad->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->cEdad->Width = 57;
			// 
			// cNumero
			// 
			this->cNumero->Text = L"Numero";
			this->cNumero->Width = 54;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(810, 512);
			this->Controls->Add(this->Table);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Numero);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->Filtros);
			this->Controls->Add(this->Eliminar);
			this->Controls->Add(this->Insertar);
			this->Name = L"MyForm";
			this->Text = L"Mini-SGDB";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	}

private: System::Void Table_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Insertar_Click(System::Object^ sender, System::EventArgs^ e) {


	


}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Insertar_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

}
};
}
