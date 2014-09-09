#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QListWidget>
#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include "elencotornei.h"
#include "searchwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    void setupView();

signals:
    //void aggiuntoNuovoTorneo();

private slots:

    void on_aggiungiTorneo_clicked();

    void on_sceltaTorneo_currentIndexChanged(const QString &arg1);

    void on_cercaButton_clicked();

    void on_torneiListWidget_itemDoubleClicked(QListWidgetItem *item);

    void changeItemListName(QString,QString);

    void eraseItemList(QString);

private:
    QWidget *centralWidget;
    QGroupBox *groupBoxRicerca;
    QPushButton *cercaButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNomeRicerca;
    QLineEdit *lineEditRicerca;
    QLabel *labelInfo;
    QListWidget *torneiListWidget;
    QLabel *label;
    QGroupBox *groupBoxInformazioni;
    QLabel *labelAddizionale;
    QLabel *labelInfoAdd;
    QGroupBox *groupBoxAggiungi;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QComboBox *sceltaTorneo;
    QHBoxLayout *horizontalLayoutNome;
    QLabel *NomeLabel;
    QLineEdit *NomeLineEdit;
    QHBoxLayout *horizontalLayoutNumG;
    QLabel *NumGLabel;
    QLineEdit *NumGLineEdit;
    QHBoxLayout *horizontalLayoutImporto;
    QLabel *ImportoLabel;
    QLineEdit *ImportoLineEdit;
    QHBoxLayout *horizontalLayoutBuyIn;
    QLabel *BuyInLabel;
    QLineEdit *BuyInLineEdit;
    QPushButton *aggiungiTorneo;
    QStatusBar *statusBar;

    ElencoTornei* elenco;

    bool addTorneo();
    void loadTorneiInfo();
    void resetCampiDati();
    void addToList(QString);
    void launchSearch(ElencoTornei* el, QString nome);
};

#endif // MAINWINDOW_H
