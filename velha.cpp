/**
 * \file velha.cpp
 * \brief Implementação das funções para verificar o estado do jogo da velha.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */

#include "velha.hpp"
#include <stdlib.h>

/**
 * \brief Verifica se um jogador venceu em alguma linha do tabuleiro.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \param jogador Número inteiro representando o jogador ('1' para 'X', '2' para 'O').
 * \return true se o jogador venceu em alguma linha, false caso contrário.
 * \details Critério: todas as três posições de uma mesma linha devem estar preenchidas pelo mesmo jogador.
 */
bool verificaLinha(int velha[3][3], int jogador) {
  for (int linhaIndex = 0 ; linhaIndex < 3 ; linhaIndex++) {
    if (velha[linhaIndex][0] == jogador &&
        velha[linhaIndex][1] == jogador &&
        velha[linhaIndex][2] == jogador) {
      return true;
    }
  }
  return false;
}

/**
 * \brief Verifica se um jogador venceu em alguma coluna do tabuleiro.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \param jogador Número inteiro representando o jogador ('1' para 'X', '2' para 'O').
 * \return true se o jogador venceu em alguma coluna, false caso contrário.
 * \details Critério: todas as três posições de uma mesma coluna devem estar preenchidas pelo mesmo jogador.
 */
bool verificaColuna(int velha[3][3], int jogador) {
  for (int colunaIndex = 0 ; colunaIndex < 3 ; colunaIndex++) {
    if (velha[0][colunaIndex] == jogador &&
        velha[1][colunaIndex] == jogador &&
        velha[2][colunaIndex] == jogador) {
      return true;
    }
  }
  return false;
}

/**
 * \brief Verifica se um jogador venceu em alguma diagonal do tabuleiro.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \param jogador Número inteiro representando o jogador ('1' para 'X', '2' para 'O').
 * \return true se o jogador venceu em uma diagonal, false caso contrário.
 * \details Critérios:
 * - Diagonal principal: todas as posições [0][0], [1][1], [2][2] devem estar preenchidas pelo mesmo jogador.
 * - Diagonal secundária: todas as posições [0][2], [1][1], [2][0] devem estar preenchidas pelo mesmo jogador.
 */
bool verificaDiagonal(int velha[3][3], int jogador) {
  if (velha[0][0] == jogador &&
      velha[1][1] == jogador &&
      velha[2][2] == jogador) {
    return true;
  } else if (velha[0][2] == jogador &&
             velha[1][1] == jogador &&
             velha[2][0] == jogador) {
    return true;
  }

  return false;
}

/**
 * \brief Conta as ocorrências de posições vazias, 'X' e 'O' no tabuleiro.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \return Ponteiro para um array contendo as contagens de '0' (vazio), '1' ('X') e '2' ('O').
 */
int* estadoTabuleiro(int velha[3][3]) {
  static int contador[3];
  contador[0] = 0;
  contador[1] = 0;
  contador[2] = 0;

  for (int linhaIndex = 0 ; linhaIndex < 3 ; linhaIndex++) {
    for (int colunaIndex = 0; colunaIndex < 3 ; colunaIndex++) {
      if (velha[linhaIndex][colunaIndex] == 0) {
        contador[0]++;
      } else if (velha[linhaIndex][colunaIndex] == 1) {
        contador[1]++;
      } else if (velha[linhaIndex][colunaIndex] == 2) {
        contador[2]++;
      }
    }
  }

  return contador;
}

/**
 * \brief Verifica se o jogador 'X' venceu o jogo.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \return true se o jogador 'X' venceu, false caso contrário.
 */
bool vencedorX(int velha[3][3]) {
  if (verificaLinha(velha, 1) ||
      verificaColuna(velha, 1) ||
      verificaDiagonal(velha, 1)) {
    return true;
  } else {
    return false;
  }
}

/**
 * \brief Verifica se o jogador 'O' venceu o jogo.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \return true se o jogador 'O' venceu, false caso contrário.
 */
bool vencedorO(int velha[3][3]) {
  if (verificaLinha(velha, 2) ||
      verificaColuna(velha, 2) ||
      verificaDiagonal(velha, 2)) {
    return true;
  } else {
    return false;
  }
}

/**
 * \brief Verifica se o jogo está empatado.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \param contadorVazio Número de posições vazias no tabuleiro.
 * \return true se o jogo estiver empatado, false caso contrário.
 * \details Critérios:
 * - Nenhum jogador venceu.
 * - Não há posições vazias restantes no tabuleiro.
 */
bool empatado(int velha[3][3], int contadorVazio) {
  if (contadorVazio == 0 && !vencedorX(velha) && !vencedorO(velha)) {
    return true;
  } else {
    return false;
  }
}

/**
 * \brief Verifica se o jogo está indefinido.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \param contadorVazio Número de posições vazias no tabuleiro.
 * \return true se o jogo estiver indefinido, false caso contrário.
 * \details Critérios:
 * - Nenhum jogador venceu.
 * - Há pelo menos uma posição vazia no tabuleiro.
 */
bool indefinido(int velha[3][3], int contadorVazio) {
  if (contadorVazio > 0 && !vencedorX(velha) && !vencedorO(velha)) {
    return true;
  } else {
    return false;
  }
}

/**
 * \brief Verifica se o jogo é impossível de acordo com as regras.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \param contadorX Número de posições ocupadas pelo jogador 'X'.
 * \param contadorO Número de posições ocupadas pelo jogador 'O'.
 * \return true se o jogo for impossível, false caso contrário.
 * \details Critérios:
 * - Diferença entre o número de 'X' e 'O' é maior que 1.
 * - Ambos os jogadores 'X' e 'O' venceram.
 */
bool impossivel(int velha[3][3], int contadorX, int contadorO) {
  if (abs(contadorX - contadorO) > 1 ||
      (vencedorX(velha) && vencedorO(velha))) {
    return true;
  } else {
    return false;
  }
}

/**
 * \brief Verifica o estado atual do jogo da velha.
 * \param velha Matriz 3x3 representando o estado do tabuleiro.
 * \return Código indicando o estado do jogo: -2 (impossível), -1 (indefinido),
 * 0 (empate), 1 ('X' venceu), 2 ('O' venceu).
 */
int VerificaVelha(int velha[3][3]) {
  int* contador = estadoTabuleiro(velha);

  if (impossivel(velha, contador[1], contador[2])) {
    return -2;
  }

  if (indefinido(velha, contador[0])) {
    return -1;
  }

  if (empatado(velha, contador[0])) {
    return 0;
  }

  if (vencedorX(velha)) {
    return 1;
  }

  if (vencedorO(velha)) {
    return 2;
  }

  return -200;
}
