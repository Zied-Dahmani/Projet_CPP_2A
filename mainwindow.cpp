#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutersalle.h"
#include "deletehall.h"
#include "deletedecorator.h"
#include "hall.h"
#include "decorator.h"


#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "connection.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //ui->listWidget->addItem("salle1");







    QIcon search_bar("C:/Users/Deadly/Desktop/Fac/2A/Projet/Qt/ProjetFac/Img/searchicon");


        //fill the search bar with the icon

        //ui->search_line->addAction(search_bar,QLineEdit::LeadingPosition);
        ui->search_line->setPlaceholderText("Search");


        //ui->search_2->addAction(search_bar,QLineEdit::LeadingPosition);
        ui->search_2->setPlaceholderText("Search");

        //ui->hall_id_line_2->setPlaceholderText("  Hall number");


}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_SelectHallButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_AddHallButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_UpdateHallButton_clicked()
{
    ui->UpdateButton->setVisible(false);



    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_AddDecButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_UpdateDecButton_clicked()
{
    ui->UpdateButton_2->setVisible(false);

    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_BackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_BackButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_BackButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_BackButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_BackButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_AddButton_clicked()
{
    bool _empty=false;


    if(ui->hall_name_line->text()=="")
    {
        ui->hall_name_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty=true;

   }

    if(ui->address_line->text()=="")
    {
        ui->address_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->price_line->text()=="")
    {
        ui->price_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->nb_places_line->text()=="")
    {
        ui->nb_places_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->number_line->text()=="")
    {
        ui->number_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }

    if(ui->email_line->text()=="")
    {
        ui->email_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty=true;

   }

    if(ui->number_line->text().length()!=8)
    {
        ui->number_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;

   }


    if(_empty) return ;

    Hall H(ui->number_line->text(),
           "0",
           ui->hall_name_line->text(),
           ui->address_line->text(),
           ui->email_line->text(),
           ui->number_line->text(),
           ui->price_line->text(),
           ui->nb_places_line->text()
           );

    bool fn=H.addHall();
    if(fn)   ui->stackedWidget->setCurrentIndex(0);




}



void MainWindow::on_AddButton_2_clicked()
{

       bool _empty2=false;


       if(ui->decorator_name_line_2->text()=="")
       {
           ui->decorator_name_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));
           _empty2=true;

      }

       if(ui->number_line_4->text()=="")
       {
           ui->number_line_4->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->price_line_4->text()=="")
       {
           ui->price_line_4->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->type_decoration_line_2->text()=="")
       {
           ui->type_decoration_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->hall_id_line->text()=="")

       {
           ui->hall_id_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }

       if(ui->number_line_4->text().length()!=8)
       {
           ui->number_line_4->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                   "  border-radius: 8px;"
                                                     "padding-left: 20px;"
                                                     "padding-right: 20px;"
                                                     "background-color: rgb(255,255,255);"));

           _empty2=true;

      }



       if(_empty2) return ;

       Decorator D(ui->number_line_4->text(),
                   ui->decorator_name_line_2->text(),
                   ui->type_decoration_line_2->text(),
                   ui->price_line_4->text(),
                   ui->number_line_4->text(),
                   "0",
                   ui->hall_id_line->text()
                   );


       bool fn=D.addDecorator();
       if(fn) ui->stackedWidget->setCurrentIndex(1);


}

void MainWindow::on_DeleteHallButton_clicked()
{

    DeleteHall *dialog =new DeleteHall(this);
    dialog->show();
;

}

void MainWindow::on_DisplayButton_clicked()
{

        Hall H(ui->search_line->text(),
               "",
               "",
               "",
               "",
               "",
               "",
               ""
               );

        ui->tableView->setModel(H.tableView());

}

void MainWindow::on_AddDecButton_2_clicked()
{

    //test git
    Decorator D(ui->search_2->text(),
                "",
                "",
                "",
                "",
                "",
                ""
                );

        ui->tableView_2->setModel(D.tableView());


}

void MainWindow::on_DeleteDecButton_clicked()
{
    DeleteDecorator *dialog =new DeleteDecorator(this);
    dialog->show();
}

void MainWindow::on_UpdateButton_clicked()
{
    bool _empty3=false;

    if(ui->hall_name_line_2->text()=="")
    {
        ui->hall_name_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->address_line_2->text()=="")
    {
        ui->address_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->price_line_2->text()=="")
    {
        ui->price_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->nb_places_line_2->text()=="")
    {
        ui->nb_places_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;

   }

    if(ui->number_line_2->text()=="")
    {

        ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;
   }

    if(ui->email_line_2->text()=="")
    {

        ui->email_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;
   }

    if(ui->number_line_2->text().length()!=8)
    {

        ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty3=true;
   }



    if(_empty3) return ;

    Hall H(ui->number_line_2->text(),
           "0",
           ui->hall_name_line_2->text(),
           ui->address_line_2->text(),
           ui->email_line_2->text(),
           ui->number_line_2->text(),
           ui->price_line_2->text(),
           ui->nb_places_line_2->text()
           );

    bool test=H.updateHall();
    if(test)
    {
           ui->stackedWidget->setCurrentIndex(0);

    }


}



void MainWindow::on_UpdateButton_2_clicked()
{
    bool _empty2=false;


    if(ui->decorator_name_line->text()=="")
    {
        ui->decorator_name_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        _empty2=true;

   }

    if(ui->number_line_3->text()=="")
    {
        ui->number_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->price_line_3->text()=="")
    {
        ui->price_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->type_decoration_line->text()=="")
    {
        ui->type_decoration_line->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->hall_id_line_3->text()=="")
    {
        ui->hall_id_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }


    if(ui->number_line_3->text().length()!=8)
    {
        ui->number_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }

    if(ui->hall_id_line_3->text().length()!=8)
    {
        ui->hall_id_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty2=true;

   }


    if(_empty2) return ;


    Decorator D(ui->number_line_3->text(),
                       ui->decorator_name_line->text(),
                       ui->type_decoration_line->text(),
                       ui->price_line_3->text(),
                       ui->number_line_3->text(),
                       "0",
                       ui->hall_id_line_3->text()
                       );



        bool test =D.updateDecorator();

          if(test)
        {
            ui->stackedWidget->setCurrentIndex(1);

        }


}

void MainWindow::on_UpdateFindButton_clicked()
{


    if(ui->number_line_2->text()=="")
    {

        ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));
        return ;
    }


    QSqlQuery qry;

            if (qry.exec("SELECT * FROM SALLE WHERE ID ='"+ ui->number_line_2->text() +"' "))
            {
                int count(0);
                while(qry.next())
                {
                    count++;
                    ui->number_line_2->setText(qry.value(0).toString());
                    ui->hall_name_line_2->setText(qry.value(2).toString());
                    ui->address_line_2->setText(qry.value(3).toString());
                    ui->email_line_2->setText(qry.value(4).toString());
                    ui->price_line_2->setText(qry.value(6).toString());
                    ui->nb_places_line_2->setText(qry.value(7).toString());

                    ui->UpdateButton->setVisible(true);


                }
                if (count == 0)
                {
                    ui->number_line_2->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                            "  border-radius: 8px;"
                                                              "padding-left: 20px;"
                                                              "padding-right: 20px;"
                                                              "background-color: rgb(255,255,255);"));

                    QMessageBox::critical(nullptr, QObject::tr("edit to data base"),
                                          QObject::tr("HALL NUMBER doesn't exist.\n"
                                                      "Click Cancel to try again."), QMessageBox::Cancel);
                }

            }

            if (!qry.exec())
            {
                qDebug("error hall findButton to db");
            }



}

void MainWindow::on_UpdateFindButton_2_clicked()
{
       bool _empty=false;


    if(ui->number_line_3->text()=="")
    {
        ui->number_line_3->setStyleSheet(QString("	border: 2px solid #e30000;"
                                                "  border-radius: 8px;"
                                                  "padding-left: 20px;"
                                                  "padding-right: 20px;"
                                                  "background-color: rgb(255,255,255);"));

        _empty=true;
   }

    if(_empty) return ;

    QSqlQuery qry2;
    QSqlQuery qry3;


        if (qry3.exec("SELECT * FROM DECORATEUR WHERE ID =  '"+ ui->number_line_3->text() +"' "))
                {
                    int count(0);
                    while(qry3.next())
                    {
                        count++;

                        ui->decorator_name_line->setText(qry3.value(0).toString());
                        ui->type_decoration_line->setText(qry3.value(1).toString());
                        ui->price_line_3->setText(qry3.value(2).toString());
                        ui->number_line_3->setText(qry3.value(3).toString());
                        ui->hall_id_line_3->setText(qry3.value(5).toString());
                        ui->number_line_3->setText(qry3.value(6).toString());


                        ui->UpdateButton_2->setVisible(true);



                    }
                    if (count == 0)
                    {
                        QMessageBox::critical(nullptr, QObject::tr("add to data base"),
                                              QObject::tr("DECORATOR  doesn't exist.\n"
                                                          "Click Cancel to try again."), QMessageBox::Cancel);
                    }

                }

                if (!qry3.exec())
                {
                    qDebug("error adding to db");
                }







}
