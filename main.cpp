#include <iostream>

struct pancake {
    int PancakeNumber; //номер блинчика
    int PreviousPosition; //номер стрежня
};

struct karnel{
    pancake PanckakeArrray[5]; //Стержень
    int NumberOfElement; //Колво
    int CurentlyIndex;

};

int Game() {



    return 0;
}


int main() {
    karnel Tower[3];
    Tower[0].PanckakeArrray[0].PancakeNumber = 5;
    Tower[0].PanckakeArrray[0].PreviousPosition = 0;
    Tower[0].PanckakeArrray[1].PancakeNumber = 4;
    Tower[0].PanckakeArrray[1].PreviousPosition = 0;
    Tower[0].PanckakeArrray[2].PancakeNumber = 3;
    Tower[0].PanckakeArrray[2].PreviousPosition = 0;
    Tower[0].PanckakeArrray[3].PancakeNumber = 2;
    Tower[0].PanckakeArrray[3].PreviousPosition = 0;
    Tower[0].PanckakeArrray[4].PancakeNumber = 1;
    Tower[0].PanckakeArrray[4].PreviousPosition = 0;
    Tower[0].CurentlyIndex = 4;

    Tower[1].PanckakeArrray[0].PancakeNumber = -1;
    Tower[1].PanckakeArrray[0].PreviousPosition = -1;
    Tower[1].PanckakeArrray[1].PancakeNumber = -1;
    Tower[1].PanckakeArrray[1].PreviousPosition = -1;
    Tower[1].PanckakeArrray[2].PancakeNumber = -1;
    Tower[1].PanckakeArrray[2].PreviousPosition = -1;
    Tower[1].PanckakeArrray[3].PancakeNumber = -1;
    Tower[1].PanckakeArrray[3].PreviousPosition = -1;
    Tower[1].PanckakeArrray[4].PancakeNumber = -1;
    Tower[1].PanckakeArrray[4].PreviousPosition = -1;
    Tower[1].CurentlyIndex = 0;


    Tower[2].PanckakeArrray[0].PancakeNumber = -1;
    Tower[2].PanckakeArrray[0].PreviousPosition = -1;
    Tower[2].PanckakeArrray[1].PancakeNumber = -1;
    Tower[2].PanckakeArrray[1].PreviousPosition = -1;
    Tower[2].PanckakeArrray[2].PancakeNumber = -1;
    Tower[2].PanckakeArrray[2].PreviousPosition = -1;
    Tower[2].PanckakeArrray[3].PancakeNumber = -1;
    Tower[2].PanckakeArrray[3].PreviousPosition = -1;
    Tower[2].PanckakeArrray[4].PancakeNumber = -1;
    Tower[2].PanckakeArrray[4].PreviousPosition = -1;
    Tower[2].CurentlyIndex = 0;





    //------Эти данные обновляются перед каждым перемещением--------------------------------------------------
    int temp_previous_number_pancake;//запоминаем предыдущий переместившийся блинчик, его номер (уникальный)  |
    int temp_previous_number_karnel;//запоминаем откуда его переместили, с какого стержня                     |
    //--------------------------------------------------------------------------------------------------------
    int number = 0;// индекс текущего стержня, может меняться на 0,1,2
    //Цикл позволяет просмотреть ровно две следующие башни для "перемещения блинчика" с текущего стержня
    //Пробуем переместить текущий блинчик с текущего стержня на следующие стержни
    for ( int i = 1; i < 3; i++) {
        int nextNumber=(number+i) % 3; //индекс следующего стержня
        //Если текущий блинчик был на предыдущей позиции в следующем стержне, то туда перемещать его бессмысленно, избегаем пустых перемещений
        if ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition ==  nextNumber) /*Если текущий блинчик был раньше на позиции следующего стержня*/
        && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) /*Если текущий блинчик был перемещен в прошлую итерацию*/
        &&  (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel))) /*Если текущий блинчик был перемещен в прошлую итерацию на следующий стержень*/
        {
            NULL; //ничего не делаем.
        }
        else{
            //Перемещать блинчик с нынешней башни можно только на блин большего значения следующего стержня
            if (Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber > Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber) {
                //можем переместить блинчик
            }
            else{//если не можем переместить блинчик, то надо смотреть следующий стержень, переход на следующую итерацию цикла
                continue;
            }
        }
    }
    //------Правила которые надо внедрить!-------------------------------------------------------------------------------------------------------------------------------------
    //Если на текущем стержне переместить блинчик некуда, то переходим на следующий стержень                                                                                  |
    //Перемещать можно лишь верхний блинчик       (вроде учтено в алгоритме)                                                                                                  |
    //Если текущий стержень является пустым, то немедленно скинуть на него блинчик с нулевого стержня, если блинчик с нулевого стержня не был на пустом стержне в прошлый раз |
    //Когда мы переместили пятый блинчик из нулевого стержня поставить флаг об этом случае), то верхнее правло меняется на                                                    |
    // "Если есть пустой стержень, то туда передается блинчик из третьего стержня, если этот блинчик с третьего стержня не был на пустом стержне в прошлый раз                |
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    return 0;
}