#pragma once
#include <msclr\marshal_cppstd.h>
#include <list>
#include<iterator>
#include "Edad.h"
#include "Equipo.h"
#include "Nombre.h"
#include "Numero.h"
#include "Sexo.h"
#include "Tabla.h"
#include "FuncionesArchivo.h"
#include "FuncionesMenu.h"

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
		Table* tabla = NULL;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			if (tabla != NULL)
				delete tabla;
			tabla = generarDataFrame();
			LLenarTabla();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
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
	private: System::Windows::Forms::Button^ FNombre;












	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ LName;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::ListView^ TableF;

	private: System::Windows::Forms::ColumnHeader^ cNombre;
	private: System::Windows::Forms::ColumnHeader^ cEquipo;
	private: System::Windows::Forms::ColumnHeader^ cSexo;
	private: System::Windows::Forms::ColumnHeader^ cEdad;
	private: System::Windows::Forms::ColumnHeader^ cNumero;
	private: System::Windows::Forms::Button^ FEquipo;
	private: System::Windows::Forms::Button^ fNum;

	private: System::Windows::Forms::Button^ FSexo;
	private: System::Windows::Forms::Button^ FEdad;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;


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
			this->Insertar = (gcnew System::Windows::Forms::Button());
			this->Eliminar = (gcnew System::Windows::Forms::Button());
			this->FNombre = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->LName = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->TableF = (gcnew System::Windows::Forms::ListView());
			this->cNombre = (gcnew System::Windows::Forms::ColumnHeader());
			this->cEquipo = (gcnew System::Windows::Forms::ColumnHeader());
			this->cSexo = (gcnew System::Windows::Forms::ColumnHeader());
			this->cEdad = (gcnew System::Windows::Forms::ColumnHeader());
			this->cNumero = (gcnew System::Windows::Forms::ColumnHeader());
			this->FEquipo = (gcnew System::Windows::Forms::Button());
			this->fNum = (gcnew System::Windows::Forms::Button());
			this->FSexo = (gcnew System::Windows::Forms::Button());
			this->FEdad = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
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
			this->Eliminar->Location = System::Drawing::Point(66, 262);
			this->Eliminar->Name = L"Eliminar";
			this->Eliminar->Size = System::Drawing::Size(75, 23);
			this->Eliminar->TabIndex = 1;
			this->Eliminar->Text = L"Eliminar";
			this->Eliminar->UseVisualStyleBackColor = true;
			// 
			// FNombre
			// 
			this->FNombre->Location = System::Drawing::Point(296, 29);
			this->FNombre->Name = L"FNombre";
			this->FNombre->Size = System::Drawing::Size(89, 23);
			this->FNombre->TabIndex = 2;
			this->FNombre->Text = L"Filtros Nombre";
			this->FNombre->UseVisualStyleBackColor = true;
			this->FNombre->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
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
			// LName
			// 
			this->LName->AutoSize = true;
			this->LName->Location = System::Drawing::Point(29, 29);
			this->LName->Name = L"LName";
			this->LName->Size = System::Drawing::Size(44, 13);
			this->LName->TabIndex = 17;
			this->LName->Text = L"Nombre";
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
			// TableF
			// 
			this->TableF->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->cNombre, this->cEquipo,
					this->cSexo, this->cEdad, this->cNumero
			});
			this->TableF->GridLines = true;
			this->TableF->HideSelection = false;
			this->TableF->Location = System::Drawing::Point(296, 218);
			this->TableF->Name = L"TableF";
			this->TableF->Size = System::Drawing::Size(493, 253);
			this->TableF->TabIndex = 23;
			this->TableF->UseCompatibleStateImageBehavior = false;
			this->TableF->View = System::Windows::Forms::View::Details;
			this->TableF->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Table_SelectedIndexChanged);
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
			// FEquipo
			// 
			this->FEquipo->Location = System::Drawing::Point(391, 29);
			this->FEquipo->Name = L"FEquipo";
			this->FEquipo->Size = System::Drawing::Size(83, 23);
			this->FEquipo->TabIndex = 24;
			this->FEquipo->Text = L"Filtros Equipo";
			this->FEquipo->UseVisualStyleBackColor = true;
			this->FEquipo->Click += gcnew System::EventHandler(this, &MyForm::FEquipo_Click);
			// 
			// fNum
			// 
			this->fNum->Location = System::Drawing::Point(676, 29);
			this->fNum->Name = L"fNum";
			this->fNum->Size = System::Drawing::Size(75, 23);
			this->fNum->TabIndex = 25;
			this->fNum->Text = L"Filtro numero";
			this->fNum->UseVisualStyleBackColor = true;
			this->fNum->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// FSexo
			// 
			this->FSexo->Location = System::Drawing::Point(490, 29);
			this->FSexo->Name = L"FSexo";
			this->FSexo->Size = System::Drawing::Size(75, 23);
			this->FSexo->TabIndex = 26;
			this->FSexo->Text = L"Filtro Sexo";
			this->FSexo->UseVisualStyleBackColor = true;
			this->FSexo->Click += gcnew System::EventHandler(this, &MyForm::FSexo_Click);
			// 
			// FEdad
			// 
			this->FEdad->Location = System::Drawing::Point(584, 29);
			this->FEdad->Name = L"FEdad";
			this->FEdad->Size = System::Drawing::Size(75, 23);
			this->FEdad->TabIndex = 27;
			this->FEdad->Text = L"Filtro Edad";
			this->FEdad->UseVisualStyleBackColor = true;
			this->FEdad->Click += gcnew System::EventHandler(this, &MyForm::FEdad_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Nombre", L"Equipo", L"Sexo ", L"Edad", L"Numero" });
			this->comboBox1->Location = System::Drawing::Point(538, 103);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 28;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(448, 106);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Ordenar por";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(810, 512);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->FEdad);
			this->Controls->Add(this->FSexo);
			this->Controls->Add(this->fNum);
			this->Controls->Add(this->FEquipo);
			this->Controls->Add(this->TableF);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->LName);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->FNombre);
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
		Nombre^ nombreForm = gcnew Nombre();
		nombreForm->ShowDialog();
	}

	private: System::Void Table_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Insertar_Click(System::Object^ sender, System::EventArgs^ e) {





	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Insertar_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	}
	private: System::Void FEquipo_Click(System::Object^ sender, System::EventArgs^ e) {
		Equipo^ equipo = gcnew Equipo();
		equipo->ShowDialog();
	}
	private: System::Void FSexo_Click(System::Object^ sender, System::EventArgs^ e) {
		Sexo^ sexo = gcnew Sexo();
		sexo->ShowDialog();

	}
	private: System::Void FEdad_Click(System::Object^ sender, System::EventArgs^ e) {
		Edad^ edad = gcnew Edad();
		edad->ShowDialog();


	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Numero^ num = gcnew Numero();
		num->ShowDialog();

	}
	public: 
	void LLenarTabla() {
		vector<vector<string>> content = tabla->get_content();
		TableF->Items->Clear();
		for (int i = 0; i < content.size(); i++)
		{
			
			ListViewItem^ item = gcnew ListViewItem();
			
			item->Text =gcnew String(content[i][0].c_str());
			item->SubItems->Add(gcnew String(content[i][1].c_str()));
			item->SubItems->Add(gcnew String(content[i][2].c_str()));
			item->SubItems->Add(gcnew String(content[i][3].c_str()));
			item->SubItems->Add(gcnew String(content[i][4].c_str()));
			this->TableF->Items->Add(item);
		}
		
	}
	};
}
