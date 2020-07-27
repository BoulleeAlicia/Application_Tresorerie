#ifndef FEN_TOUSLESCOMPTES_H
#define FEN_TOUSLESCOMPTES_H

#include <QDialog>

namespace Ui {
class fen_touslesComptes;
}

class fen_touslesComptes : public QDialog
{
    Q_OBJECT

public:
    explicit fen_touslesComptes(QWidget *parent = nullptr);
    ~fen_touslesComptes();

private:
    Ui::fen_touslesComptes *ui;
};

#endif // FEN_TOUSLESCOMPTES_H
