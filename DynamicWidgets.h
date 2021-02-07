#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DynamicWidgets.h"

class DynamicWidgets : public QMainWindow
{
    Q_OBJECT

private:
    QHash<QPushButton*, QHBoxLayout*> mButtonToLayoutMap;

public:
    /// @brief Constructor.
    DynamicWidgets(QWidget *parent = Q_NULLPTR);

    /// @brief Destructor.
    ~DynamicWidgets();

    ///  @brief Handles user clicking on "add widget" button.
    void onAddWidget();

    ///  @brief Handles user clicking on a remove widget button.
    void onRemoveWidget();

private:
    Ui::DynamicWidgetsClass ui;
};
