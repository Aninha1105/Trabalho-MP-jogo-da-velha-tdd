/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Teste 1: se o vencedor foi o X") {
  int teste1[3][3]= {{ 2, 0, 1 },
                     { 2, 0, 1 },
                     { 0, 2, 1 }};
    REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Teste 2: se o vencedor foi o O") {
  int teste2[3][3]= {{ 2, 0, 1 },
                     { 0, 2, 1 },
                     { 0, 1, 2 }};
    REQUIRE(VerificaVelha(teste2) == 2);
}

TEST_CASE("Teste 3: se o jogo está empatado") {
  int teste3[3][3]= {{ 2, 1, 2 },
                     { 2, 1, 1 },
                     { 1, 2, 1 }};
    REQUIRE(VerificaVelha(teste3) == 0);
}

TEST_CASE("Teste 4: se o jogo está indefinido") {
  int teste4[3][3]= {{ 0, 0, 0 },
                     { 0, 1, 0 },
                     { 0, 0, 0 }};
    REQUIRE(VerificaVelha(teste4) == -1);
}

TEST_CASE("Teste 5: se o jogo é com certeza impossível pelas regras") {
  int teste5[3][3]= {{ 2, 2, 2 },
                     { 1, 1, 1 },
                     { 2, 2, 2 }};
    REQUIRE(VerificaVelha(teste5) == -2);
}
