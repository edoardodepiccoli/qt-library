#include "bookwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QIcon>

BookWidget::BookWidget(Book *book, QWidget *parent) : QWidget(parent)
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
  QIcon icon(":/icons/src/assets/menu_book.svg");
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
  QLabel *titleLabel = new QLabel(book->getTitle());
  QLabel *authorLabel = new QLabel(book->getAuthor());
  titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #323232;");
  authorLabel->setStyleSheet("font-size: 12px; color: #323232;");
  detailsLayout->addWidget(titleLabel);
  detailsLayout->addWidget(authorLabel);

  mainLayout->addWidget(detailsWidget);
}
