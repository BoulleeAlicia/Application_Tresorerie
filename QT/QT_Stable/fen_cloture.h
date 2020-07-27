#ifndef FEN_CLOTURE_H
#define FEN_CLOTURE_H

#include <QDialog>

namespace Ui {
class fen_cloture;
}

class fen_cloture : public QDialog
{
    Q_OBJECT

public:
    explicit fen_cloture(QWidget *parent = nullptr);
    ~fen_cloture();

private:
    Ui::fen_cloture *ui;
};

#endif // FEN_CLOTURE_H
