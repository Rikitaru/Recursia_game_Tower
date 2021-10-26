#include <iostream> //Created by Glagolev & Korobkov
#include <iomanip>
//#define A if ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == nextNumber) && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel))){continue;}
//#define B if ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == tempnextNumber) && ((Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PancakeNumber == temp_previous_number_pancake) && (Tower[number].PanckakeArrray[Tower[number].CurentlyIndex].PreviousPosition == temp_previous_number_karnel))){ break;}

#define n  6
int count123 = 0;
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
    pancake PanckakeArrray[n]; //Стержень
    int NumberOfElement; //Колво
    int CurentlyIndex; //Текущее положение
    void show_karnel(int index_karnel) {
        cout << "Стержень № " << index_karnel + 1 << " " << "Текущее положение (ИНДЕКС верхнего блинчика) .. " << CurentlyIndex << endl;
        for (int i = n-1; i>=0; i--)
        {
            this->PanckakeArrray[i].show_pancake(i);
        }
    }

    karnel() { //конструктор пустого стержня
        for (int i = 0; i < n; i++)
        {
            PanckakeArrray[i].PancakeNumber = -1;
            PanckakeArrray[i].PreviousPosition = -1;
        }
        CurentlyIndex = -1;
    }
    void start_position() { //функция заполнения стержня блинчиками
        for (int i = 0; i <=n; i++)
        {
            PanckakeArrray[i].PancakeNumber = n-i;
            PanckakeArrray[i].PreviousPosition = 0;
        }
        CurentlyIndex = n-1;
    }
};

int main() {
    system("chcp 65001");
    karnel Tower[3]; //создание трех путсых башен
    Tower[0].start_position(); //даем нулевой башне блинчики
    Tower[0].show_karnel(0);
    Tower[1].show_karnel(1);
    Tower[2].show_karnel(2);
    cout << "===========================================================================================" << endl;

    //------Эти данные обновляются после каждого перемещения--------------------------------------------------------
    int temp_previous_number_pancake = -1;//запоминаем предыдущий переместившийся блинчик, его номер (уникальный)  |
    int temp_previous_number_karnel = -1;//запоминаем откуда его переместили, с какого стержня                     |
    //--------------------------------------------------------------------------------------------------------------

    int number = -1;// индекс текущего стержня, может меняться на 0,1,2
    //Цикл позволяет просмотреть ровно две следующие башни для "перемещения блинчика" с текущего стержня
    //Пробуем переместить текущий блинчик с текущего стержня на следующие стержни
    if (n % 2 == 1) {
        while ((Tower[2].PanckakeArrray[n - 1].PancakeNumber != 1)) {//Проверка на то, собрали ли мы 3 башнюЫ                                         //Tower[0].CurentlyIndex!=0 && Tower[1].CurentlyIndex!=0){ //условие проверить потом

            cout << "=========================================" << ++count123 << "==================================================" << endl;
            //Если текущий блинчик был на предыдущей позиции в следующем стержне, то туда перемещать его бессмысленно, избегаем пустых перемещений, поэтому переходим на след. итерацию
            if (((Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber < Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber) && (Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber > 0)) || (Tower[2].CurentlyIndex < 0)) {
                if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                    return 0;
                }
                Tower[2].CurentlyIndex++; //повышаем индекс следующей башни
                //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;
                Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 0;
                Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 0; //указываем, откуда переместили блинчик

                //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = NULL;
                Tower[0].CurentlyIndex--;

                //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
                temp_previous_number_karnel = 0;
                cout << "===========================================================================================" << endl;
                Tower[0].show_karnel(0);
                Tower[1].show_karnel(1);
                Tower[2].show_karnel(2);
                cout << "===========================================================================================" << endl;
            }
            else {
                if ((Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber < Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber) || (Tower[0].CurentlyIndex < 0)) {
                    if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                        return 0;
                    }
                    Tower[0].CurentlyIndex++; //повышаем индекс следующей башни
                   //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                    Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
                    Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 2;
                    Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 2; //указываем, откуда переместили блинчик

                    //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                    Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = NULL;
                    Tower[2].CurentlyIndex--;

                    //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                    temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
                    temp_previous_number_karnel = 0;
                    cout << "===========================================================================================" << endl;
                    Tower[0].show_karnel(0);
                    Tower[1].show_karnel(1);
                    Tower[2].show_karnel(2);
                    cout << "===========================================================================================" << endl;
                }
            }

            if (((Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber < Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber) && (Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber > 0)) || (Tower[1].CurentlyIndex < 0)) {
                if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                    return 0;
                }
                Tower[1].CurentlyIndex++; //повышаем индекс следующей башни
                //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;
                Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 0;
                Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 0; //указываем, откуда переместили блинчик

                //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = NULL;
                Tower[0].CurentlyIndex--;

                //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                temp_previous_number_pancake = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
                temp_previous_number_karnel = 0;
                cout << "===========================================================================================" << endl;
                Tower[0].show_karnel(0);
                Tower[1].show_karnel(1);
                Tower[2].show_karnel(2);
                cout << "===========================================================================================" << endl;
            }
            else {
                if ((Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber < Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber) || (Tower[0].CurentlyIndex < 0)) {
                    if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                        return 0;
                    }
                    Tower[0].CurentlyIndex++; //повышаем индекс следующей башни
                   //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                    Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
                    Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 1;
                    Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 1; //указываем, откуда переместили блинчик

                    //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                    Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = NULL;
                    Tower[1].CurentlyIndex--;

                    //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                    temp_previous_number_pancake = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
                    temp_previous_number_karnel = 0;
                    cout << "===========================================================================================" << endl;
                    Tower[0].show_karnel(0);
                    Tower[1].show_karnel(1);
                    Tower[2].show_karnel(2);
                    cout << "===========================================================================================" << endl;
                }
            }

            if (((Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber < Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber) && (Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber > 0)) || (Tower[2].CurentlyIndex < 0)) {
                if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                    return 0;
                }
                Tower[2].CurentlyIndex++; //повышаем индекс следующей башни
                //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
                Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 1;
                Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 1; //указываем, откуда переместили блинчик

                //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = NULL;
                Tower[1].CurentlyIndex--;

                //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
                temp_previous_number_karnel = 1;
                cout << "===========================================================================================" << endl;
                Tower[0].show_karnel(0);
                Tower[1].show_karnel(1);
                Tower[2].show_karnel(2);
                cout << "===========================================================================================" << endl;
            }
            else {
                if ((Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber < Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber) || (Tower[1].CurentlyIndex < 0)) {
                    if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                        return 0;
                    }
                    Tower[1].CurentlyIndex++; //повышаем индекс следующей башни
                   //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
                    Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
                    Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 2;
                    Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 2; //указываем, откуда переместили блинчик

                    //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
                    Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = NULL;
                    Tower[2].CurentlyIndex--;

                    //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
                    temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
                    temp_previous_number_karnel = 1;
                    cout << "===========================================================================================" << endl;
                    Tower[0].show_karnel(0);
                    Tower[1].show_karnel(1);
                    Tower[2].show_karnel(2);
                    cout << "===========================================================================================" << endl;
                }
            }
        }
    }
 else {
 while ((Tower[2].PanckakeArrray[n - 1].PancakeNumber != 1)) {//Проверка на то, собрали ли мы 3 башнюЫ                                         //Tower[0].CurentlyIndex!=0 && Tower[1].CurentlyIndex!=0){ //условие проверить потом

     cout << "=========================================" << ++count123 << "==================================================" << endl;
     //Если текущий блинчик был на предыдущей позиции в следующем стержне, то туда перемещать его бессмысленно, избегаем пустых перемещений, поэтому переходим на след. итерацию
    
     
     if (((Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber < Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber) && (Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber > 0)) || (Tower[1].CurentlyIndex < 0)) {
         if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
             return 0;
         }
         Tower[1].CurentlyIndex++; //повышаем индекс следующей башни
         //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
         Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;
         Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 0;
         Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 0; //указываем, откуда переместили блинчик

         //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
         Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = NULL;
         Tower[0].CurentlyIndex--;

         //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
         temp_previous_number_pancake = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
         temp_previous_number_karnel = 0;
         cout << "===========================================================================================" << endl;
         Tower[0].show_karnel(0);
         Tower[1].show_karnel(1);
         Tower[2].show_karnel(2);
         cout << "===========================================================================================" << endl;
     }
     else {
         if ((Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber < Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber) || (Tower[0].CurentlyIndex < 0)) {
             if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                 return 0;
             }
             Tower[0].CurentlyIndex++; //повышаем индекс следующей башни
            //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
             Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
             Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 1;
             Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 1; //указываем, откуда переместили блинчик

             //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
             Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = NULL;
             Tower[1].CurentlyIndex--;

             //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
             temp_previous_number_pancake = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
             temp_previous_number_karnel = 0;
             cout << "===========================================================================================" << endl;
             Tower[0].show_karnel(0);
             Tower[1].show_karnel(1);
             Tower[2].show_karnel(2);
             cout << "===========================================================================================" << endl;
         }
     }
     
     
     if (((Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber < Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber) && (Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber > 0)) || (Tower[2].CurentlyIndex < 0)) {
         if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
             return 0;
         }
         Tower[2].CurentlyIndex++; //повышаем индекс следующей башни
         //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
         Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber;
         Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 0;
         Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 0; //указываем, откуда переместили блинчик

         //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
         Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = NULL;
         Tower[0].CurentlyIndex--;

         //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
         temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
         temp_previous_number_karnel = 0;
         cout << "===========================================================================================" << endl;
         Tower[0].show_karnel(0);
         Tower[1].show_karnel(1);
         Tower[2].show_karnel(2);
         cout << "===========================================================================================" << endl;
     }
     else {
         if ((Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber < Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber) || (Tower[0].CurentlyIndex < 0)) {
             if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                 return 0;
             }
             Tower[0].CurentlyIndex++; //повышаем индекс следующей башни
            //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
             Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PancakeNumber = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
             Tower[0].PanckakeArrray[Tower[0].CurentlyIndex].PreviousPosition = 2;
             Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 2; //указываем, откуда переместили блинчик

             //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
             Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = NULL;
             Tower[2].CurentlyIndex--;

             //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
             temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
             temp_previous_number_karnel = 0;
             cout << "===========================================================================================" << endl;
             Tower[0].show_karnel(0);
             Tower[1].show_karnel(1);
             Tower[2].show_karnel(2);
             cout << "===========================================================================================" << endl;
         }
     }




     if (((Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber < Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber) && (Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber > 0)) || (Tower[2].CurentlyIndex < 0)) {
         if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
             return 0;
         }
         Tower[2].CurentlyIndex++; //повышаем индекс следующей башни
         //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
         Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber;
         Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 1;
         Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 1; //указываем, откуда переместили блинчик

         //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
         Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = NULL;
         Tower[1].CurentlyIndex--;

         //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
         temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
         temp_previous_number_karnel = 1;
         cout << "===========================================================================================" << endl;
         Tower[0].show_karnel(0);
         Tower[1].show_karnel(1);
         Tower[2].show_karnel(2);
         cout << "===========================================================================================" << endl;
     }
     else {
         if ((Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber < Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber) || (Tower[1].CurentlyIndex < 0)) {
             if (Tower[2].PanckakeArrray[n - 1].PancakeNumber == 1) {//Проверка на то, собрали ли мы 3 башню
                 return 0;
             }
             Tower[1].CurentlyIndex++; //повышаем индекс следующей башни
            //в следующую башню перемещаем блинчик с нынешней башни, повышаем текущий индекс и добавляем информацию о предыдущей позиции перемещенного блинчика
             Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PancakeNumber = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
             Tower[1].PanckakeArrray[Tower[1].CurentlyIndex].PreviousPosition = 2;
             Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PreviousPosition = 2; //указываем, откуда переместили блинчик

             //у текущей башни очищаем текущий блинчик (так как его переместили) и уменьшаем индекс
             Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber = NULL;
             Tower[2].CurentlyIndex--;

             //записываем, какой блинчик и откуда переместили (блинчик уже на следующей башне) (чтобы избежать пустых перемещений в будущем)
             temp_previous_number_pancake = Tower[2].PanckakeArrray[Tower[2].CurentlyIndex].PancakeNumber;
             temp_previous_number_karnel = 1;
             cout << "===========================================================================================" << endl;
             Tower[0].show_karnel(0);
             Tower[1].show_karnel(1);
             Tower[2].show_karnel(2);
             cout << "===========================================================================================" << endl;
         }
     }
 }
    }
    Tower[0].show_karnel(0);
    Tower[1].show_karnel(1);
    Tower[2].show_karnel(2);
    return 0;
}