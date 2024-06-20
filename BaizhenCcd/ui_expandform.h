/********************************************************************************
** Form generated from reading UI file 'expandform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPANDFORM_H
#define UI_EXPANDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpandForm
{
public:

    void setupUi(QWidget *ExpandForm)
    {
        if (ExpandForm->objectName().isEmpty())
            ExpandForm->setObjectName(QString::fromUtf8("ExpandForm"));
        ExpandForm->resize(1407, 991);

        retranslateUi(ExpandForm);

        QMetaObject::connectSlotsByName(ExpandForm);
    } // setupUi

    void retranslateUi(QWidget *ExpandForm)
    {
        ExpandForm->setWindowTitle(QCoreApplication::translate("ExpandForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpandForm: public Ui_ExpandForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPANDFORM_H
