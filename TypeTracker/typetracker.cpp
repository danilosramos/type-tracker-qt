#include "typetracker.h"
#include "ui_typetracker.h"
#include <QTimer>
#include <QString>
#include <string>
#include <vector>
#include <QMessageBox>
#include <QIcon>

BaseTypeTracker::BaseTypeTracker()
    : wordIndex(0), error(0), amount(0), chars(0), pastError(false)
{
    word = {"love", "friendship", "peace", "enjoy", "hope", "courage", "honor", "wisdom", "happiness", "freedom", "respect", "justice", "solidarity", "gratitude", "resilience", "compassion", "kindness", "optimism", "creativity", "determination", "patience", "humility", "integrity", "trust", "forgiveness", "self-love", "responsibility", "discipline", "tolerance", "enthusiasm", "diligence", "altruism", "loyalty", "sensitivity", "adaptability", "assertiveness", "competence", "consistency", "collaboration", "empathy", "balance", "fidelity", "strength", "honesty", "inclusion", "innovation", "inspiration", "modesty", "objectivity", "perseverance", "insight", "prudence", "rationality", "resolution", "simplicity", "sincerity", "transparency", "unity", "bravery", "vigilance", "vivacity", "zeal", "shelter", "hospitality", "admiration", "relief", "benevolence", "calmness", "clarity", "companionship", "commitment", "understanding", "comfort", "consideration", "contentment", "care", "dedication", "delicacy", "dignity", "discretion", "thoughtfulness", "generosity", "joyfulness", "peacefulness", "serenity", "compassionate", "benevolent", "sincere", "truthful", "mindfulness", "carefulness", "attentiveness", "warmth", "humbleness", "gentleness", "charity", "kindhearted", "helpfulness", "understanding", "tenderness", "loyal", "friendly", "cheerful", "energetic", "enthusiastic"};
}

BaseTypeTracker::~BaseTypeTracker() {}

TypeTracker::TypeTracker(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TypeTracker), timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &TypeTracker::updateCounter); // Conecta o timer c/ slot updateCounter
    connect(ui->pushButton, &QPushButton::clicked, this, &TypeTracker::on_pushButton_clicked);// Conecta o botão c/ on_pushButton_clicked
}

TypeTracker::~TypeTracker()
{
    delete ui;
}

void TypeTracker::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();

    if (!timer->isActive()) {
        timer->start(16.67); //Tempo aproximado em ms p/ que 1 min se passe em 1s
    } else {
        counterTime.setHMS(0, 0, 0);
        ui->timeEdit->setTime(counterTime);
    }
    userWord.clear();
    userWord.resize(word.size());
    wordIndex = 0;
    error = 0;
    amount = 0;
    chars = 0;
}

void TypeTracker::updateCounter()
{
    counterTime = counterTime.addSecs(1);
    ui->timeEdit->setTime(counterTime);

    if (counterTime.hour() == 0 && wordIndex < word.size()) {
        QString displayedWord = QString::fromStdString(word[wordIndex]);
        ui->textEdit->setText(displayedWord);
        QString userInput = ui->lineEdit->text();

        int min_length = qMin(userInput.length(), displayedWord.length());// Calcula o comprimento mínimo das palavras
        int wordErrors = 0;

        for (int i = 0; i < min_length; ++i) { // Compara char a char
            if (userInput[i] != displayedWord[i]) {
                wordErrors++;
            }
        }

        if (userInput.length() == displayedWord.length()) {
            userWord[wordIndex] = userInput.toStdString();
            amount += wordErrors;
            chars += userInput.length();
            wordIndex++;
            ui->lineEdit->clear();
        }

        ui->lineEdit_2->setText(QString::number(amount));
    }

    if (counterTime.hour() == 1 || wordIndex >= word.size()) {
        timer->stop();
        counterTime.setHMS(0, 0, 0);
        ui->timeEdit->setTime(counterTime);
        ui->textEdit->setText(QString::number(amount));
        float wpm = (chars / 60) * 5;
        float accuracy = ((chars - amount) / chars) * 100;

        QMessageBox::information(this, "ScoreBoard", QString("You have written about %2 WPM.\n You typed %1 chars.\n Your accuracy was %3 %.").arg(chars).arg(wpm).arg(accuracy));
    }
}

