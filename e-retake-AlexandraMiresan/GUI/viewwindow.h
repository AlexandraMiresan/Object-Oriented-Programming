//
// Created by Ale on 7/10/2025.
//

#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QDialog>
#include <QPainter>
#include "../Domain/Recipe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewWindow; }
QT_END_NAMESPACE

class ViewWindow : public QDialog, public QPainter {
Q_OBJECT

public:
    explicit ViewWindow(std::vector<std::shared_ptr<Recipe>> recipes, QWidget *parent = nullptr);
    ~ViewWindow() override;
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::ViewWindow *ui{};
    std::vector<std::shared_ptr<Recipe>> recipes;
};


#endif //VIEWWINDOW_H
