using namespace std;
#include <iostream>
#include <cmath>


bool part(double x, int n)
{
    if (x<=-1)
    {
        cout << "Недопустимое значение х" << endl;
        return 0;
    }
    if (n == 1)
    {
        cout << "Абсолютная погрешность равна >"<<1/sqrt(2)<<endl;
        cout << "Погрешность меньше последнего члена на"<<abs((1/sqrt(2))-1)<<endl;
        cout << "Частичная сумма ряда >1" << endl;
        return 0;
    }
       
    double thng = 1.0; long double itg = 1; long double a=0; double compr;
    long double cmpr1; long double cmpr2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2*i; j++)
        {
            if (j % 2 == 0)
                thng=thng / j;
            else thng=thng*j;
        }

        a = pow(x, i) * thng * pow(-1, i);
        itg +=a;
        thng = 1; 
    }

    compr =1/(sqrt(1+x));

    cmpr1 = fabs(compr - itg);
    cout << "Абсолютная погрешность >" << cmpr1 << endl;
    cmpr2 = cmpr1 -fabs(a);
    if (cmpr2 < 0) cout << "Погрешность меньше последнего члена на " << abs(cmpr2) << endl;
    if (cmpr2 > 0) cout << "Погрешность больше последнего члена на" << cmpr2 << endl;
    if (cmpr2 == 0) cout << "Погрешность равна последнему члену" << endl;
    cout << "Частичная сумма ряда >"<<itg<<endl;
   

    return 1;
}

bool lopata(double x, double e)
{
    if (x <= -1)
    {
        cout << "Недопустимое значение х" << endl;
        return 0;
    }
    if (x > 1)
    {
        cout << "Ряд расходится" << endl;
        return 0;
    }

    if (e >= 1)
    {
        cout << "Количество членов ряда больше Е >0" << endl;
        cout << "Сумма членов >0" << endl;
        return 0;
    }

    int n = 1; double thng = 1; long double a = 0; long double itg = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * i; j++)
        {
            if (j % 2 == 0)
                thng = thng / j;
            else thng = thng * j;
        }

        a = pow(x, i) * thng * pow(-1, i);
        if (fabs(a) > e)
        {
            itg += a;
            n += 1;
        }
        thng = 1;
    }
    cout << "Количество членов ряда больше Е >"<< n << endl;
    cout << "Сумма членов >"<< itg << endl<<endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int ch = 1;
    while (ch == 1)
    {
        cout << "Для работы программы введите 1. Для завершения 0 >";
        cin >> ch;
        switch (ch)
        {
            case(0):
                break;
            case(1):
                {
                    double x; int n;
                    cout <<endl<< "Введите x >";
                    cin >> x;
                    cout << "Количество членов ряда >";
                    cin >> n;
                    if (n >= 0)
                        part(x, n);
                    else cout << "Недопустимое значение n" << endl;

                    double e;
                    cout << endl<< "Введите х "<< "[Предупреждение! Ряд расходится при значении х>1] >";
                    cin >> x;
                    cout << "Введите Е >";
                    cin >> e;
                    lopata(x,e);
                    break;
                }
            default:
                {
                cout << "Ошибка ввода" << endl;
                ch = 1;
                }
        }
    }
}

