#pragma once

#include "Storage.h"
#include <msclr/marshal_cppstd.h>

namespace Project5 {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace msclr::interop;

    public ref class EditForm : public System::Windows::Forms::Form
    {
    public:
        // режим добавления
        EditForm(void)
        {
            InitializeComponent();
            isEditMode = false;
            editIndex = -1;
            this->Text = L"Добавить направление";
            // номер сгенерируем при сохранении, поэтому поле скрываем
            txtNumber->Visible = false;
            lblNumber->Visible = false;
        }

        // режим редактирования
        EditForm(int index)
        {
            InitializeComponent();
            isEditMode = true;
            editIndex = index;
            this->Text = L"Изменить направление";

            Storage* storage = Storage::getInstance();
            Counter* c = storage->getCounter(static_cast<size_t>(index));
            if (c != nullptr)
            {
                txtNumber->Text = System::Convert::ToString(c->getNumber());
                txtName->Text = gcnew String(c->getStationName().c_str());
                txtPrice->Text = System::Convert::ToString(c->getTicketPrice());
                txtCountPlace->Text = System::Convert::ToString(c->getCountPlace());
                txtSellTicket->Text = System::Convert::ToString(c->getSellTicket());
            }
        }

    protected:
        ~EditForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        bool isEditMode;
        int  editIndex;

        System::Windows::Forms::Label^ lblNumber;
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::Label^ lblPrice;
        System::Windows::Forms::Label^ lblCountPlace;
        System::Windows::Forms::Label^ lblSellTicket;

        System::Windows::Forms::TextBox^ txtNumber;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtPrice;
        System::Windows::Forms::TextBox^ txtCountPlace;
        System::Windows::Forms::TextBox^ txtSellTicket;

        System::Windows::Forms::Button^ btnOk;
        System::Windows::Forms::Button^ btnCancel;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblNumber = (gcnew System::Windows::Forms::Label());
            this->lblName = (gcnew System::Windows::Forms::Label());
            this->lblPrice = (gcnew System::Windows::Forms::Label());
            this->lblCountPlace = (gcnew System::Windows::Forms::Label());
            this->lblSellTicket = (gcnew System::Windows::Forms::Label());
            this->txtNumber = (gcnew System::Windows::Forms::TextBox());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtPrice = (gcnew System::Windows::Forms::TextBox());
            this->txtCountPlace = (gcnew System::Windows::Forms::TextBox());
            this->txtSellTicket = (gcnew System::Windows::Forms::TextBox());
            this->btnOk = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // lblNumber
            // 
            this->lblNumber->AutoSize = true;
            this->lblNumber->Location = System::Drawing::Point(12, 15);
            this->lblNumber->Name = L"lblNumber";
            this->lblNumber->Size = System::Drawing::Size(60, 17);
            this->lblNumber->TabIndex = 0;
            this->lblNumber->Text = L"Номер:";
            // 
            // lblName
            // 
            this->lblName->AutoSize = true;
            this->lblName->Location = System::Drawing::Point(12, 47);
            this->lblName->Name = L"lblName";
            this->lblName->Size = System::Drawing::Size(128, 17);
            this->lblName->TabIndex = 1;
            this->lblName->Text = L"Название станции:";
            // 
            // lblPrice
            // 
            this->lblPrice->AutoSize = true;
            this->lblPrice->Location = System::Drawing::Point(12, 79);
            this->lblPrice->Name = L"lblPrice";
            this->lblPrice->Size = System::Drawing::Size(104, 17);
            this->lblPrice->TabIndex = 2;
            this->lblPrice->Text = L"Цена билета:";
            // 
            // lblCountPlace
            // 
            this->lblCountPlace->AutoSize = true;
            this->lblCountPlace->Location = System::Drawing::Point(12, 111);
            this->lblCountPlace->Name = L"lblCountPlace";
            this->lblCountPlace->Size = System::Drawing::Size(88, 17);
            this->lblCountPlace->TabIndex = 3;
            this->lblCountPlace->Text = L"Всего мест:";
            // 
            // lblSellTicket
            // 
            this->lblSellTicket->AutoSize = true;
            this->lblSellTicket->Location = System::Drawing::Point(12, 143);
            this->lblSellTicket->Name = L"lblSellTicket";
            this->lblSellTicket->Size = System::Drawing::Size(115, 17);
            this->lblSellTicket->TabIndex = 4;
            this->lblSellTicket->Text = L"Продано мест:";
            // 
            // txtNumber
            // 
            this->txtNumber->Location = System::Drawing::Point(160, 12);
            this->txtNumber->Name = L"txtNumber";
            this->txtNumber->Size = System::Drawing::Size(120, 22);
            this->txtNumber->TabIndex = 5;
            // 
            // txtName
            // 
            this->txtName->Location = System::Drawing::Point(160, 44);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(250, 22);
            this->txtName->TabIndex = 6;
            // 
            // txtPrice
            // 
            this->txtPrice->Location = System::Drawing::Point(160, 76);
            this->txtPrice->Name = L"txtPrice";
            this->txtPrice->Size = System::Drawing::Size(120, 22);
            this->txtPrice->TabIndex = 7;
            // 
            // txtCountPlace
            // 
            this->txtCountPlace->Location = System::Drawing::Point(160, 108);
            this->txtCountPlace->Name = L"txtCountPlace";
            this->txtCountPlace->Size = System::Drawing::Size(120, 22);
            this->txtCountPlace->TabIndex = 8;
            // 
            // txtSellTicket
            // 
            this->txtSellTicket->Location = System::Drawing::Point(160, 140);
            this->txtSellTicket->Name = L"txtSellTicket";
            this->txtSellTicket->Size = System::Drawing::Size(120, 22);
            this->txtSellTicket->TabIndex = 9;
            // 
            // btnOk
            // 
            this->btnOk->Location = System::Drawing::Point(160, 180);
            this->btnOk->Name = L"btnOk";
            this->btnOk->Size = System::Drawing::Size(100, 30);
            this->btnOk->TabIndex = 10;
            this->btnOk->Text = L"OK";
            this->btnOk->UseVisualStyleBackColor = true;
            this->btnOk->Click += gcnew System::EventHandler(this, &EditForm::btnOk_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->Location = System::Drawing::Point(270, 180);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(100, 30);
            this->btnCancel->TabIndex = 11;
            this->btnCancel->Text = L"Отмена";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &EditForm::btnCancel_Click);
            // 
            // EditForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(430, 230);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnOk);
            this->Controls->Add(this->txtSellTicket);
            this->Controls->Add(this->txtCountPlace);
            this->Controls->Add(this->txtPrice);
            this->Controls->Add(this->txtName);
            this->Controls->Add(this->txtNumber);
            this->Controls->Add(this->lblSellTicket);
            this->Controls->Add(this->lblCountPlace);
            this->Controls->Add(this->lblPrice);
            this->Controls->Add(this->lblName);
            this->Controls->Add(this->lblNumber);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Name = L"EditForm";
            this->Text = L"EditForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (String::IsNullOrWhiteSpace(txtName->Text))
            {
                MessageBox::Show("Введите название станции");
                return;
            }

            double price;
            if (!Double::TryParse(txtPrice->Text, price) || price <= 0 || price > 10000)
            {
                MessageBox::Show("Некорректная цена (0 < цена <= 10000)");
                return;
            }

            int countPlace;
            if (!Int32::TryParse(txtCountPlace->Text, countPlace) || countPlace <= 0)
            {
                MessageBox::Show("Количество мест должно быть целым числом > 0");
                return;
            }

            int sellTicket;
            if (!Int32::TryParse(txtSellTicket->Text, sellTicket) || sellTicket < 0 || sellTicket > countPlace)
            {
                MessageBox::Show("Продано мест должно быть от 0 до количества мест");
                return;
            }

            Storage* storage = Storage::getInstance();
            int number;

            if (isEditMode)
            {
                Counter* existing = storage->getCounter(static_cast<size_t>(editIndex));
                if (existing == nullptr)
                {
                    MessageBox::Show("Ошибка: направление не найдено");
                    return;
                }
                number = existing->getNumber();
            }
            else
            {
                number = storage->generateNextNumber();
            }

            std::string name = marshal_as<std::string>(txtName->Text);
            Counter c(number, name, countPlace, sellTicket, price);

            if (isEditMode)
                storage->updateCounter(static_cast<size_t>(editIndex), c);
            else
                storage->addCounter(c);

            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }

        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
        }
    };
}
