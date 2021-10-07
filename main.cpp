#include <iostream>
#include <iomanip>
using namespace std;
struct pancake {
    int PancakeNumber; //номер(вес) блинчика
    int PreviousPosition; //предыдущее положение блинчика
    void show_pancake(int index) {
        cout << "\t[" << index << "]==  ";
        if (PancakeNumber > 0) {
            cout << "  " << PancakeNumber << " ";
        }
        else {
            cout << "None";
        }
        cout << " <---- " << setw(2) << PreviousPosition << endl;
    }
};

struct karnel {
    pancake PanckakeArrray[5]; //Стержень
    int NumberOfElement; //Колво
    int CurentlyIndex; //Текущее положение
    void show_karnel(int index_karnel) {
        cout << "Стержень № " << index_karnel + 1 << " " << "Текущее положение (ИНДЕКС верхнего блинчика) .. " << CurentlyIndex << endl;
        this->PanckakeArrray[4].show_pancake(4);
        this->PanckakeArrray[3].show_pancake(3);
        this->PanckakeArrray[2].show_pancake(2);
        this->PanckakeArrray[1].show_pancake(1);
        this->PanckakeArrray[0].show_pancake(0);
    }
    karnel() { //конструктор пустого стержня
        PanckakeArrray[0].PancakeNumber = -1;
        PanckakeArrray[0].PreviousPosition = -1;
        PanckakeArrray[1].PancakeNumber = -1;
        PanckakeArrray[1].PreviousPosition = -1;
        PanckakeArrray[2].PancakeNumber = -1;
        PanckakeArrray[2].PreviousPosition = -1;
        PanckakeArrray[3].PancakeNumber = -1;
        PanckakeArrray[3].PreviousPosition = -1;
        PanckakeArrray[4].PancakeNumber = -1;
        PanckakeArrray[4].PreviousPosition = -1;
        CurentlyIndex = 0;
    }
    void start_position() { //функция заполнения стержня блинчикамиФАЫВАПВАРВАПЫАП
        PanckakeArrray[0].PancakeNumber = 5;
        PanckakeArrray[0].PreviousPosition = 0;
        PanckakeArrray[1].PancakeNumber = 4;
        PanckakeArrray[1].PreviousPosition = 0;
        PanckakeArrray[2].PancakeNumber = 3;
        PanckakeArrray[2].PreviousPosition = 0;
        PanckakeArrray[3].PancakeNumber = 2;
        PanckakeArrray[3].PreviousPosition = 0;
        PanckakeArrray[4].PancakeNumber = 1;
        PanckakeArrray[4].PreviousPosition = 0;
        CurentlyIndex = 4;
    }
};

int Game(karnel* Tower) {
    for (int i = 0; i < 3; i++) {
        if (Tower[i].CurentlyIndex < 0) {
            return i;
        }
    }
    return -1;
}
int Game_only_one(karnel* Tower) {
    if (Tower[0].CurentlyIndex < 0) {
        return 0;
    }
    return -1;
}
int Game_only_two(karnel* Tower) {
    if (Tower[1].CurentlyIndex < 0) {
        return 0;
    }
    return -1;
}

int main() {
    system("chcp 65001");
    karnel Tower[3]; //создание трех путсых башен
    karnel* prt = &Tower[0]; //указатель на нулевую башню
    /*int index = proverka(prt); //
    (index != -1 ? cout << " Пустой стержень найден, он под индексом " << index : cout << " Пустой стержень не найден ")
    << endl;*/
    Tower[0].start_position(); //даем нулевой башне блинчики
    Tower[0].show_karnel(0);
    Tower[1].show_karnel(1);
    Tower[2].show_karnel(2);





    //------Эти данные обновляются после каждого перемещения--------------------------------------------------------
    int temp_previous_number_pancake = -1;//запоминаем предыдущий переместившийся блинчик, его номер (уникальный)  |
    int temp_previous_number_karnel = -1;//запоминаем откуда его переместили, с какого стержня                     |
    //--------------------------------------------------------------------------------------------------------------

    /*-------------------------------------------------------------------------------------------------*/
    bool Flag = false;// Флаг, который показывает, что нулевой стержень пуст. Ввод нового правила       /
    /*-------------------------------------------------------------------------------------------------*/
    bool Flag2 = false;

    int number = 0;// индекс текущего стержня, может меняться на 0,1,2
    //Цикл позволяет просмотреть ровно две следующие башни для "перемещения блинчика" с текущего стержня
    //Пробуем переместить текущий блинчик с текущего стержня на следующие стержни
    for (int i = 0; i < 3; i++) {
        int nextNumber = (number + i + 1) % 3; //индекс следующего стержня

        //Если текущий блинчик был на предыдущей позиции в следующем стержне, то туда перемещать его бессмысленно, избегаем пустых перемещений, поэтому переходим на след. итерацию
        if ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == nextNumber) /*Если текущий блинчик был раньше на позиции следующего стержня*/
            && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) /*Если текущий блинчик был перемещен в прошлую итерацию*/
                && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel))) /*Если текущий блинчик был перемещен в прошлую итерацию на следующий стержень*/
        {
            continue; //переход на след. итерацию
        }
        if (Flag == 0) {//если у нас первая башня не пустая, то выполняются следующие правила:
            //Перемещать блинчик с нынешней башни можно только на блин большего значения следующего стержня
            if (Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber > Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber) {
                //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber = Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber;
                Tower[nextNumber].CurentlyIndex++; //повышаем индекс следующей башни
                Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PreviousPosition = number; //указываем, откуда переместили блинчик

                //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition = -1;
                Tower[number].CurentlyIndex--;

                //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                temp_previous_number_pancake = Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber;
                temp_previous_number_karnel = number;
            }
        }
        //если у нас первая башня оказалась пустой, теперь надо башню собрать вновь на другом стержне, то выполняются следующие правила:
        else if ((Tower[nextNumber].CurentlyIndex < 0) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition != nextNumber))
        {

            if (Game_only_two(Tower) == 0) {
                Flag2 = true;
            }

            if (Flag2 == true) {
                int temp;
                temp = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;

                if (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp) {
                    if (number == 0) {
                        Tower[number + 2].PanckakeArrray[Tower[number + 2].CurentlyIndex].PancakeNumber = temp;
                    }
                    else {
                        Tower[number - 1].PanckakeArrray[Tower[number - 1].CurentlyIndex].PancakeNumber = temp;

                    }
                }
                //Перемещать блинчик с нынешней башни можно только на блин большего значения следующего стержня
                if ((Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber > Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber) or (Tower[i].CurentlyIndex <= 0)) {
                    //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                    Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber = Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber;
                    Tower[nextNumber].CurentlyIndex++; //повышаем индекс следующей башни
                    Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PreviousPosition = number; //указываем, откуда переместили блинчик

                    //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                    Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition = -1;
                    Tower[number].CurentlyIndex--;

                    //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                    temp_previous_number_pancake = Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber;
                    temp_previous_number_karnel = number;
                }
            }
            //Перемещать блинчик с нынешней башни можно только на блин большего значения следующего стержня
            if ((Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber > Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber) or (Tower[i].CurentlyIndex <= 0)) {
                //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber = Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber;
                Tower[nextNumber].CurentlyIndex++; //повышаем индекс следующей башни
                Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PreviousPosition = number; //указываем, откуда переместили блинчик

                //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition = -1;
                Tower[number].CurentlyIndex--;

                //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                temp_previous_number_pancake = Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber;
                temp_previous_number_karnel = number;
            }
            ///////////************************//////////////
        }
        //после перемещения блинчика надо осуществить проверку на "пустой ли нулевой стержень", надо ли переходить на режим "сборки башни"
        if (Game_only_one(Tower) == 0) {//если вернет индекс нулевой башни, то башня была разобрана и теперь надо ее собрать на другом стержне
            Flag = true;
        }
        //после перемещения блинчика надо осуществить проверку на пустой стержень
        int temp = Game(Tower);//вернется индекс пустой башни
        if (temp != -1) {//если индекс от 0 до 2, то
            //необходимо выполнить "падение блинчика с нулевой башни на пустую башню
            if (Flag == 0) {
                //в пустую башню перемещаем блинчик с нулевой башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                Tower[temp].PanckakeArrray[Tower[temp].CurentlyIndex].PancakeNumber = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;
                Tower[temp].CurentlyIndex++; //повышаем индекс пустой башни
                Tower[temp].PanckakeArrray[Tower[temp].CurentlyIndex].PreviousPosition = 0; //указываем, откуда переместили блинчик

                //у нулевой башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = -1;
                Tower[0].CurentlyIndex--;

                //записываем, какой блинчик и откуда переместили (блинчик уже на новой башне) (чтобы избежать пустых перемещений в будущем)
                temp_previous_number_pancake = Tower[temp].PanckakeArrray[Tower[temp].CurentlyIndex].PancakeNumber;
                temp_previous_number_karnel = 0;
            }
            //необходимо выполнить "падение блинчика с нулевой башни на пустую башню
            else {
                //если у нас Flag == 1, то значит мы собираем башню вновь, то есть нулевая башня уже однажды была очищена,
                //теперь предстоит построить ее на другом стержне
                //как именно необходимо поменять правило для этого случая?
                //для ответа на этот вопрос - загляни в visio схемы наши, и найди, где перемещается с нулевого стержня пятый (Самый большой) блинчик
                //далее анализ того, как у нас заполняются пустые стержни (откуда берется блинчик)
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