#include <iostream>
#include <ctime>

using namespace std;

struct NetComponent {
    string Type; // тип
    string Name; // название
    string Descr; // описание
    double Price; // цена 
    string MakerCompany; // производитель
    string SupplierCompany; // поставщик
    string ArchitectureType; // архитектура
    string NetTopologyType; // топология сети
    string DeliveryTime; // время поставки
};

double MinNetComponentPrice(NetComponent components[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    double minPrice = components[0].Price;
    
    for (int i = 1; i < size; i++)
    {
        if (minPrice > components[i].Price)
        {
            minPrice = components[i].Price;
        }
    }

    return minPrice;
}

double MaxNetComponentPrice(NetComponent components[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    double maxPrice = components[0].Price;
    
    for (int i = 1; i < size; i++)
    {
        if (maxPrice < components[i].Price)
        {
            maxPrice = components[i].Price;
        }
    }

    return maxPrice;
}

double AvarageNetComponentPrice(NetComponent components[], int size)
{
    if (size == 0)
    {
        return 0.0;
    }

    double avg = 0.0;

    for (int i = 0; i < size; i++)
    {
        avg += components[i].Price;
    }

    return avg / size;
}

double NetComponentsSummary(NetComponent c[], int size)
{
    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += c[i].Price;
    }

    return sum;
}


int main()
{
    const int N = 5;
    NetComponent components[N] =
    {
        {
            "Маршрутизатор",
            "TP-Link TL-R480T+",
            "LAN 1x100 Мбит/c, WAN 1x100 Мбит/c, WAN/LAN 3x100",
            3690.0,
            "TP-Link",
            "DNS",
            "...",
            "Полносвязная топология",
            "2018/05/21 09:30:00 MSK+00"
        },
        {
            "Маршрутизатор",
            "TP-Link ER605 (TL-R605) v1",
            "LAN 1x1000 Мбит/c, WAN 1x1000 Мбит/c, WAN/LAN 3x1000 Мбит/c, IPv6 ",
            5299.0,
            "TP-Link",
            "DNS",
            "...",
            "Полносвязная топология",
            "2020/02/18 18:00:00 MSK+00"
        },
        {
            "Коммутатор",
            "Edimax ES-3308P",
            "100 Мбит/сек, 8 port",
            699.0,
            "EDIMAX",
            "DNS",
            "...",
            "Иерархическая топология",
            "2015/07/15 12:00:00 MSK+00"
        },
        {
            "Ноутбук",
            "HP dw1495nia 6J5C0EA",
            "...",
            24999.0,
            "HP",
            "Mvideo",
            "...",
            "...",
            "2020/04/30 12:00:00 MSK+00"
        },
        {
            "Ноутбук",
            "HP 15-dw3682nia",
            "...",
            49999.0,
            "HP",
            "Mvideo",
            "...",
            "...",
            "2022/10/10 09:00:00 MSK+00"
        }
    };

    cout << "Min NetComponents Price: " << MinNetComponentPrice(components, N) << endl;
    cout << "Max NetComponents Price: " << MaxNetComponentPrice(components, N) << endl;
    cout << "Avarage NetComponents Price: " << AvarageNetComponentPrice(components, N) << endl;
    cout << "Summary NetComponents Price: " << NetComponentsSummary(components, N) << endl;

    return 0;
}