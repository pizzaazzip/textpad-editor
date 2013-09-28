#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include "Code/Base/Shared.hh"

class FindDialog: public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);

    QTextCursor *TextCursor;
    QPlainTextEdit *TextEdit;

    QLabel *FindLabel;
    QLabel *ReplaceLabel;
    QCheckBox *MatchCaseCheckbox;
    QCheckBox *WholeWordsCheckbox;
    QLineEdit *FindLineEdit;
    QLineEdit *ReplaceLineEdit;
    QGridLayout *Layout;
    QPushButton *CancelButton;
    QPushButton *ReplaceAllButton;
    QPushButton *ReplaceButton;
    QSpacerItem *VerticalSpacer;

public slots:
    void SetTextEdit(QPlainTextEdit *TextEdit_);

private slots:
    void CreateWidgets();
    void SearchText();
    void ReplaceAll();
    void ReplaceFirstOccurence();
};

#endif
