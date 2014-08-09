#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    elenco(new ElencoTornei)
{
    centralWidget = new QWidget(this);
    groupBoxRicerca = new QGroupBox(centralWidget);
    cercaButton = new QPushButton(groupBoxRicerca);
    layoutWidget = new QWidget(groupBoxRicerca);
    horizontalLayout = new QHBoxLayout(layoutWidget);
    labelNomeRicerca = new QLabel(layoutWidget);
    lineEditRicerca = new QLineEdit(layoutWidget);
    labelInfo = new QLabel(groupBoxRicerca);
    torneiListWidget = new QListWidget(groupBoxRicerca);
    label = new QLabel(groupBoxRicerca);
    groupBoxInformazioni = new QGroupBox(centralWidget);
    labelAddizionale = new QLabel(groupBoxInformazioni);
    labelInfoAdd = new QLabel(groupBoxInformazioni);
    groupBoxAggiungi = new QGroupBox(centralWidget);
    layoutWidget1 = new QWidget(groupBoxAggiungi);
    verticalLayout = new QVBoxLayout(layoutWidget1);
    sceltaTorneo = new QComboBox(layoutWidget1);
    horizontalLayoutNome = new QHBoxLayout();
    NomeLabel = new QLabel(layoutWidget1);
    NomeLineEdit = new QLineEdit(layoutWidget1);
    horizontalLayoutNumG = new QHBoxLayout();
    NumGLabel = new QLabel(layoutWidget1);
    NumGLineEdit = new QLineEdit(layoutWidget1);
    horizontalLayoutImporto = new QHBoxLayout();
    ImportoLabel = new QLabel(layoutWidget1);
    ImportoLineEdit = new QLineEdit(layoutWidget1);
    horizontalLayoutBuyIn = new QHBoxLayout();
    BuyInLabel = new QLabel(layoutWidget1);
    BuyInLineEdit = new QLineEdit(layoutWidget1);
    aggiungiTorneo = new QPushButton(layoutWidget1);
    menuBar = new QMenuBar(this);
    menuTornei_di_Poker = new QMenu(menuBar);
    mainToolBar = new QToolBar(this);
    statusBar = new QStatusBar(this);


    setupView();
    loadTorneiInfo();

    connect(aggiungiTorneo,SIGNAL(clicked()),this,SLOT(on_aggiungiTorneo_clicked()));
    connect(sceltaTorneo,SIGNAL(currentIndexChanged(QString)),this, SLOT(on_sceltaTorneo_currentIndexChanged(QString)));
    connect(cercaButton,SIGNAL(clicked()),this,SLOT(on_cercaButton_clicked()));
    connect(torneiListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_torneiListWidget_itemDoubleClicked(QListWidgetItem*)));
}

void MainWindow::setupView(){
    resize(709, 535);
    setToolButtonStyle(Qt::ToolButtonTextOnly);

    groupBoxRicerca->setGeometry(QRect(370, 10, 271, 371));
    cercaButton->setGeometry(QRect(40, 60, 181, 27));
    layoutWidget->setGeometry(QRect(10, 30, 247, 29));

    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout->addWidget(labelNomeRicerca);
    horizontalLayout->addWidget(lineEditRicerca);

    labelInfo->setEnabled(true);
    labelInfo->setGeometry(QRect(20, 100, 231, 71));
    QFont font;
    font.setFamily(QString::fromUtf8("Abyssinica SIL"));
    font.setItalic(true);
    labelInfo->setFont(font);
    labelInfo->setScaledContents(false);
    labelInfo->setWordWrap(true);

    torneiListWidget->setGeometry(QRect(10, 220, 256, 141));
    label->setGeometry(QRect(10, 200, 101, 17));

    cercaButton->raise();
    layoutWidget->raise();
    labelInfo->raise();
    torneiListWidget->raise();
    label->raise();
    layoutWidget->raise();

    groupBoxInformazioni->setGeometry(QRect(10, 400, 381, 41));
    labelAddizionale->setGeometry(QRect(310, 20, 67, 17));
    labelInfoAdd->setGeometry(QRect(0, 20, 311, 17));
    groupBoxAggiungi->setGeometry(QRect(10, 10, 321, 361));
    layoutWidget1->setGeometry(QRect(20, 40, 277, 286));
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->addWidget(sceltaTorneo);

    horizontalLayoutNome->setSpacing(6);
    horizontalLayoutNome->addWidget(NomeLabel);
    horizontalLayoutNome->addWidget(NomeLineEdit);

    verticalLayout->addLayout(horizontalLayoutNome);

    horizontalLayoutNumG->setSpacing(6);
    horizontalLayoutNumG->addWidget(NumGLabel);
    horizontalLayoutNumG->addWidget(NumGLineEdit);

    verticalLayout->addLayout(horizontalLayoutNumG);

    horizontalLayoutImporto->setSpacing(6);
    horizontalLayoutImporto->addWidget(ImportoLabel);
    horizontalLayoutImporto->addWidget(ImportoLineEdit);

    verticalLayout->addLayout(horizontalLayoutImporto);

    horizontalLayoutBuyIn->setSpacing(6);
    horizontalLayoutBuyIn->addWidget(BuyInLabel);
    horizontalLayoutBuyIn->addWidget(BuyInLineEdit);

    verticalLayout->addLayout(horizontalLayoutBuyIn);
    verticalLayout->addWidget(aggiungiTorneo);

    layoutWidget->raise();
    layoutWidget->raise();
    setCentralWidget(centralWidget);

    menuBar->setGeometry(QRect(0, 0, 709, 25));
    setMenuBar(menuBar);
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    setStatusBar(statusBar);
    menuBar->addAction(menuTornei_di_Poker->menuAction());
}

void MainWindow::loadTorneiInfo(){
    setWindowTitle("qDataBase");
    labelAddizionale->setText(QString::number(elenco->getAddCash())+" EURO");
    statusBar->showMessage("Programmazione ad Oggetti 2013/2014 @ UniPD - Suierica Bogdan");

    sceltaTorneo->addItem("SitAndGo");
    sceltaTorneo->addItem("Cash");
    NomeLabel->setText("Nome");
    NumGLabel->setText("Giocatori");
    ImportoLabel->setText("Importo");
    BuyInLabel->setText("BuyIn");
    aggiungiTorneo->setText("Aggiungi");

    groupBoxAggiungi->setTitle("Spazio Aggiungi Tornei");
    groupBoxInformazioni->setTitle("Informazioni");
    labelInfoAdd->setText("Per i tornei Cash c'e' un'addizionale unica di :");

    groupBoxRicerca->setTitle("Spazio Ricerca");
    labelNomeRicerca->setText("Nome");
    cercaButton->setText("Cerca");
    labelInfo->setText("Attraverso la ricerca o il doppio click sulla lista e' possibile eliminare o modificare i dati del torneo.");
    label->setText("Lista Tornei");
}

bool MainWindow::addTorneo(){
        //test sull'input
    if(sceltaTorneo->currentText()=="SitAndGo"){
        bool gi, ta, bu;
        QString name = NomeLineEdit->text();
        int giocatori=NumGLineEdit->text().toInt(&gi);
        double tax = ImportoLineEdit->text().toDouble(&ta);
        double buy = BuyInLineEdit->text().toDouble(&bu);
        if(name == "" || !gi || !ta || !bu){
               QMessageBox err;
               err.setText("Sembra che i dati del torneo non siano corretti..");
               err.exec();
               resetCampiDati();
               return false;
        }
        else{
            if(sceltaTorneo->currentText()=="SitAndGo"){
                bool presente=elenco->addSitAndGoIfNotPresent(name.toStdString(),giocatori,tax,buy);
                if(presente){
                    QMessageBox err;
                    err.setText("Il torneo e gia' presente");
                    err.exec();
                    resetCampiDati();
                    return false;
                }

            }
            else {
                QMessageBox err;
                err.setText("Si e' verificato qualche problema con l'inserimento. Il torneo non e' stato creato");
                err.exec();
                resetCampiDati();
                return false;
            }
        addToList(name);
        QMessageBox info;
        info.setText("Torneo creato e salvato con successo!");
        info.exec();
        resetCampiDati();
        emit aggiuntoNuovoTorneo();
        return true;
        }
    }
    else
        if(sceltaTorneo->currentText()=="Cash"){
            bool gi, ta, bu;
            QString name = NomeLineEdit->text();
            int giocatori=NumGLineEdit->text().toInt(&gi);
            double tax = ImportoLineEdit->text().toDouble(&ta);
            double dura = BuyInLineEdit->text().toDouble(&bu);
            if(name == "" || !gi || !ta || !bu){
                   QMessageBox err;
                   err.setText("Sembra che i dati del torneo non siano corretti..");
                   err.exec();
                   resetCampiDati();
                   return false;
            }
            else{
                if(sceltaTorneo->currentText()=="Cash"){
                    bool presente=elenco->addCashIfNotPresent(name.toStdString(),giocatori,tax,dura);
                    if(presente){
                        QMessageBox err;
                        err.setText("Il torneo e gia' presente");
                        err.exec();
                        resetCampiDati();
                        return false;
                    }
                }
                else {
                    QMessageBox err;
                    err.setText("Si e' verificato qualche problema con l'inserimento. Il torneo non e' stato creato");
                    err.exec();
                    resetCampiDati();
                    return false;
                }
            addToList(name);
            QMessageBox info;
            info.setText("Torneo creato e salvato con successo!");
            info.exec();
            resetCampiDati();
            emit aggiuntoNuovoTorneo();
            return true;
            }
        }

}

void MainWindow::on_aggiungiTorneo_clicked()
{
    addTorneo();
}


void MainWindow::on_sceltaTorneo_currentIndexChanged(const QString &arg1)
{
    if(arg1=="SitAndGo")
        BuyInLabel->setText("BuyIn");
    else
        if(arg1=="Cash")
            BuyInLabel->setText("Durata");
}

void MainWindow::resetCampiDati(){
    NomeLineEdit->setText("");
    NumGLineEdit->setText("");
    ImportoLineEdit->setText("");
    BuyInLineEdit->setText("");
}

void MainWindow::on_cercaButton_clicked()
{
    QString name = lineEditRicerca->text();
    if(name==""){
        QMessageBox err;
        err.setText("Nome non permesso");
        lineEditRicerca->setText("");
        err.exec();
    }
    else{
        ElencoTornei::SmartPtr p=elenco->searchTorneo(lineEditRicerca->text().toStdString());
        if(p==0){
            QMessageBox err;
            err.setText("Nessun torneo trovato");
            err.exec();
            lineEditRicerca->setText("");
        }
        else{
            launchSearch(elenco,lineEditRicerca->text());
        }
    }
}

void MainWindow::addToList(QString nome){
    QListWidgetItem *newItem= new QListWidgetItem(nome);
    torneiListWidget->addItem(newItem);
}

void MainWindow::launchSearch(ElencoTornei* el, QString nome){
    SearchWindow *sw = new SearchWindow;
    MainWindow::connect(sw, SIGNAL(nameChanged(QString,QString)), this, SLOT(changeItemListName(QString,QString)));
    MainWindow::connect(sw,SIGNAL(torneoRemove(QString)), this, SLOT(eraseItemList(QString)));
    sw->bindElenco(el, nome);
    lineEditRicerca->setText("");
    sw->show();
}


void MainWindow::on_torneiListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    launchSearch(elenco,item->text());
}

void MainWindow::changeItemListName(QString resetNome,QString nome ){
    for(int row = 0; row < torneiListWidget->count(); row++)
    {
        QListWidgetItem *item = torneiListWidget->item(row);
        if(item->text()==nome)
            item->setText(resetNome);
    }
}

void MainWindow::eraseItemList(QString nome){
    for(int row = 0; row < torneiListWidget->count(); row++)
    {
        QListWidgetItem *item = torneiListWidget->item(row);
        if(item->text()==nome)
            torneiListWidget->removeItemWidget(torneiListWidget->takeItem(row));

    }
}
