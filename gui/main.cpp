/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#include "shapeknotsapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShapeKnotsApp *shapeKnotsGui = new ShapeKnotsApp();
    int ret = a.exec();
    delete shapeKnotsGui;
    return ret;
}
