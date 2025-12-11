#pragma once

#include "Storage.h"
#include "EditForm.h"
#include <msclr/marshal_cppstd.h>

namespace Project5 {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Text;
    using namespace msclr::interop;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            RefreshGrid();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ btnLoad;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnEdit;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnSortName;
        System::Windows::Forms::Button^ btnSortUnsold;
        System::Windows::Forms::Button^ btnShowUnsold;
        System::Windows::Forms::Label^ lblTitle;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->btnLoad = (gcnew System::Windows::Forms::Button());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnEdit = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnSortName = (gcnew System::Windows::Forms::Button());
            this->btnSortUnsold = (gcnew System::Windows::Forms::Button());
            this->btnShowUnsold = (gcnew System::Windows::Forms::Button());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(12, 50);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersVisible = false;
            this->dataGridView1->Size = System::Drawing::Size(760, 300);
            this->dataGridView1->TabIndex = 0;
            {
                auto colNumber = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
                colNumber->HeaderText = L"№";
                colNumber->Name = L"colNumber";
                colNumber->Width = 40;

                auto colName = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
                colName->HeaderText = L"Станция";
                colName->Name = L"colName";
                colName->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

                auto colPrice = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
                colPrice->HeaderText = L"Цена";
                colPrice->Name = L"colPrice";
                colPrice->Width = 80;

                auto colTotal = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
                colTotal->HeaderText = L"Мест всего";
                colTotal->Name = L"colTotal";
                colTotal->Width = 90;

                auto colSold = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
                colSold->HeaderText = L"Продано";
                colSold->Name = L"colSold";
                colSold->Width = 80;

                auto colUnsold = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
                colUnsold->HeaderText = L"Свободно";
                colUnsold->Name = L"colUnsold";
                colUnsold->Width = 80;

                auto colUnsoldAmount = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
                colUnsoldAmount->HeaderText = L"Сумма непрод.";
                colUnsoldAmount->Name = L"colUnsoldAmount";
                colUnsoldAmount->Width = 110;

                this->dataGridView1->Columns->Add(colNumber);
                this->dataGridView1->Columns->Add(colName);
                this->dataGridView1->Columns->Add(colPrice);
                this->dataGridView1->Columns->Add(colTotal);
                this->dataGridView1->Columns->Add(colSold);
                this->dataGridView1->Columns->Add(colUnsold);
                this->dataGridView1->Columns->Add(colUnsoldAmount);
            }
           
            this->btnLoad->Location = System::Drawing::Point(12, 370);
            this->btnLoad->Name = L"btnLoad";
            this->btnLoad->Size = System::Drawing::Size(100, 30);
            this->btnLoad->TabIndex = 1;
            this->btnLoad->Text = L"Загрузить";
            this->btnLoad->UseVisualStyleBackColor = true;
            this->btnLoad->Click += gcnew System::EventHandler(this, &MyForm::btnLoad_Click);
            // 
            // btnSave
            // 
            this->btnSave->Location = System::Drawing::Point(118, 370);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(100, 30);
            this->btnSave->TabIndex = 2;
            this->btnSave->Text = L"Сохранить";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &MyForm::btnSave_Click);
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(230, 370);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(100, 30);
            this->btnAdd->TabIndex = 3;
            this->btnAdd->Text = L"Добавить";
            this->btnAdd->UseVisualStyleBackColor = true;
            this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
            // 
            // btnEdit
            // 
            this->btnEdit->Location = System::Drawing::Point(336, 370);
            this->btnEdit->Name = L"btnEdit";
            this->btnEdit->Size = System::Drawing::Size(110, 30);
            this->btnEdit->TabIndex = 4;
            this->btnEdit->Text = L"Изменить";
            this->btnEdit->UseVisualStyleBackColor = true;
            this->btnEdit->Click += gcnew System::EventHandler(this, &MyForm::btnEdit_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(452, 370);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(100, 30);
            this->btnDelete->TabIndex = 5;
            this->btnDelete->Text = L"Удалить";
            this->btnDelete->UseVisualStyleBackColor = true;
            this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
            // 
            // btnSortName
            // 
            this->btnSortName->Location = System::Drawing::Point(564, 370);
            this->btnSortName->Name = L"btnSortName";
            this->btnSortName->Size = System::Drawing::Size(100, 30);
            this->btnSortName->TabIndex = 6;
            this->btnSortName->Text = L"Сорт. имя";
            this->btnSortName->UseVisualStyleBackColor = true;
            this->btnSortName->Click += gcnew System::EventHandler(this, &MyForm::btnSortName_Click);
            // 
            // btnSortUnsold
            // 
            this->btnSortUnsold->Location = System::Drawing::Point(670, 370);
            this->btnSortUnsold->Name = L"btnSortUnsold";
            this->btnSortUnsold->Size = System::Drawing::Size(100, 30);
            this->btnSortUnsold->TabIndex = 7;
            this->btnSortUnsold->Text = L"Сорт. непрод.";
            this->btnSortUnsold->UseVisualStyleBackColor = true;
            this->btnSortUnsold->Click += gcnew System::EventHandler(this, &MyForm::btnSortUnsold_Click);
            // 
            // btnShowUnsold
            // 
            this->btnShowUnsold->Location = System::Drawing::Point(12, 410);
            this->btnShowUnsold->Name = L"btnShowUnsold";
            this->btnShowUnsold->Size = System::Drawing::Size(200, 30);
            this->btnShowUnsold->TabIndex = 8;
            this->btnShowUnsold->Text = L"Стоимость непроданных";
            this->btnShowUnsold->UseVisualStyleBackColor = true;
            this->btnShowUnsold->Click += gcnew System::EventHandler(this, &MyForm::btnShowUnsold_Click);
            // 
            // lblTitle
            // 
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->lblTitle->Location = System::Drawing::Point(12, 9);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(454, 31);
            this->lblTitle->TabIndex = 9;
            this->lblTitle->Text = L"Направления поездов (касса билетов)";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 461);
            this->Controls->Add(this->lblTitle);
            this->Controls->Add(this->btnShowUnsold);
            this->Controls->Add(this->btnSortUnsold);
            this->Controls->Add(this->btnSortName);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->btnEdit);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->btnLoad);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"MyForm";
            this->Text = L"TicketApp";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        void RefreshGrid()
        {
            dataGridView1->Rows->Clear();

            Storage* storage = Storage::getInstance();
            const auto& list = storage->getCounters();

            for (const auto& c : list)
            {
                System::String^ sNumber = System::Convert::ToString(c.getNumber());
                System::String^ sName = gcnew System::String(c.getStationName().c_str());
                System::String^ sPrice = System::String::Format("{0:F2}", c.getTicketPrice());
                System::String^ sTotal = System::Convert::ToString(c.getCountPlace());
                System::String^ sSold = System::Convert::ToString(c.getSellTicket());
                System::String^ sUnsold = System::Convert::ToString(c.getUnsoldCount());
                System::String^ sUnsoldAmount = System::String::Format("{0:F2}", c.getUnsoldAmount());

                dataGridView1->Rows->Add(sNumber, sName, sPrice, sTotal, sSold, sUnsold, sUnsoldAmount);
            }
        }

        System::Void btnLoad_Click(System::Object^ sender, System::EventArgs^ e)
        {
            OpenFileDialog^ ofd = gcnew OpenFileDialog();
            ofd->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";

            if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                std::string path = marshal_as<std::string>(ofd->FileName);
                Storage* storage = Storage::getInstance();
                if (!storage->loadFromFile(path))
                    MessageBox::Show("Не удалось загрузить файл");
                RefreshGrid();
            }
        }

        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
        {
            SaveFileDialog^ sfd = gcnew SaveFileDialog();
            sfd->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";

            if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                std::string path = marshal_as<std::string>(sfd->FileName);
                Storage* storage = Storage::getInstance();
                if (!storage->saveToFile(path))
                    MessageBox::Show("Не удалось сохранить файл");
            }
        }

        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
        {
            EditForm^ form = gcnew EditForm();
            if (form->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                RefreshGrid();
        }

        System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (dataGridView1->CurrentRow == nullptr)
            {
                MessageBox::Show("Выберите строку для редактирования");
                return;
            }
            int index = dataGridView1->CurrentRow->Index;

            EditForm^ form = gcnew EditForm(index);
            if (form->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                RefreshGrid();
        }

        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (dataGridView1->CurrentRow == nullptr)
            {
                MessageBox::Show("Выберите строку для удаления");
                return;
            }
            int index = dataGridView1->CurrentRow->Index;

            Storage* storage = Storage::getInstance();
            storage->removeCounter(static_cast<size_t>(index));
            RefreshGrid();
        }

        System::Void btnSortName_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Storage* storage = Storage::getInstance();
            storage->sortByName();
            RefreshGrid();
        }

        System::Void btnSortUnsold_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Storage* storage = Storage::getInstance();
            storage->sortByUnsoldAmountDesc();
            RefreshGrid();
        }

        System::Void btnShowUnsold_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Storage* storage = Storage::getInstance();
            const auto& list = storage->getCounters();

            if (list.empty())
            {
                MessageBox::Show("Список направлений пуст");
                return;
            }

            StringBuilder^ sb = gcnew StringBuilder();
            for (const auto& c : list)
            {
                System::String^ name = gcnew System::String(c.getStationName().c_str());
                sb->Append(name);
                sb->Append(" - ");
                sb->Append(System::String::Format("{0:F2}", c.getUnsoldAmount()));
                sb->Append(" (");
                sb->Append(System::Convert::ToString(c.getUnsoldCount()));
                sb->Append(" мест)\n");
            }

            MessageBox::Show(sb->ToString(), "Стоимость непроданных билетов");
        }
    };
}
