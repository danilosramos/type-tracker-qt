# Type Tracker (Testador de Velocidade de Digitação)

Este projeto é uma aplicação de desktop desenvolvida em **C++ com o framework Qt** que funciona como um testador de velocidade de digitação (similar ao TypeRacer ou 10fastfingers).

Este projeto é um excelente exemplo de uma aplicação completa, com interface gráfica e lógica de negócios.

## Funcionalidades

*   **Interface Gráfica (GUI):** Desenvolvida usando o Qt Designer, proporcionando uma experiência de usuário intuitiva.
*   **Contagem de Palavras Por Minuto (WPM):** Calcula a velocidade de digitação em tempo real.
*   **Precisão:** Monitora e exibe a porcentagem de acertos e erros.
*   **Controle de Tempo:** Gerenciamento do tempo de teste.
*   **Lógica de Jogo:** Implementação da lógica para comparar a entrada do usuário com o texto de referência.

## Conceitos Demonstrados

*   **Desenvolvimento de Aplicações Desktop:** Uso do framework **Qt** para criar uma aplicação multiplataforma.
*   **Programação Orientada a Objetos (POO):** Estrutura de classes para a janela principal (`TypeTracker`), lógica do jogo e gerenciamento da interface.
*   **Manipulação de Eventos:** Tratamento de eventos de teclado para capturar a digitação do usuário.
*   **Gerenciamento de Interface:** Uso de *widgets* e *layouts* do Qt para construir a GUI.
*   **C++ Moderno:** Utilização de recursos e bibliotecas do C++.

## Estrutura do Projeto

O projeto segue a estrutura padrão de um projeto Qt:

*   `TypeTracker.pro`: Arquivo de projeto do Qt.
*   `typetracker.ui`: Arquivo XML que descreve a interface gráfica (gerado pelo Qt Designer).
*   `typetracker.h` / `typetracker.cpp`: Implementação da classe principal da aplicação.
*   `main.cpp`: Ponto de entrada da aplicação.

## Como Compilar e Executar

Este projeto requer o **Qt Framework** e o **Qt Creator** para ser compilado e executado facilmente.

1.  Abra o arquivo `TypeTracker.pro` no Qt Creator.
2.  Configure o kit de compilação (Debug/Release).
3.  Execute a compilação (Build).
4.  Execute o aplicativo.

---
**Linguagem:** C++ (Qt Framework)
**Tópicos:** Desenvolvimento Desktop, GUI (Qt), POO, Manipulação de Eventos.
'''
