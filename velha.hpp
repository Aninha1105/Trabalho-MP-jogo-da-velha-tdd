/**
 * \file velha.hpp
 * \brief Declaração das funções para verificar o estado do jogo da velha.
 * \author Programador
 */

/**
 * \brief Verifica o estado atual do jogo da velha.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \return -2 se o jogo é impossível, -1 se está indefinido, 0 se empatado,
 *          1 se o jogador X venceu, 2 se o jogador O venceu, -200 para erro desconhecido.
 */
int VerificaVelha(int velha[3][3]);

/**
 * \brief Verifica se o jogador X (representado por 1) venceu o jogo.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \return true se o jogador X venceu, false caso contrário.
 */
bool vencedorX(int velha[3][3]);

/**
 * \brief Verifica se o jogador O (representado por 2) venceu o jogo.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \return true se o jogador O venceu, false caso contrário.
 */
bool vencedorO(int velha[3][3]);

/**
 * \brief Verifica se o jogo está empatado.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \param contadorVazio Número de posições vazias no tabuleiro.
 * \return true se o jogo está empatado, false caso contrário.
 */
bool empatado(int velha[3][3], int contadorVazio);

/**
 * \brief Verifica se o jogo está indefinido.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \param contadorVazio Número de posições vazias no tabuleiro.
 * \return true se o jogo está indefinido, false caso contrário.
 */
bool indefinido(int velha[3][3], int ContadorVazio);

/**
 * \brief Verifica se o jogo é impossível.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \param contadorX Número de peças X no tabuleiro.
 * \param contadorO Número de peças O no tabuleiro.
 * \return true se o jogo é impossível, false caso contrário.
 */
bool impossivel(int velha[3][3], int contadorX, int contadorO);

/**
 * \brief Verifica se o jogador venceu em alguma linha.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \param jogador Valor do jogador (1 para X, 2 para O).
 * \return true se o jogador venceu em uma linha, false caso contrário.
 */
bool verificaLinha(int velha[3][3], int jogador);

/**
 * \brief Verifica se o jogador venceu em alguma coluna.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \param jogador Valor do jogador (1 para X, 2 para O).
 * \return true se o jogador venceu em uma coluna, false caso contrário.
 */
bool verificaColuna(int velha[3][3], int jogador);

/**
 * \brief Verifica se o jogador venceu em alguma diagonal.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \param jogador Valor do jogador (1 para X, 2 para O).
 * \return true se o jogador venceu em uma diagonal, false caso contrário.
 */
bool verificaDiagonal(int velha[3][3], int jogador);

/**
 * \brief Conta as ocorrências de peças X, O e posições vazias no tabuleiro.
 * \param velha Matriz 3x3 representando o tabuleiro.
 * \return Ponteiro para um array com as contagens de [vazias, X, O].
 */
int* estadoTabuleiro(int velha[3][3]);
