#ifndef FEN_RELEVES_H
#define FEN_RELEVES_H

#include <QDialog>

namespace Ui {
class fen_releves;
}

class fen_releves : public QDialog
{
    Q_OBJECT

public:
    explicit fen_releves(QWidget *parent = nullptr);
    ~fen_releves();

private:
    Ui::fen_releves *ui;
};

#endif // FEN_RELEVES_H
