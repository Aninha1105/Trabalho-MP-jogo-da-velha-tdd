/**
 * \file  velha.cpp
 */

#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 


// Verifica se o 'jogador' venceu em alguma linha do tabuleiro.
// Retorna true se venceu, caso contrário, retorna false.
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

// Verifica se o 'jogador' venceu em alguma coluna do tabuleiro.
// Retorna true se venceu, caso contrário, retorna false.
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

// Verifica se o 'jogador' venceu em alguma diagonal do tabuleiro.
// Retorna true se venceu, caso contrário, retorna false.
bool verificaDiagonal(int velha[3][3], int jogador) {
  if (velha[0][0] == jogador &&
      velha[1][1] == jogador &&
      velha[2][2] == jogador) {  // Verifica a diagonal principal
    return true;
  } else if (velha[0][2] == jogador &&
             velha[1][1] == jogador &&
             velha[2][0] == jogador) {  // Verifica a diagonal secundária
    return true;
  }

  return false;
}

// Verifica se o jogador 'X' (representado por '1') venceu o jogo.
// Chama as funções de linha, coluna e diagonal para verificar a vitória.
// Retorna true se o jogador 'X' venceu, caso contrário, retorna false.
bool vencedorX(int velha[3][3]) {
  if (verificaLinha(velha, 1) ||
      verificaColuna(velha, 1) ||
      verificaDiagonal(velha, 1)) {
    return true;
  } else {
    return false;
  }
}

bool vencedorO(int velha[3][3]) {
  if (verificaLinha(velha, 2) ||
      verificaColuna(velha, 2) ||
      verificaDiagonal(velha, 2)) {
    return true;
  } else {
    return false;
  }
}

int VerificaVelha(int velha[3][3]) {
  // Verifica se 'X' (representado por '1') venceu o jogo
  if (vencedorX(velha)) {
    return 1;
  }

  if (vencedorO(velha)) {
    return 2;
  }

  return -200;
}
