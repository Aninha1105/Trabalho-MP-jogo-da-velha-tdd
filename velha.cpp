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

bool vencedorX(int velha[3][3]) {
  return false;
}

int VerificaVelha(int velha[3][3]) {
  if (vencedorX(velha) == true) {
    return 1;
  }

  return -200;
}
