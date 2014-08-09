#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGroupBox>

#include <elencotornei.h>

class SearchWindow : public QDialog
{
    Q_OBJECT
public:
    explicit SearchWindow(QWidget *parent = 0);
    ~SearchWindow();

    void setupView();

    void bindElenco(ElencoTornei*, QString);

    void setNomeTorneo(QString);

private slots:
    void on_searchDeleteButton_clicked();

    void on_editNomeButton_clicked();

    void on_editGiocButton_clicked();

    void on_editImportoButton_clicked();

    void on_editBuyInButton_clicked();

signals:
    void nameChanged(QString,QString);
    void torneoRemove(QString);

private:
    QGroupBox *groupBox;
    QLabel *searchTotaleLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutTutto;
    QHBoxLayout *horizontalLayoutNome;
    QLabel *searchLabelNome;
    QLineEdit *searchNomeEdit;
    QPushButton *editNomeButton;
    QHBoxLayout *horizontalLayoutG;
    QLabel *searchLabelGioc;
    QLineEdit *searchGiocEdit;
    QPushButton *editGiocButton;
    QHBoxLayout *horizontalLayoutImporto;
    QLabel *searchImportoLabel;
    QLineEdit *searchImportoEdit;
    QPushButton *editImportoButton;
    QHBoxLayout *horizontalLayoutBuy;
    QLabel *searchBuyInLabel;
    QLineEdit *searchBuyInEdit;
    QPushButton *editBuyInButton;
    QPushButton *searchDeleteButton;
    QLabel *searchTipoLabel;

    ElencoTornei *el;

    QString nomeTorneo;

    void resetNome();

    void resetCampi();

    void setCampiRicerca();

    void loadTorneiInfo();

};

#endif // SEARCHWINDOW_H
