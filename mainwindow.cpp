#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"open the file");
   QFile file (file_name);
   file_path_ =file_name;
   if(!file.open(QFile::ReadOnly | QFile::Text))  {
       QMessageBox::warning(this, ".."," file not open");
       return;

}
 QTextStream in(&file);
 QString text=in.readAll();
 ui->textEdit->setText(text);
 file.close();

}


void MainWindow::on_actionSave_triggered()
{

   QFile file (file_path_);
   if(!file.open(QFile::WriteOnly| QFile::Text))  {
       QMessageBox::warning(this, ".."," file not open");
       return;

}
 QTextStream out (&file);
 QString text=ui->textEdit->toPlainText();
 out<< text;
 file .flush();
 file.close();

}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"open the file");
   QFile file (file_name);
   file_path_ = file_name;
   if(!file.open(QFile::WriteOnly| QFile::Text))  {
       QMessageBox::warning(this, ".."," file not open");
       return;

}
 QTextStream out (&file);
 QString text=ui->textEdit->toPlainText();
 out<< text;
 file .flush();
 file.close();

}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
  ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
  ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString about_text;
    about_text ="programmers : Esraa Ehab Ebrahiem\n Mariam Elsayd Mansour\nShahd Yacout Mostafa\nMohamed Waleed Mohamed\nAzzat Ahmed Mohamed\n";
    about_text += "Date  : 1/5/2022\n";
    about_text += "(c)Notepad  :c++ notepad\n";
QMessageBox::about(this,"About Notepad",about_text);
}


void MainWindow::on_actionNew_triggered()
{
    file_path_="";
    ui->textEdit->setText("");
}


void MainWindow::on_actionFont_triggered()
{
   bool ok;
   QFont font = QFontDialog::getFont(&ok,this);
   if (ok){
       ui->textEdit->setFont(font);

   }else return;
}

