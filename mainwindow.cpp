#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include "datedelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTable2();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int nTest = 0;

    int* pTest = NULL;

    nTest = *pTest;
}

void MainWindow::initTable2()
{
    QStandardItemModel* pmodel = new QStandardItemModel();
    ui->tableView->setModel(pmodel);
    pmodel->setColumnCount(4);

    DateDelegate *pdateDelegate = new DateDelegate(this);
    ui->tableView->setItemDelegateForColumn(0, pdateDelegate);
    ui->tableView->setItemDelegateForColumn(1, pdateDelegate);

    //selects row, Only one row at one time.
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    pmodel->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
    pmodel->setHeaderData(1,Qt::Horizontal,QObject::tr("Birthday"));
    pmodel->setHeaderData(2,Qt::Horizontal,QObject::tr("Job"));
    pmodel->setHeaderData(3,Qt::Horizontal,QObject::tr("Income"));

    for(int i = 0; i < 4; i++)
    {
        pmodel->setItem(i, 0, new QStandardItem("zhangsan"));
        pmodel->setItem(i, 1, new QStandardItem("20120202"));
        pmodel->setItem(i, 2, new QStandardItem("nan"));
        pmodel->setItem(i, 3, new QStandardItem("18"));
    }

}

void MainWindow::initTable1()
{
    QStandardItemModel* pmodel = new QStandardItemModel(4,4);
    ui->tableView->setModel(pmodel);

    DateDelegate *pdateDelegate = new DateDelegate(this);
    ui->tableView->setItemDelegateForColumn(1,pdateDelegate);

    ui->tableView->setColumnWidth(0, 40);
    ui->tableView->setColumnWidth(1, 80);
    ui->tableView->setColumnWidth(2, 100);
    ui->tableView->setColumnWidth(3, 100);

    pmodel->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
    pmodel->setHeaderData(1,Qt::Horizontal,QObject::tr("Birthday"));
    pmodel->setHeaderData(2,Qt::Horizontal,QObject::tr("Job"));
    pmodel->setHeaderData(3,Qt::Horizontal,QObject::tr("Income"));

    pmodel->removeRows(0,pmodel->rowCount(QModelIndex()),QModelIndex());

    for(int i = 0; i < 4; i++)
    {
        pmodel->insertRows(i,1,QModelIndex());
        pmodel->setData(pmodel->index(i,0,QModelIndex()),"1");
        pmodel->setData(pmodel->index(i,1,QModelIndex()),"2");
        pmodel->setData(pmodel->index(i,2,QModelIndex()),"3");
        pmodel->setData(pmodel->index(i,3,QModelIndex()),"4");
    }

    ui->tableView->setWindowTitle(QObject::tr("Delegate"));
}
