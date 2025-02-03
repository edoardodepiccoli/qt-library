#include "sidebar.h"
#include <QVBoxLayout>
#include <QIcon>

Sidebar::Sidebar(QWidget *parent) : QWidget(parent), selectedButton(nullptr)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(8, 8, 8, 8);

    searchButton = new QPushButton(this);
    addButton = new QPushButton(this);

    setupButton(searchButton, ":/assets/search.svg");
    setupButton(addButton, ":/assets/add.svg");

    // Set search as initially selected
    selectedButton = searchButton;
    styleButton(searchButton, true);
    styleButton(addButton, false);

    layout->addWidget(searchButton);
    layout->addWidget(addButton);
    layout->addStretch();

    setLayout(layout);

    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor("#383838")); // see https://wiki.qt.io/How_to_Change_the_Background_Color_of_QWidget

    this->setAutoFillBackground(true);
    this->setPalette(pal); // why is setting the palette necessary? should look into this
}

void Sidebar::setupButton(QPushButton *button, const QString &iconPath)
{
    button->setFixedSize(50, 50);
    button->setIconSize(QSize(24, 24));
    button->setIcon(QIcon(iconPath));
    button->setCursor(Qt::PointingHandCursor);

    connect(button, &QPushButton::clicked, this, &Sidebar::handleButtonClick);
}

void Sidebar::styleButton(QPushButton *button, bool selected)
{
    QString style = QString(
                        "QPushButton {"
                        "    border: none;"
                        "    border-radius: 12px;"
                        "    margin-bottom: 8px;"
                        "    background-color: %1;"
                        "}")
                        .arg(selected ? "#D9D9D9" : "#222222");

    button->setStyleSheet(style);

    // Update icon color (AI generated, don't understand it yet)
    QIcon icon = button->icon();

    QPixmap pixmap = icon.pixmap(QSize(24, 24));
    QPixmap newPixmap(pixmap.size());
    newPixmap.fill(selected ? QColor("#222222") : QColor("#D9D9D9"));
    newPixmap.setMask(pixmap.createMaskFromColor(Qt::transparent));

    button->setIcon(QIcon(newPixmap));
}

void Sidebar::handleButtonClick()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton && clickedButton != selectedButton)
    {
        styleButton(selectedButton, false);
        styleButton(clickedButton, true);
        selectedButton = clickedButton;
    }
}

Sidebar::~Sidebar()
{
}