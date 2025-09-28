#include <iostream>
#include "states.hpp"
#include "soda.hpp"
#include "student.hpp"

using namespace std;

int main()
{
    VendingMachineState currentState = SELECIONA;

    Soda vendingMachine[3];

    vendingMachine[0].brandName = COCA;
    vendingMachine[0].inventory = 10;
    vendingMachine[0].price = 1000;

    vendingMachine[1].brandName = PEPSI;
    vendingMachine[1].inventory = 10;
    vendingMachine[1].price = 2000;

    vendingMachine[2].brandName = GUARANA;
    vendingMachine[2].inventory = 10;
    vendingMachine[2].price = 3000;

    Soda selectedSoda;
    Student murilo;
    murilo.name = "Murilo";
    murilo.points = 100000;

    int selectedIndex = -1;
    int quantity = 0;
    int option;
    int totalCost = 0;
    int pagamento = 0;

    while (true)
    {
        switch (currentState)
        {
        case SELECIONA:
            cout << "<<<<<---STATUS ATUAL--->>>>>" << endl;
            cout << "[[[Máquina de Refrigerantes]]]" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << "Temos " << vendingMachine[i].inventory << " " 
                     << brandToString(vendingMachine[i].brandName)
                     << "(s) e custa " << vendingMachine[i].price << " pontos." << endl;
            }
            cout << "\n[[[Estudante]]]" << endl;
            cout << murilo.name << " - " << murilo.points << " pontos\n" << endl;
            cout << "==========================================" << endl;
            cout << endl;
            cout << "Por favor, selecione uma bebida dentre as opções disponíveis:" << endl;
            cout << "COCA = 100\nPEPSI = 200\nGUARANÁ = 300" << endl;
            cout << endl;
            while (true)
            {
                cin >> option;

                switch (option)
                {
                case 100:
                    selectedIndex = 0;
                    cout << "Você selecionou " << brandToString(vendingMachine[0].brandName) << endl;
                    currentState = QUANTIDADE;
                    break;

                case 200:
                    selectedIndex = 1;
                    cout << "Você selecionou " << brandToString(vendingMachine[1].brandName) << endl;
                    currentState = QUANTIDADE;
                    break;

                case 300:
                    selectedIndex = 2;
                    cout << "Você selecionou " << brandToString(vendingMachine[2].brandName) << endl;
                    currentState = QUANTIDADE;
                    break;

                default:
                    cout << "Opção inválida, tente novamente." << endl;
                    continue;
                }

                break;
            }
            break;
        case QUANTIDADE:
            cout << "Quantas unidades você deseja? " << endl;
            while (true)
            {
                cin >> quantity;
                if (quantity > 0 && quantity <= vendingMachine[selectedIndex].inventory)
                {
                    break;
                }
                else if (quantity > vendingMachine[selectedIndex].inventory)
                {
                    cout << "Estoque insuficiente. Tente novamente." << endl;
                    currentState = SELECIONA;
                    break;
                }

                else
                {
                    cout << "Quantidade inválida. Tente novamente." << endl;
                    continue;
                }
            }
            currentState = CALCULA;
            break;
        case CALCULA:
            totalCost = vendingMachine[selectedIndex].price * quantity;
            selectedSoda = vendingMachine[selectedIndex];
            cout << "Total a pagar: " << totalCost << " pontos." << endl;
            cout << "Por favor, digite o valor do seu pagamento em pontos: " << endl;
            cin >> pagamento;
            if (pagamento < totalCost)
            {
                cout << "Pagamento insuficiente. Transação cancelada.\n" << endl;
                currentState = SELECIONA;
                break;
            }
            else if (pagamento >= totalCost)
            {
                if (pagamento > murilo.points)
                {
                    cout << "Você não tem pontos suficientes. Transação cancelada.\n" << endl;
                    currentState = SELECIONA;
                    break;
                }
                murilo.points -= totalCost;
                vendingMachine[selectedIndex].inventory -= quantity;
                int troco = pagamento - totalCost;
                cout << "Compra realizada com sucesso! Seu troco é: " << troco << " pontos." << endl;
            }
            currentState = ATUALIZA;

            break;
        case ATUALIZA:
            cout << "Atualizando estoque e pontos do usuário..." << endl;
            cout << "Estoque restante de " << brandToString(vendingMachine[selectedIndex].brandName)
                 << ": " << vendingMachine[selectedIndex].inventory << endl;
            cout << murilo.name << " agora tem " << murilo.points << " pontos.\n" << endl;
            currentState = SELECIONA;
            break;
        default:
            cout << "Erro! Estado inválido." << endl;
            return 1;
        }
    }

    return 0;
}
