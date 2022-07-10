#include "Label.h"
#include <QFont>
#include <QTextDocument>
Label::Label() {


    setDefaultTextColor(QColor("white"));
    QFont font;
    font.setPixelSize(40);
    font.setBold(true);
    setFont(font);


    document()->setDocumentMargin(4);

}
