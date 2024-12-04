# Verificador de Jogo da Velha

Este projeto implementa um **verificador de estados do jogo da velha** usando a abordagem de **Desenvolvimento Orientado a Testes (TDD)**. O objetivo é garantir que o jogo seja validado corretamente em diferentes situações, como vitória, empate, jogo indefinido ou impossível.

## Tecnologias Utilizadas

- **Linguagem:** C++
- **Framework de Testes:** [Catch2](https://github.com/catchorg/Catch2)
- **Ferramentas de Análise:**
  - `cpplint` (Estilo de código)
  - `cppcheck` (Análise estática)
  - `Valgrind` (Detecção de vazamentos de memória)
  - `gcov` (Cobertura de testes)

## Regras de Verificação

O programa analisa o estado do tabuleiro (matriz 3x3) e retorna:
- `1` - Vitória do jogador **X**.
- `2` - Vitória do jogador **O**.
- `0` - **Empate** (sem posições vazias e sem vencedores).
- `-1` - **Jogo indefinido** (sem vencedores, mas com posições vazias).
- `-2` - **Jogo impossível** (dois vencedores ou número de jogadas inválido).
- `-200` - Estado desconhecido ou erro interno.

## Como Executar

### 1. Clonar o Repositório

```bash
git clone https://github.com/Aninha1105/Trabalho-MP-jogo-da-velha-tdd.git
cd Trabalho-MP-jogo-da-velha-tdd
```

### 2. Compilar e Executar o Projeto

```bash
make
```

## Conclusão
Este projeto demonstrou a aplicação prática de Desenvolvimento Orientado a Testes (TDD). Ao integrar boas práticas de programação, testes rigorosos e ferramentas de análise de qualidade, foi possível garantir um código confiável, eficiente e fácil de manter. A abordagem TDD não só melhorou a precisão das validações, como também proporcionou maior confiança no desenvolvimento de cada funcionalidade.

## Link para o github
https://github.com/Aninha1105/Trabalho-MP-jogo-da-velha-tdd