#pragma once
#include "VecJugadores.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace solitario_0_3 {

	/// <summary>
	/// Summary for FormMejoresTiempos
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormMejoresTiempos : public System::Windows::Forms::Form
	{
	private:
		CVecJugadores * jugadores;
	public:
		FormMejoresTiempos(CVecJugadores * pJugadores)
		{
			jugadores = pJugadores;
			InitializeComponent();
		}
		FormMejoresTiempos(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormMejoresTiempos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_cerrar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  picBG;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMejoresTiempos::typeid));
			this->btn_cerrar = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->picBG = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBG))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_cerrar
			// 
			this->btn_cerrar->Location = System::Drawing::Point(88, 199);
			this->btn_cerrar->Name = L"btn_cerrar";
			this->btn_cerrar->Size = System::Drawing::Size(73, 25);
			this->btn_cerrar->TabIndex = 0;
			this->btn_cerrar->Text = L"Cerrar";
			this->btn_cerrar->UseVisualStyleBackColor = true;
			this->btn_cerrar->Click += gcnew System::EventHandler(this, &FormMejoresTiempos::btn_cerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormMejoresTiempos::timer1_Tick);
			// 
			// picBG
			// 
			this->picBG->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picBG.Image")));
			this->picBG->Location = System::Drawing::Point(12, 41);
			this->picBG->Name = L"picBG";
			this->picBG->Size = System::Drawing::Size(100, 50);
			this->picBG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picBG->TabIndex = 1;
			this->picBG->TabStop = false;
			this->picBG->Visible = false;
			// 
			// FormMejoresTiempos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(245, 232);
			this->ControlBox = false;
			this->Controls->Add(this->picBG);
			this->Controls->Add(this->btn_cerrar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"FormMejoresTiempos";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mejores Tiempos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBG))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Bitmap ^bmp = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
				 Graphics ^buffer = Graphics::FromImage(bmp);
				 buffer->Clear(Color::White);
				 buffer->DrawImage(picBG->Image,0,0,this->ClientSize.Width,this->ClientSize.Height);
				 jugadores->dibujar(buffer);
				 Graphics ^g = this->CreateGraphics();
				 g->DrawImage(bmp, 0, 0);
				 delete bmp;
				 delete buffer;
				 delete g;
			 }
	private: System::Void btn_cerrar_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 this->Close();
			 }
};
}
