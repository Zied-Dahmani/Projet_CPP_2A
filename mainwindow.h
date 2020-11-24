#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void test(bool test);
    ~MainWindow();

private slots:



    void on_SelectHallButton_clicked();

    void on_AddHallButton_clicked();

    void on_UpdateHallButton_clicked();

    void on_AddDecButton_clicked();

    void on_UpdateDecButton_clicked();

    void on_BackButton_clicked();

    void on_BackButton_2_clicked();

    void on_BackButton_3_clicked();

    void on_BackButton_4_clicked();

    void on_BackButton_5_clicked();

    void on_search_2_windowIconChanged(const QIcon &icon);

    void on_AddButton_clicked();

    void on_AddButton_2_clicked();

    void on_DeleteHallButton_clicked();

    void on_DisplayButton_clicked();

    void on_hall_id_line_2_textChanged(const QString &arg1);

    void on_AddDecButton_2_clicked();

    void on_DeleteDecButton_clicked();

    void on_UpdateButton_clicked();

    void on_UpdateButton_2_clicked();

    void on_UpdateFindButton_clicked();

    void on_UpdateFindButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
