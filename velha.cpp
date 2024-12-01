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

bool linha(int velha[3][3], int j) {
  for (int l = 0 ; l < 3 ; l++) {
    if (velha[l][0] == j && velha[l][1] == j && velha[l][2] == j) {
      return true;
    }
  }
  return false;
}

bool coluna(int velha[3][3], int j) {
  for (int c = 0 ; c < 3 ; c++) {
    if (velha[0][c] == j && velha[1][c] == j && velha[2][c] == j) {
      return true;
    }
  }
  return false;
}

bool diagonal(int velha[3][3], int j) {
  if (velha[0][0] == j && velha[1][1] == j && velha[2][2] == j) {
    return true;
  } else if (velha[0][2] == j && velha[1][1] == j && velha[2][0] == j) {
    return true;
  }

  return false;
}

bool vencedorX(int velha[3][3]) {
  if (linha(velha, 1) || coluna(velha, 1) || diagonal(velha, 1)) {
    return true;
  } else {
    return false;
  }
}

int VerificaVelha(int velha[3][3]) {
  if (vencedorX(velha) == true) {
    return 1;
  }

  return -200;
}
