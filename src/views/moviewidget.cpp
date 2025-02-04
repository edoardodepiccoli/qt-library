#include "moviewidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QIcon>
#include <QDebug>
#include "clickablelabel.h"

MovieWidget::MovieWidget(Movie *movie, QWidget *parent) : QWidget(parent)
{
    setFixedHeight(150);
    setStyleSheet("background-color: #D9D9D9;");

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Icon container
    QWidget *iconContainer = new QWidget();
    iconContainer->setFixedWidth(100);
    iconContainer->setStyleSheet("background-color: #D9D9D9;");
    QVBoxLayout *iconLayout = new QVBoxLayout(iconContainer);

    // Icon part
    QLabel *iconLabel = new QLabel();
    QIcon icon(":/icons/src/assets/movie.svg");
    QPixmap pixmap = icon.pixmap(64, 64);
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), QColor("#323232"));
    iconLabel->setPixmap(pixmap);
    iconLabel->setFixedSize(64, 64);
    iconLayout->addWidget(iconLabel, 0, Qt::AlignCenter);
    mainLayout->addWidget(iconContainer);

    // Details part
    QWidget *detailsWidget = new QWidget();
    QVBoxLayout *detailsLayout = new QVBoxLayout(detailsWidget);
    detailsLayout->setAlignment(Qt::AlignVCenter);
    detailsLayout->setSpacing(4);
    QLabel *titleLabel = new QLabel(movie->getTitle());
    QLabel *yearLabel = new QLabel(QString::number(movie->getReleaseYear()));
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #323232;");
    yearLabel->setStyleSheet("font-size: 12px; color: #323232;");
    detailsLayout->addWidget(titleLabel);
    detailsLayout->addWidget(yearLabel);

    mainLayout->addWidget(detailsWidget);

    // Actions part
    QWidget *actionsContainer = new QWidget();
    actionsContainer->setStyleSheet("background-color: #D9D9D9;");
    QHBoxLayout *actionsLayout = new QHBoxLayout(actionsContainer);
    actionsLayout->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    actionsLayout->setContentsMargins(0, 0, 10, 0);

    ClickableLabel *deleteIconLabel = new ClickableLabel();
    deleteIconLabel->setCursor(Qt::PointingHandCursor);
    QIcon deleteIcon(":/icons/src/assets/delete_forever.svg");
    QPixmap deletePixmap = deleteIcon.pixmap(24, 24);
    QPainter deletePainter(&deletePixmap);
    deletePainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    deletePainter.fillRect(deletePixmap.rect(), QColor("#323232"));
    deleteIconLabel->setPixmap(deletePixmap);
    deleteIconLabel->setFixedSize(24, 24);
    connect(deleteIconLabel, &ClickableLabel::clicked, this, &MovieWidget::handleDeleteClick);
    actionsLayout->addWidget(deleteIconLabel);

    mainLayout->addWidget(actionsContainer);
}

void MovieWidget::handleDeleteClick()
{
    qDebug() << "Delete button clicked for movie!";
    emit deleteRequested();
}
