#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fen_newcompte.h>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include "TransactionManager.h"
#include "fen_supprimercompte.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_Tous_les_transactions_clicked();

    void on_Releves_banque_clicked();

    void on_Cloture_clicked();

    void on_Ajouter_compte_clicked();

    void afficher_comptes_main(string n);

    void on_Ajouter_transaction_clicked();

    void on_treeWidget_doubleClicked(const QModelIndex &index);

    void on_Supprimer_clicked();

    void on_Modifier_transaction_clicked();

private:

    Ui::MainWindow* ui;
    fen_Supprimercompte* fen_supp ;
    enum Column{
        MEMO,REFERENCE,DATE
    };
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *Compte_Racine = new QStandardItem("Compte Racine");
};
#endif // MAINWINDOW_H
