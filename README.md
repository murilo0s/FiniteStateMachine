# Vending Machine (Máquina de Refrigerantes)

Projeto simples em **C++** que simula uma máquina de venda de refrigerantes usando uma **Máquina de Estados Finitos (FSM - Finite State Machine)**.  

O usuário (estudante) pode:
- Selecionar uma bebida
- Escolher a quantidade
- Realizar pagamento com pontos virtuais
- Atualizar saldo e estoque automaticamente

---

## Funcionalidades
- Mostrar bebidas disponíveis com estoque e preço
- Seleção de opção (Coca, Pepsi, Guaraná)
- Verificação de estoque e quantidade
- Cálculo do custo total
- Pagamento com pontos (com troco e validação de saldo)
- Atualização do estoque e pontos do usuário
- Loop contínuo até o usuário encerrar o programa manualmente

---

## Estrutura de Pastas

```
FiniteStateMachine/
│
├── include/ # Headers (.hpp)
│ ├── Soda.hpp
│ ├── Student.hpp
│ └── States.hpp
│
├── src/ # Fontes (.cpp)
│ ├── main.cpp
│ └── Soda.cpp
│
├── build/ # Saída da compilação (.o e binário)
│
├── Makefile # Script de compilação
└── README.md # Este arquivo
```

---

## Como compilar e executar

Para compilar e rodar o projeto, utilize o Makefile:

```bash
make
./main
```

Para remover os arquivos de compilação:

```bash
make clean
```

---
