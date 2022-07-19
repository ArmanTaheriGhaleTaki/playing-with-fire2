#include "Label.h"
#include <QFont>
#include <QTextDocument>
Label::Label(int fontSize,const char* color) {


    setDefaultTextColor(QColor(color));
    QFont font;
    font.setPixelSize(fontSize);
    font.setBold(true);
    setFont(font);


    document()->setDocumentMargin(4);

}
