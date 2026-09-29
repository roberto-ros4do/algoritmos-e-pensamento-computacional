# Sistema de Reserva de Poltronas

## 1. Identificação

- **Aluno(a):** _Roberto Rosado_
- **Disciplina:** _Algoritmos e Pensamento Comnputacional_
- **Professora:** Profa. Karla Sartin
- **Título do projeto:** Sistema de Reserva de Poltronas

## 2. Objetivo

O programa simula a reserva de poltronas de uma pequena sala (cinema, teatro, auditório etc.) com 9 lugares, organizados em uma matriz 3x3. Ele permite que o usuário escolha poltronas livres, impede que uma mesma poltrona seja reservada duas vezes e encerra automaticamente quando todas as poltronas estiverem ocupadas.

## 3. Funcionamento do programa

### Como as poltronas são definidas
No início da execução, a matriz `plt[3][3]` é preenchida com os números de 1 a 9, um para cada poltrona. Esse número é o que o usuário digita para escolher o lugar.

```
[ 1 ][ 2 ][ 3 ]
[ 4 ][ 5 ][ 6 ]
[ 7 ][ 8 ][ 9 ]
```

### Como as reservas são realizadas
A cada repetição, o programa exibe o mapa de poltronas (função `exibirPoltronas`) e pergunta qual poltrona o usuário deseja reservar. O número digitado é enviado para a função `verificaEscolha`, que percorre a matriz procurando a poltrona correspondente.

Ao ser reservada, a poltrona tem seu valor trocado pelo **negativo do seu número** (por exemplo, a poltrona 5 passa a valer `-5`). Assim o programa sabe que ela está ocupada sem perder a informação de qual poltrona ela é. No mapa, poltronas reservadas aparecem como `[  X ]`.

### Como valores inválidos são tratados
Antes de procurar a poltrona, `verificaEscolha` confere se o número está entre 1 e 9. Caso não esteja (ex.: `0`, `-3`, `15`), o programa exibe a mensagem `POLTRONA INVALIDA! ESCOLHA DE 1 A 9.` e nenhuma alteração é feita na matriz.

### Como o programa identifica poltronas já reservadas
Se o valor encontrado na matriz for igual ao negativo do número escolhido, significa que a poltrona já foi reservada anteriormente. Nesse caso, é exibida a mensagem `POLTRONA JA RESERVADA! ESCOLHA OUTRA!` e a reserva não é repetida.

### Como funciona a contagem de poltronas ocupadas
A função `verificarLotacao` percorre toda a matriz e conta quantas posições possuem valor negativo, ou seja, quantas poltronas estão reservadas. Essa contagem é feita no início de cada repetição do laço principal.

### Qual condição encerra o programa
O programa é encerrado em duas situações:
1. **Lotação completa:** quando `verificarLotacao` retorna 9 (todas as poltronas reservadas), é exibida a mensagem `TODAS AS POLTRONAS ESTÃO OCUPADAS` e o laço é interrompido com `break`.
2. **Escolha do usuário:** após cada reserva, o programa pergunta `Deseja continuar?[S/N]`. Qualquer resposta diferente de `S` ou `s` encerra o laço.

Em ambos os casos é exibida a mensagem `SAINDO...`.

## 4. Estruturas de repetição utilizadas

- **`for` (aninhados):** usados para percorrer as linhas e colunas da matriz 3x3 no preenchimento inicial, na exibição das poltronas, na busca da poltrona escolhida e na contagem das reservadas.
- **`do...while`:** usado no laço principal do programa, em `main`, que exibe as poltronas, recebe a escolha do usuário e pergunta se ele deseja continuar.

**Justificativa da escolha:**

_Escolhi a estrutura DO...WHILE pois na dinâmica deste código faria mais sentido pois o usuário escolhia se gostaria de continuar ou não no final do código, logo a verificação deve ser feita ao final do algoritmo, oque é proporcionado pelo DO...WHILE_

## 5. Como executar

Compile o programa com o GCC:

```bash
gcc main.c -o main
```

Execute:

```bash
./main
```

No Windows, execute com:

```bash
main.exe
```

## 6. Testes realizados

### Teste 1: validação de entradas inválidas
**Entradas:** `0`, depois `15`.

**Resultado obtido:** para ambos os valores o programa exibiu `POLTRONA INVALIDA! ESCOLHA DE 1 A 9.` e o mapa de poltronas permaneceu inalterado, com todas as poltronas livres.

### Teste 2: tentativa de reservar uma poltrona já ocupada
**Entradas:** `5`, continuar `S`, depois `5` novamente.

**Resultado obtido:** na primeira escolha o programa exibiu `POLTRONA RESERVADA!` e a poltrona 5 passou a aparecer como `[  X ]`. Na segunda tentativa foi exibida a mensagem `POLTRONA JA RESERVADA! ESCOLHA OUTRA!` e a poltrona continuou reservada, sem duplicidade.

### Teste 3: ocupação de todas as poltronas, provocando o encerramento automático
**Entradas:** poltronas `1` a `9`, respondendo `S` a cada pergunta de continuar.

**Resultado obtido:** cada poltrona foi reservada e marcada com `[  X ]`. Após a nona reserva, ao responder `S`, o programa verificou a lotação, exibiu `TODAS AS POLTRONAS ESTÃO OCUPADAS` e encerrou automaticamente com `SAINDO...`, sem pedir uma nova poltrona.

> _Evidências (prints da execução de cada teste) estão disponíveis na pasta do repositório._
