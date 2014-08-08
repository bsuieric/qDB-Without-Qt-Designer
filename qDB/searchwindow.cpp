#include "searchwindow.h"

SearchWindow::SearchWindow(QWidget *parent) :
    QDialog(parent)
{
    searchTipoLabel = new QLabel(this);
    searchTotaleLabel = new QLabel(this);
    layoutWidget = new QWidget(this);
    verticalLayoutTutto = new QVBoxLayout(layoutWidget);
    horizontalLayoutNome = new QHBoxLayout();
    searchLabelNome = new QLabel(layoutWidget);
    searchNomeEdit = new QLineEdit(layoutWidget);
    editNomeButton = new QPushButton(layoutWidget);
    horizontalLayoutG = new QHBoxLayout();
    searchLabelGioc = new QLabel(layoutWidget);
    searchGiocEdit = new QLineEdit(layoutWidget);
    editGiocButton = new QPushButton(layoutWidget);
    horizontalLayoutImporto = new QHBoxLayout();
    searchImportoLabel = new QLabel(layoutWidget);
    searchImportoEdit = new QLineEdit(layoutWidget);
    editImportoButton = new QPushButton(layoutWidget);
    horizontalLayoutBuy = new QHBoxLayout();
    searchBuyInLabel = new QLabel(layoutWidget);
    searchBuyInEdit = new QLineEdit(layoutWidget);
    editBuyInButton = new QPushButton(layoutWidget);
    searchDeleteButton = new QPushButton(layoutWidget);

    connect(searchDeleteButton,SIGNAL(clicked()),this,SLOT(on_searchDeleteButton_clicked()));
    connect(editNomeButton,SIGNAL(clicked()),this,SLOT(on_editNomeButton_clicked()));
    connect(editGiocButton,SIGNAL(clicked()),this,SLOT(on_editGiocButton_clicked()));
    connect(editImportoButton,SIGNAL(clicked()),this,SLOT(on_editImportoButton_clicked()));
    connect(editBuyInButton,SIGNAL(clicked()),this,SLOT(on_editBuyInButton_clicked()));
}

SearchWindow::~SearchWindow()
{
}

void SearchWindow::setupView(){
    resize(329, 334);
    layoutWidget->setGeometry(QRect(10, 100, 309, 169));

    searchTipoLabel->setGeometry(QRect(100, 20, 151, 17));

    searchTotaleLabel->setGeometry(QRect(40, 50, 261, 17));


    verticalLayoutTutto->setContentsMargins(0, 0, 0, 0);

    horizontalLayoutNome->addWidget(searchLabelNome);
    horizontalLayoutNome->addWidget(searchNomeEdit);
    horizontalLayoutNome->addWidget(editNomeButton);

    verticalLayoutTutto->addLayout(horizontalLayoutNome);

    horizontalLayoutG->addWidget(searchLabelGioc);
    horizontalLayoutG->addWidget(searchGiocEdit);
    horizontalLayoutG->addWidget(editGiocButton);

    verticalLayoutTutto->addLayout(horizontalLayoutG);

    horizontalLayoutImporto->addWidget(searchImportoLabel);
    horizontalLayoutImporto->addWidget(searchImportoEdit);
    horizontalLayoutImporto->addWidget(editImportoButton);

    verticalLayoutTutto->addLayout(horizontalLayoutImporto);

    horizontalLayoutBuy->addWidget(searchBuyInLabel);
    horizontalLayoutBuy->addWidget(searchBuyInEdit);
    horizontalLayoutBuy->addWidget(editBuyInButton);

    verticalLayoutTutto->addLayout(horizontalLayoutBuy);
    verticalLayoutTutto->addWidget(searchDeleteButton);

}

void SearchWindow::bindElenco(ElencoTornei * e, QString nomeT){
    nomeTorneo=nomeT;
    el = e;
    setCampiRicerca();
}

void SearchWindow::setCampiRicerca()
{
    ElencoTornei::SmartPtr p=el->searchTorneo(nomeTorneo.toStdString());
    SitAndGo* sit=dynamic_cast<SitAndGo*>(p.getTorneo());
    Cash * cash=dynamic_cast<Cash*>(p.getTorneo());
      if(sit){
         searchBuyInLabel->setText("BuyIn");
         searchNomeEdit->setText(QString::fromStdString(sit->getNome()));
         searchGiocEdit->setText(QString::number(sit->getNumeroGiocatori()));
         searchImportoEdit->setText(QString::number(sit->getTaxPerGiocatore()));
         searchBuyInEdit->setText(QString::number(sit->getBuyIn()));
         searchTipoLabel->setText("Tipo : SitAndGo");
         searchTotaleLabel->setText("Totale da pagare : "+ QString::number(sit->tax())+" euro");
      }
      else
          if(cash){
              searchBuyInLabel->setText("Durata/h");
              searchNomeEdit->setText(QString::fromStdString(cash->getNome()));
              searchGiocEdit->setText(QString::number(cash->getNumeroGiocatori()));
              searchImportoEdit->setText(QString::number(cash->getTaxPerGiocatore()));
              searchBuyInEdit->setText(QString::number(cash->getDurata()));
              searchTipoLabel->setText("Tipo : Cash");
              searchTotaleLabel->setText("Totale da pagare : "+ QString::number(cash->tax())+" euro");
          }
}

void SearchWindow::resetCampi(){
    searchNomeEdit->setText("");
    searchGiocEdit->setText("");
    searchImportoEdit->setText("");
    searchBuyInEdit->setText("");
    searchTipoLabel->setText("Tipo :");
    searchTotaleLabel->setText("Totale da pagare : ");
}

void SearchWindow::on_searchDeleteButton_clicked()
{
      int reply = QMessageBox::question(this, "Cancellazione Torneo", "Confermi la cancellazione del torneo?",
                                      QMessageBox::Yes, QMessageBox::Cancel);
      if(reply == QMessageBox::Yes){
            resetCampi();
            emit torneoRemove(nomeTorneo);
            bool presente=el->deleteTorneo(nomeTorneo.toStdString());
            if(presente==0){
                QMessageBox err;
                err.setText("C'e' stato un errore");
                err.exec();
            }
         this->close();
      }
}

void SearchWindow::on_editNomeButton_clicked()
{
    QString resetNome=searchNomeEdit->text();
    ElencoTornei::SmartPtr ptr=el->searchTorneo(resetNome.toStdString());
    ElencoTornei::SmartPtr cerca=el->searchTorneo(nomeTorneo.toStdString());
    int reply = QMessageBox::question(this, "Modifica Torneo", "Confermi la modifica del torneo?",
                                    QMessageBox::Yes, QMessageBox::Cancel);
    if(reply == QMessageBox::Yes){
            if(ptr!=0)
            {
                searchNomeEdit->setText(nomeTorneo);
                QMessageBox err;
                err.setText("Nome uguale o gia' presente");
                err.exec();
            }
            else{
                SitAndGo* sit=dynamic_cast<SitAndGo*>(cerca.getTorneo());
                Cash* cash=dynamic_cast<Cash*>(cerca.getTorneo());
                if(sit){
                    el->modificaSitAndGo(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetNome(resetNome.toStdString());
                    emit nameChanged(resetNome,nomeTorneo);
                    this->setNomeTorneo(resetNome);
                }
                else if(cash){
                    el->modificaCash(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetNome(resetNome.toStdString());
                    emit nameChanged(resetNome, nomeTorneo);
                    this->setNomeTorneo(resetNome);
                }
            }
    }
    else
        searchNomeEdit->setText(nomeTorneo);
}

void SearchWindow::on_editGiocButton_clicked()
{
    ElencoTornei::SmartPtr cerca=el->searchTorneo(nomeTorneo.toStdString());
    SitAndGo* sit=dynamic_cast<SitAndGo*>(cerca.getTorneo());
    Cash* cash=dynamic_cast<Cash*>(cerca.getTorneo());
    int reply = QMessageBox::question(this, "Modifica Torneo", "Confermi la modifica del torneo?",
                                    QMessageBox::Yes, QMessageBox::Cancel);
    if(reply == QMessageBox::Yes){
        bool ok;
        int giocatori=searchGiocEdit->text().toInt(&ok);
        if(!ok)
        {
            searchGiocEdit->setText(QString::number(cerca->getNumeroGiocatori()));
            QMessageBox err;
            err.setText("Numero non permesso");
            err.exec();
        }
        else
        {
        if(sit){
            el->modificaSitAndGo(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetNumeroGiocatori(giocatori);
            searchTotaleLabel->setText("Totale da pagare : "+ QString::number(sit->tax())+ " euro");
        }
        else
            if(cash){
               el->modificaCash(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetNumeroGiocatori(giocatori);
               searchTotaleLabel->setText("Totale da pagare : "+ QString::number(cash->tax())+ " euro");
            }
        }
    }
    else
        searchGiocEdit->setText(QString::number(cerca->getNumeroGiocatori()));

}

void SearchWindow::on_editImportoButton_clicked()
{
    ElencoTornei::SmartPtr cerca=el->searchTorneo(nomeTorneo.toStdString());
    SitAndGo* sit=dynamic_cast<SitAndGo*>(cerca.getTorneo());
    Cash* cash=dynamic_cast<Cash*>(cerca.getTorneo());
    int reply = QMessageBox::question(this, "Modifica Torneo", "Confermi la modifica del torneo?",
                                    QMessageBox::Yes, QMessageBox::Cancel);
    if(reply == QMessageBox::Yes){
        bool ok;
        double importo=searchImportoEdit->text().toDouble(&ok);
        if(!ok){
            searchImportoEdit->setText(QString::number(cerca->getTaxPerGiocatore()));
            QMessageBox err;
            err.setText("Importo non permesso");
            err.exec();
        }
        else{
            if(sit){
                el->modificaSitAndGo(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetTax(importo);
                searchTotaleLabel->setText("Totale da pagare : "+ QString::number(sit->tax())+ " euro");
            }
            else
                if(cash){
                    el->modificaCash(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetTax(importo);
                    searchTotaleLabel->setText("Totale da pagare : "+ QString::number(cash->tax())+ " euro");
                }
        }
    }
    else
        searchImportoEdit->setText(QString::number(cerca->getTaxPerGiocatore()));
}

void SearchWindow::on_editBuyInButton_clicked()
{
    ElencoTornei::SmartPtr cerca=el->searchTorneo(nomeTorneo.toStdString());
    SitAndGo* sit=dynamic_cast<SitAndGo*>(cerca.getTorneo());
    Cash* cash=dynamic_cast<Cash*>(cerca.getTorneo());
    int reply = QMessageBox::question(this, "Modifica Torneo", "Confermi la modifica del torneo?",
                                    QMessageBox::Yes, QMessageBox::Cancel);
    if(reply == QMessageBox::Yes){
        if(sit){
            bool ok;
            double buy=searchBuyInEdit->text().toDouble(&ok);
            if(!ok){
                searchBuyInEdit->setText(QString::number(sit->getBuyIn()));
                QMessageBox err;
                err.setText("BuyIn non permesso");
                err.exec();
            }
            else{
                el->modificaSitAndGo(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetBuyIn(buy);
                searchTotaleLabel->setText("Totale da pagare : "+ QString::number(sit->tax())+ " euro");
            }
        }
        else
            if(cash){
                bool ok;
                int durata=searchBuyInEdit->text().toInt(&ok);
                if(!ok){
                    searchBuyInEdit->setText(QString::number(cash->getDurata()));
                    QMessageBox err;
                    err.setText("Durata non permessa");
                    err.exec();
                }
                else{
                    el->modificaCash(el->getAccount(el->editTornei(nomeTorneo.toStdString()))).resetDurata(durata);
                    searchTotaleLabel->setText("Totale da pagare : "+ QString::number(cash->tax()) + " euro");
                }
            }
    }
    else{
        if(sit)
            searchBuyInEdit->setText(QString::number(sit->getBuyIn()));
        else
            if(cash)
                searchBuyInEdit->setText(QString::number(cash->getDurata()));
    }
}

void SearchWindow::setNomeTorneo(QString reset){
    nomeTorneo=reset;
}
