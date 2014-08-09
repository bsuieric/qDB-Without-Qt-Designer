#include "mainwindow.h"
#include <QApplication>
#include "elencotornei.h"
#include"searchwindow.h"


#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}



//#include "elencotornei.h"
//#include <iostream>
//using std::cout;
//using std::endl;

//int main(){
//    ElencoTornei el;
//    el.addSitAndGoIfNotPresent("tu",1,2,3);
//    el.addCashIfNotPresent("noi",1,2,3);

//    el.modificaSitAndGo(el.getAccount(el.editTornei("tu"))).resetNome("tusieuuu");
//    el.modificaCash(el.getAccount(el.editTornei("noi"))).resetNome("noiiii");


//    cout<<el;

//}
