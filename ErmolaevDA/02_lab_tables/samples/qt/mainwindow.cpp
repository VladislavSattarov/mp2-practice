﻿#include "mainwindow.h"
#include <string>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateHash()
{
    std::stringstream tmp;
    tmp << HS;
    ui->textBrowser_2->setText(QString::fromStdString(tmp.str()));
    ui->textBrowser_10->setText(QString::fromStdString(tmp.str()));
}
void MainWindow::updateSort()
{
    std::stringstream tmp;
    tmp << SR;
    ui->textBrowser_3->setText(QString::fromStdString(tmp.str()));
    ui->textBrowser_11->setText(QString::fromStdString(tmp.str()));
}
void MainWindow::updateScan()
{
    std::stringstream tmp;
    tmp << ST;
    ui->textBrowser_4->setText(QString::fromStdString(tmp.str()));
    ui->textBrowser_12->setText(QString::fromStdString(tmp.str()));
}

void MainWindow::on_pushButton_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    Polinom A;
    if((ui->comboBox->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома A в выбранную таблицу...");
    A.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    HS.InsertRecord(A,strig2.toStdString());
    updateHash();
    }
    else{
        i++;
        HS.InsertRecord(A,to_string(i));
        updateHash();
    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }

    if((ui->comboBox->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома A в выбранную таблицу...");
    A.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    SR.InsertRecord(A,strig2.toStdString());
    updateSort();
    }
    else{
        j++;
        SR.InsertRecord(A,to_string(j));
        updateSort();
    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }


    if((ui->comboBox->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома A в выбранную таблицу...");
    A.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    ST.InsertRecord(A,strig2.toStdString());
    updateScan();
    }
    else{
        k++;
        ST.InsertRecord(A,to_string(k));
        updateScan();
    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }

    if((ui->comboBox->currentText())== "All Tables")
    {
    ui->textBrowser->append("Выбраны все таблицы для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома A в выбранные таблицу...");
    A.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){

    HS.InsertRecord(A,strig2.toStdString());
    updateHash();
    SR.InsertRecord(A,strig2.toStdString());
    updateSort();
    ST.InsertRecord(A,strig2.toStdString());
    updateScan();

    }
    else{
        i++;
        j++;
        k++;
        HS.InsertRecord(A,to_string(i));
        updateHash();
        SR.InsertRecord(A,to_string(j));
        updateSort();
        ST.InsertRecord(A,to_string(k));
        updateScan();

    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }
}


void MainWindow::on_pushButton_2_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    Polinom B;
    if((ui->comboBox_2->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранную таблицу...");
    B.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    HS.InsertRecord(B,strig2.toStdString());
    updateHash();
    }
    else{
        i++;
        HS.InsertRecord(B,to_string(i));
        updateHash();
    }
     }
     else{
         ui->textBrowser->append("Полином B пустой");
     }

    }

    if((ui->comboBox_2->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранную таблицу...");
    B.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    SR.InsertRecord(B,strig2.toStdString());
    updateSort();
    }
    else{
        j++;
        SR.InsertRecord(B,to_string(j));
        updateSort();
    }
     }
     else{
         ui->textBrowser->append("Полином B пустой");
     }

    }


    if((ui->comboBox_2->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранную таблицу...");
    B.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    ST.InsertRecord(B,strig2.toStdString());
    updateScan();
    }
    else{
        k++;
        ST.InsertRecord(B,to_string(k));
        updateScan();
    }
     }
     else{
         ui->textBrowser->append("Полином B пустой");
     }

    }

    if((ui->comboBox_2->currentText())== "All Tables")
    {
    ui->textBrowser->append("Выбраны все таблицы для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранные таблицу...");
    B.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){

    HS.InsertRecord(B,strig2.toStdString());
    updateHash();
    SR.InsertRecord(B,strig2.toStdString());
    updateSort();
    ST.InsertRecord(B,strig2.toStdString());
    updateScan();

    }
    else{
        i++;
        j++;
        k++;
        HS.InsertRecord(B,to_string(i));
        updateHash();
        SR.InsertRecord(B,to_string(j));
        updateSort();
        ST.InsertRecord(B,to_string(k));
        updateScan();

    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }

}


void MainWindow::on_pushButton_4_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;

    if((ui->comboBox->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома A из выбранной таблицы...");

    if (strig2!=nullptr){
    HS.RemoveRecord(strig2.toStdString());
    updateHash();
    }
    else{
         ui->textBrowser->append("Впишите в ключ А, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином А, который хотите удалить");
     }
    }

    if((ui->comboBox->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома A из выбранной таблицы...");

    if (strig2!=nullptr){
    SR.RemoveRecord(strig2.toStdString());
    updateSort();
    }
    else{
         ui->textBrowser->append("Впишите в ключ А, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином А, который хотите удалить");
     }
    }

    if((ui->comboBox->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома A из выбранной таблицы...");

    if (strig2!=nullptr){
    ST.RemoveRecord(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ А, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином А, который хотите удалить");
     }

    }

    if((ui->comboBox->currentText())== "All Tables")
    {
    ui->textBrowser->append("Выбраны все таблицы для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома A из выбранных таблиц...");

    if (strig2!=nullptr){
    HS.RemoveRecord(strig2.toStdString());
    updateHash();
    SR.RemoveRecord(strig2.toStdString());
    updateSort();
    ST.RemoveRecord(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ А, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином А, который хотите удалить");
     }
    }
}


void MainWindow::on_pushButton_5_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    if((ui->comboBox_2->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома B из выбранной таблицы...");

    if (strig2!=nullptr){
    HS.RemoveRecord(strig2.toStdString());
    updateHash();
    }
    else{
         ui->textBrowser->append("Впишите в ключ B, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином B, который хотите удалить");
     }
    }

    if((ui->comboBox_2->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома B из выбранной таблицы...");

    if (strig2!=nullptr){
    SR.RemoveRecord(strig2.toStdString());
    updateSort();
    }
    else{
         ui->textBrowser->append("Впишите в ключ B, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином B, который хотите удалить");
     }
    }

    if((ui->comboBox_2->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома B из выбранной таблицы...");

    if (strig2!=nullptr){
    ST.RemoveRecord(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ B, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином B, который хотите удалить");
     }

    }
    if((ui->comboBox->currentText())== "All Tables")
    {
    ui->textBrowser->append("Выбраны все таблицы для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома B из выбранных таблиц...");

    if (strig2!=nullptr){
    HS.RemoveRecord(strig2.toStdString());
    updateHash();
    SR.RemoveRecord(strig2.toStdString());
    updateSort();
    ST.RemoveRecord(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ B, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином B, который хотите удалить");
     }
    }
}


void MainWindow::on_pushButton_7_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
Polinom A;
Polinom B;
AB*=0;
std::stringstream tmp;
QString stA = ui->textEdit->toPlainText().trimmed();
QString stB = ui->textEdit_2->toPlainText().trimmed();

if ((stA==nullptr)||(stB==nullptr)){
    if (stA==nullptr) ui->textBrowser->append("Полином A пуст,нечего считать");
    if (stB==nullptr) ui->textBrowser->append("Полином B пуст,нечего считать");
}
else {
    A.str_to_poly(stA.toStdString());
    B.str_to_poly(stB.toStdString());

if((ui->comboBox_3->currentText())== "A +B"){
    AB=A+B;
    ui->textBrowser->append("Расчёт суммы A+B");
    tmp << AB;
    ui->textEdit_3->setText(QString::fromStdString(tmp.str()));
}
if((ui->comboBox_3->currentText())== "A - B"){
    AB=A-B;
    ui->textBrowser->append("Расчёт разности A-B");
    tmp << AB;
    ui->textEdit_3->setText(QString::fromStdString(tmp.str()));
}
if((ui->comboBox_3->currentText())== "A * B"){
    AB=A*B;
    ui->textBrowser->append("Расчёт произведения A*B");
    tmp << AB;
    ui->textEdit_3->setText(QString::fromStdString(tmp.str()));
}

}

}


void MainWindow::on_pushButton_3_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    if((ui->comboBox_4->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома AB в выбранную таблицу...");
    //AB.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    HS.InsertRecord(AB,strig2.toStdString());
    updateHash();
    }
    else{
        i++;
        HS.InsertRecord(AB,to_string(i));
        updateHash();
    }
     }
     else{
         ui->textBrowser->append("Полином AB пустой, сосчитайте его");
     }

    }

    if((ui->comboBox_4->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома AB в выбранную таблицу...");
    //AB.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    SR.InsertRecord(AB,strig2.toStdString());
    updateSort();
    }
    else{
        j++;
        SR.InsertRecord(AB,to_string(j));
        updateSort();
    }
     }
     else{
          ui->textBrowser->append("Полином AB пустой, сосчитайте его");
     }

    }


    if((ui->comboBox_4->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома AB в выбранную таблицу...");
    //AB.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    ST.InsertRecord(AB,strig2.toStdString());
    updateScan();
    }
    else{
        k++;
        ST.InsertRecord(AB,to_string(k));
        updateScan();
    }
     }
     else{
          ui->textBrowser->append("Полином AB пустой, сосчитайте его");
     }

    }

    if((ui->comboBox_4->currentText())== "All Tables")
    {
    ui->textBrowser->append("Выбраны все таблицы для полинома B");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранные таблицу...");
    //AB.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){

    HS.InsertRecord(AB,strig2.toStdString());
    updateHash();
    SR.InsertRecord(AB,strig2.toStdString());
    updateSort();
    ST.InsertRecord(AB,strig2.toStdString());
    updateScan();

    }
    else{
        i++;
        j++;
        k++;
        HS.InsertRecord(AB,to_string(i));
        updateHash();
        SR.InsertRecord(AB,to_string(j));
        updateSort();
        ST.InsertRecord(AB,to_string(k));
        updateScan();

    }
     }
     else{
         ui->textBrowser->append("Полином AB пустой, сосчитайте его");
     }

    }

}


void MainWindow::on_pushButton_6_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    if((ui->comboBox_4->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома AB из выбранной таблицы...");

    if (strig2!=nullptr){
    HS.RemoveRecord(strig2.toStdString());
    updateHash();
    }
    else{
         ui->textBrowser->append("Впишите в ключ AB, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином AB, который хотите удалить");
     }
    }

    if((ui->comboBox_4->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома AB из выбранной таблицы...");

    if (strig2!=nullptr){
    SR.RemoveRecord(strig2.toStdString());
    updateSort();
    }
    else{
         ui->textBrowser->append("Впишите в ключ AB, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином AB, который хотите удалить");
     }
    }

    if((ui->comboBox_4->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома AB из выбранной таблицы...");

    if (strig2!=nullptr){
    ST.RemoveRecord(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ AB, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином AB, который хотите удалить");
     }

    }

    if((ui->comboBox_4->currentText())== "All Tables")
    {
    ui->textBrowser->append("Выбраны все таблицы для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома AB из выбранных таблиц...");

    if (strig2!=nullptr){
    HS.RemoveRecord(strig2.toStdString());
    updateHash();
    SR.RemoveRecord(strig2.toStdString());
    updateSort();
    ST.RemoveRecord(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ AB, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином AB, который хотите удалить");
     }
    }
}


void MainWindow::on_pushButton_8_released()
{
    SaT.str_to_poly("0");
    SaT*=0;
    ui->textBrowser_6->append("Действие №"+QString::number(R)+"_____________________________________________");
    R++;
    //Polinom RAS;
    QString stx = ui->textEdit_7->toPlainText().trimmed();
    QString sty = ui->textEdit_8->toPlainText().trimmed();
    QString stz = ui->textEdit_9->toPlainText().trimmed();
    QString stPol = ui->textEdit_10->toPlainText().trimmed();

    if ((stx==nullptr)||(sty==nullptr)||(stz==nullptr)||(stPol==nullptr))  ui->textBrowser_6->append("Нехватка данных для расчёта полинома");
    else{
    ui->textBrowser_6->append("Расчёт полинома...");
    if (SaT==RAS){
    RAS.str_to_poly(stPol.toStdString());}

    RAS(stx.toDouble(),sty.toDouble(),stz.toDouble());
    ras=RAS(stx.toDouble(),sty.toDouble(),stz.toDouble());
    ui->textBrowser_5->setText(QString::number(RAS(stx.toDouble(),sty.toDouble(),stz.toDouble()),'f',10));
    ui->textBrowser_6->append("Готово!");
    RAS*=0;
    }
}


void MainWindow::on_pushButton_11_released()
{
 ST.Clear();
 updateScan();
}


void MainWindow::on_pushButton_10_released()
{
    SR.Clear();
    updateSort();
}


void MainWindow::on_pushButton_9_released()
{
    HS.Clear();
    updateHash();
}


void MainWindow::on_pushButton_15_released()
{
    ui->textBrowser_6->append("Действие №"+QString::number(R)+"_____________________________________________");
    R++;
    RAS*=0;
    std::stringstream tmp;
    if((ui->comboBox_5->currentText())== "Scan Table")
    {
    ui->textBrowser_6->append("Выбрана Scan таблица для поиска расчитываемого полинома");

     QString strig = ui->textEdit_11->toPlainText().trimmed();
    // QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser_6->append("Помещение полинома для расчёта в нужное поле...");
    Polinom R(*ST.FindRecord(strig.toStdString()));
    RAS+=R;
    tmp << RAS;
    ui->textEdit_10->setText(QString::fromStdString(tmp.str()));
    //ui->textEdit_10->append(RAS)
    //if (strig2!=nullptr){
    //ST.RemoveRecord(strig2.toStdString());
    //updateScan();
    ui->textBrowser_6->append("Полином размещён, можете сосчитать его с заданными параметрами!");
    }
    else
     {
          ui->textBrowser_6->append("Ключ для полинома не задан в нужное поле");
     }
}
    if((ui->comboBox_5->currentText())== "Hash Table")
    {
    ui->textBrowser_6->append("Выбрана Hash таблица для поиска расчитываемого полинома");

     QString strig = ui->textEdit_11->toPlainText().trimmed();
    // QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser_6->append("Помещение полинома для расчёта в нужное поле...");
    Polinom R(*HS.FindRecord(strig.toStdString()));
    RAS+=R;
    tmp << RAS;
    ui->textEdit_10->setText(QString::fromStdString(tmp.str()));
    //ui->textEdit_10->append(RAS)
    //if (strig2!=nullptr){
    //ST.RemoveRecord(strig2.toStdString());
    //updateScan();
    ui->textBrowser_6->append("Полином размещён, можете сосчитать его с заданными параметрами!");
    }
    else
     {
          ui->textBrowser_6->append("Ключ для полинома не задан в нужное поле");
     }
}
    if((ui->comboBox_5->currentText())== "Sort Table")
    {
    ui->textBrowser_6->append("Выбрана Sort таблица для поиска расчитываемого полинома");

     QString strig = ui->textEdit_11->toPlainText().trimmed();
    // QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser_6->append("Помещение полинома для расчёта в нужное поле...");
    Polinom R(*SR.FindRecord(strig.toStdString()));
    RAS+=R;
    tmp << RAS;
    ui->textEdit_10->setText(QString::fromStdString(tmp.str()));
    //ui->textEdit_10->append(RAS)
    //if (strig2!=nullptr){
    //ST.RemoveRecord(strig2.toStdString());
    //updateScan();
    ui->textBrowser_6->append("Полином размещён, можете сосчитать его с заданными параметрами!");
    }
    else
     {
          ui->textBrowser_6->append("Ключ для полинома не задан в нужное поле");
     }
}
}


void MainWindow::on_pushButton_16_released()
{
    ui->textBrowser_6->append("Действие №"+QString::number(R)+"_____________________________________________");
    R++;
    Polinom e;
    e.str_to_poly(to_string(ras));
    std::stringstream tmp;
    if((ui->comboBox_6->currentText())== "Scan Table")
    {
    ui->textBrowser_6->append("Выбрана Scan таблица для вставки расчитываемого полинома");

     QString strig = ui->textEdit_12->toPlainText().trimmed();
    // QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser_6->append("Помещение полинома для расчёта в нужную таблицу...");
    ST.InsertRecord(e,strig.toStdString());
    updateScan();
    ui->textBrowser_6->append("Полином размещён в таблице!");
    }
    else
     {
          ui->textBrowser_6->append("Ключ для полинома не задан в нужное поле");
     }
}
    if((ui->comboBox_6->currentText())== "Hash Table")
    {
    ui->textBrowser_6->append("Выбрана Hash таблица для вставки расчитываемого полинома");

     QString strig = ui->textEdit_12->toPlainText().trimmed();
    // QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser_6->append("Помещение полинома для расчёта в нужную таблицу...");
    HS.InsertRecord(e,strig.toStdString());
    updateHash();
    ui->textBrowser_6->append("Полином размещён в таблице!");
    }
    else
     {
          ui->textBrowser_6->append("Ключ для полинома не задан в нужное поле");
     }
}
    if((ui->comboBox_6->currentText())== "Sort Table")
    {
    ui->textBrowser_6->append("Выбрана Sort таблица для вставки расчитываемого полинома");

     QString strig = ui->textEdit_12->toPlainText().trimmed();
    // QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser_6->append("Помещение полинома для расчёта в нужную таблицу...");
    SR.InsertRecord(e,strig.toStdString());
    updateSort();
    ui->textBrowser_6->append("Полином размещён в таблице!");
    }
    else
     {
          ui->textBrowser_6->append("Ключ для полинома не задан в нужное поле");
     }
}
    if((ui->comboBox_6->currentText())== "All Tables")
    {
    ui->textBrowser_6->append("Выбраны все таблицы для вставки расчитываемого полинома");

     QString strig = ui->textEdit_12->toPlainText().trimmed();
    // QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser_6->append("Помещение полинома для расчёта в нужную таблицу...");
    SR.InsertRecord(e,strig.toStdString());
    updateSort();
    HS.InsertRecord(e,strig.toStdString());
    updateHash();
    ST.InsertRecord(e,strig.toStdString());
    updateScan();
    ui->textBrowser_6->append("Полином размещён в таблице!");
    }
    else
     {
          ui->textBrowser_6->append("Ключ для полинома не задан в нужное поле");
     }
}
}

