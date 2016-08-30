#pragma once
#include "Solitario.h"
#include "VecJugadores.h"
#include "FormMejoresTiempos.h"
#include "FormAyuda.h"
#include <stdlib.h>
#include <time.h>
namespace solitario_0_3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		CSolitario * solitario;
	private: System::Windows::Forms::ToolStripButton^  btn_tiempo;

	private: System::Windows::Forms::ToolStripComboBox^  cb_barra;
	private: System::Windows::Forms::ToolStripButton^  btn_ayuda;


			 CVecJugadores * jugadores;
	public:
		Form1(void)
		{
			solitario = new CSolitario();
			jugadores = new CVecJugadores();
			InitializeComponent();
			solitario->inicializar(picBaraja->Image, time(NULL), 0, true);
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			delete jugadores;
			delete solitario;
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  picBaraja;
	private: System::Windows::Forms::PictureBox^  picBG;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  btn_reiniciar;
	private: System::Windows::Forms::ToolStripButton^  btn_deshacer;


	private: System::Windows::Forms::ToolStripComboBox^  cb_carta_inicio;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;




	protected: 
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->picBaraja = (gcnew System::Windows::Forms::PictureBox());
			this->picBG = (gcnew System::Windows::Forms::PictureBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->cb_carta_inicio = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->cb_barra = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->btn_reiniciar = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->btn_deshacer = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_ayuda = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_tiempo = (gcnew System::Windows::Forms::ToolStripButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBaraja))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBG))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// picBaraja
			// 
			this->picBaraja->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picBaraja.Image")));
			this->picBaraja->Location = System::Drawing::Point(12, 33);
			this->picBaraja->Name = L"picBaraja";
			this->picBaraja->Size = System::Drawing::Size(936, 480);
			this->picBaraja->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picBaraja->TabIndex = 0;
			this->picBaraja->TabStop = false;
			this->picBaraja->Visible = false;
			// 
			// picBG
			// 
			this->picBG->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picBG.Image")));
			this->picBG->Location = System::Drawing::Point(174, 79);
			this->picBG->Name = L"picBG";
			this->picBG->Size = System::Drawing::Size(100, 50);
			this->picBG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBG->TabIndex = 1;
			this->picBG->TabStop = false;
			this->picBG->Visible = false;
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::Color::White;
			this->toolStrip1->GripMargin = System::Windows::Forms::Padding(0);
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->toolStripSeparator3, 
				this->toolStripButton1, this->cb_carta_inicio, this->cb_barra, this->toolStripSeparator1, this->btn_reiniciar, this->toolStripSeparator2, 
				this->btn_deshacer, this->btn_ayuda, this->btn_tiempo});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(834, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->AutoSize = false;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(19, 22);
			this->toolStripButton1->Text = L"Nuevo";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// cb_carta_inicio
			// 
			this->cb_carta_inicio->AutoSize = false;
			this->cb_carta_inicio->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"0", L"5", L"10", L"12"});
			this->cb_carta_inicio->Name = L"cb_carta_inicio";
			this->cb_carta_inicio->Size = System::Drawing::Size(56, 23);
			this->cb_carta_inicio->Text = L"Cartas";
			// 
			// cb_barra
			// 
			this->cb_barra->AutoSize = false;
			this->cb_barra->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Sí", L"No"});
			this->cb_barra->Name = L"cb_barra";
			this->cb_barra->Size = System::Drawing::Size(50, 23);
			this->cb_barra->Text = L"Barra";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// btn_reiniciar
			// 
			this->btn_reiniciar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_reiniciar->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_reiniciar.Image")));
			this->btn_reiniciar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_reiniciar->Name = L"btn_reiniciar";
			this->btn_reiniciar->Size = System::Drawing::Size(23, 22);
			this->btn_reiniciar->Text = L"Reiniciar";
			this->btn_reiniciar->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// btn_deshacer
			// 
			this->btn_deshacer->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_deshacer->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_deshacer.Image")));
			this->btn_deshacer->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_deshacer->Name = L"btn_deshacer";
			this->btn_deshacer->Size = System::Drawing::Size(23, 22);
			this->btn_deshacer->Text = L"Deshacer";
			this->btn_deshacer->Click += gcnew System::EventHandler(this, &Form1::btn_deshacer_Click);
			// 
			// btn_ayuda
			// 
			this->btn_ayuda->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->btn_ayuda->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_ayuda->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_ayuda.Image")));
			this->btn_ayuda->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_ayuda->Name = L"btn_ayuda";
			this->btn_ayuda->Size = System::Drawing::Size(23, 22);
			this->btn_ayuda->Text = L"toolStripButton2";
			this->btn_ayuda->Click += gcnew System::EventHandler(this, &Form1::btn_ayuda_Click);
			// 
			// btn_tiempo
			// 
			this->btn_tiempo->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->btn_tiempo->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_tiempo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_tiempo.Image")));
			this->btn_tiempo->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_tiempo->Name = L"btn_tiempo";
			this->btn_tiempo->Size = System::Drawing::Size(23, 22);
			this->btn_tiempo->Text = L"Mejores tiempos ...";
			this->btn_tiempo->Click += gcnew System::EventHandler(this, &Form1::btn_tiempo_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(834, 621);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->picBG);
			this->Controls->Add(this->picBaraja);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Solitario";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBaraja))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBG))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {	 
			 if (this->WindowState != FormWindowState::Minimized)
			 {
				 Bitmap ^bmp = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
				 Graphics ^buffer = Graphics::FromImage(bmp);
				 buffer->Clear(Color::White);
				 buffer->DrawImage(picBG->Image,0,0,this->ClientSize.Width,this->ClientSize.Height);
				 solitario->dibujar_todos(buffer, picBaraja->Image);
				 Graphics ^g = this->CreateGraphics();
				 g->DrawImage(bmp, 0, 0);
				 delete bmp;
				 delete buffer;
				 delete g;
		     }
			 solitario->aumentarTiempo();
			 if (solitario->getBarraActivada())
				 solitario->getBarra()->disminuir();
			 if (solitario->verificar_victoria())
			 {
				 timer1->Stop();
				 MessageBox::Show(" Ganaste! ");
				 CJugador * nuevo = new CJugador();
				 nuevo->setCartasIniciales(solitario->getCartasIniciales());
				 nuevo->setMovimientos(solitario->getMovimientos());
				 nuevo->setTiempo(solitario->getTiempo());
				 jugadores->agregarJugador(nuevo);
				 if (jugadores->verificar_mejor_tiempo(nuevo->getTiempo()))
					 MessageBox::Show(" Mejor tiempo! ");
				 jugadores->ordenar();
				 if (jugadores->getN() > 5)
					jugadores->eliminarUltimo();
				 FormMejoresTiempos ^ftiempo = gcnew FormMejoresTiempos(jugadores);
				 ftiempo->ShowDialog();
				 CSolitario * solitarioAux = new CSolitario();
				 delete solitario;
				 solitario = solitarioAux;
				 solitario->inicializar(picBaraja->Image, time(NULL), 0, true);
				 timer1->Start();
			 }
			 if (solitario->verificar_derrota() > 0)
			 {
				 timer1->Stop();
				 MessageBox::Show(" Perdiste! ");
				 CSolitario * solitarioAux = new CSolitario();
				 delete solitario;
				 solitario = solitarioAux;
				 solitario->inicializar(picBaraja->Image, time(NULL), 0, true);
				 timer1->Start();
			 }
		 }
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Stop();
			 int num;
			 if(Int32::TryParse(cb_carta_inicio->Text,num))
			 {
				 if(num >= 0 && num <= 12)
				 {
					 CSolitario * solitarioAux = new CSolitario();
					 delete solitario;
					 solitario = solitarioAux;
					 solitario->inicializar(picBaraja->Image, time(NULL), num, cb_barra->Text == "Sí");
				 }
				 else
				 {
					 MessageBox::Show(" El numero ingresado debe estar entre 0 y 12 ");
				 }
			 }
			 timer1->Start();
		 }
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			 timer1->Stop();
			 int semilla = solitario->getSemilla();
			 int cartasIniciales = solitario->getCartasIniciales();
			 bool act = solitario->getBarraActivada();
			 CSolitario * solitarioAux = new CSolitario();
			 delete solitario;
			 solitario = solitarioAux;
			 solitario->inicializar(picBaraja->Image, semilla, cartasIniciales, act);
			 timer1->Start();
		 }
private: System::Void btn_deshacer_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 solitario->deshacer();
		 }
private: System::Void btn_tiempo_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Stop();
			 FormMejoresTiempos ^ftiempo = gcnew FormMejoresTiempos(jugadores);
			 ftiempo->ShowDialog();
			 timer1->Start();
		 }
private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if (e->Button == System::Windows::Forms::MouseButtons::Left)
				solitario->interactuar_con_click(e->X, e->Y);
			 else if (e->Button == System::Windows::Forms::MouseButtons::Right)
				solitario->interactuar_con_click_der(e->X, e->Y);
		 }
private: System::Void btn_ayuda_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 timer1->Stop();
			 FormAyuda ^fAyuda = gcnew FormAyuda();
			 fAyuda->ShowDialog();
			 timer1->Start();
		 }
};
}

