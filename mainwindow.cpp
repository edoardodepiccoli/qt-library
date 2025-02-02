#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

#include "book.h"
#include "movie.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout();

    // Left empty space (2/3 of the window)
    QWidget *leftSpace = new QWidget();
    leftSpace->setStyleSheet("background-color: white;");
    mainLayout->addWidget(leftSpace, 2); // 2/3 of the space

    // Right form (1/3 of the window)
    QWidget *rightForm = new QWidget();
    QVBoxLayout *rightLayout = new QVBoxLayout(rightForm);

    // ComboBox to choose between Book and Movie
    QComboBox *typeComboBox = new QComboBox();
    typeComboBox->addItem("Book");
    typeComboBox->addItem("Movie");
    rightLayout->addWidget(typeComboBox);

    // Form layout for Book/Movie details
    QFormLayout *formLayout = new QFormLayout();
    QLineEdit *titleLineEdit = new QLineEdit();
    QLineEdit *idLineEdit = new QLineEdit();
    QLineEdit *authorLineEdit = new QLineEdit();
    QLineEdit *yearLineEdit = new QLineEdit();

    formLayout->addRow("Title:", titleLineEdit);
    formLayout->addRow("ID:", idLineEdit);
    formLayout->addRow("Author:", authorLineEdit);
    formLayout->addRow("Year:", yearLineEdit);

    rightLayout->addLayout(formLayout);

    // Initially hide author and year fields
    authorLineEdit->setVisible(false);
    yearLineEdit->setVisible(false);

    // Connect the ComboBox signal to update the form
    connect(typeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        if (index == 0) { // Book
            authorLineEdit->setVisible(true);
            yearLineEdit->setVisible(false);
        } else if (index == 1) { // Movie
            authorLineEdit->setVisible(false);
            yearLineEdit->setVisible(true);
        }
    });

    // Button to add the item
    QPushButton *addButton = new QPushButton("Add Item");
    rightLayout->addWidget(addButton);

    // Connect the button to add the item
    connect(addButton, &QPushButton::clicked, [=]() {
        int id = idLineEdit->text().toInt();
        QString title = titleLineEdit->text();

        if (typeComboBox->currentIndex() == 0) { // Book
            QString author = authorLineEdit->text();
            Book *book = new Book(id, title, author);
            library->addItem(book);
        } else if (typeComboBox->currentIndex() == 1) { // Movie
            int year = yearLineEdit->text().toInt();
            Movie *movie = new Movie(id, title, year);
            library->addItem(movie);
        }

        // Clear the form
        titleLineEdit->clear();
        idLineEdit->clear();
        authorLineEdit->clear();
        yearLineEdit->clear();
    });

    mainLayout->addWidget(rightForm, 1); // 1/3 of the space

    // Set the main layout to the central widget
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Load and debug items
    library = new Library();
    library->loadItems();
    library->debugItems();
}

MainWindow::~MainWindow()
{
    delete ui;
}
