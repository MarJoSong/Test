#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    
    void (QSpinBox::*valChg)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, valChg, ui->horizontalSlider, &QSlider::setValue);
    
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

SmallWidget::~SmallWidget()
{
    delete ui;
}

void SmallWidget::setMedium()
{
    ui->spinBox->setValue(50);
}

int SmallWidget::retValue()
{
    return ui->spinBox->value();
}
