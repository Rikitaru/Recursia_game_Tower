#include <iostream> //Created by Glagolev & Korobkov
#include <iomanip>
#define A if ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == nextNumber) && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel))){continue;}
#define B if ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == tempnextNumber) && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel))){ break;}

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
        CurentlyIndex = -1;
    }
    void start_position() { //функция заполнения стержня блинчиками
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


int sbros(karnel* Tower){
    int temp = Game(Tower);//вернется индекс пустой башни
    if (temp==1 || temp==2){
        //необходимо выполнить "падение блинчика с нулевой башни на пустую башню
        Tower[temp].CurentlyIndex++; //повышаем индекс пустой башни
        //в пустую башню перемещаем блинчик с нулевой башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
        Tower[temp].PanckakeArrray[Tower[temp].CurentlyIndex].PancakeNumber = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;
        Tower[temp].PanckakeArrray[Tower[temp].CurentlyIndex].PreviousPosition = 0; //указываем, откуда переместили блинчик


        //у нулевой башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
        Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = NULL;
        Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = -1;
        Tower[0].CurentlyIndex--;

        //записываем, какой блинчик и откуда переместили (блинчик уже на новой башне) (чтобы избежать пустых перемещений в будущем)

        Tower[0].show_karnel(0);
        Tower[1].show_karnel(1);
        Tower[2].show_karnel(2);
        cout << "==========================================================================================="<<endl;
        return Tower[temp].PanckakeArrray[Tower[temp].CurentlyIndex].PancakeNumber;
    }
    return -1;
}

int main() {
    system("chcp 65001");
    karnel Tower[3]; //создание трех путсых башен
    Tower[0].start_position(); //даем нулевой башне блинчики
    Tower[0].show_karnel(0);
    Tower[1].show_karnel(1);
    Tower[2].show_karnel(2);
    cout << "==========================================================================================="<<endl;

    //------Эти данные обновляются после каждого перемещения--------------------------------------------------------
    int temp_previous_number_pancake = -1;//запоминаем предыдущий переместившийся блинчик, его номер (уникальный)  |
    int temp_previous_number_karnel = -1;//запоминаем откуда его переместили, с какого стержня                     |
    //--------------------------------------------------------------------------------------------------------------

    /*-------------------------------------------------------------------------------------------------*/
    bool Flag = false;// Флаг, который показывает, что нулевой стержень пуст. Ввод нового правила       /
    /*-------------------------------------------------------------------------------------------------*/
    bool Flag2 = false; // Флаг, который показывает, что в данныц момент второй стержень пуст

    int number = -1;// индекс текущего стержня, может меняться на 0,1,2
    //Цикл позволяет просмотреть ровно две следующие башни для "перемещения блинчика" с текущего стержня
    //Пробуем переместить текущий блинчик с текущего стержня на следующие стержни
   
    while(true){//Tower[0].CurentlyIndex!=0 && Tower[1].CurentlyIndex!=0){ //условие проверить потом
        cout << "==========================================================================================="<<endl;
        number = (++number)%3;
        int nextNumber = (number + 1) % 3; //индекс следующего стержня
        //******************************************************************************************************************************************************************

        //Проверка на пустоту нулевой башни
        if (Game_only_one(Tower) == 0) {//если вернет индекс нулевой башни, то башня была разобрана и теперь надо ее собрать на другом стержне
            Flag = true; //переход на второй этап
            break;
        }

        if (Flag == false){//если у нас первая башня не пустая, то выполняются следующие правила:
            /*Постоянная проверка на сброс*/

            if (!((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == nextNumber) && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel)))){
                while( Game(Tower) != -1){
                    temp_previous_number_karnel=0;
                    temp_previous_number_pancake = sbros(Tower);
                }
            }
            /*Обычное смещение блинчика со стержня*/
            while (Tower[number].CurentlyIndex>-1){
                int f = 0;
                for (int i = 0; i < 2; i++) {
                    int tempnextNumber = (nextNumber + i)%3;
                    //Если текущий блинчик был на предыдущей позиции в следующем стержне, то туда перемещать его бессмысленно, избегаем пустых перемещений, поэтому переходим на след. итерацию
                    if ((Tower[tempnextNumber].PanckakeArrray[Tower[tempnextNumber].CurentlyIndex].PancakeNumber > Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber)
                    && !((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == tempnextNumber) && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel)))){
                        Tower[tempnextNumber].CurentlyIndex++; //повышаем индекс следующей башни
                        //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                        Tower[tempnextNumber].PanckakeArrray[Tower[tempnextNumber].CurentlyIndex].PancakeNumber = Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber;
                        Tower[tempnextNumber].PanckakeArrray[Tower[tempnextNumber].CurentlyIndex].PreviousPosition = number;
                        Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition = number; //указываем, откуда переместили блинчик

                        //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                        Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber = NULL;
                        Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition = -1;
                        Tower[number].CurentlyIndex--;

                        //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                        temp_previous_number_pancake = Tower[tempnextNumber].PanckakeArrray[Tower[tempnextNumber].CurentlyIndex].PancakeNumber;
                        temp_previous_number_karnel = number;
                        Tower[0].show_karnel(0);
                        Tower[1].show_karnel(1);
                        Tower[2].show_karnel(2);
                        cout << "==========================================================================================="<<endl;
                        /*Постоянная проверка на сброс*/
                        /*пофиксить условие, чтобы не давал сбрасывать блинчики которые только что положили на первую башню*/if (!((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == nextNumber) && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel)))){
                            if (Game(Tower) != -1){
                                temp_previous_number_karnel=0;
                                temp_previous_number_pancake = sbros(Tower);
                            }
                        }
                        break;
                    }
                    else if (i==1){
                        f=1;
                        break;//выход из for
                    }
                }
                if (f==1){
                    break;//выход из while
                }
            }
        }
        else{ //второй этап
            int temp;
            temp = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;//Если 2 второй стержень пуст, то запоминаем первый (текущий) бличик на первом стержне

            if (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp) {//Проверяем, нходимся ли мы на блинчике, который пометили
                if (number == 0) {
                    Tower[number + 2].PanckakeArrray[Tower[number + 2].CurentlyIndex].PancakeNumber = temp;//Перемещаем ппомеченный блинчик на number + 1
                }
                else {
                    Tower[number - 1].PanckakeArrray[Tower[number - 1].CurentlyIndex].PancakeNumber = temp;//Перемещаем помеченный блинчик на number + 1
                }
            }
            //Перемещать блинчик с нынешней башни можно только на блин большего значения следующего стержня
            if ((Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber > Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber) || (Tower[number].CurentlyIndex <= 0)) {
                Tower[nextNumber].CurentlyIndex++; //повышаем индекс следующей башни
                //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber = Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber;
                Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition = 0; //указываем, откуда переместили блинчик

                //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber = NULL;
                Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition = -1;
                Tower[number].CurentlyIndex--;

                //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                temp_previous_number_pancake = Tower[nextNumber].PanckakeArrray[Tower[nextNumber].CurentlyIndex].PancakeNumber;
                temp_previous_number_karnel = number;
                Tower[0].show_karnel(0);
                Tower[1].show_karnel(1);
                Tower[2].show_karnel(2);
            }
        }
    }




    Tower[0].show_karnel(0);
    Tower[1].show_karnel(1);
    Tower[2].show_karnel(2);


    //------Правила которые надо внедрить!-------------------------------------------------------------------------------------------------------------------------------------
    //Если на текущем стержне переместить блинчик некуда, то переходим на следующий стержень                                                                                  |
    //Перемещать можно лишь верхний блинчик       (вроде учтено в алгоритме)                                                                                                  |
    //Если текущий стержень является пустым, то немедленно скинуть на него блинчик с нулевого стержня, если блинчик с нулевого стержня не был на пустом стержне в прошлый раз |
    //Когда мы переместили пятый блинчик из нулевого стержня поставить флаг об этом случае), то верхнее правло меняется на                                                    |
    // "Если есть пустой стержень, то туда передается блинчик из третьего стержня, если этот блинчик с третьего стержня не был на пустом стержне в прошлый раз                |
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    return 0;
}