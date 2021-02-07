#include "DynamicWidgets.h"
#include <QtWidgets/QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set the app style sheet
    QFile styleSheetFile("./Adaptic.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);

    DynamicWidgets w;
    w.show();
    return app.exec();
}
