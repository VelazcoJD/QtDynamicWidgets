#include "DynamicWidgets.h"

#include <QCheckBox>

DynamicWidgets::DynamicWidgets(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QObject::connect(
        ui.addWidget_button, &QPushButton::clicked,
        this, &DynamicWidgets::onAddWidget);
}

DynamicWidgets::~DynamicWidgets() {}

void DynamicWidgets::onAddWidget() {
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui.widgets_frame->layout());

    QHBoxLayout* newLayout = new QHBoxLayout(ui.widgets_frame);

    QString buttonText = tr("Button: #%1").arg(layout->count());
    QPushButton* button = new QPushButton(buttonText, ui.widgets_frame);
    newLayout->addWidget(button);

    QCheckBox* checkBox = new QCheckBox("Check me!", ui.widgets_frame);
    newLayout->addWidget(checkBox);

    layout->insertLayout(0, newLayout);

    mButtonToLayoutMap.insert(button, newLayout);

    QObject::connect(
        button, &QPushButton::clicked,
        this, &DynamicWidgets::onRemoveWidget);
}

void DynamicWidgets::onRemoveWidget() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* layout = mButtonToLayoutMap.take(button);

    while (layout->count() != 0) {
        QLayoutItem* item = layout->takeAt(0);
        delete item->widget();
        delete item;
    }
    delete layout;

}
