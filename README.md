# 🏆 Sistema de Gestão para Maratona de Programação (Linguagem C)

> 📌 **Contexto do Projeto:**  
> Projeto acadêmico desenvolvido durante o 1º ano de graduação (disciplina de Algoritmos e Programação), com o objetivo de consolidar fundamentos essenciais da linguagem C, manipulação de memória e estruturas de dados heterogêneas (`structs`).

---

## 🎯 Objetivo de Aprendizado
O objetivo deste repositório é registrar o início da minha trajetória técnica e prática com C puro, exercitando:
* Modularização de código em funções.
* Manipulação manual de vetores e cadeias de caracteres (`char[]`).
* Algoritmos de ordenação implementados do zero (Bubble Sort com múltiplos critérios de desempate).
* Validação de fluxos de entrada e tratamento de regras de negócio via terminal.

---

## 📌 Funcionalidades

* **Cadastro e Atualização de Equipes:**
  * Registro da instituição de ensino e dos 3 integrantes por equipe.
  * Validação de nomes (exigência de sobrenome, caracteres alfabéticos permitidos e limite de tamanho).
  * Atualização dinâmica de dados para equipes já cadastradas.
* **Consulta por Instituição:**
  * Busca de equipes filtradas por instituição com listagem de integrantes.
  * Ordenação alfabética das equipes retornadas na busca.
* **Registro de Submissões:**
  * Suporte para até 13 problemas (letras de `A` a `M`).
  * Validação de veredito (`AC`, `PE` ou rejeição).
  * Contabilização automática de penalidades (tempo acumulado + 5 minutos por erro).
  * Bloqueio de novas submissões para problemas já aceitos.
* **Placar Geral em Tempo Real:**
  * Algoritmo de ordenação baseado nas regras de competição:
    1. Maior número de problemas resolvidos.
    2. Menor tempo total acumulado com penalidades (critério de desempate).
  * Matriz visual de status de cada problema (`A` = Aceito, `X` = Rejeitado, `-` = Sem submissão).

---

## 🛠️ Tecnologias e Conceitos Aplicados

* **Linguagem C** (padrão C99 / C11).
* **Estruturas de Dados:** `structs` aninhadas (`struct Problemas` dentro de `struct Equipes`).
* **Algoritmos de Ordenação:** Bubble Sort com múltiplos critérios de desempate.
* **Manipulação de Strings e I/O:** `fgets`, `strlen`, `strcpy`, sanitização de quebras de linha (`\n`) e tratamento de caracteres com `tolower`/`toupper`.

---

## 📅 Histórico
* **Desenvolvido em:** 2025 (1º ano de graduação)
* **Status:** Concluído / Registro de aprendizado prático
