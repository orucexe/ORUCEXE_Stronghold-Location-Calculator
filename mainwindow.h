#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

private:
    Ui::MainWindow *ui;
    double degree1, degree2, x1, x2, z1, z2, CoordinatesDistance, strongholdDistance, overworldX, overworldZ;
    double rightDegreeOverflow(double d)
    {
        double result = d+90;
        if(result > 180)
        {
            result = -180 + (result-180);
        }
        return result;
    }
    double leftDegreeOverflow(double d)
    {
        double result = d-90;
        if(result < -180)
        {
            result = (-180-result);
        }
        return result;
    }
    double calculateStrongholdDistance(double distance)
    {
        double rad = distance * M_PI / 180.0;
        double resultDouble = CoordinatesDistance / sin(rad);
        strongholdDistance = resultDouble;
        return strongholdDistance;
    }
    double calculateCoordinatesDistance()
    {
        CoordinatesDistance = sqrt((x1-x2)*(x1-x2) + (z1-z2)*(z1-z2));
        return CoordinatesDistance;
    }
    void calculateOverworldCoordinates()
    {
        if(fmin(abs(180-degree2),abs(-180-degree2)) > abs(degree2))
        {
            double degree2copy = degree2;
            degree2 = abs(degree2);
            double radx = degree2 * M_PI / 180.0;
            double radz = (90.0-degree2) * M_PI / 180.0;
            overworldX = (strongholdDistance * sin(radx));
            overworldZ = z2 + (strongholdDistance * sin(radz));
            if(degree2copy >= 0 && degree2copy <= 180)
            {
                overworldX = x2-overworldX;
            }
            else
            {
                overworldX = x2+overworldX;
            }

        }
        else
        {
            double degree2copy = degree2;
            degree2 = fmin(abs(180-degree2),abs(-180-degree2));
            double radx = degree2 * M_PI / 180.0;
            double radz = (90.0-degree2) * M_PI / 180.0;
            overworldX = (strongholdDistance * sin(radx));
            overworldZ = z2 - (strongholdDistance * sin(radz));
            if(degree2copy >= 0 && degree2copy <= 180)
            {
                overworldX = x2-overworldX;
            }
            else
            {
                overworldX = x2+overworldX;
            }
        }

    }
};
#endif // MAINWINDOW_H
