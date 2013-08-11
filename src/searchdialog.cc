// Copyright (C) 2013  Alex S. <alex_sr97@outlook.com>
// See the "Copying.txt" file that comes with this distribution

#include "src/searchdialog.hh"

FindDialog::FindDialog(QWidget *parent): QDialog(parent) {
    setWindowTitle(tr("Search and Replace"));
    CreateWidgets();
}

void FindDialog::CreateWidgets() {
    // Remove the window icon in Mac OS X
    QIcon BlankIcon;
    if (Shared::CheckOS() == 1)
        setWindowIcon(BlankIcon);

    // Create the widgets
    Layout             = new QGridLayout(this);
    FindLabel          = new QLabel(this);
    ReplaceLabel       = new QLabel(this);
    MatchCaseCheckbox  = new QCheckBox(this);
    WholeWordsCheckbox = new QCheckBox(this);
    FindLineEdit       = new QLineEdit(this);
    ReplaceLineEdit    = new QLineEdit(this);
    CancelButton       = new QPushButton(this);
    ReplaceAllButton   = new QPushButton(this);
    ReplaceButton      = new QPushButton(this);

    // Change the text
    FindLabel->setText          (tr("Find what:"));
    ReplaceLabel->setText       (tr("Replace with:"));
    MatchCaseCheckbox->setText  (tr("Match case"));
    WholeWordsCheckbox->setText (tr("Whole words only"));
    CancelButton->setText       (tr("Cancel"));
    ReplaceAllButton->setText   (tr("Replace All"));
    ReplaceButton->setText      (tr("Replace"));

    // Set the VerticalSpacer
    VerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    // Set the layout
    Layout->setSpacing(10);
    Layout->addWidget(FindLabel,          1, 1, 1, 1);
    Layout->addWidget(FindLineEdit,       1, 2, 1, 2);
    Layout->addWidget(ReplaceLabel,       2, 1, 2, 1);
    Layout->addWidget(ReplaceLineEdit,    2, 2, 2, 2);
    Layout->addWidget(ReplaceAllButton,   2, 4, 2, 4);
    Layout->addWidget(ReplaceButton,      1, 4, 1, 4);
    Layout->addWidget(CancelButton,       6, 4, 3, 4);
    Layout->addWidget(MatchCaseCheckbox,  4, 1, 3, 1);
    Layout->addWidget(WholeWordsCheckbox, 6, 1, 3, 1);
    Layout->addItem  (VerticalSpacer,     3, 1, 3, 1);

    // Set the fixed size
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    // Connect the slots
    connect(CancelButton,       SIGNAL(clicked()),            this, SLOT(hide()));
    connect(FindLineEdit,       SIGNAL(textChanged(QString)), this, SLOT(SearchText()));
    connect(MatchCaseCheckbox,  SIGNAL(clicked()),            this, SLOT(SearchText()));
    connect(WholeWordsCheckbox, SIGNAL(clicked()),            this, SLOT(SearchText()));
    connect(ReplaceAllButton,   SIGNAL(clicked()),            this, SLOT(ReplaceAll()));
    connect(ReplaceButton,      SIGNAL(clicked()),            this, SLOT(ReplaceFirstOccurence()));

    // Disable Replace Functions
    ReplaceAllButton->setEnabled(false);
    ReplaceButton->setEnabled(false);
    ReplaceLineEdit->setEnabled(false);
}

void FindDialog::SetTextEdit(QPlainTextEdit *TextEdit_) {
    TextEdit = TextEdit_;
}

void FindDialog::SearchText() {
    QTextDocument::FindFlags Flags;
    if (MatchCaseCheckbox->isChecked())
        Flags |= QTextDocument::FindCaseSensitively;

    if (WholeWordsCheckbox->isChecked())
        Flags |= QTextDocument::FindWholeWords;

    if (!FindLineEdit->text().isEmpty()) {
        ReplaceAllButton->setEnabled(1);
        ReplaceButton->setEnabled(1);
        ReplaceLineEdit->setEnabled(1);

        // Search for something (and highlight the results)
        {
            QList<QTextEdit::ExtraSelection> ExtraSelections;
            TextEdit->moveCursor(QTextCursor::End);

            while (TextEdit->find(FindLineEdit->text(), Flags | QTextDocument::FindBackward)) {
                QTextEdit::ExtraSelection Selection;
                Selection.format.setBackground(QColor(Qt::yellow).lighter(160));
                Selection.format.setForeground(QColor(Qt::black));
                Selection.cursor = TextEdit->textCursor();
                ExtraSelections.append(Selection);
            }
            TextEdit->setExtraSelections(ExtraSelections);
        }
    }

    // Disable replace functions
    else {
        ReplaceAllButton->setEnabled (false);
        ReplaceButton->setEnabled    (false);
        ReplaceLineEdit->setEnabled  (false);
    }
}

void FindDialog::ReplaceAll() {
    QTextDocument::FindFlags Flags;
    if (MatchCaseCheckbox->isChecked())
        Flags |= QTextDocument::FindCaseSensitively;

    if (WholeWordsCheckbox->isChecked())
        Flags |= QTextDocument::FindWholeWords;

    int i = 0;
    while (TextEdit->find(FindLineEdit->text(), Flags)) {
        while (TextEdit->textCursor().hasSelection()) {
            TextEdit->moveCursor(QTextCursor::Start);
            while (TextEdit->find(FindLineEdit->text(), Flags)) {
                TextEdit->textCursor().insertText(ReplaceLineEdit->text());
                i++;
            }
        }
    }
}

void FindDialog::ReplaceFirstOccurence() {
    SearchText();
    if (TextEdit->textCursor().hasSelection())
        TextEdit->textCursor().insertText(ReplaceLineEdit->text());
    else
        QMessageBox::warning(this, tr("Warning"), tr("No matches where found"));
}
